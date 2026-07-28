#include "Senzor.h"
#include "SenzorSpotreby.h"
#include <iostream>
#include <string>

SenzorSpotreby::SenzorSpotreby(std::string oznaceni, double max) : Senzor(oznaceni), maximalniLimit(max){}
SenzorSpotreby::~SenzorSpotreby(){}

void SenzorSpotreby::vypisInfo() const{
    Senzor::vypisInfo();
    std::cout << "Maximalni limit: " << maximalniLimit << "\n";
}

void SenzorSpotreby::analyzujSenzor() const{
    int vypadky = 0;
    for(double x : historieMereni){
        if(x < 0){
            vypadky++;
        }
    }
    std::cout << "Pocet zaznamenanych vypadku: " << vypadky << "\n\n";
}

bool SenzorSpotreby::operator==(const SenzorSpotreby& druhy) const{
    return this -> maximalniLimit == druhy.maximalniLimit;
}

SenzorSpotreby& SenzorSpotreby::operator+=(double hodnota){
    this -> pridejMereni(hodnota);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SenzorSpotreby& senzor){
    os << "SenzorSpotreby[" << senzor.oznaceniSenzoru << "], mereni: " << senzor.historieMereni.size();
    return os;
}