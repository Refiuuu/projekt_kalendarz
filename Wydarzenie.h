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
    string godzina;
    string aktualna;
    Powtarzanie powtarzanie;


    string strDTSTART() {
        return "Wydarzenie POCZATEK (" + data_start + ")";
    }

    string strDTEND() {
        return "Wydarzenie KONIEC (" + data_end + ")";
    }

    string strCREATED() {
        return "Wydarzenie STWORZONO (" + created + ")";
    }

    string strDESCRIPTION() {
        return "Wydarzenie NOTATKA (" + notatka + ")";
    }

    string strLOCATION() {
        return "Wydarzenie LOKALIZACJA (" + lokalizacja + ")";
    }

    string strSEQUENCE() {
        return "Wydarzenie POWTARZANIE (" + sequence + ")";
    }

    string strSUMMARY() {
        return "Wydarzenie TYTUL (" + tytul + ")";
    }

};


