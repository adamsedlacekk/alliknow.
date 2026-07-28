#include "Ucet.h"
#include <iostream>
#include <string>
#include <vector>

int Ucet::citac = 0;

int Ucet::getCitac(){
    return citac;
}

Ucet::Ucet(std::string accNum) : cisloUctu(accNum){
    citac++;
}

Ucet::~Ucet(){
    citac--;
}

void Ucet::pridejTransakci(double hodnota){
    historieTransakci.push_back(hodnota);
}

void Ucet::pridejTransakce(const std::vector<double>& hodnoty){
    for(double n : hodnoty){
        historieTransakci.push_back(n);
    }
}

std::vector<double>& Ucet::getHistorie(){
    return historieTransakci;
}

void Ucet::vypisInfo() const{
    std::cout << "Ucet " << cisloUctu << " | pocet transakci: " << historieTransakci.size() << " | ";
}