#include "ServerNode.h"
#include <iostream>
#include <string>
#include <vector>

class KritickyServer : public ServerNode{
    public:
    explicit KritickyServer(std::string name); //explicit něco navíc idk
    void diagnostika() override; 
};