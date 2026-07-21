==================================================
          C++ STD::VECTOR CHEATSHEET
==================================================


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



==================================================
1) VYTVOŘENÍ VECTORU
==================================================


Prázdný vector:

vector<int> cisla;


Vector s hodnotami:

vector<int> cisla = {10,20,30};


Vector určité velikosti:

vector<int> cisla(5);

Výsledek:
[0,0,0,0,0]


Vector velikost + hodnota:

vector<int> cisla(5,100);

Výsledek:
[100,100,100,100,100]



==================================================
2) ZÁKLADNÍ FUNKCE
==================================================


size()

Počet prvků:

cisla.size();


empty()

Kontrola, jestli je prázdný:

cisla.empty();


capacity()

Aktuálně rezervovaná paměť:

cisla.capacity();


max_size()

Maximální možný počet prvků:

cisla.max_size();



==================================================
3) PŘÍSTUP K PRVKŮM
==================================================


Index:

vector<int> v = {10,20,30};

cout << v[0];


Bezpečný přístup:

v.at(0);


První prvek:

v.front();


Poslední prvek:

v.back();



==================================================
4) PŘIDÁVÁNÍ PRVKŮ
==================================================


push_back()

Přidání na konec:

v.push_back(50);


Příklad:

vector<int> v;

v.push_back(10);
v.push_back(20);

Výsledek:

10 20



emplace_back()

Vytvoří prvek přímo ve vectoru:

v.emplace_back(30);


U objektů:

vector<Motor> motory;

motory.emplace_back("MK1",500);



==================================================
5) MAZÁNÍ PRVKŮ
==================================================


pop_back()

Smaže poslední prvek:

v.pop_back();



erase()

Smazání podle pozice:


První prvek:

v.erase(v.begin());


Index:

v.erase(v.begin()+2);



Smazání rozsahu:

v.erase(v.begin()+1,
        v.begin()+4);



clear()

Smaže všechny prvky:

v.clear();



==================================================
6) ITERÁTORY
==================================================


Začátek:

v.begin();


Konec:

v.end();



Průchod:

for(auto it = v.begin(); it != v.end(); it++)
{
    cout << *it;
}



==================================================
7) PRŮCHOD VECTORU
==================================================


Klasický for:

for(int i = 0; i < v.size(); i++)
{
    cout << v[i];
}



Range based for:

for(int x : v)
{
    cout << x;
}



Reference:

for(int &x : v)
{
    x++;
}



Pouze čtení:

for(const int &x : v)
{
    cout << x;
}



==================================================
8) VECTOR JAKO PARAMETR FUNKCE
==================================================


ŠPATNĚ:

void funkce(vector<int> v)

Kopíruje celý vector.



SPRÁVNĚ:

void funkce(vector<int>& v)



Pouze čtení:

void funkce(const vector<int>& v)



Příklad:

void vypis(const vector<int>& v)
{
    for(int x : v)
    {
        cout << x;
    }
}



==================================================
9) VECTOR OBJEKTŮ
==================================================


class Motor
{
public:

    string nazev;
    int vykon;

};



Vector:

vector<Motor> motory;



Přidání:

Motor m;

motory.push_back(m);



Nebo:

motory.emplace_back("MK1",500);



Přístup:

motory[0].vykon;



==================================================
10) VECTOR UKAZATELŮ
==================================================


Použití u polymorfismu:


vector<Modul*> moduly;



Přidání:

Motor* m = new Motor();

moduly.push_back(m);



Použití:

for(Modul* m : moduly)
{
    m->vypis();
}



Mazání:

for(Modul* m : moduly)
{
    delete m;
}

moduly.clear();



==================================================
11) ŘAZENÍ VECTORU
==================================================


Nutný:

#include <algorithm>



Vzestupně:

sort(v.begin(), v.end());



Příklad:

5 2 8 1

výsledek:

1 2 5 8



Sestupně:

sort(v.begin(),
     v.end(),
     greater<int>());



==================================================
12) ŘAZENÍ OBJEKTŮ
==================================================


Podle vlastnosti:


sort(motory.begin(),
     motory.end(),

[](Motor a, Motor b)
{
    return a.vykon < b.vykon;
});



==================================================
13) HLEDÁNÍ
==================================================


find()

Najde prvek:


auto vysledek =
find(v.begin(),
     v.end(),
     30);



Kontrola:

if(vysledek != v.end())
{
    cout<<"Nalezeno";
}



==================================================
14) POČET VÝSKYTŮ
==================================================


count()


int pocet =
count(v.begin(),
      v.end(),
      10);



==================================================
15) MINIMUM A MAXIMUM
==================================================


Minimum:

*min_element(v.begin(),
             v.end());



Maximum:

*max_element(v.begin(),
             v.end());



==================================================
16) OTOČENÍ VECTORU
==================================================


reverse():

reverse(v.begin(),
        v.end());



==================================================
17) SPOJENÍ VECTORŮ
==================================================


vector<int> a;
vector<int> b;


a.insert(
a.end(),
b.begin(),
b.end()
);



==================================================
18) KOPIE VECTORU
==================================================


vector<int> a = {1,2,3};


vector<int> b = a;



==================================================
19) REZERVACE PAMĚTI
==================================================


reserve()


v.reserve(100);



Používá se při velkém množství dat.



==================================================
20) NEJDŮLEŽITĚJŠÍ FUNKCE KE ZKOUŠCE
==================================================


push_back()
    přidání prvku


emplace_back()
    vytvoření prvku přímo


pop_back()
    odstranění posledního


erase()
    odstranění podle pozice


clear()
    odstranění všeho


size()
    počet prvků


empty()
    kontrola prázdnosti


front()
    první prvek


back()
    poslední prvek


at()
    bezpečný přístup


begin()
    začátek


end()
    konec


sort()
    řazení


find()
    hledání


count()
    počet výskytů


reverse()
    otočení


min_element()
    minimum


max_element()
    maximum


insert()
    vložení


reserve()
    rezervace paměti



==================================================
TIPY KE ZKOUŠCE
==================================================


1) Vector předávej do funkcí vždy:

const vector<T>&


2) Mazání podle podmínky:

for(auto it = v.begin(); it != v.end();)
{
    if(*it == hodnota)
        it = v.erase(it);
    else
        it++;
}


3) Pro objekty používej:

vector<Objekt>


4) Pro polymorfismus:

vector<Base*> 


5) Nezapomeň:

#include <vector>
#include <algorithm>



==================================================
KONEC CHEATSHEETU
==================================================