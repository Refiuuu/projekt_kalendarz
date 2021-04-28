#pragma once

#include "Wydarzenie.h"
#include "Powtarzanie.h"
#include <string>

using namespace std;

class Fabryka
{
public:

    Wydarzenie StworzWydarzenie();
    
    DataZGodzina dodaj_data();
    DataZGodzina dodaj_godzine();
    DataZGodzina Data_zapisu_od();
    DataZGodzina Data_zapisu_do();
private:

    int rok;
    int miesiac;
    int dzien;
    int godzina;
    int minuta;
    int sekunda;
    string Miesiac;
    string Dzien;
    string Godzina;
    string Minuta;
    string Sekunda;

    bool czy_przestepny(int rok);
    string dodaj_notatke();
    string dodaj_lokalizacje();
    string dodaj_tytul();
    DataZGodzina AktualnaData();
    Powtarzanie Zasada();
    string Jaki_dzien();

    string pobierzString(const char* wiadomosc);
    char pobierzZnak(const char* wiadomosc);
    int pobierzLiczbe(const char* wiadomosc);
};
