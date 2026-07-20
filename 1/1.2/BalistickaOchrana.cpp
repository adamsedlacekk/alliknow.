#include "Vybaveni.h"
#include "BalistickaOchrana.h"
#include <iostream>
#include <string>

BalistickaOchrana :: BalistickaOchrana(std::string kod, double kg, int odolnost) : Vybaveni(kod, kg), tridaOdolnosti(odolnost){}
void BalistickaOchrana::pripravKAkci(){
    std::cout << "Kontrola celistvosti balisticke ochrany " << kodOznaceni << " (trida odolnosti: T" << tridaOdolnosti << ")." << std::endl;
}
