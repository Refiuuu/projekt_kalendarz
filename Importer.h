#pragma once

#include "Wydarzenie.h"
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

class Importer {
public:
    vector<Wydarzenie> wczytaj();

private:
    IcsType jakiTyp(string linia);

    void wezDetal(IcsType typ, string linia, Wydarzenie &wydarzenie);

};
