#include "Vybaveni.h"
#include "PalnaZbran.h"
#include "BalistickaOchrana.h"
#include <iostream>

int main(){
    std::cout << "Aktualni pocet kusu v evidenci: " << Vybaveni::getPocetKusu() << "\n" << std::endl;

    PalnaZbran* m4a1 = new PalnaZbran("M4A1", 3.5, 800);
    PalnaZbran* m203 = new PalnaZbran("M203", 1.5, 100);
    BalistickaOchrana* vesta = new BalistickaOchrana("Vesta-NIJ4", 2.0, 4);

    std::cout << "--- Vytvoreni vojenskeho vybaveni ---\nAkutalni pocet kusu v evidenci: " << Vybaveni::getPocetKusu() << "\n" << std:: endl;
    std::cout << "-- Test polymorfismu ---" << std::endl;

    Vybaveni* pole[3] = {m4a1, m203, vesta};

    for(int i = 0; i < 3; i++){
        pole[i] -> pripravKAkci();
    }

    std::cout << "\n--- Test pretizeni operatoru ---" << std::endl;
    {
    PalnaZbran komplet = *m4a1 + *m203;

    std::cout << "Sloučený zbraňový systém: " << komplet << std::endl;
    komplet.pripravKAkci();
    }

    delete m4a1;
    delete m203;
    delete vesta;
    
    std::cout << "\n---Uklid pameti ---\nKonecny pocet kusu v evidenci: " << Vybaveni::getPocetKusu << std:: endl;

    return 0;
}