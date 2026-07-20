#pragma once
#include "Vozidlo.h"
#include <iostream>
#include <string>

class OsobniAuto : public Vozidlo{
    private:
    int pocetMist;

    public:
    OsobniAuto(std::string id, double kg, int mista);
    void vypisSpecifikaci() const override;
};