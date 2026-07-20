#pragma once
#include "Vybaveni.h"
#include <iostream>
#include <string>

class BalistickaOchrana : public Vybaveni{
    private:
    int tridaOdolnosti;
    public:
    BalistickaOchrana(std::string kod, double hmotnost, int odolnost);
    void pripravKAkci() override;
};