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
    string rule;
    string zasada;

    // TODO: potrzebne?
    Powtarzanie powtarzanie;

    string str() {
        return "Wydarzenie POCZATEK (" 
                      "data_start: " +  data_start + "\n"
                   +    "data_end: " +    data_end + "\n"
                   +     "rrule"     +    zasada   + "\n"
                   +       "tytul: " +       tytul + "\n"
                   +     "notatka: " +     notatka + "\n"
                   + "lokalizacja: " + lokalizacja + "\n"
                   +    "sequence: " +    sequence + "\n"
                   +     "created: " +     created + ")\n";
    }
};


