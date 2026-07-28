#pragma once
#include "Ucet.h"
#include <iostream>
#include <string>

class BeznyUcet : public Ucet{
    protected:
    double poplatek;

    public:
    BeznyUcet(std::string accNum, double fee);
    ~BeznyUcet() override;

    void vypisInfo() const override;
    void analyzujUcet() const override;

    //Operátory
    bool operator==(const BeznyUcet& druhy) const; //==
    BeznyUcet& operator +=(double hodnota); //+=
    friend std::ostream& operator<<(std::ostream& os, const BeznyUcet& ucet); //<<
};