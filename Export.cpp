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
        << "DTSTART:" << wydarzenie.data_start.do_zapisu() << endl
        << "DTEND:" << wydarzenie.data_end.do_zapisu() << endl
        << "RRULE:FREQ=" << wydarzenie.powtarzanie.stworzWpis() << endl
        << "DTSTAMP:20210318T170142Z" << endl
        << "UID:110l8lpmu394madloslhqi91r0@google.com" << endl
        << "CREATED:" << wydarzenie.created.do_zapisu() << endl
        << "SUMMARY:" << wydarzenie.notatka << endl
        << "LAST-MODIFIED:" << wydarzenie.created.do_zapisu() << endl
        << "LOCATION:" << wydarzenie.lokalizacja << endl
        <<  "SEQUENCE:0" << endl
        << "STATUS:CONFIRMED" << endl
        << "DESCRIPTION:" << wydarzenie.tytul << endl
        << "TRANSP:OPAQUE" << endl
        << "END:VEVENT" << endl;
}
