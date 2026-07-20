#include "Vozidlo.h"
#include "NakladniAuto.h"
#include "OsobniAuto.h"
#include <iostream>
#include <string>

int main(){
    OsobniAuto* oa01 = new OsobniAuto("OA-01", 1.8, 5);
    OsobniAuto* oa02 = new OsobniAuto("OA-02", 2.2, 7);
    NakladniAuto* tatra = new NakladniAuto("NA-Tatra", 12, 15);
    NakladniAuto* scania = new NakladniAuto("NA-Scania", 14, 18);

    Vozidlo* depo[4] = {oa01, tatra, oa02, scania};

    std:: cout << "--- VSTUP VOZIDEL DO DEPA ---\nAktivnich vozidel v evidenci: " << Vozidlo::getPocetVozidel() << std::endl;
    std:: cout << "\n--- SEZNAM VOZIDEL V DEPU (Polymorfni vypis) ---" << std::endl;
    for (int i = 0; i < 4; i++){
        depo[i] ->vypisSpecifikaci();
    }

    {
    NakladniAuto komplet = *tatra + *scania;

    std::cout << "TEST OPERATORU + (Spojeni soupravy) ---\nVytvarim soupravu z Tatra a Scania..." <<std::endl;
    std::cout << "Spojena souprava ID: Souprava " << komplet << std:: endl;
    }

    std::cout << "\n--- CISTENI DEPA ---\nUvolnuji pamet..." << std:: endl;
    delete oa01;
    delete tatra;
    delete oa02;
    delete scania;
    std::cout << "Aktivnich vozidel v evidenci: " << Vozidlo::getPocetVozidel() << std::endl;

    return 0;
}