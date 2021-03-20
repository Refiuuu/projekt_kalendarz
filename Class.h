#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

class Kalendarz
{
private:
   

    int rok, PierwszyDzienMiesiac;
    int miesiac;
    int dzien;
    int IleDni;
    int PodanyMiesiac;

public:
    bool czy_przestepny(int rok);
	void wyswietl();
    string dodaj_data();
    string dodaj_godzine();
    string Data_zapisu_od();
    string Data_zapisu_do();
    string dodaj_notatke();
    string dodaj_lokalizacje();
    string dodaj_tytul(); 
};

class Data {
    int rok;
    int miesiac;
    int dzien;

public:
    int getRok() {
        return rok;
    }

    int getMiesiac() {
        return miesiac;
    }

    int getDzien() {
        return dzien;
    }

    string pokaz() {
        return string(to_string(rok) + "-" + to_string(miesiac) + "-" + to_string(dzien));
    }

 };

class Godzina {

};

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

enum IcsType {
    BEGIN_VCALENDAR,
    END_VCALENDAR,
    BEGIN_VEVENT,
    END_VEVENT,
    DTSTART,
    DTEND,
    DESCRIPTION,
    LOCATION,
    SEQUENCE,
    RULE,
    SUMMARY,
    PRODID,
    VERSION,
    CALSCALE,
    METHOD,
    XWRCALNAME,
    CREATED,
    STATUS,
    TRANSP,
    ERROR = -1
};

class ICS {
public:
    vector<Wydarzenie> wczytaj();
    //void wypisz();

private:
    IcsType jakiTyp(string linia);

    void wezDetal(IcsType typ, string linia, Wydarzenie* wydarzenie);

};

class ZapisWydarzenie
{
private:

    string godzina;
    string data_od;
    string data_do;
    string notatka;
    string tytul;
    string lokalizacja;
    string data;
public:

    void zapisz(Kalendarz k)
    {
        godzina = k.dodaj_godzine();
        data_od = k.Data_zapisu_od();
        data_do = k.Data_zapisu_do();
        notatka = k.dodaj_notatke();
        tytul = k.dodaj_tytul();
        lokalizacja = k.dodaj_lokalizacje();
        data = k.dodaj_data();
    }

};