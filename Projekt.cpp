
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
    string wpiszz;

plik:

    

    cout << "Czy chcesz otworzyc istniejacy juz plik ? [T/N]" << "\t";

    cin >> wpiszz;
    while ((wpiszz != "T") && (wpiszz != "N"))
    {
        cout << "Prosze wybrac opcje [T/N]: \t";
        cin >> wpiszz;
    }

    if (wpiszz == "T")
    {
        auto nazwaPliku = importer.wczytaj_nazwe();
        auto wydarzenia = importer.wczytaj(nazwaPliku);
        zarzadca.DodajWydarzenia(wydarzenia);
       
    }
    else
    {

    }
    
start:

    while (wpisz != "quit")
    {
        cout << endl 
           << "1.Dodaj Event\n"
           << "2.Usun Event\n"
           << "3.Modyfikuj\n"
           << "4.Export\n"
           << "P.Pokaz\n"
           << "N.Otworz nowy plik\n"
           << "quit zamyka aplikacje\n";

        cin >> wpisz;

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
                goto start;
            }

          int element = pobierzNumer("Ktory element chcesz modyfikowac?\n", lista.size());

          while (!(element > 0 && element <= lista.size()))
          {
              element = pobierzNumer("Ktory element chcesz modyfikowac?\n", lista.size());
          }

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
            cout << endl;
            cout << "Zamykanie programu :)!";
        }

        else if (wpisz == "N") {
            string wybor;
            cout << endl;
            cout << "Tworzenie nowego pliku !!" << endl;
            cout << "Wszystkie niezapisane zmiany zostana utracone, czy na pewno ?[T/N]\n";

            cin >> wybor;
            while ((wybor != "T") && (wybor != "N"))
            {
                cout << "Prosze wybrac opcje [T/N]: \t";
                cin >> wybor;
            }

            if (wybor == "T")
            {
                auto lista = zarzadca.Podajliste();
                zarzadca.Usun(lista);
                cout << endl;

                goto plik;
            }
            else
            {
                goto start;
            }
        }

        else {
          cout << "Nie ma takiej opcji" << endl;
        }
    }

    return 0;
}

