#include <iostream>
#include "Vybaveni.h"
#include "PalnaZbran.h"
#include "BalistickaOchrana.h"

int main(){
    std::cout << "Pocatecni pocet kusu vybaveni: " << Vybaveni::getPocetKusu() << "\n" << std::endl;
    std::cout << "--- Vytvoreni vojenskeho vybaveni ---" << std::endl;

    PalnaZbran* m4a1 = new PalnaZbran("M4A1", 3.5, 800);
    PalnaZbran* m203 = new PalnaZbran("M203", 1.5, 100);
    BalistickaOchrana* vesta = new BalistickaOchrana("Vesta-NIJ4", 2.0, 4);

    std::cout << "Aktualni pocet kusu v evidenci: " << Vybaveni::getPocetKusu() << "\n" <<std:: endl;
    std::cout << "--- Test polymorfismu ---" << std:: endl;

    Vybaveni* pole[3] = {m4a1, m203, vesta};

    for(int i=0; i < 3; i++){
        pole[i]->pripravKAkci();
    }

    std::cout <<std::endl;
    std::cout << "--- Test pretizeni operatoru ---" <<std::endl;

    {
    PalnaZbran komplet = *m4a1 + *m203;

    std::cout << "Slouceny zbranovy system: " << komplet << std::endl;

    komplet.pripravKAkci();
    }
    std::cout << std::endl;
    std::cout << "--- Uklid pameti ---" << std::endl;

    delete m4a1;
    delete m203;
    delete vesta;

    std::cout << "Konecny pocet kusu v evidenci: " << Vybaveni::getPocetKusu() << std::endl;

    return 0;
}