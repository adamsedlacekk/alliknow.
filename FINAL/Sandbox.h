#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include <cstdint> // Pro novinku SFML 3 (std::uint8_t barvy)

// list materiálu (Enum nahrazuje čísla za slova)
enum Material {
    VZDUCH = 0, PISEK = 1, KAMEN = 2, DREVO = 3, 
    OHEN = 4, VODA = 5, KOUR = 6, PARA = 7
};

class Sandbox {
private:
    int width;
    int height;
    
    // 1D vektor, velikost je ŠÍŘKA * VÝŠKA, ukládá typy materiálů v číslech
    std::vector<int> grid;
    
    // Grafické pole (Barvy): 1D vektor, velikost x4 kvůli RGBA barvám
    std::vector<std::uint8_t> pixels;
    
    // Prázdný papír (textura) a plátno (sprite) pro vykreslení částic materiálu
    sf::Texture texture;
    std::optional<sf::Sprite> sprite;
    std::optional<sf::Sprite> enemySprite; //Na začátku prázdné
    
    // Textura a plátno pro obrázek v rohu
    sf::Texture uiTexture;
    std::optional<sf::Sprite> uiSprite;

public:
    // Konstruktor pískoviště
    Sandbox(int w, int h);
    
    // Funkce
    void loadGuideImage(const std::string& path);                    // Načtení png s bindy
    void clearGrid();                                                // F5 vymazání
    void paint(int mouseX, int mouseY, int brushSize, int material); // Malování myší
    void updatePhysics();                                            // Vlastní chování písků/vody
    void render(sf::RenderWindow& window);                           // Obarvení pixelů
};