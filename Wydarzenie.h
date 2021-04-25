#pragma once
#include "Powtarzanie.h"
#include <string>

using namespace std;

class Wydarzenie {
public:

    string data_start;
    string data_end;
    string tytul;
    string notatka;
    string lokalizacja;
    string sequence;
    string created;
    Powtarzanie powtarzanie;

    string str() {
        return "Wydarzenie POCZATEK (" 
                      "data_start: " +  data_start + "\n"
                   +    "data_end: " +    data_end + "\n"
                   +       "tytul: " +       tytul + "\n"
                   +     "notatka: " +     notatka + "\n"
                   + "lokalizacja: " + lokalizacja + "\n"
                   +    "sequence: " +    sequence + "\n"
                   + "powtarzanie: " +    powtarzanie.stworzWpis() + "\n"
                   +     "created: " +     created + ")\n";
    }
};


