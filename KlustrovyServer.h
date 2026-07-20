#pragma once
#include "ServerNode.h"
#include <iostream>
#include <vector>

class KlustrovyServer : public ServerNode{
    public:
    KlustrovyServer(std:: string nazev);
    void diagnostika() override;
    
    //přetížení operátoru
    KlustrovyServer operator+(const KlustrovyServer& other) const;

};