
#include <iostream>
#include <string>
#include "Fabryka.h"
#include "Importer.h"
#include "Export.h"
#include "Zarzadca.h"
#include "Wydarzenie.h"

using namespace std;

void pokazListe(vector<Wydarzenie> &lista) {
  for (int i = 1; i <= lista.size(); i++) {
    cout << i << ": " <<lista.at(i-1).str() << endl;
  }
}

int pobierzNumer(const char* wiadomosc, int max) {
    int element;
    do {
      cout << wiadomosc;
      cin >> element;
    } while (element <= 0 && element > max);
    return element;
}

int main() 
{
    Importer importer;
    Zarzadca zarzadca;
    Export exporter;
    Fabryka fabryka;
    
    string wpisz;

    cout << "WITAJ W WERSJI ALFA :)\t";
    while (wpisz != "quit")
    {
        cout << endl
           << "1.Wczytaj eventy\n"
           << "2.Dodaj Event\n"
           << "3.Usun Event\n"
           << "4.Modyfikuj\n"
           << "5.Export\n"
           << "P.Pokaz\n"
           << "quit zamyka aplikacje\n";
        cin >> wpisz;

        if (wpisz == "1")
        {
            auto nazwaPliku = importer.wczytaj_nazwe();
            auto wydarzenia = importer.wczytaj(nazwaPliku);
            zarzadca.DodajWydarzenia(wydarzenia);
        }

        else if (wpisz == "2")
        {   
            auto wydarzenie = fabryka.StworzWydarzenie();
            zarzadca.DodajWydarzenie(wydarzenie);
        }

        else if (wpisz == "3")
        {
          auto lista = zarzadca.Podajliste();
          pokazListe(lista);
          auto element = pobierzNumer("Ktory element chcesz usunac?\n", lista.size());
          zarzadca.UsunWydarzenia(element);
        }

        else if (wpisz == "4")
        {
          auto lista = zarzadca.Podajliste();
          int element = pobierzNumer("Ktory element chcesz modyfikowac?\n", lista.size());
          auto oryginalneWydarzenie = lista.at(element);
          auto noweWydarzenie = fabryka.modyfikuj_wydarzenie(oryginalneWydarzenie); // modyfikuj_wydarzenie
          zarzadca.Modyfikuj(noweWydarzenie, element);
        }

        else if (wpisz == "5") {
          auto lista = zarzadca.Podajliste();
          auto nazwa_do_exportu = importer.wczytaj_nazwe();
          exporter.export_do_pliku(nazwa_do_exportu, lista);
          cout << "Zapisane\n";
        }

        else if (wpisz == "P") {
          auto lista = zarzadca.Podajliste();
          pokazListe(lista);
        }

        else {
          cout << "Nie ma takiej opcji" << endl;
        }
    }

    return 0;
}

