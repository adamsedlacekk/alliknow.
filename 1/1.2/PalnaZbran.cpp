#include "Vybaveni.h"
#include "PalnaZbran.h"
#include <iostream>
#include <string>

PalnaZbran :: PalnaZbran(std::string kod, double kg, int kad) : Vybaveni(kod, kg), kadence(kad){}
void PalnaZbran :: pripravKAkci(){
    std::cout << "Nabijeni zbrane " << kodOznaceni << ", nastaveni kadence na " << kadence << " ran/min." << std::endl;
}
PalnaZbran PalnaZbran::operator+(const PalnaZbran& druha) const{
    std::string novyKod = kodOznaceni + " a " + druha.kodOznaceni;
    double novaHmotnost = hmotnost + druha.hmotnost;
    int novaKadence = kadence + druha.kadence;
}
