#pragma once
#include <iostream>
#include <string>
#include <vector>

class Senzor{
    protected:
    std::string oznaceniSenzoru;
    std::vector<double> historieMereni;
    static int citac;

    public:
    static int getCitac();

    Senzor(std::string oznaceni);
    virtual ~Senzor();

    void pridejMereni(double hodnota);
    void pridejMereni(const std::vector<double>& hodnoty);

    std::vector<double>& getHistorie();

    virtual void analyzujSenzor() const =0;

    virtual void vypisInfo() const;
};