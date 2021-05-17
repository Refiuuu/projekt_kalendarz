#include "Export.h"
#include "Fabryka.h"
#include "Importer.h"
#include "Sterowanie.h"
#include "Wydarzenie.h"
#include "Zarzadca.h"

#include <iostream>
#include <string>
#include <BearLibTerminal.h>

using namespace std;

void pokazListe(vector<Wydarzenie> &lista) {
  for (int i = 1; i <= lista.size(); i++) {
    cout << i << ": " <<lista.at(i-1).str() << endl;
  }
}

void wczytajOdNowa(Importer &importer, Zarzadca &zarzadca) {
    if (takCzyNie("Czy chcesz otworzyc istniejacy juz plik? [T/N]"))
    {
        auto nazwaPliku = importer.wczytaj_nazwe();
        auto wydarzenia = importer.wczytaj(nazwaPliku);
        zarzadca.DodajWydarzenia(wydarzenia);
    }
}

int main()
{

    {
        terminal_open();

        // Printing text
        terminal_print(1, 1, "Hello, world!");
        terminal_refresh();

        // Wait until user close the window
        while (terminal_read() != TK_CLOSE);

        terminal_close();
    }


    Importer importer;
    Zarzadca zarzadca;
    Export exporter;
    Fabryka fabryka;

    string wpisz;

    wczytajOdNowa(importer, zarzadca);

    while (wpisz != "quit")
    {
        auto menu =
          "\n1.Dodaj Event\n"
          "2.Usun Event\n"
          "3.Modyfikuj\n"
          "4.Export\n"
          "P.Pokaz\n"
          "N.Otworz nowy plik\n"
          "quit zamyka aplikacje\n";

        wpisz = pobierzString(menu);

        if (wpisz == "1")
        {   
            auto wydarzenie = fabryka.StworzWydarzenie();
            zarzadca.DodajWydarzenie(wydarzenie);
        }

        else if (wpisz == "2")
        {
          auto lista = zarzadca.Podajliste();
          pokazListe(lista);
          auto element = pobierzNumer("Ktory element chcesz usunac?\n", lista.size());
          zarzadca.UsunWydarzenia(element);
        }

        else if (wpisz == "3")
        {
          auto lista = zarzadca.Podajliste();
          pokazListe(lista);
        
          if (lista.size() == 0)
          {   
              cout << "Nie ma w tym pliku jeszcze zadnego elementu !!!" << endl;    
              continue;
          }

          int element;
          do {
              element = pobierzNumer("Ktory element chcesz modyfikowac?\n", lista.size());
          } while (!(element > 0 && element <= lista.size()));

          auto oryginalneWydarzenie = lista.at(element - 1);
          auto noweWydarzenie = fabryka.modyfikuj_wydarzenie(oryginalneWydarzenie);
          zarzadca.Modyfikuj(noweWydarzenie, element);
        }

        else if (wpisz == "4") {
          auto lista = zarzadca.Podajliste();
          auto nazwa_do_exportu = importer.wczytaj_nazwe();
          exporter.export_do_pliku(nazwa_do_exportu, lista);
          cout << "Zapisane\n";
        }

        else if (wpisz == "P") {
          auto lista = zarzadca.Podajliste();
          pokazListe(lista);
        }

        else if (wpisz == "quit") {
            cout << "\nZamykanie programu :)!";
        }

        else if (wpisz == "N") {
            auto wiadomosc =
              "Tworzenie nowego pliku !!\n" 
              "Wszystkie niezapisane zmiany zostana utracone, czy na pewno? [T/N]\n\n";

            if (takCzyNie(wiadomosc))
            {
                auto lista = zarzadca.Podajliste();
                zarzadca.Usun(lista);
                wczytajOdNowa(importer, zarzadca);
            }
        }

        else {
          cout << "Nie ma takiej opcji" << endl;
        }
    }

    return 0;
}

