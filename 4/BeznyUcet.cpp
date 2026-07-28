#include "Ucet.h"
#include "BeznyUcet.h"
#include <iostream>
#include <string>

BeznyUcet::BeznyUcet(std::string accNum, double fee) : Ucet(accNum), poplatek(fee){}
BeznyUcet::~BeznyUcet(){}

void BeznyUcet::vypisInfo() const{
    Ucet::vypisInfo();
    std::cout << "Poplatek : " << poplatek << " Kc\n";
}

void BeznyUcet::analyzujUcet() const{
    int pocetVyberu = 0;
    for(double n : historieTransakci){
        if(n < 0){
            pocetVyberu++;
        }
    }
    std::cout << "Analyza (" << cisloUctu << "): Provedeno " << pocetVyberu << " vyberu.\n\n";
}

bool BeznyUcet::operator==(const BeznyUcet& druhy) const{
    return this -> poplatek == druhy.poplatek;
}

BeznyUcet& BeznyUcet::operator +=(double hodnota){
    this ->pridejTransakci(hodnota);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const BeznyUcet& ucet){
    os << "BeznyUcet[" << ucet.cisloUctu << "], transakci: " << ucet.historieTransakci.size();
    return os;
}