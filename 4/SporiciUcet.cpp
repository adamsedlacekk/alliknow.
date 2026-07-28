#include "Ucet.h"
#include "SporiciUcet.h"
#include <iostream>
#include <string>


SporiciUcet::SporiciUcet(std::string accNum, double urok) : Ucet(accNum), urokovaSazba(urok){}
SporiciUcet::~SporiciUcet(){}

void SporiciUcet::vypisInfo() const{
    Ucet::vypisInfo();
    std::cout << "Urok: " << urokovaSazba << " %\n";
}

void SporiciUcet::analyzujUcet() const{
    double celkem = 0.0;
    int pocetTransakci = 0;
    for(double n : historieTransakci){
        if(n > 0){
            celkem += n;
            pocetTransakci++;
        }
    }
    double prumer = celkem / pocetTransakci;

    std::cout << "Analyza (" << cisloUctu << "): Prumerna vyse vkladu je " << prumer << " Kc.\n\n";
}
