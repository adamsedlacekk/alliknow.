#include "Senzor.h"
#include "TeplotniSenzor.h"
#include <iostream>
#include <string>

TeplotniSenzor::TeplotniSenzor(std::string oznaceni, double cil) : Senzor(oznaceni), cilovaTeplota(cil){}
TeplotniSenzor::~TeplotniSenzor(){}

void TeplotniSenzor::vypisInfo() const{
    Senzor::vypisInfo();
    std::cout << "Cilova teplota: " << cilovaTeplota << "\n";
}

void TeplotniSenzor::analyzujSenzor() const{
    double celkem = 0.0;
    int pocetMereni = 0;
    for(double x : historieMereni){
        if(x > 0){
            celkem += x;
            pocetMereni++;
        }
    }
    double prumer = celkem / pocetMereni;

    std::cout << "Prumerna hodnota standartnich mereni je " << prumer << " C\n\n";
}