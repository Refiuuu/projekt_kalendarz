#include "Importer.h"

#include <iostream>
#include <fstream>

vector<Wydarzenie> &Importer::wczytaj()
{
    string nazwaPliku;
    cout << "PODAJ NAZWE PLIKU DO WYSWIETLENIA:" << endl;

    cin >> nazwaPliku;
    nazwaPliku += ".ics";

    ifstream plik;

    plik.open(nazwaPliku);

    string linia;
    string tytul;
    string notatka;
    string data;
    string godzina;
    string lokalizacja;
    string powtarzalnosc;

    bool koniec = false;

    Wydarzenie wydarzenie;

    vector<Wydarzenie> *ww = new vector<Wydarzenie>();
    
    while (!plik.eof())
    {
        if (plik.good())
        {
            getline(plik, linia);
            auto typ = jakiTyp(linia);


            if (typ == IcsType::BEGIN_VEVENT) {
                wydarzenie = Wydarzenie();
                cout << endl;
            }

            if (typ == IcsType::DTSTART) { // da sie zrobic w 3 ifach
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie.strDTSTART() << endl;
            }

            if (typ == IcsType::DTEND) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie.strDTEND() << endl;
            }

            if (typ == IcsType::CREATED) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie.strCREATED() << endl;
            }

            if (typ == IcsType::DESCRIPTION) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie.strDESCRIPTION() << endl;
            }

            if (typ == IcsType::LOCATION) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie.strLOCATION() << endl;
            }

            if (typ == IcsType::SEQUENCE) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie.strSEQUENCE() << endl;
            }

            if (typ == IcsType::SUMMARY) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie.strSUMMARY() << endl;
            }

            if (typ == IcsType::END_VEVENT) {
                //cout << wydarzenie.str();
                ww->push_back(wydarzenie);
                break;
            }
        }
    }
    plik.close();

    if (koniec == false) {
        throw "brak znacznieka konca";
    }

    return *ww;
}

IcsType Importer::jakiTyp(string linia)
{
    if (linia.find("BEGIN:VEVENT") != -1)
    {
        return IcsType::BEGIN_VEVENT;
    }

    if (linia.find("END:VEVENT") != -1)
    {
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
      
}
 
string wezDane(string linia) { // powinno nalezec do klasy i byc prwatne
    return linia.substr(linia.find(':') + 1);
}

string getDate(string date) {

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

    std::tm tm;
    tm.tm_year = atoi(rok.c_str());
    tm.tm_mon = atoi(miesiac.c_str());

    return string(rok + "-" + miesiac + "-" + dzien + "  " + godzina + ":" + minuta + ":" + sekunda);
   

}

void Importer::wezDetal(IcsType typ, string linia, Wydarzenie &wydarzenie)
{
    switch (typ) {
    case IcsType::DESCRIPTION:
        wydarzenie.notatka = wezDane(linia);
        break;
    case IcsType::SUMMARY:
        wydarzenie.tytul = wezDane(linia);
        break;
    case IcsType::LOCATION:
        wydarzenie.lokalizacja = wezDane(linia);
        break;
    case IcsType::DTSTART:
        wydarzenie.data_start = getDate(wezDane(linia));
        break;
    case IcsType::DTEND:
        wydarzenie.data_end = getDate(wezDane(linia));
        break;
    case IcsType::CREATED:
        wydarzenie.created = getDate(wezDane(linia));
        break;
    case IcsType::SEQUENCE:
        wydarzenie.sequence = wezDane(linia);
        break;
    }
}