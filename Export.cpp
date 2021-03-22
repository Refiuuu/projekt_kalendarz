#include "Export.h"
#include "Fabryka.h"
#include "Wydarzenie.h"


using namespace std;

bool Export::export_do_pliku(string nazwa_pliku, vector<Wydarzenie> &wydarzenia)
{
	ofstream plik;

	plik.open(nazwa_pliku);

	if (plik.good()) {
    plik << "BEGIN:VCALENDAR" << endl;
    for (auto wydarzenie : wydarzenia) {
      zapisz_wydarzenie(wydarzenie, plik);
    }
    plik << "END:VCALENDAR";
    return true;
	}
	else {
		plik.close();
		return false;
	}

}

void Export::zapisz_wydarzenie(Wydarzenie &wydarzenie, ofstream &plik) 
{
      plik << "BEGIN:VEVENT" << endl
        << wydarzenie.data_start << endl
        << wydarzenie.data_end << endl
        << "DTSTAMP:20210318T170142Z" << endl
        << "UID:110l8lpmu394madloslhqi91r0@google.com" << endl
        << "CREATED:" <<wydarzenie.aktualna << endl
        << wydarzenie.notatka << endl
        << "LAST-MODIFIED:"<< wydarzenie.aktualna << endl
        << wydarzenie.lokalizacja << endl
        << "SEQUENCE:0" << endl
        << "STATUS:CONFIRMED" << endl
        << wydarzenie.tytul << endl
        << "TRANSP:OPAQUE" << endl
        << "END:VEVENT" << endl;
}
