#include "ServerNode.h"
#include "KritickyServer.h"
#include <iostream>
#include <string>

KritickyServer::KritickyServer(std::string name) : ServerNode(name){}

void KritickyServer::diagnostika(){
    std::cout << getNazev() << ": Spustena kriticka bezpecnostni diagnostika jadra." << std:: endl;
}