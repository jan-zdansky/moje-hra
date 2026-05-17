#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>

using namespace std;

// Pomocná funkce pro barvy v konzoli (Windows)
void nastavBarvu(int barva) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), barva);
}

// Definice monster
struct Monstrum {
    string jmeno;
    int zivoty;
    int utok;
    string hlaska;
};

// Definice hrace a jeho statistik
struct Hrac {
    string classa;
    int hp, maxHp, mana, maxMana, utok, gold, level, exp, expPotreba;
};

// Funkce pro zobrazeni aktualniho stavu hrace
void ukazStav(Hrac h) {
    nastavBarvu(7);
    cout << "\n--- STAV [LVL " << h.level << "] | HP: " << h.hp << "/" << h.maxHp
         << " | Mana: " << h.mana << " | Gold: " << h.gold << "g | EXP: " << h.exp << "/" << h.expPotreba << " ---" << endl;
}

// Funkce pro navstevu vesnice a nakup vybaveni
void vesnice(Hrac &h) {
    nastavBarvu(7);
    cout << "\n>>> VSTOUPIL JSI DO VESNICE <<<" << endl;

    int volba = 0;
    while (volba != 4) {
        nastavBarvu(7);
        cout << "\nAktualni zustatek: " << h.gold << " gold." << endl;
        cout << "Obchodnik nabizi:\n1) Vyleceni (5 gold)\n2) Trenink HP +10 (15 gold)\n3) Ostreni zbrane +3 ATK (20 gold)\n4) Pokracovat v ceste\nVolba: ";
        cin >> volba;

        if (volba == 1) {
            if (h.gold >= 5) {
                h.hp = h.maxHp; h.gold -= 5;
                nastavBarvu(10); cout << "Byl jsi vylecen! Zbyva ti: " << h.gold << " gold." << endl;
            } else { nastavBarvu(4); cout << "Malo penez!" << endl; }
        } else if (volba == 2) {
            if (h.gold >= 15) {
                h.maxHp += 10; h.hp += 10; h.gold -= 15;
                nastavBarvu(10); cout << "Zvysena vydrz! Zbyva ti: " << h.gold << " gold." << endl;
            } else { nastavBarvu(4); cout << "Malo penez!" << endl; }
        } else if (volba == 3) {
            if (h.gold >= 20) {
                h.utok += 3; h.gold -= 20;
                nastavBarvu(10); cout << "Zbran je ostrejsi! Zbyva ti: " << h.gold << " gold." << endl;
            } else { nastavBarvu(4); cout << "Malo penez!" << endl; }
        }
    }
}
