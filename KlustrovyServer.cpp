#include "KlustrovyServer.h"
#include <iostream>
#include <stdexcept>
#include <string>

KlustrovyServer::KlustrovyServer(std::string name) : ServerNode(name) {}

void KlustrovyServer::diagnostika() {
    std::cout << "[" << getNazev() << "]: Probiha synchronizace klustru." << std::endl;
}

KlustrovyServer KlustrovyServer::operator+(const KlustrovyServer& other) const {
    // Kontrola shodného počtu záznamů ve vektoru zátěže
    if (this->zatezCPU.size() != other.zatezCPU.size()) {
        throw std::invalid_argument("Nelze spojit klustry s ruznym poctem mereni!");
    }
    
    // Vytvoření nového uzlu se sloučeným názvem
    KlustrovyServer vysledek(this->getNazev() + " + " + other.getNazev());
    
    // Aritmetický průměr zátěží na každém indexu
    for (size_t i = 0; i < this->zatezCPU.size(); ++i) {
        double prumer = (this->zatezCPU[i] + other.zatezCPU[i]) / 2.0;
        vysledek.pridejZaznam(prumer);
    }
    
    return vysledek;
}