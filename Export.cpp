#include "Export.h"
#include "Fabryka.h"
#include "Powtarzanie.h"
#include "Wydarzenie.h"

/**
* \file Export.cpp
* \brief Plik zrodlowy modulu Export
*/

using namespace std;



/// <summary>
/// Funkcja odpowiada za export do pliku o podanej nazwie przez uzytkownika calej listy wydarzen.
/// </summary>
/// <param name="nazwa_pliku">Nazwa podanego pliku</param>
/// <param name="wydarzenia">Lista wydarzen</param>
bool Export::export_do_pliku(string nazwa_pliku, vector<Wydarzenie> &wydarzenia)
{
	ofstream plik;

	plik.open(nazwa_pliku);

	if (plik.good()) {
        plik << "BEGIN:VCALENDAR" << endl
            << "PRODID:-//Google Inc//Google Calendar 70.9054//EN" << endl
            << "VERSION:2.0" << endl
            << "CALSCALE:GREGORIAN" << endl
            << "METHOD:PUBLISH" << endl
            << "X-WR-TIMEZONE:Europe/Warsaw" << endl;
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

/// <summary>
/// Zapisywanie jednego wydarzenia kolejno jedno po drugim w odpowiednim formacie dla ICAL
/// </summary>
/// <param name="wydarzenie">Wydarzenie z listy</param>
/// <param name="plik">Nazwa pliku za zapisu</param>

void Export::zapisz_wydarzenie(Wydarzenie &wydarzenie, ofstream &plik) 
{

    

   plik << "BEGIN:VEVENT" << endl
        << "DTSTART:" << wydarzenie.data_start.do_zapisu() << endl
        << "DTEND:" << wydarzenie.data_end.do_zapisu() << endl;
    if(wydarzenie.powtarzanie.powtarzaj == true) 
    {
       plik << "RRULE:FREQ=" << wydarzenie.powtarzanie.stworzWpis() << endl;
    }   

   plik << "DTSTAMP:20210318T170142Z" << endl
        << "UID:"<<wydarzenie.Losowanie()<<"@google.com"<< endl
        << "CREATED:" << wydarzenie.created.do_zapisu() << endl
        << "DESCRIPTION:" << wydarzenie.notatka << endl
        << "LAST-MODIFIED:" << wydarzenie.created.do_zapisu() << endl
        << "LOCATION:" << wydarzenie.lokalizacja << endl
        << "SEQUENCE:0" << endl
        << "STATUS:CONFIRMED" << endl
        << "SUMMARY:" << wydarzenie.tytul << endl
        << "TRANSP:OPAQUE" << endl
        << "END:VEVENT" << endl;
}
