#include "Vozidlo.h"
#include <iostream>
#include <string>

int Vozidlo::pocetVozidel = 0;

Vozidlo::Vozidlo(std::string kod, double kg) : id(kod), hmotnost(kg){
    pocetVozidel ++;
}

Vozidlo::~Vozidlo(){
    pocetVozidel--;
}

int Vozidlo::getPocetVozidel(){return pocetVozidel;}

std::ostream& operator<<(std::ostream& os, Vozidlo& v){
    v.vypisSpecifikaci();
    return os;
}

