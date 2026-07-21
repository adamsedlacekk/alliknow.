# Závěrečná zkouška z C++: Bankovní účty
**Časová dotace:** 120 minut
**Pravidla:** Můžete využívat veškeré zdrojové kódy a materiály na počítači.

Vaším úkolem je vytvořit aplikaci pro jednoduchou evidenci bankovních účtů a jejich transakcí. Úloha klade důraz na **polymorfismus, přetěžování operátorů a základní algoritmizaci**.

> **Důležité upozornění:** 
> Kód musíte **rozdělit do více souborů** (hlavičkové `.h` a implementační `.cpp` soubory pro každou třídu + hlavní `main.cpp`).
> Pokud program nelze zkompilovat (obsahuje syntaktické chyby), je automaticky strženo **20 bodů**. Pokud program během běhu spadne, strhává se **10 bodů**.

## Zadání úkolu

### 1. Bázová třída `Ucet`
Vytvořte bázovou abstraktní třídu `Ucet`, která bude obsahovat:
- Chráněné (protected) atributy pro `cisloUctu` (text) a `historieTransakci` v korunách (`std::vector<double>`). Kladná čísla jsou vklady, záporná čísla jsou výběry.
- **Statickou proměnnou** (čítač), která udržuje přehled o tom, kolik objektů této třídy aktuálně existuje v paměti (zvýší se v konstruktoru, sníží v destruktoru). Přidejte veřejnou statickou metodu pro její přečtení.
- Veřejnou metodu `void pridejTransakci(double hodnota)` a její přetíženou verzi pro vektor `void pridejTransakce(const std::vector<double>& hodnoty)`, které zařadí transakce na konec historie.
- Metodu, která vrátí referenci na historii transakcí (getter).
- Virtuální destruktor a **čistě virtuální** metodu `analyzujUcet() const`.
- Virtuální metodu `vypisInfo() const`, která vypíše číslo účtu a kolik transakcí je zaznamenáno v historii.

### 2. Odvozené třídy
Vytvořte dvě odvozené třídy (každou ve vlastních `.h` a `.cpp` souborech):
- **`SporiciUcet`**: Přidává atribut `urokovaSazba` (v procentech, double).
  - V metodě `vypisInfo()` navíc vypíše výši úroku.
  - V metodě `analyzujUcet()` spočítá a vypíše **průměrnou hodnotu vkladů** (vklad je každá transakce větší než 0).
- **`BeznyUcet`**: Přidává atribut `poplatek` (za vedení účtu, double).
  - V metodě `vypisInfo()` navíc vypíše výši tohoto poplatku.
  - V metodě `analyzujUcet()` spočítá a vypíše celkový **počet provedených výběrů** (výběr je každá transakce menší než 0).

### 3. Přetěžování operátorů (u třídy `BeznyUcet`)
- Operátor **`==`** : Porovná dva běžné účty a vrátí `true`, pokud mají nastavený úplně stejný `poplatek`.
- Operátor **`+=`** : Přijme desetinné číslo (typu `double`) a přidá ho jako novou transakci na konec historie daného účtu. (Například zavoláním `ucet += 500.0;` se přidá kladný vklad 500).
- Operátor **`<<`** : Umožní výpis běžného účtu např. ve formátu: `BeznyUcet[CISLO], transakci: X`.

> **💡 TIP k operátorům:**  
> Pro otestování operátoru porovnání `==` a výpisu `<<` doporučujeme nevytvářet účty pomocí `new`, ale vytvořit si je v `main` jako normální lokální proměnné (na zásobníku). Nebudete tak muset u porovnávání složitě používat hvězdičky (dereference) a operátory se vám budou volat snadno (např. `ucet1 == ucet2`).

### 4. Algoritmizace (`main.cpp`)
V hlavní funkci `main` proveďte následující ukázku:
1. Vypište počáteční počet aktivních účtů (měl by být 0).
2. Vytvořte `std::vector` ukazatelů na `Ucet`. Do vektoru vložte (přes operátor `new`) alespoň 2 běžné účty a 1 spořicí účet. Každému účtu přidejte nějaké transakce.
3. Projděte tento vektor běžným cyklem a u každého účtu zavolejte `vypisInfo()` a `analyzujUcet()` (ukázka polymorfismu).
4. **Algoritmus 1 (Nejdelší řada vkladů):** Napište funkci, která dostane účet a projde jeho transakce. Spočítá, kolik kladných transakcí proběhlo bezprostředně za sebou (bez toho, aby mezi nimi byl nějaký výběr). Zjistěte a vypište délku vůbec nejdelší takové řady u jednoho z účtů.
5. **Algoritmus 2 (Odstranění malých výběrů):** Napište funkci, která projde účet a vymaže z jeho historie všechny drobné výběry. Drobný výběr je každé číslo, které je záporné a zároveň větší než -50 (tj. je v rozmezí od -49.99 do -0.01). (Například výběry jako -20 nebo -45 budou smazány, ale -100 nebo vklady jako 50 v historii zůstanou).
6. Otestujte přetížení operátorů (viz TIP výše).
7. Nezapomeňte uvolnit veškerou paměť, kterou jste pomocí `new` alokovali, a na konci vypište přes statickou metodu stav čítače, aby bylo vidět, že v paměti nic nezůstalo.

---

## Bodové ohodnocení (Max 100 bodů)

| Úloha | Maximum bodů |
|---|:---:|
| **Základní OOP a rozdělení souborů** (Třídy `Ucet`, statický čítač) | 15 b. |
| **Dědičnost a polymorfismus** (`BeznyUcet`, `SporiciUcet`, override metod) | 15 b. |
| **Přetížení operátorů** (`==`, `+=` a `<<` pro výpis) | 15 b. |
| **Algoritmus 1:** Počítání posloupnosti vkladů | 20 b. |
| **Algoritmus 2:** Podmíněné smazání prvků z vektoru | 20 b. |
| **Polymorfní průchod vektorem (volání v main)** | 10 b. |
| **Správa paměti** (uvolnění `delete`, prokázáno statickým čítačem na konci) | 5 b. |

---

## Očekávaný výstup programu

*(Čísla a texty si můžete zvolit libovolně, výpis slouží jen pro kontrolu, že program dělá to, co má.)*

```text
Pocatecni aktivni ucty: 0

Aktivni ucty po alokaci: 3

--- Pocatecni Polymorfismus a Analyza ---
Ucet: CZ-1111 | Pocet transakci: 8 | Typ: Bezny | Poplatek: 50 Kc
Analyza (CZ-1111): Provedeno 3 vyberu.

Ucet: CZ-2222 | Pocet transakci: 5 | Typ: Bezny | Poplatek: 0 Kc
Analyza (CZ-2222): Provedeno 3 vyberu.

Ucet: CZ-3333 | Pocet transakci: 4 | Typ: Sporici | Urok: 4.5 %
Analyza (CZ-3333): Prumerna vyssi vkladu je 3333.33 Kc.

--- Algoritmus 1: Nejdelsi rada vkladu ---
Ucet CZ-1111 ma nejdelsi radu vkladu o delce: 3 transakci.

--- Algoritmus 2: Odstraneni malych vyberu ---
Data u1 pred odstranenim (pocet): 8
Data u1 po odstraneni (vybery mensi nez 50 Kc smazany): 6

--- Pretizeni operatoru ---
Porovnani pomoci operatoru == (podle vyse poplatku):
BeznyUcet[LOKAL-A], transakci: 1 
 ma stejny poplatek jako 
BeznyUcet[LOKAL-B], transakci: 2 ? -> ANO

BeznyUcet[LOKAL-A], transakci: 1 
 ma stejny poplatek jako 
BeznyUcet[LOKAL-C], transakci: 0 ? -> NE

Pridani transakce pomoci operatoru += :
Stav lokA pred pridanim: BeznyUcet[LOKAL-A], transakci: 1
Stav lokA po pridani 500 Kc: BeznyUcet[LOKAL-A], transakci: 2

--- Uklid pameti ---
Konecny pocet uctu v pameti: 0
```
