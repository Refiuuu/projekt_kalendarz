#include "Export.h"
#include "Fabryka.h"


using namespace std;

bool Export::export_do_pliku()
{
	Fabryka fabryka;
	auto wydarzenie = fabryka.StworzWydarzenie();

	
	string tab[7] = { };

	{
		ifstream plik;
		
		string linia;
		plik.open("KALENDARZ.ics");
		
		if (plik.good())
		{
			for (int w = 0; w < 7; w++)
			{
				getline(plik, linia);
				tab[w] = linia;
			}
		}
		
		plik.close();
	}



	ofstream plik;

	cout << "Podaj nazwe pliku: \t" << endl;
	string nazwa_pliku;

	cin >> nazwa_pliku;


	plik.open(nazwa_pliku);

	if (plik.good()) {

		for (int w = 0; w < 7; w++)
		{
			plik << tab[w] << endl;
		}
		plik << "BEGIN:VEVENT\n";
		plik << wydarzenie.data_start << endl;
		plik << wydarzenie.data_end << endl;
		plik << "DTSTAMP:20210318T170142Z" << endl;
		plik << "UID:110l8lpmu394madloslhqi91r0@google.com" << endl;
		plik << "CREATED:" <<wydarzenie.aktualna << endl;
		plik << wydarzenie.notatka << endl;
		plik << "LAST-MODIFIED:"<< wydarzenie.aktualna << endl;
		plik << wydarzenie.lokalizacja << endl;
		plik << "SEQUENCE:0" << endl;
		plik << "STATUS:CONFIRMED\n";
		plik << wydarzenie.tytul << endl;
		plik << "TRANSP:OPAQUE\n";
		plik << "END:VEVENT\n";
		plik << "END:VCALENDAR";
		return true;
	}
	else {
		plik.close();
		return false;
	}

}
