#include "Importer.h"
#include "Export.h"
#include <iostream>
#include <fstream>



 string Importer::wczytaj_nazwe()
{
    cout << "PODAJ NAZWE PLIKU:\t";
    string nazwaPliku;

    cin >> nazwaPliku;

    nazwaPliku += ".ics";

    return nazwaPliku;
}



 vector<Wydarzenie> Importer::wczytaj(string Wczytaj)
{
    ifstream plik;

    plik.open(Wczytaj);

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

    if (linia.find("RRULE:FREQ=") != -1) {
        return IcsType::RRULE;
    }

    return IcsType::ERROR;
      
}
 
string wez_dane(string linia) {
    return linia.substr(linia.find(':') + 1);
}

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
        wydarzenie.powtarzalnosc = wez_dane(linia);
        break;
    }
}
