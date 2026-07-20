#pragma once
#include <iostream>
#include <string>

class Vozidlo{
    protected:
    std::string id;
    double hmotnost;
    private:
    static int pocetVozidel;

    public:
    Vozidlo(std::string id, double kg);
    virtual ~Vozidlo();
    static int getPocetVozidel();
    virtual void vypisSpecifikaci() const = 0;
    friend std::ostream& operator<<(std::ostream& os, Vozidlo& v);
};