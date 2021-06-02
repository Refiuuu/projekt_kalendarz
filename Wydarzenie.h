#pragma once
#include "Powtarzanie.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

/**
* \file Wydarzenie.h
* \brief Plik naglowkowy modulu Wydarzenie
*/


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
  /// <summary>
  /// Poprawia wpisana liczba, jezeli byla z zakresu <0,9> to dopisuje 0 przed nia.
  /// </summary>
  /// <param name="liczba">Wpisana liczba</param>
  /// <returns>Zwraca poprawiona liczbe</returns>
  string popraw(int &liczba) {
    if (liczba >= 0 && liczba < 10) {
      return "0" + to_string(liczba);
    }
    return to_string(liczba);
  }
  /// <summary>
  /// Funckaj zmienia na odpowiedni format do wyswietlania w konsoli date i godzine 
  /// </summary>
  /// <returns>Zwraca odpowiedni format do wyswietlania</returns>
  string str() {
    return popraw(rok) + "-" + popraw(miesiac) + "-" + popraw(dzien) + " " + popraw(godzina) + ":" + popraw(minuta) + ":" + popraw(sekunda);
  };


  /// <summary>
  /// Funkcja zmienia na odpowiedni format dla norm ICAL date i godzine
  /// </summary>
  /// <returns>Zwraca odpowiedni format do zapisu</returns>
  string do_zapisu() {
    return popraw(rok) + popraw(miesiac) + popraw(dzien) + "T" + popraw(godzina) + popraw(minuta) + popraw(sekunda) + "Z";
  }
  /// <summary>
  /// Funkcja odpowiada za aktualna date
  /// </summary>
  /// <returns>Zwraca aktualna date</returns>
  static DataZGodzina aktualnaData() {
    return aktualnaPlusDni(0);
  }
  /// <summary>
  /// Funckaj ktora dodaje dni do aktualnej daty
  /// </summary>
  /// <param name="dni">Ile dni chcemy dodac</param>
  /// <returns>Zwraca date i godzine</returns>
  static DataZGodzina aktualnaPlusDni(int dni) {
      time_t czas_m = dodajDni(dni);
      tm* czas = localtime(&czas_m);
      DataZGodzina wynik;
      auto rok = czas->tm_year + 1900;

      auto miesiac = czas->tm_mon + 1;
      auto dzien = czas->tm_mday;
      auto godzina = czas->tm_hour;
      auto minuta = czas->tm_min;
      auto sekunda = czas->tm_sec;

      DataZGodzina dataIgodzina;
      dataIgodzina.rok     = rok;
      dataIgodzina.miesiac = miesiac;
      dataIgodzina.dzien   = dzien;
      dataIgodzina.godzina = godzina;
      dataIgodzina.minuta  = minuta;
      dataIgodzina.sekunda = sekunda;

      return dataIgodzina;
  }

private:
  static time_t dodajDni(int days)
  {
      return time(0)+86400*days;
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
    

    /// <summary>
    /// Funkcja ktora odpowiada za losowanie 26 losowych liczb oraz cyfr
    /// </summary>
    /// <returns>Wylosowane ciag znakow w postaci napisu </returns>
    string Losowanie()
    {

        
        const char Litery[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789";

        string Losowanie;
        const int N = 26;
        string tab;


        for (int w = 0; w < N; w++)
        {
            tab = Litery[rand() % (sizeof(Litery) - 1)];
            Losowanie = Losowanie + tab;
        }

        return Losowanie;
    }


    DataZGodzina created;

    /** \brief Przechowuje zmnienna bool , czy chcemy powtarzac wydarzenie
     */
    Powtarzanie powtarzanie;

    /** \brief Przechowuje zmnienna bool , czy chcemy powtarzac wydarzenie
   */

    /// <summary>
    /// Funkcja ktora odpowiada za wypisanie w konsoli parametrow wydarzenia w odpowiedniej kolejnosci
    /// </summary>
    /// <returns>Ladne wyswietlanie na konsoli</returns>
    string str() {

 return     "\n              WYDARZENIE"
            "\n______________________________________\n"
              "Data rozpoczecia: " + data_start.str() + "\n"
            + "Data zakoncenia: " + data_end.str() + "\n"
            + "Powtarzanie Wydarzenia: " + powtarzanie.stworzWpis() + "\n"
            + "Tytul: " + tytul + "\n"
            + "Notatka: " + notatka + "\n"
            + "Lokalizacja: " + lokalizacja + "\n"
            + "Data stworzenia: " + created.str() + "\n";
    }

};

