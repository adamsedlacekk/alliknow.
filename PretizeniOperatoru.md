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