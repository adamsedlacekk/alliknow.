#pragma once
#include "Ucet.h"
#include <iostream>
#include <string>

class SporiciUcet : public Ucet{
    protected:
    double urokovaSazba;

    public:
    SporiciUcet(std::string accNum, double urok);
    ~SporiciUcet() override;

    void vypisInfo() const override;
    void analyzujUcet() const override;
};