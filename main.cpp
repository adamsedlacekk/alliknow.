#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "KritickyServer.h"
#include "KlustrovyServer.h"

// 1. Algoritmická funkce: Odstranění duplicit
// Funkce přijme referenci na vektor, seřadí jej a pomocí kombinace unique a erase odstraní duplicity
void odstranDuplicity(std::vector<double>& zatez) {
    std::sort(zatez.begin(), zatez.end());
    auto last = std::unique(zatez.begin(), zatez.end());
    zatez.erase(last, zatez.end());
}

// 2. Algoritmická funkce: Detekce skoků
// Funkce prochází vektor od indexu 1 a porovnává hodnoty s předchozím měřením
int detekujSkokyZateze(const std::vector<double>& zatez, double hranice) {
    int pocetSkoku = 0;
    if (zatez.empty()) return 0;
    
    for (size_t i = 1; i < zatez.size(); ++i) {
        if ((zatez[i] - zatez[i-1]) > hranice) {
            std::cout << " -> Skok na indexu " << i << ": narust z " 
                      << zatez[i-1] << "% na " << zatez[i] << "%" << std::endl;
            pocetSkoku++;
        }
    }
    return pocetSkoku;
}

int main() {
    // Krok 1: Výpis počátečního stavu počítadla serverů (očekáváno 0)
    std::cout << "Pocatecni pocet serveru: " << ServerNode::getPocetServeru() << "\n\n";

    // Krok 2: Příprava dat a test algoritmických funkcí
    std::cout << "--- Test algoritmu nad std::vector (externi funkce) ---\n";
    // Vytvoření objektu na zásobníku
    KritickyServer k1("Sec-Master");
    k1.pridejZaznam(40.0);
    k1.pridejZaznam(40.0);
    k1.pridejZaznam(45.0);
    k1.pridejZaznam(90.0);
    k1.pridejZaznam(90.0);
    k1.pridejZaznam(50.0);
    k1.pridejZaznam(50.0);

    // Výpis před deduplikací
    std::cout << "Pred deduplikaci: " << k1 << "\n";
    
    // Aplikace deduplikace přes getter a opětovný výpis
    odstranDuplicity(k1.getZatezCPU());
    std::cout << "Po deduplikaci:   " << k1 << "\n";

    // Detekce skoků s hranicí 30.0
    std::cout << "Detekce skoku (hranice 30%):\n";
    int pocet = detekujSkokyZateze(k1.getZatezCPU(), 30.0);
    std::cout << "Celkem detekovano skoku: " << pocet << "\n\n";

    // Krok 3: Test Výjimek a operátoru +
    std::cout << "--- Test vyjimek a klustrovani ---\n";
    
    // Vytvoření dynamických objektů na haldě pomocí new
    KlustrovyServer* nodeX = new KlustrovyServer("Node-X");
    KlustrovyServer* nodeY = new KlustrovyServer("Node-Y");

    // Vložení měření do obou klustrů
    nodeX->pridejZaznam(20.0);
    nodeX->pridejZaznam(40.0);
    nodeX->pridejZaznam(60.0);

    nodeY->pridejZaznam(30.0);
    nodeY->pridejZaznam(50.0);

    // Pokus o součet s různým počtem záznamů zachycený do try-catch bloku
    try {
        KlustrovyServer vysledek = *nodeX + *nodeY;
    } catch (const std::invalid_argument& e) {
        std::cout << "Zachycena vyjimka: " << e.what() << "\n";
    }

    // Přidání chybějícího měření pro srovnání velikostí
    nodeY->pridejZaznam(70.0);

    // Opakovaný pokus o sečtení (zprůměrování) a uložení na zásobník
    std::cout << "Pouziti operatoru + po oprave rozmeru:\n";
    KlustrovyServer finalniKluster = *nodeX + *nodeY;
    std::cout << finalniKluster << "\n\n";

    // Krok 4: Úklid paměti
    std::cout << "--- Uklid pameti ---\n";
    
    // Smazání dynamicky alokovaných objektů z haldy
    delete nodeX;
    delete nodeY;

    // Výpis konečného počtu serverů v evidenci (měl by započítat zbývající objekty k1 a finalniKluster)
    std::cout << "Konecny pocet serveru v evidenci: " << ServerNode::getPocetServeru() << "\n";

    return 0;
}