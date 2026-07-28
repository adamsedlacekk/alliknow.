#include "Senzor.h"
#include "SenzorSpotreby.h"
#include "TeplotniSenzor.h"
#include <iostream>
#include <string>
#include <vector>

int nejdelsiStabilniObdobi(Senzor* s){
    int aktualniRada = 0;
    int maxRada = 0;
    for(double x : s->getHistorie()){
        if(x > 0){
            aktualniRada++;
            if(aktualniRada > maxRada){
                maxRada = aktualniRada;
            }
        }
        else{
            aktualniRada = 0;
        }
    }
    
    return maxRada;
}

void odstraneniDrobnychChybMereni(Senzor* s){
    std::vector<double>& historie = s -> getHistorie();
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
    std::cout << "Pocatecni aktivni ucty: " << Senzor::getCitac() << "\n\n";

    std::vector<Senzor*> senzory;
    senzory.push_back(new SenzorSpotreby("PWR-1111", 3000));
    senzory.push_back(new SenzorSpotreby("PWR-2222", 1500));
    senzory.push_back(new TeplotniSenzor("PWR-3333", 22.5));

    senzory[0] -> pridejMereni({30, -50, 3, -4, 100, -100});
    senzory[1] -> pridejMereni({14,-14,51,-51});
    senzory[2] -> pridejMereni({3,-3});

    std::cout<< "Pocet uctu po alokaci: " << Senzor::getCitac() << "\n\n";

    for(Senzor* s : senzory){
        s->vypisInfo();
        s->analyzujSenzor();
    }

    std::cout<< "--- Algoritmus 1: Nejdelsi stabilni obdobi ---\n";
    std::cout<< "Senzor PWR-1111 ma nejdelsi radu kladnych mereni o delce: " << nejdelsiStabilniObdobi(senzory[0]) << " zaznamu.\n\n";

    std::cout<<"--- Algoritmus 2: Odstraneni drobnych chyb mereni ---\n";
    std::cout<<"Data S1 pred odstranenim (pocet): " << senzory[0]->getHistorie().size() << "\n";
    odstraneniDrobnychChybMereni(senzory[0]);
    std::cout<<"Data S1 po odstraneni (vypadky mensi nez 50 smazany): " << senzory[0]->getHistorie().size() << "\n\n";

    {
    std::cout << "--- Pretizeni operatoru ---\n";
    std::cout << "Porovnani pomoci operatoru == (podle maximalniho limitu):\n";

    SenzorSpotreby lokal1("LOKAL-A", 3200);
    SenzorSpotreby lokal2("LOKAL-B", 1800);
    SenzorSpotreby lokal3("LOKAL-3", 500);

    std::cout << lokal1 << "\nma stejny limit jako\n" << lokal2 << " -> " << (lokal1 == lokal2 ? "ANO" : "NE") << "\n\n";
    std::cout << lokal1 << "\nma stejny limit jako\n" << lokal3 << " -> " << (lokal1 == lokal3 ? "ANO" : "NE") << "\n\n";

    std::cout << "Pridani mereni pomoci operatoru += :\n";
    std::cout << "Stav lokA pred pridanim: " << lokal1 << "\n";
    lokal1+=500;
    std::cout << "Stav lokA po pridani 500: " << lokal1 << "\n\n";
    }

    std::cout << "--- Uklid pameti ---\n";
    for(Senzor* s : senzory){
        delete s;
    }
    senzory.clear();
    std::cout << "Konecny pocet senzoru v pameti: " << Senzor::getCitac();
}
