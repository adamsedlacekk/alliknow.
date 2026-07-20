#pragma once
#include <iostream>
#include <string>
#include <vector>

class ServerNode{
    private:
    std::string nazev;
    static int pocetServeru;

    protected:
    std::vector<double> zatezCPU;

    public:
    ServerNode(std::string name);
    virtual ~ServerNode();

    static int getPocetServeru();
    
    void pridejZaznam(double zatez);

    //Gater vrací referenci pro možnost úprav externími funkcemi
    std::vector<double>& getZatezCPU();
    std::string getNazev() const;

    virtual void diagnostika() = 0;

    friend std::ostream& operator<<(std::ostream& os, const ServerNode& sn);
};  