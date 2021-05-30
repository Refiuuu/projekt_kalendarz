#pragma once

#include "Wydarzenie.h"
#include "Powtarzanie.h"
#include <vector>
#include <string>

using namespace std;

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
    RRULE,
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
/// <summary>
/// Importer odpowiada za wczytywanie oraz rozszyfrowywanie pliku .ics.
/// </summary>
class Importer {
public:

    vector<Wydarzenie> wczytaj(string Wczytaj);
    string wczytaj_nazwe();

private:

    Powtarzanie wez_powtarzalnosc(string linia);
    void sprawdzDzienPowtarzania(Powtarzanie &powtarzanie, string linia);
    void sprawdzPowtarzalnosc(Powtarzanie &powtarzanie, string linia);

    IcsType wykryj_typ(string linia);
    void ustaw_pole(IcsType typ, string linia, Wydarzenie &wydarzenie);
   
};
