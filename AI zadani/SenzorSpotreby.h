#pragma once
#include "Senzor.h"
#include <iostream>
#include <string>

class SenzorSpotreby : public Senzor{
    protected:
    double maximalniLimit;
    
    public:
    SenzorSpotreby(std::string oznaceni, double max);
    ~SenzorSpotreby() override;

    void vypisInfo() const override;

    void analyzujSenzor() const override;

    bool operator==(const SenzorSpotreby& druhy) const;
    
    SenzorSpotreby& operator+=(double hodnota);

    friend std::ostream& operator<<(std::ostream& os, const SenzorSpotreby& senzor);
};