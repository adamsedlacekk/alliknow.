#include "Vozidlo.h"
#include "OsobniAuto.h"
#include <iostream>
#include <string>

OsobniAuto::OsobniAuto(std::string id, double kg, int mista) : Vozidlo(id,kg), pocetMist(mista){}

void OsobniAuto::vypisSpecifikaci() const{
    std::cout << "Osobni auto ID: " << id << " | Hmotnost: " << hmotnost << "t | Mist: " << pocetMist << std::endl;
}
