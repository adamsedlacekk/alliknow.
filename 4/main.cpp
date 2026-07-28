#include "Ucet.h"
#include "SporiciUcet.h"
#include "BeznyUcet.h"
#include <iostream>
#include <string>
#include <vector>

int nejdelsiRadaVkladu(Ucet* ucet){
    int aktualRada = 0;
    int maxRada = 0;
    for(double transakce : ucet->getHistorie()){
        if(transakce > 0){
            aktualRada++;
            if(aktualRada > maxRada){
                maxRada = aktualRada;
            }
        }
        else{
            aktualRada = 0;
        }
    }

    return maxRada;
}

void odstraneniMalychVyberu(Ucet* ucet){
    std::vector<double>& historie = ucet -> getHistorie();
    for(auto it = historie.begin(); it != historie.end();){
        if(*it < 0 && *it > -50){
            it = historie.erase(it);
        }
        else{
            ++it;
        }
    }

}

int main(){
    std::cout << "Pocatecni aktivni ucty: " << Ucet::getCitac() << "\n\n";

    std::vector<Ucet*> ucty;
    ucty.push_back(new BeznyUcet("CZ-1111", 50));
    ucty.push_back(new BeznyUcet("CZ-2222", 0));
    ucty.push_back(new SporiciUcet("CZ-3333", 4.5));
    
    ucty[0]->pridejTransakce({1000, 500, -20, 200, 300, 100, -45, -100});
    ucty[1]->pridejTransakce({-10, 50, -40, -60, 200});
    ucty[2]->pridejTransakce({1000, 5000, 3400, -500});

    std::cout << "Aktivni ucty po alokaci: " << Ucet::getCitac() << "\n\n";

    std::cout << "--- Pocatecni Polymorfismus a Analyza ---\n";

    for(Ucet* u : ucty){
        u->vypisInfo();
        u->analyzujUcet();
    }

    std::cout<< " --- Algoritmus 1: Nejdelsi rada vkladu ---\n";
    std::cout<< "Ucet CZ1111 ma nejdelsi radu vkladu o delce: " << nejdelsiRadaVkladu(ucty[0]) << " transakci.\n\n";

    std::cout<< " --- Algoritmus 2: Odstraneni malych vyberu ---\n";
    std::cout<< "Data u1 pred odstranenim (pocet): " << ucty[0]->getHistorie().size() << "\n";
    odstraneniMalychVyberu(ucty[0]);
    std::cout<< "Data u1 po odstraneni (vybery mensi nez 50Kc smazany): " << ucty[0]->getHistorie().size() << "\n\n";

    std::cout << "--- Pretizeni operatoru ---\n";
    std::cout << "Porovnani pomoci operatoru == (podle vyse poplatku):\n";
    {
    BeznyUcet lokal1("LOKAL-A", 50);
    BeznyUcet lokal2("LOKAL-B", 50);
    BeznyUcet lokal3("LOKAL-C", 76);
    
    //==
    std::cout << lokal1 << "\nma stejny poplatek jako\n" << lokal2 << " -> " << (lokal1 == lokal2 ? "ANO" : "NE") << "\n\n";
    std::cout << lokal1 << "\nma stejny poplatek jako\n" << lokal3 << " -> " << (lokal1 == lokal3 ? "ANO" : "NE") << "\n\n";

    //+=
    std::cout << "Pridani transakce pomoci operatoru += :\n";
    std::cout << "Stav LokA pred pridanim: " << lokal1 << "\n";
    lokal1+=500;
    std::cout << "Stav LokA po pridani: " << lokal1 << "\n\n";
    }

    //Uklid
    for(Ucet* u : ucty){
        delete u;
    }
    ucty.clear();
    std::cout << "Konecny pocet uctu v pameti: " << Ucet::getCitac();
}