#pragma once
#include <string>

using namespace std;

enum Powtarzanie {
    Codzienne,
    Tygodniowe,
    Miesieczne,
    Roczne
};


class Wydarzenie {
public:

    string data_start;
    string data_end;
    string tytul;
    string notatka;
    string lokalizacja;
    string sequence;
    string created;

    // TODO: potrzebne?
    string godzina;
    string aktualna;
    Powtarzanie powtarzanie;

    string str() {
        return "Wydarzenie POCZATEK (" 
                      "data_start: " +  data_start + ", "
                   +    "data_end: " +    data_end + ", "
                   +       "tytul: " +       tytul + ", "
                   +     "notatka: " +     notatka + ", "
                   + "lokalizacja: " + lokalizacja + ", "
                   +    "sequence: " +    sequence + ", "
                   +     "created: " +     created + ")";
    }
};


