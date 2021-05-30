#include "Export.h"
#include "Fabryka.h"
#include "Importer.h"
#include "Sterowanie.h"
#include "Wydarzenie.h"
#include "Zarzadca.h"

#include <windows.h>
#include <cstdio>
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
    if (takCzyNie("Czy chcesz otworzyc istniejacy juz plik? [T/N]:  "))
    {
        auto nazwaPliku = importer.wczytaj_nazwe();
        auto wydarzenia = importer.wczytaj(nazwaPliku);
        zarzadca.DodajWydarzenia(wydarzenia);
    }
    system("cls");
}

string LadnaNazwa(DataZGodzina cos)
{
    string miesiac;
    if (cos.miesiac == 1) miesiac = "Stycznia";
    else if (cos.miesiac == 2) miesiac = "Lutego";
    else if (cos.miesiac == 3) miesiac = "Marca";
    else if (cos.miesiac == 4) miesiac = "Kwietnia";
    else if (cos.miesiac == 5) miesiac = "Maja";
    else if (cos.miesiac == 6) miesiac = "Czerwca";
    else if (cos.miesiac == 7) miesiac = "Lipca";
    else if (cos.miesiac == 8) miesiac = "Sierpnia";
    else if (cos.miesiac == 9) miesiac = "Wrzesnia";
    else if (cos.miesiac == 10) miesiac = "Pazdzeirnika";
    else if (cos.miesiac == 11) miesiac = "Listopada";
    else if (cos.miesiac == 12) miesiac = "Grudnia";

    return miesiac;
}

int main()
{
   

    Importer importer;
    Zarzadca zarzadca;
    Export exporter;
    Fabryka fabryka;

    wczytajOdNowa(importer, zarzadca);

    string ladna = LadnaNazwa(DataZGodzina::aktualnaPlusDni(0));

    string wpisz;

    while (wpisz != "quit")
    {
        

   cout<< "\n**Projekt Zap Kalendarz**\n\n" <<
          "Aktualna data:"<< DataZGodzina::aktualnaPlusDni(0).dzien <<"  "<< ladna <<"  "<<DataZGodzina::aktualnaPlusDni(0).rok <<"\n\n" <<
          "\n1.Dodaj Event\n" <<
          "2.Usun Event\n" <<
          "3.Modyfikuj\n" <<
          "4.Export\n" <<
          "P.Pokaz\n" <<
          "N.Otworz nowy plik\n" <<
          "quit zamyka aplikacje\n\n";

        

        auto dzisiaj = DataZGodzina::aktualnaData();
        dzisiaj.godzina = 0;
        dzisiaj.minuta = 0;
        dzisiaj.sekunda = 0;
        auto jutro = DataZGodzina::aktualnaPlusDni(1);
        jutro.godzina = 23;
        jutro.minuta = 59;
        jutro.sekunda = 59;

        auto do_przypomnienia = zarzadca.FiltrujOdDo(dzisiaj, jutro);
        cout << "        Najblizsze wydarzenia\n";
        cout << "_____________________________________\n";
        pokazListe(do_przypomnienia);
        cout << "_____________________________________\n";

        wpisz = pobierzString("Ktora opcje chcesz wybrac?: ");

        if (wpisz == "1")
        {
            system("cls");
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
          if (lista.size() == 0)
          {   
              system("cls");
              cout << "********Nie ma w tym pliku jeszcze zadnego elementu********" << endl;    
              continue;
          }
          system("cls");
          pokazListe(lista);
          int element;
          do {
             element = pobierzNumer("Ktory element chcesz modyfikowac?:  ", lista.size());
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
          system("cls");
          cout << "1.Wydarzenia w tym tygodniu\n" 
               << "2.Wydarzenia w tym miesiacu\n"
               << "3.Wszystkie\n";
          auto element = pobierzNumer("W jaki sposob chcesz wyswietlic wydarzenia ?:\t", 3);

          if (element == 1) {
              auto lista = zarzadca.FiltrujOdDo(DataZGodzina::aktualnaData(), DataZGodzina::aktualnaPlusDni(7));
              pokazListe(lista);
              cout << endl;
              system("pause");
              system("cls");
          } else if (element == 2) {
              auto koniec_miesiaca = DataZGodzina::aktualnaData();
              koniec_miesiaca.dzien = 31;
              auto lista = zarzadca.FiltrujOdDo(DataZGodzina::aktualnaData(), koniec_miesiaca);
              pokazListe(lista);
              cout << endl;
              system("pause");
              system("cls");
          } else if (element == 3) {
            auto lista = zarzadca.Podajliste();
            pokazListe(lista);
            cout << endl;
            system("pause");
            system("cls");
          }
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
                system("cls");
                auto lista = zarzadca.Podajliste();
                zarzadca.Usun(lista);
                wczytajOdNowa(importer, zarzadca);
            }
        }

        else {
          system("cls");
          cout << "Nie ma takiej opcji" << endl;
        }
    }

    return 0;
}

