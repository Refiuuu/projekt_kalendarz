#include "Delete.h"
#include <iostream>
#include <ctime>



void Delete::zapis_do_pliku(string nazwa_pliku)
{
	cout << "Podaj nazwe pliku z ktorego chcesz usunac event: \n";

	auto wydarzenia = imp.wczytaj();
	
	cout << "Podaj date i godzine rozpoczecia wydarzenie ktore chcesz usunac: \n";

	cout << "Date zapisz w formacie [np: 2021 12 23]" << "\n";

	cout << "Po wpisanym roku wcisniej ENTER etc..." << "\n";

	data = fab.dodaj_data();

	cout << endl;

	cout << "Podaj od ktorej ma byc to wydarzenie w formacie [np: 13 00 00 ]" << "\n";
	cout << "Po wpisanym roku wcisniej ENTER etc..." << "\n";

	godzina = fab.dodaj_godzine();

	Data = "DTSTART:" + data + godzina;

	auto wydarzenie = Data;

	//Je¿eli 'wydarzenie = Data'   znajdzie z pliku    'wydarzenie = temu co wpisane'    to wtedy usuñ od poprzedniej linijki do END:VEVENT w³¹cznie;

	//if(wydarzenie ==  )

}
 