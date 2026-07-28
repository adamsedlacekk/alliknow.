#pragma once
#include "Senzor.h"
#include <iostream>
#include <string>

class TeplotniSenzor : public Senzor{
    protected:
    double cilovaTeplota;

    public:
    TeplotniSenzor(std::string oznaceni, double cil);
    ~TeplotniSenzor() override;

    void vypisInfo() const override;

    void analyzujSenzor() const override;
};