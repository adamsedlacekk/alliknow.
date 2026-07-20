#include "Sandbox.h"
#include <algorithm> // Pro F5 reset
#include <cstdlib>   // Pro náhodná čísla (rand)

// Konstruktor
Sandbox::Sandbox(int w, int h)
    : width(w), height(h),
    texture()
{
    (void)texture.resize({(unsigned int)w, (unsigned int)h});
    sprite.emplace(texture);

    grid.assign(width * height, VZDUCH);   // Vyplní pole nulami (vzduchem)
    pixels.assign(width * height * 4, 0);  // Vyplní pole pixelů nulami

    // 4x zvětšení mřížky (480x270) kvůli většímu oknu (1920x1080)
    sprite->setScale({4.0f, 4.0f}); 
}

void Sandbox::clearGrid()
{
    // Vezme začátek a konec paměti a vše přepíše na VZDUCH (0)
    std::fill(grid.begin(), grid.end(), VZDUCH);
}

void Sandbox::paint(int mouseX, int mouseY, int brushSize, int material)
{
    // 2 cykly co projdou celé okolí myši (podle velikosti štětce)
    for (int yOffset = -brushSize; yOffset <= brushSize; yOffset++)
    {
        for (int xOffset = -brushSize; xOffset <= brushSize; xOffset++)
        {
            // Pozice aktuálního zrnka
            int brushX = mouseX + xOffset;
            int brushY = mouseY + yOffset;

            // Ověření, že zrnko nepadá mimo okno
            if (brushX >= 0 && brushX < width && brushY >= 0 && brushY < height)
            {
                int gridIndex = brushY * width + brushX;
                grid[gridIndex] = material; // Zapsání podle vybraného materiálu
            }
        }
    }
}

void Sandbox::loadGuideImage(const std::string &path)
{
    if (uiTexture.loadFromFile(path))
    {
        uiSprite.emplace(uiTexture);
        uiSprite->setPosition({10.0f, 10.0f}); // ukotvení v levém horním rohu
    }
}

void Sandbox::updatePhysics()
{
    // z dola nahoru (Pevné látky a tekutiny)
    for (int y = height - 2; y >= 0; y--)
    {
        for (int x = 0; x < width; x++)
        {
            int currentIndex = y * width + x;

            // oheň
            if (grid[currentIndex] == OHEN)
            {
                if (y > 0 && grid[currentIndex - width] == DREVO && rand() % 100 < 5)
                    grid[currentIndex - width] = OHEN; // Šíření nahoru
                if (y < height - 1 && grid[currentIndex + width] == DREVO && rand() % 100 < 5)
                    grid[currentIndex + width] = OHEN; // Šíření dolů
                if (x > 0 && grid[currentIndex - 1] == DREVO && rand() % 100 < 5)
                    grid[currentIndex - 1] = OHEN;     // Šíření doleva
                if (x < width - 1 && grid[currentIndex + 1] == DREVO && rand() % 100 < 5)
                    grid[currentIndex + 1] = OHEN;     // Šíření doprava

                // Oheň postupně zhasne a změní se na kouř (2% šance každý snímek)
                if (rand() % 100 < 2)
                    grid[currentIndex] = KOUR;
                continue;
            }

            // =Písek
            if (grid[currentIndex] == PISEK)
            {
                int belowIndex = (y + 1) * width + x;
                int PouzeVlevoIndex = (y + 1) * width + (x - 1);
                int PouzeVpravoIndex = (y + 1) * width + (x + 1);

                // Dolů (Propustí ho Vzduch NEBO Voda)
                if (grid[belowIndex] == VZDUCH || grid[belowIndex] == VODA)
                {
                    grid[currentIndex] = grid[belowIndex]; // Voda (nebo vzduch) probublá nahoru
                    grid[belowIndex] = PISEK;              // Písek spadne dolů
                }
                // Doleva dolů
                else if (x > 0 && (grid[PouzeVlevoIndex] == VZDUCH || grid[PouzeVlevoIndex] == VODA))
                {
                    grid[currentIndex] = grid[PouzeVlevoIndex];
                    grid[PouzeVlevoIndex] = PISEK;
                }
                // Doprava dolů
                else if (x < width - 1 && (grid[PouzeVpravoIndex] == VZDUCH || grid[PouzeVpravoIndex] == VODA))
                {
                    grid[currentIndex] = grid[PouzeVpravoIndex];
                    grid[PouzeVpravoIndex] = PISEK;
                }
            }

            // VODA H2O
            if (grid[currentIndex] == VODA)
            {
                // Pokud se voda dotkne ohně, voda se vypaří (Pára) a oheň zhasne
                if (y > 0 && grid[currentIndex - width] == OHEN) { grid[currentIndex] = PARA; grid[currentIndex - width] = VZDUCH; continue; }
                if (y < height - 1 && grid[currentIndex + width] == OHEN) { grid[currentIndex] = PARA; grid[currentIndex + width] = VZDUCH; continue; }
                if (x > 0 && grid[currentIndex - 1] == OHEN) { grid[currentIndex] = PARA; grid[currentIndex - 1] = VZDUCH; continue; }
                if (x < width - 1 && grid[currentIndex + 1] == OHEN) { grid[currentIndex] = PARA; grid[currentIndex + 1] = VZDUCH; continue; }

                // Pád vody dolů jako u písku
                int belowIndex = (y + 1) * width + x;
                int PouzeVlevoIndex = (y + 1) * width + (x - 1);
                int PouzeVpravoIndex = (y + 1) * width + (x + 1);

                if (grid[belowIndex] == VZDUCH) {
                    grid[currentIndex] = VZDUCH; grid[belowIndex] = VODA;
                }
                else if (x > 0 && grid[PouzeVlevoIndex] == VZDUCH) {
                    grid[currentIndex] = VZDUCH; grid[PouzeVlevoIndex] = VODA;
                }
                else if (x < width - 1 && grid[PouzeVpravoIndex] == VZDUCH) {
                    grid[currentIndex] = VZDUCH; grid[PouzeVpravoIndex] = VODA;
                }
                else {
                    // ROZLÉVÁNÍ: Když nemůže padat, hledá místo vlevo/vpravo
                    int leftIndex = y * width + (x - 1);
                    int rightIndex = y * width + (x + 1);
                    bool canGoLeft = (x > 0 && grid[leftIndex] == VZDUCH);
                    bool canGoRight = (x < width - 1 && grid[rightIndex] == VZDUCH);

                    if (canGoLeft && canGoRight) {
                        if (rand() % 2 == 0) { grid[currentIndex] = VZDUCH; grid[leftIndex] = VODA; }
                        else { grid[currentIndex] = VZDUCH; grid[rightIndex] = VODA; }
                    }
                    else if (canGoLeft) { grid[currentIndex] = VZDUCH; grid[leftIndex] = VODA; }
                    else if (canGoRight) { grid[currentIndex] = VZDUCH; grid[rightIndex] = VODA; }
                }
            }
        }
    }

    //  Odshora dolů (Stoupání plynů)
    for (int y = 1; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int currentIndex = y * width + x;

            // =Kouř a pára
            if (grid[currentIndex] == KOUR || grid[currentIndex] == PARA)
            {
                int chanceToDie = (grid[currentIndex] == KOUR) ? 2 : 5;
                if (rand() % 100 < chanceToDie)
                {
                    grid[currentIndex] = VZDUCH; // Plyn mizí
                    continue;
                }

                int aboveIndex = (y - 1) * width + x;
                int aboveLeftIndex = (y - 1) * width + (x - 1);
                int aboveRightIndex = (y - 1) * width + (x + 1);
                int currentGas = grid[currentIndex]; // Pamatuje si jestli je to Kouř nebo Pára

                // Stoupání nahoru
                if (grid[aboveIndex] == VZDUCH) {
                    grid[currentIndex] = VZDUCH; grid[aboveIndex] = currentGas;
                }
                // Do stran (náhodné kličkování)
                else if (x > 0 && grid[aboveLeftIndex] == VZDUCH && rand() % 2 == 0) {
                    grid[currentIndex] = VZDUCH; grid[aboveLeftIndex] = currentGas;
                }
                else if (x < width - 1 && grid[aboveRightIndex] == VZDUCH && rand() % 2 == 0) {
                    grid[currentIndex] = VZDUCH; grid[aboveRightIndex] = currentGas;
                }
            }
        }
    }
}

void Sandbox::render(sf::RenderWindow &window)
{
    // Obarvení pixelů (Render)
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int gridIndex = y * width + x;
            int pixelIndex = gridIndex * 4;

            switch (grid[gridIndex])
            {
            case PISEK: // Písek -> Žlutá
                pixels[pixelIndex] = 255; pixels[pixelIndex + 1] = 255; pixels[pixelIndex + 2] = 0; break;
            case KAMEN: // Kámen -> Šedá
                pixels[pixelIndex] = 120; pixels[pixelIndex + 1] = 120; pixels[pixelIndex + 2] = 120; break;
            case DREVO: // Dřevo -> Hnědá
                pixels[pixelIndex] = 100; pixels[pixelIndex + 1] = 50; pixels[pixelIndex + 2] = 20; break;
            case OHEN: // Oheň -> Červeno-oranžová
                pixels[pixelIndex] = 230; pixels[pixelIndex + 1] = 60; pixels[pixelIndex + 2] = 20; break;
            case VODA: // Voda -> Modrá
                pixels[pixelIndex] = 40; pixels[pixelIndex + 1] = 100; pixels[pixelIndex + 2] = 200; break;
            case KOUR: // Kouř -> Světle šedá
                pixels[pixelIndex] = 150; pixels[pixelIndex + 1] = 150; pixels[pixelIndex + 2] = 150; break;
            case PARA: // Pára -> Bílo-modrá
                pixels[pixelIndex] = 200; pixels[pixelIndex + 1] = 200; pixels[pixelIndex + 2] = 220; break;
            default: // Vzduch -> Černá
                pixels[pixelIndex] = 0; pixels[pixelIndex + 1] = 0; pixels[pixelIndex + 2] = 0; break;
            }
            
            // Plná neprůhlednost (Alpha = 255)
            pixels[pixelIndex + 3] = 255;
        }
    }

    // Aktualizování papíru novými barvami
    texture.update(pixels.data(), {(unsigned int)width, (unsigned int)height}, {0, 0});
    
    // Vykreslení:
    if (sprite) window.draw(*sprite);   // Prvně nakreslíme hru (písek atd.)
    if (uiSprite) window.draw(*uiSprite); // A úplně nakonec přes to plácneme ten obrázek s návodem
}