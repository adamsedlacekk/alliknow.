#pragma once
#include "Vozidlo.h"
#include <iostream>
#include <string>

class NakladniAuto : public Vozidlo{
    private:
    double nosnost;
    public:
    NakladniAuto(std::string kod, double kg, double nos);
    void vypisSpecifikaci() const override;
    NakladniAuto operator+(const NakladniAuto& druhe) const;
};