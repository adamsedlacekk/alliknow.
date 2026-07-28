#pragma once
#include <iostream>
#include <string>
#include <vector>

class Ucet{
    protected:
    std::string cisloUctu;
    std::vector<double> historieTransakci;

    public:
    static int citac;
    static int getCitac();

    Ucet(std::string accNum);
    virtual ~Ucet();

    void pridejTransakci(double hodnota);
    void pridejTransakce(const std::vector<double>& hodnoty);

    std::vector<double>& getHistorie();

    virtual void vypisInfo() const;

    virtual void analyzujUcet() const =0;
};