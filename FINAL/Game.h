#pragma once
#include <SFML/Graphics.hpp>
#include "Sandbox.h"

// Třída Game se stará o hlavní okno, zachytávání událostí (klávesnice/myš) a chod programu
class Game {
private:
    sf::RenderWindow window; // Hlavní okno
    Sandbox sandbox;         // Mřížka pro vykreslování
    
    int brushSize;           // Velikost štětce
    int currentMaterial;     // Aktuálně vybraný materiál (1 = písek, 2 = kámen atd.)

    //pomocné funkce
    void handleEvents();
    void update();
    void render();

public:
    // Konstr.
    Game();

    void run();
};