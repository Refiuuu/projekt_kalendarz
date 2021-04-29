#pragma once
#include "Powtarzanie.h"
#include <string>

using namespace std;

class DataZGodzina {
public:
  int rok;
  int miesiac;
  int dzien;
  int godzina;
  int minuta;
  int sekunda;

  string popraw(int &liczba) {
    if (liczba >= 0 && liczba < 10) {
      return "0" + to_string(liczba);
    }
    return to_string(liczba);
  }

  string str() {
    return popraw(rok) + "-" + popraw(miesiac) + "-" + popraw(dzien) + " " + popraw(godzina) + ":" + popraw(minuta) + ":" + popraw(sekunda);
  };

  string do_zapisu() {
    return popraw(rok) + popraw(miesiac) + popraw(dzien) + "T" + popraw(godzina) + popraw(minuta) + popraw(sekunda) + "Z";
  }
};

class Wydarzenie {
public:

    DataZGodzina data_start;
    DataZGodzina data_end;
    string tytul;
    string notatka;
    string lokalizacja;
    string sequence;
    DataZGodzina created;
    Powtarzanie powtarzanie;

    string str() {
   
        return "Wydarzenie POCZATEK (\n" 
                      "data_start: " +  data_start.str() + "\n"
                   +    "data_end: " +    data_end.str() + "\n"
                   +       "tytul: " +             tytul + "\n"
                   +     "notatka: " +           notatka + "\n"
                   + "lokalizacja: " +     lokalizacja + "\n"
                   +     "created: " +     created.str() + ")\n";
    }

};

