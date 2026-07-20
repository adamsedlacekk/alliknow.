#include "Game.h"

// Vytvoření okna a nastavení základních hodnot
Game::Game() : window(sf::VideoMode({1920, 1080}), "adee: falling sand."), sandbox(480, 270) {
    window.setFramerateLimit(60); // max 60 FPS
    brushSize = 0;                // Výchozí štětec
    currentMaterial = PISEK;      // Výchozí materiál
    
    // Načtení obrázku s bindy
    sandbox.loadGuideImage("guide.png"); 
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents(); // 1. Vem input (myš a kl.)
        update();       // 2. Vyřeš co a kam
        render();       // 3. Vykresli to
    }
}

void Game::handleEvents() {
    // Čtení eventů ve verzi SFML 3
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        
        // Zavření okna křížkem
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
        
        // Zmáčkl uživatel nějakou klávesu?
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            // F5 (Obnovení - vymaže mřížku)
            if (keyPressed->code == sf::Keyboard::Key::F5)   sandbox.clearGrid();
            
            // Písek (1)
            if (keyPressed->code == sf::Keyboard::Key::Num1) currentMaterial = PISEK;
            // Kámen (2)
            if (keyPressed->code == sf::Keyboard::Key::Num2) currentMaterial = KAMEN;
            // Dřevo (3)
            if (keyPressed->code == sf::Keyboard::Key::Num3) currentMaterial = DREVO;
            // Oheň (4)
            if (keyPressed->code == sf::Keyboard::Key::Num4) currentMaterial = OHEN;
            // Voda (5)
            if (keyPressed->code == sf::Keyboard::Key::Num5) currentMaterial = VODA;

            // Šipka nahoru (Zvětšení štětce)
            if (keyPressed->code == sf::Keyboard::Key::Up) brushSize += 3;
            // Šipka dolu (Zmenšení štětce)
            if (keyPressed->code == sf::Keyboard::Key::Down) {
                brushSize -= 3;
                if (brushSize < 0) brushSize = 0; // Nepůjde do mínusu
            }
        }
        
        // Kolečko myši
        if (const auto* mouseWheel = event->getIf<sf::Event::MouseWheelScrolled>()) {
            if (mouseWheel->wheel == sf::Mouse::Wheel::Vertical) {
                if (mouseWheel->delta > 0) brushSize += 1; // Kolečko nahoru
                if (mouseWheel->delta < 0) {               // Kolečko dolu
                    brushSize -= 1;
                    if (brushSize < 0) brushSize = 0;      // bS>0
                }
            }
        }
    }
}

void Game::update() {
    // Držení levého tlačítka myši (Kreslení)
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        
        // Dělení protože okno je 4x větší (1920x1080 / 4 = 480x270)
        int mouseX = mousePos.x / 4;
        int mouseY = mousePos.y / 4;
        
        // Poslání pozice myši pískovišti, ať tam "kápne" materiál
        sandbox.paint(mouseX, mouseY, brushSize, currentMaterial);
    }
    
    // Spuštění fyziky pro tento snímek
    sandbox.updatePhysics();
}

void Game::render() {
    window.clear(sf::Color::Black); // Vymazání starého okna (černá)
    sandbox.render(window);         // Vykreslení pískoviště a obrázku
    window.display();               // Zobrazení na monitor
}