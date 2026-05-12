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

// Definice hráèe a jeho statistik
struct Hrac {
    string classa;
    int hp, maxHp, mana, maxMana, utok, gold, level, exp, expPotreba;
};

// Funkce pro zobrazení aktuálního stavu hráèe
void ukazStav(Hrac h) {
    nastavBarvu(7);
    cout << "\n--- STAV [LVL " << h.level << "] | HP: " << h.hp << "/" << h.maxHp
         << " | Mana: " << h.mana << " | Gold: " << h.gold << "g | EXP: " << h.exp << "/" << h.expPotreba << " ---" << endl;
}
