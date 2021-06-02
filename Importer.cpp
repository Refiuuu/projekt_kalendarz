#include "Importer.h"
#include "Sterowanie.h"
#include <fstream>
#include <iostream>
#include <iomanip>

/**
* \file Importer.cpp
* \brief Plik zrodlowy modulu Importer
*/


/// <summary>
/// Wczytywanie nazwy przez uzytkownika
/// </summary>
/// <returns></returns>
string Importer::wczytaj_nazwe()
{
    auto nazwaPliku = pobierzString("PODAJ NAZWE PLIKU:\t");
    nazwaPliku += ".ics";
    return nazwaPliku;
}

/// <summary>
/// Wczytywanie danych z pliku o podanej nazwie przez uzytkownika
/// </summary>
/// <param name="Wczytaj">Plik ktory ma byc wczytany</param>
/// <returns>Zwraca liste wydarzen zapisanych w pliku </returns>
vector<Wydarzenie> Importer::wczytaj(string Wczytaj)
{
    ifstream plik;
    Importer pliczek;

    plik.open(Wczytaj);

    while(!plik.good())
    { 
        cout << "BLAD WCZYTYWANIA, NIE MA TAKIEGO PLIKU: \n\n";
        auto nowy = pliczek.wczytaj_nazwe();
        plik.open(nowy);
    }

    string linia;
    string tytul;
    string notatka;
    string data;
    string godzina;
    string lokalizacja;
    string powtarzalnosc;

    string TablicaLinii[7];

    auto wydarzenie = Wydarzenie();
    auto wszystkie_wydarzenia = vector<Wydarzenie>();

    
    while (!plik.eof())
    {
        if (plik.good())
        {

            getline(plik, linia);
            auto typ = wykryj_typ(linia);

            if (typ == IcsType::BEGIN_VEVENT) {
                wydarzenie = Wydarzenie();
                continue;
            }

            if (typ == IcsType::END_VEVENT) {
                cout << wydarzenie.str() << endl;
                wszystkie_wydarzenia.push_back(wydarzenie);
                continue;
            }

            if (typ != IcsType::ERROR && typ != IcsType::END_VCALENDAR) {
                ustaw_pole(typ, linia, wydarzenie);
            }
        }
    }

    plik.close();

    return wszystkie_wydarzenia;
}

/// <summary>
/// Wykrywanie znaczacyh slow w pliku do jego poprawnego pretwarzania
/// </summary>
/// <param name="linia">Przechodzenie przez plik linia po lini i przypisywanie enumeracji odpowiednim wartoscia linii</param>
/// <returns></returns>
IcsType Importer::wykryj_typ(string linia)
{
    if (linia.find("BEGIN:VEVENT") != -1) {
        return IcsType::BEGIN_VEVENT;
    }

    if (linia.find("END:VEVENT") != -1) {
        return IcsType::END_VEVENT;
    }

    if (linia.find("DESCRIPTION") != -1) {
        return IcsType::DESCRIPTION;
    }

    if (linia.find("SUMMARY") != -1) {
        return IcsType::SUMMARY;
    }

    if (linia.find("LOCATION") != -1) {
        return IcsType::LOCATION;
    }
   
    if (linia.find("DTSTART") != -1) {
        return IcsType::DTSTART;
    }
    
    if (linia.find("DTEND") != -1) {
        return IcsType::DTEND;
    }

    if (linia.find("CREATED") != -1) {
        return IcsType::CREATED;
    }

    if (linia.find("SEQUENCE") != -1) {
        return IcsType::SEQUENCE;
    }

    if (linia.find("STATUS") != -1) {
        return IcsType::STATUS;
    }

    if (linia.find("TRANSP") != -1) {
        return IcsType::TRANSP;
    }

    if (linia.find("RRULE:FREQ=") != -1) {
        return IcsType::RRULE;
    }

    return IcsType::ERROR;
      
}

string wez_dane(string linia) {
    return linia.substr(linia.find(':') + 1);
}


/// <summary>
/// Szukanie powtarzalnosci zapisanej w pliku
/// </summary>
/// <param name="linia">Odpowiednia linia z pliku</param>

Powtarzanie Importer::wez_powtarzalnosc(string linia) {
  Powtarzanie powtarzanie;
  
  if (linia != "FREQ=") {
    auto podzial = linia.find(';');
    auto powtarzalnosc = linia.substr(0, podzial);
    auto dzien = linia.substr(podzial + 1, linia.length());

    powtarzanie.powtarzaj = true;
    sprawdzPowtarzalnosc(powtarzanie, powtarzalnosc);
    sprawdzDzienPowtarzania(powtarzanie, dzien);
  }
  return powtarzanie;
}

/// <summary>
/// Przypisanie odpowiedniego napisu w zaleznosci do wpisanego dnia przez uzytkownika
/// </summary>
void Importer::sprawdzDzienPowtarzania(Powtarzanie &powtarzanie, string linia) {
  auto dzien = linia.substr(linia.find('=') + 1);
  if (dzien == "MO") {
    powtarzanie.ktoryDzien = dzien;
  }
  else if (dzien == "TU") {
    powtarzanie.ktoryDzien = dzien;
  }
  else if (dzien == "WE") {
    powtarzanie.ktoryDzien = dzien;
  }
  else if (dzien == "TH") {
    powtarzanie.ktoryDzien = dzien;
  }
  else if (dzien == "FR") {
    powtarzanie.ktoryDzien = dzien;
  }
  else if (dzien == "SA") {
    powtarzanie.ktoryDzien = dzien;
  }
  else if (dzien == "SU") {
    powtarzanie.ktoryDzien = dzien;
  }
  else {
    cout << "Blad przetwarzania - nie prawidlowy zapis dnia powtarzania\n" << linia << endl; 
    powtarzanie.powtarzaj = false;
  }
}
/// <summary>
/// Funkcja odpowiada za przypisanie powtarzania w zaleznosci do wybranego numeru przez uzytkownika
/// </summary>
/// <param name="powtarzanie"></param>
/// <param name="linia"></param>
void Importer::sprawdzPowtarzalnosc(Powtarzanie &powtarzanie, string linia) {
  auto czestotliwosc = linia.substr(linia.find('=')+1, linia.length());
  if (czestotliwosc == "DAILY") {
    powtarzanie.typ = TypPowtarzania::DZIENNIE;
  }
  else if (czestotliwosc == "WEEKLY") {
    powtarzanie.typ = TypPowtarzania::TYGODNIOWO;
  }
  else if (czestotliwosc == "MONTHLY") {
    powtarzanie.typ = TypPowtarzania::MIESIECZNIE;
  }
  else {
    cout << "Blad przetwarzania - nie prawidlowy zapis powtarzania\n" << linia << endl; 
    powtarzanie.powtarzaj = false;
  }
}

/// <summary>
/// Funkcja ktora odkodowywuje zapisana date i godzine z pliku
/// </summary>
/// <param name="date">Data</param>
/// <returns>Zwraca odkodowana date i godzine z pliku ICAL</returns>
DataZGodzina wez_date_godzine(string date) { 

    string rok;
    string miesiac;
    string dzien;
    string godzina;
    string minuta;
    string sekunda;

    rok = date.substr(0, 4);
    miesiac = date.substr(4,2);
    dzien = date.substr(6,2);
    godzina = date.substr(9, 2);
    minuta = date.substr(11, 2);
    sekunda = date.substr(13, 2);

    DataZGodzina dataIgodzina;
    dataIgodzina.rok     = atoi(rok.c_str());
    dataIgodzina.miesiac = atoi(miesiac.c_str());
    dataIgodzina.dzien   = atoi(dzien.c_str());
    dataIgodzina.godzina = atoi(godzina.c_str());
    dataIgodzina.minuta  = atoi(minuta.c_str());
    dataIgodzina.sekunda = atoi(sekunda.c_str());

    return dataIgodzina;
}
/// <summary>
/// Pobiera wartosc z danej linii pliku, porownuje ja z enumeracja oraz przypisuje do odpowiedniej zmiennej wydarzenia 
/// </summary>
/// <param name="typ">enumeracja</param>
/// <param name="linia">Linia w pliku</param>
/// <param name="wydarzenie">Wydarzenie ktore bedzie mialo przypisane zmienne</param>
void Importer::ustaw_pole(IcsType typ, string linia, Wydarzenie &wydarzenie)
{
    switch (typ) {
    case IcsType::DESCRIPTION:
        wydarzenie.notatka = wez_dane(linia);
        break;
    case IcsType::SUMMARY:
        wydarzenie.tytul = wez_dane(linia);
        break;
    case IcsType::LOCATION:
        wydarzenie.lokalizacja = wez_dane(linia);
        break;
    case IcsType::DTSTART:
        wydarzenie.data_start = wez_date_godzine(wez_dane(linia));
        break;
    case IcsType::DTEND:
        wydarzenie.data_end = wez_date_godzine(wez_dane(linia));
        break;
    case IcsType::CREATED:
        wydarzenie.created = wez_date_godzine(wez_dane(linia));
        break;
    case IcsType::SEQUENCE:
        wydarzenie.sequence = wez_dane(linia);
        break;
    case IcsType::RRULE:
        wydarzenie.powtarzanie = wez_powtarzalnosc(wez_dane(linia));
        break;
    }
}
