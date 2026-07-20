#include"Vozidlo.h"
#include "NakladniAuto.h"
#include <iostream>
#include <string>

NakladniAuto:: NakladniAuto(std::string kod, double kg, double nos) : Vozidlo(kod,kg), nosnost(nos){}

void NakladniAuto::vypisSpecifikaci() const{
    std::cout << "Nakladni auto ID: " << id << " | Hmotnost: " << hmotnost << "t | Nosnost: " << nosnost << "t" << std::endl;
}

NakladniAuto NakladniAuto::operator+(const NakladniAuto& druhe) const{
    std::string noveID = id  + " + " + druhe.id;
    double novaHmotnost = hmotnost + druhe.hmotnost;
    double novaNosnost = nosnost + druhe.nosnost;

    return NakladniAuto(noveID, novaHmotnost, novaNosnost);  
}
