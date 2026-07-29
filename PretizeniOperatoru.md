==
// Porovnání
h: bool operator==(const MojeTrida& druhy) const;
cpp: bool MojeTrida::operator==(const MojeTrida& druhy) const {
    return this->hodnota == druhy.hodnota;
}


+=
// Složené přiřazení
h: MojeTrida& operator+=(const MojeTrida& druhy);
cpp: MojeTrida& MojeTrida::operator+=(const MojeTrida& druhy) {
    this->hodnota += druhy.hodnota;
    return *this;}


+
// Sčítání, Lze definovat i jako non-member (friend) pro symetrii, zde jako metoda třídy.
h: MojeTrida operator+(const MojeTrida& druhy) const;
cpp: MojeTrida MojeTrida::operator+(const MojeTrida& druhy) const {
    MojeTrida vysledek = *this; 
    vysledek += druhy;          
    return vysledek;}


<<
// Zápis do proudu, Musí být friend, protože levým operandem je std::ostream, ne naše třída.
h: friend std::ostream& operator<<(std::ostream& os, const MojeTrida& obj);
cpp: std::ostream& operator<<(std::ostream& os, const MojeTrida& obj) {
    os << "Hodnota: " << obj.hodnota;
    return os; // Vrací stream pro umožnění řetězení (cout << a << b)}


++ (Prefixový: ++obj)
// Zvyšuje hodnotu a vrací referenci na aktuální (již zvětšený) objekt.
h: MojeTrida& operator++();
cpp: MojeTrida& MojeTrida::operator++() {
    ++this->hodnota;
    return *this;}


++ (Postfixový: obj++)
// Bere fiktivní parametr int (pro odlišení) a vrací KOPII původního stavu.
h: MojeTrida operator++(int);
cpp: MojeTrida MojeTrida::operator++(int) {
     MojeTrida kopie = *this;
     ++this->hodnota;         
     return kopie;}


()
// Může brát libovolný počet parametrů, zde ukázka s jedním parametrem.
h: int operator()(int nasobitel) const;
cpp: int MojeTrida::operator()(int nasobitel) const {
    return this->hodnota * nasobitel;}


main:
#include <iostream>
#include "MojeTrida.h"

int main() {
    // Vytvoření objektů
    MojeTrida a(5);
    MojeTrida b(10);
    MojeTrida c(5);

    std::cout << "--- 1. Operator << (Zapis do proudu) ---" << std::endl;
    std::cout << "Objekt a: " << a << std::endl; // Vypíše: Hodnota: 5
    std::cout << "Objekt b: " << b << std::endl; // Vypíše: Hodnota: 10
    std::cout << std::endl;

    std::cout << "--- 2. Operator == (Porovnani) ---" << std::endl;
    if (a == c) {
        std::cout << "a se rovna c" << std::endl;
    }
    if (!(a == b)) {
        std::cout << "a se nerovna b" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- 3. Operator + (Scitani) ---" << std::endl;
    MojeTrida d = a + b; // Sečte 5 + 10
    std::cout << "Vysledek a + b (objekt d): " << d << std::endl; // Vypíše: Hodnota: 15
    std::cout << std::endl;

    std::cout << "--- 4. Operator += (Slozene prirazeni) ---" << std::endl;
    a += b; // a = a + b (tedy 5 + 10)
    std::cout << "Objekt a po operaci a += b: " << a << std::endl; // Vypíše: Hodnota: 15
    std::cout << std::endl;

    std::cout << "--- 5. Operator ++ (Prefixovy: ++obj) ---" << std::endl;
    MojeTrida p1(10);
    // ++p1 nejdříve zvětší hodnotu na 11 a pak tuto novou hodnotu vrátí
    std::cout << "Puvodni p1: " << p1 << std::endl;
    std::cout << "Vypis ++p1: " << ++p1 << std::endl; // Vypíše 11
    std::cout << "Stav po  : " << p1 << std::endl; // Vypíše 11
    std::cout << std::endl;

    std::cout << "--- 6. Operator ++ (Postfixovy: obj++) ---" << std::endl;
    MojeTrida p2(10);
    // p2++ nejdříve vrátí původní hodnotu (10), a AŽ PAK se objekt zvětší na 11
    std::cout << "Puvodni p2: " << p2 << std::endl;
    std::cout << "Vypis p2++: " << p2++ << std::endl; // Vypíše 10 !
    std::cout << "Stav po  : " << p2 << std::endl; // Vypíše 11
    std::cout << std::endl;

    std::cout << "--- 7. Operator () (Funktor) ---" << std::endl;
    MojeTrida f(4);
    // Zavolá se operator() s parametrem 5. V našem případě jsme ho 
    // naprogramovali tak, že vynásobí vnitřní hodnotu (4) parametrem (5).
    int vysledekVolani = f(5); 
    std::cout << "Volani f(5) vraci: " << vysledekVolani << std::endl; // Vypíše 20

    return 0;
}
