#pragma once

#include "Wydarzenie.h"
#include <string>

using namespace std;

class Fabryka
{
public:

    Wydarzenie StworzWydarzenie();

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
    string dodaj_data();
    string dodaj_godzine();
    string Data_zapisu_od();
    string Data_zapisu_do();
    string dodaj_notatke();
    string dodaj_lokalizacje();
    string dodaj_tytul();
    string AktualnaData();
};