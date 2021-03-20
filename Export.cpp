#include "Export.h"


bool Export::export_do_pliku(string nazwa_pliku, vector<Wydarzenie> wydarzenia_zapis)
{
	ofstream plik;

	plik.open(nazwa_pliku);

	if (plik.good()) {
		plik << "BEGIN:VCALENDAR\n";
		for (auto w : wydarzenia_zapis) {
			zapiszWydarzenie(w, plik);
		}
		plik << "END:VCALENDAR";
		return true;
	}
	else {
		plik.close();
		return false;
	}
};

void Export::zapiszWydarzenie(Wydarzenie &w, ofstream &plik) {
	plik << "BEGIN:VEVENT\n";
	plik << "dupa";
	plik << "END:VEVENT\n";
}
