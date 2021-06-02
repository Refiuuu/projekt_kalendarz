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

/**
* \file Projekt.cpp
* \brief Glowny plik zrodlowyw ktorym znajduje sie "int main()"
*/

using namespace std;

/**
* \mainpage
* \Aplikacja "Kalendarz" ktora w pelni przetwarza oraz tworzy pliki .ics oraz dziala na zasadzie ICAL.
* \Program umozliwia stworzenie listy wydarzen oraz ich ewentualna korekte, nastepnie mozliwosc zapisu.
* \Odczyt wlasnego pliku .ics polega na wpisaniu jego nazwy na poczatku dzialania programu.
* \Dalej nalezy juz tylko postepowac zgodnie z komunikatami pojawiajacymi sie na ekranie konsoli.
* 
* 
* \author Rafal Olender
* \date 2021.06.01
* \version Koncowa
* 
* \a raf.olender@wp.pl
*/



/// <summary>
/// Wczytywanie od nowa pliku
/// </summary>
/// <param name="importer"></param>
/// <param name="zarzadca"></param>
void wczytajOdNowa(Importer &importer, Zarzadca &zarzadca) {
    if (takCzyNie("Czy chcesz otworzyc istniejacy juz plik? [T/N]:  "))
    {
        auto nazwaPliku = importer.wczytaj_nazwe();
        auto wydarzenia = importer.wczytaj(nazwaPliku);
        zarzadca.DodajWydarzenia(wydarzenia);
    }
    system("cls");
}
/// <summary>
/// Powitanie
/// </summary>
void Intro() {
    cout << "\t\t\t\t\tWitaj w programie 'Kalendarz' :)\n\n";
    system("pause");
    system("cls");
}

/// <summary>
/// Wyswietlanie miesiaca jako nazwa
/// </summary>
/// <param name="cos">Miesiac do zamiany</param>
/// <returns>Napis w ulepszonym formacie</returns>
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
   
    srand(time(NULL));
    Importer importer;
    Zarzadca zarzadca;
    Export exporter;
    Fabryka fabryka;

    Intro();
    wczytajOdNowa(importer, zarzadca);

    string ladna = LadnaNazwa(DataZGodzina::aktualnaPlusDni(0));

    string wpisz;

    while (wpisz != "quit")
    {
        

   cout<< "**Projekt Zap Kalendarz**\n\n" <<
          "Made by Rafal Olender\n\n" <<
          "Aktualna data:  ["<< DataZGodzina::aktualnaPlusDni(0).dzien <<"  "<< ladna <<"  "<<DataZGodzina::aktualnaPlusDni(0).rok <<"]"<<"\n\n" <<
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
        zarzadca.pokazListe(do_przypomnienia);
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
          system("cls");

          auto lista = zarzadca.Podajliste();
          zarzadca.pokazListe(lista);
          auto element = pobierzNumer("Ktory element chcesz usunac?\n\n", lista.size());
          zarzadca.UsunWydarzenia(element);
          system("cls");
        }

        else if (wpisz == "3")
        {
            system("cls");
            auto lista = zarzadca.Podajliste();
            zarzadca.pokazListe(lista);

            if (lista.size() == 0)
            {
                cout << "Nie ma w tym pliku jeszcze zadnego elementu !!!" << endl;
                continue;
            }

            int element;
            do {
                element = pobierzNumer("Ktory element chcesz modyfikowac?\n", lista.size());
            } while (!(element > 0 && element <= lista.size()));

            system("cls");
  
            auto menu_modyfikacji =
              "Co chcesz Modyfikowac ?\n" 
              "1.Data rozpoczecia.\n"
              "2.Data zakonczenia.\n"
              "3.Tytul wydarzenia.\n"
              "4.Notatka.\n"
              "5.Lokalizacja.\n"
              "6.Zakoncz edycje.\n"
              "Podaj numer akcji:\t";

            Wydarzenie noweWydarzenie = lista.at(element - 1);;
            int opcja;
            do {
               zarzadca.wyswietl(noweWydarzenie);
               opcja = pobierzNumer(menu_modyfikacji, 6);
               noweWydarzenie = fabryka.modyfikuj_wydarzenie(noweWydarzenie, opcja);
            } while (opcja != 6);
            zarzadca.Modyfikuj(noweWydarzenie, element);
          
        }

        else if (wpisz == "4") {
          auto lista = zarzadca.Podajliste();
          auto nazwa_do_exportu = importer.wczytaj_nazwe();
          exporter.export_do_pliku(nazwa_do_exportu, lista);
          cout << "Zapisane\n";
          system("pause");
          system("cls");
        }

        else if (wpisz == "P") {
          system("cls");
          cout << "1.Wydarzenia w najblizszych 7 dniach\n" 
               << "2.Wydarzenia w tym miesiacu\n"
               << "3.Wszystkie wydarzenia zapisane w pliku\n\n";
          auto element = pobierzNumer("W jaki sposob chcesz wyswietlic wydarzenia ?:\t", 3);
          system("cls");

          if (element == 1) {
              auto lista = zarzadca.FiltrujOdDo(DataZGodzina::aktualnaData(), DataZGodzina::aktualnaPlusDni(7));
              zarzadca.pokazListe(lista);
              cout << endl;
              system("pause");
              system("cls");
          } else if (element == 2) {
              auto koniec_miesiaca = DataZGodzina::aktualnaData();
              koniec_miesiaca.dzien = 31;
              auto lista = zarzadca.FiltrujOdDo(DataZGodzina::aktualnaData(), koniec_miesiaca);
              zarzadca.pokazListe(lista);
              cout << endl;
              system("pause");
              system("cls");
          } else if (element == 3) {
            auto lista = zarzadca.Podajliste();
            zarzadca.pokazListe(lista);
            cout << endl;
            system("pause");
            system("cls");
          }
        }

        else if (wpisz == "quit") {
            auto wiadomosc =
                "\nZamykanie programu :)!\n"
                "Wszystkie niezapisane zmiany zostana utracone, czy chcesz zapisac? [T/N]\n\n";

            if (takCzyNie(wiadomosc))
            {
                auto lista = zarzadca.Podajliste();
                auto nazwa_do_exportu = importer.wczytaj_nazwe();
                exporter.export_do_pliku(nazwa_do_exportu, lista);
                cout << "Zapisane\n";
                system("pause");
            }
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
          cout << "***Nie ma takiej opcji***\n" << endl;
        }
    }

    return 0;
}

