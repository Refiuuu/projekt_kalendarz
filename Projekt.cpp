
#include <iostream>
#include <string>
#include "Fabryka.h"
#include "Importer.h"
#include "Export.h"
#include "Zarzadca.h"
#include"Wydarzenie.h"

using namespace std;

int main() 
{
    Importer importer;
    Zarzadca zarzadca;
    Export exporter;
    Fabryka fabryka;
    Wydarzenie wydarzenie;
    

    //To jest tak tymczasowo, poźniej zostanie zmienione na liste :)
    vector<Wydarzenie> wydarzenia = vector<Wydarzenie>();

    string nazwaPliku;
    string znak;
    string wpisz;

    

    cout << "WITAJ W WERSJI ALFA :)\t";
    nazwaPliku = importer.wczytaj_nazwe();
    

    while (wpisz != "quit")
    {
        cout << endl;
        Menu:

        cout << "1.Wczytaj eventy\n";
        cout << "2.Dodaj Event\n";
        cout << "3.Usun Event\n";
        cout << "4.Modyfikuj\n";
        cin >> wpisz;

        if (wpisz == "1")
        {
            wydarzenia = importer.wczytaj(nazwaPliku);
            wydarzenia = zarzadca.Podajliste();
            cin >> wpisz;
            goto Menu;
        }


        if (wpisz == "2")
        {   

            wydarzenie = fabryka.StworzWydarzenie();
            zarzadca.DodajWydarzenie(wydarzenie);
            exporter.export_do_pliku("zapis.txt", wydarzenia); // tutaj wpisujemy nazwe do zapisu i jej format.
           
            cin >> wpisz;
            goto Menu;
        }

        if (wpisz == "3")
        {



            cin >> wpisz;
            goto Menu;
        }

        if (wpisz == "4")
        {



            cin >> wpisz;
            goto Menu;
        }
       
    }

    return 0;
}