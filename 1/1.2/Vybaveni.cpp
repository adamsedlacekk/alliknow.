#include "Vybaveni.h"
#include <iostream>
#include <string>

int Vybaveni::pocetKusu = 0;
Vybaveni::Vybaveni(std::string kod, double kg) : kodOznaceni(kod), hmotnost(kg){
    pocetKusu++;
}
Vybaveni::~Vybaveni(){
    pocetKusu--;
}
int Vybaveni::getPocetKusu(){return pocetKusu;}
void Vybaveni::pripravKAkci(){}
std::ostream& operator << (std::ostream& os, const Vybaveni& v){
    os << v.kodOznaceni << " (hmotnost: " << v.hmotnost << " kg)." << std::endl;
    return os;
}