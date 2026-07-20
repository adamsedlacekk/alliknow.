#pragma once
#include "Vybaveni.h"
#include <iostream>
#include <string>

class PalnaZbran: public Vybaveni{
    protected:
    int kadence;
    public:
    PalnaZbran(std::string kod, double kg, int kad);
    void pripravKAkci() override;
    PalnaZbran operator+(const PalnaZbran& druha) const;
};