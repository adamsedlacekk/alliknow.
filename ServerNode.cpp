#include "ServerNode.h"
#include <iostream>
#include <string>

int ServerNode::pocetServeru = 0;

ServerNode::ServerNode(std:: string name) : nazev(name){
    pocetServeru++;
}

ServerNode::~ServerNode(){
    pocetServeru--;
}

int ServerNode::getPocetServeru(){
    return pocetServeru;
}

void ServerNode::pridejZaznam(double zatez){
    zatezCPU.push_back(zatez);  //Vloží hodnotu na konec vektoru zatezCPU
}

std::vector<double>& ServerNode:: getZatezCPU(){
    return zatezCPU;
}

std::string ServerNode::getNazev() const{
    return nazev;
}

std::ostream& operator<<(std::ostream& os, const ServerNode& sn){
    os << sn.nazev << "Historie: ";
    
    //Projít celý vektor a vypsat jednotlivé hodnoty zátěže
    for(double z : sn.zatezCPU){
        os << z << "%, ";
    }

    return os;
}
