Getter
h: std::vector<double>& getHistorie();
cpp: std::vector<double>& Ucet::getHistorie(){
     return historieTransakci;}

Odstraneni
main.cpp: 
void odstraneniMalychVyberu(Ucet* ucet){
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

1)	std::vector<Ucet*> ucty;
2)	ucty.push_back(new BeznyUcet("CZ-1111", 50));
3)	ucty[0] -> pridejTransakce({1000, 500, -20, 200, 300, 100, -45, -1003});
4)	for(Ucet* u : ucty){
u -> vypisInfo();
u -> analyzujUcet();}

5) BeznyUcet lokal1("LOKAL-A", 50);
6) std::cout << lokal1 << "\nma stejny poplatek jako\n" << lokal2 << " -> " << (lokal1 == lokal2 ? "ANO" : "NE") << "\n\n";
7) lokal1+=500;
8) for(Ucet* u : ucty){
        delete u;
    }
    ucty.clear();
