Falling Sand Simulation (SFML 3)
Tento projekt je implementací klasické „Falling Sand“ hry (pískoviště) v jazyce C++. Projekt využívá knihovnu SFML 3 pro vykreslování a zaměřuje se na efektivní simulaci fyziky částic v reálném čase pomocí objektově orientovaného programování (OOP).

🎮 O hře
Hra funguje na principu celulárních automatů, kde je svět reprezentován mřížkou. Každá buňka v mřížce obsahuje určitý typ materiálu, který se chová podle definovaných fyzikálních pravidel (např. písek padá dolů, voda se rozlévá, oheň hoří a vytváří kouř).

🛠 Technické detaily
Jazyk: C++
Knihovna: SFML 3 (vykreslování oken, vstupů a textur)
Struktura: Projekt je rozdělen do modulů (Game pro řízení hry, Sandbox pro fyziku a logiku).
Optimalizace: Simulace využívá 1D vektor pro reprezentaci 2D mřížky a přímý zápis do pixelového pole std::vector<std::uint8_t>, což zajišťuje vysoký výkon i při větším množství částic.

⌨️ Ovládání
Klávesa / Akce                  Funkce
Levé tlačítko myši  Kreslení vybraného materiálu
F5                  Resetování (vyčištění) celé mřížky
1 - 5               Přepínání mezi materiály
Šipky (Nahoru/Dolů) Změna velikosti štětce
Kolečko myši        Jemná změna velikosti štětce

Materiály
Písek – Padá dolů, hromadí se.
Kámen – Pevný materiál, nepadá.
Dřevo – Hořlavý pevný materiál.
Oheň – Šíří se po dřevě, postupně se mění na kouř.
Voda – Rozlévá se, při kontaktu s ohněm vytváří páru.

🧩 Použité technologie a vnitřní fungování kódu

Projekt je postaven tak, aby byl co nejrychlejší a kód zůstal přehledný. Pro běh logiky a vykreslování byly použity následující klíčové prvky a knihovny:

Standardní C++ knihovny
* **`<vector>`**: Základní stavební kámen projektu. Místo pomalých 2D polí hra používá rychlý jednorozměrný `std::vector`, který simuluje 2D mřížku pomocí vzorce `index = y * width + x`.
* **`<algorithm>`**: Využito pro funkci `std::fill()`, která umožňuje bleskové vyčištění celé mřížky (F5 reset) bez nutnosti používat zdlouhavé for-cykly.
* **`<cstdlib>`**: Využití funkce `rand()` pro generování náhodných čísel. Fyzika díky tomu působí přirozeně (plyny kličkují, oheň se šíří nepředvídatelně).
* **`<cstdint>`**: Poskytuje přesný datový typ `std::uint8_t` (0-255), který je nutný pro ukládání RGBA hodnot jednotlivých pixelů na obrazovce.

### SFML 3 (Simple and Fast Multimedia Library)
Projekt je napsán přímo pro moderní verzi **SFML 3**, což přineslo několik specifik:
* **Moderní Event System**: Klávesnice a myš jsou zpracovávány pomocí `std::optional` a metod jako `event->getIf<sf::Event::KeyPressed>()`. Je to modernější a bezpečnější způsob zachytávání událostí než ve starších verzích.
* **Přímý zápis do Textury**: Hra nevykresluje každý čtvereček písku jako samostatný objekt (což by zabilo procesor). Místo toho upravuje syrová data v paměti (`pixels.data()`) a celou obrazovku aktualizuje naráz jedním zavoláním `texture.update()`.
* **Sprite a UI**: Hra pracuje s vrstvami – hlavní `sf::Sprite` slouží jako zvětšené herní plátno (škálované z 480x270 na 1080p), zatímco druhý Sprite (`uiSprite`) je vykreslen staticky přes něj a slouží jako uživatelské rozhraní.

🚀 Jak spustit
Ujistěte se, že máte nainstalované SFML 3 (přes MSYS2 UCRT64: pacman -S mingw-w64-ucrt-x86_64-sfml).
Kompilujte projekt pomocí překladače g++.
Ujistěte se, že soubor guide.png (návod) je ve stejné složce jako výsledný Sandbox.exe.Spusťte Sandbox.exe.

✍️ Autor
Projekt vytvořen jako studijní práce zaměřená na C++ a osvojení klíčových vlastností v projektové sféře.