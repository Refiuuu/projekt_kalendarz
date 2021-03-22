#include "Importer.h"
#include "Export.h"
#include <iostream>
#include <fstream>


// to jest spoko
 string Importer::wczytaj_nazwe()
{
    cout << "PODAJ NAZWE PLIKU DO WYSWIETLENIA:" << endl;
    string nazwaPliku;

    cin >> nazwaPliku;

    nazwaPliku += ".ics";

    return nazwaPliku;
}

//TODO: vector<Wydarzenie> Importer::wczytaj(string nazwaPliku) - tak będzie lepiej
// a wczytaj_nazwe wywołaj przed wczytywaniem danych w pliku Projekt.cpp i przekaz nazwe do wczytaj()
// np.
// auto nazwa_pliku = importer.wczytaj_nazwe();
// auto dane = importer.wczytaj(nazwa_pliku);
//
// albo do testów bedzie ci latwiej
//
// auto nazwa_pliku = string("kalendarz.ics");
// auto dane = importer.wczytaj(nazwa_pliku);
//
// w ten sposob nie bedziesz musial za kazdym razem podawac nazwy pliku!

vector<Wydarzenie> Importer::wczytaj()
{
    ifstream plik;

    plik.open(wczytaj_nazwe());

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

    return IcsType::ERROR;
      
}
 
string wez_dane(string linia) { // TODO powinno nalezec do klasy i byc prwatne
    return linia.substr(linia.find(':') + 1);
}

string wez_date_godzine(string date) { // TODO powinno nalezec do klasy i byc prywaten

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
    }
}
