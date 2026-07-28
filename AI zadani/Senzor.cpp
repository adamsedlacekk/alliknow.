#include "Senzor.h"
#include <iostream>

int Senzor::citac = 0;

int Senzor::getCitac(){
    return citac;
}

Senzor::Senzor(std::string oznaceni) : oznaceniSenzoru(oznaceni){
    citac++;
}

Senzor::~Senzor(){
    citac--;
}

void Senzor::pridejMereni(double hodnota){
    historieMereni.push_back(hodnota);
}

void Senzor::pridejMereni(const std::vector<double>& hodnoty){
    for(double x : hodnoty){
        historieMereni.push_back(x);
    }
}

std::vector<double>& Senzor::getHistorie(){
    return historieMereni;
}

void Senzor::vypisInfo() const{
    std::cout << "Senzor: " << oznaceniSenzoru << " | Mereni: " << historieMereni.size() << " | ";
}