#pragma once
#include "Powtarzanie.h"
#include <string>

using namespace std;
/// <summary>
/// DataZGodzina odpowiada za "sklejenie" w calosc daty i godziny w formacie odpowiednim dla formatu pliku .ics.
/// </summary>
class DataZGodzina {
public:
  int rok;
  int miesiac;
  int dzien;
  int godzina;
  int minuta;
  int sekunda;

  string popraw(int &liczba) {
    if (liczba >= 0 && liczba < 10) {
      return "0" + to_string(liczba);
    }
    return to_string(liczba);
  }

  string str() {
    return popraw(rok) + "-" + popraw(miesiac) + "-" + popraw(dzien) + " " + popraw(godzina) + ":" + popraw(minuta) + ":" + popraw(sekunda);
  };

  string do_zapisu() {
    return popraw(rok) + popraw(miesiac) + popraw(dzien) + "T" + popraw(godzina) + popraw(minuta) + popraw(sekunda) + "Z";
  }
};
/// <summary>
/// Wydarzenie odpowiada za przechowywanie danych wczytanych/stworzonych oraz wypisywanie ich w odpowiedniej kolejnosci.
/// </summary>
class Wydarzenie {
public:
    /** \brief Przechowuje date i godzine rozpoczecia wydarzenia
   */
    DataZGodzina data_start; 
    /** \brief Przechowuje date i godzine zakonczenia wydarzenia
   */
    DataZGodzina data_end;
    /** \brief Zmienna typu string przechowujaca tytul wydarzenia
   */
    string tytul;
    /** \brief Zmienna typu string przechowujaca notatke wydarzenia
   */
    string notatka;
    /** \brief Zmienna typu string przechowujaca lokalizacje wydarzenia
   */
    string lokalizacja;
    /** \brief Zmienna typu string przechowujaca sequence wydarzenia
   */
    string sequence;
    /** \brief Przechowuje date i godzine stworzenia listy wydarzen
   */
    DataZGodzina created;

    /** \brief Przechowuje zmnienna bool , czy chcemy powtarzac wydarzenie
     */
    Powtarzanie powtarzanie;

    /** \brief Przechowuje zmnienna bool , czy chcemy powtarzac wydarzenie
   */

    /// <summary>
    /// Wypisywanie listy
    /// </summary>
    /// <returns>Zwraca zapisana liste wydarzen</returns>
    string str() {
   
        return "\n Wydarzenie POCZATEK: \n" 
                     "Data rozpoczecia: "       + data_start.str() + "\n"
                   + "Data zakoncenia: "        + data_end.str() + "\n"
                   + "Powtarzanie Wydarzenia: " + powtarzanie.stworzWpis() + "\n"
                   + "tytul: "                  + tytul + "\n"
                   + "notatka: "                + notatka + "\n"
                   + "lokalizacja: "            + lokalizacja + "\n"
                   + "created: "                + created.str() + "\n";
    }

};

