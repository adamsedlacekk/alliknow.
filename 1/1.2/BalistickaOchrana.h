#pragma once
#include "Vybaveni.h"
#include <iostream>
#include <string>

class BalistickaOchrana : public Vybaveni{
    protected:
    int tridaOdolnosti;
    public:
    BalistickaOchrana(std::string kod, double kg, int odolnost);
    void pripravKAkci() override;
};