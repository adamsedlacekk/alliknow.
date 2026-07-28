Getter
h: std::vector<double>& getHistorie();
cpp: std::vector<double>& Ucet::getHistorie(){
     return historieTransakci;}

Odstraneni
main.cpp: void odstraneniMalychVyberu(Ucet* ucet){
           std::vector<double>& historie = ucet -> getHistorie();
           for(auto it = historie.begin(); it != historie.end();){
            if(*it < 0 && *it > -50){
              it = historie.erase(it);
            }   
            else{
            ++it;
            } 
        }
    }   