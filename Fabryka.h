#pragma once

#include "Wydarzenie.h"
#include "Powtarzanie.h"
#include <string>


/**
* \file Fabryka.h
* \brief Plik naglowkowy modulu Fabryka
*/



using namespace std;
/// <summary>
///  Klasa odpowiada za tworzenie i modyfikowaanie wydarzen.
/// </summary>
class Fabryka
{
public:

    /// <summary>
    /// Funkcja odpowiada za tworzenie wydarzenia od podstaw.
    /// </summary>
    /// <returns> liste wydarzen</returns>
    Wydarzenie StworzWydarzenie();

    /// <summary>
    /// Funkcja odpowiada za pelna modyfikacje wydarzenia 
    /// </summary>
    /// <param name="oryginalneWydarzenie">Wydarzenie ktore ma byc modyf</param>
    /// <returns>Zwraca zmieniona liste</returns>
 
    Wydarzenie modyfikuj_wydarzenie(const Wydarzenie &oryginalneWydarzenie);
    /// <summary>
    /// Funkcja odpowiada za dodanie daty przez uzytkownika
    /// </summary>
    /// <returns>Zwraca date</returns>
    DataZGodzina dodaj_data();
    /// <summary>
    /// Funkcja odpowiada za dodanie godziny przez uzytkownika
    /// </summary>
    /// <returns></returns>
    DataZGodzina dodaj_godzine();
    /// <summary>
    /// Funckaj odpowiada za polaczenie daty i godziny w calosc
    /// </summary>
    /// <returns>Zwraca zlaczona date i godzine</returns>
    DataZGodzina Data_zapisu_od();
    /// <summary>
    /// Funkcja odpowiada za polaczenie daty i godziny w calosc
    /// </summary>
    /// <returns>Zwraca zlaczona date i godzine</returns>
    DataZGodzina Data_zapisu_do();


private:
    int rok;
    int miesiac;
    int dzien;
    int godzina;
    int minuta;
    int sekunda;
    string Miesiac;
    string Dzien;
    string Godzina;
    string Minuta;
    string Sekunda;
    /// <summary>
    /// Sprawdza czy rok jest przestepny
    /// </summary>
    /// <param name="rok">Podany rok</param>
    /// <returns>Zwraca bool czy rok jest przestepny</returns>
    bool czy_przestepny(int rok);
    /// <summary>
    /// Funckcja ktora dodaje notatke do wydarzenia
    /// </summary>
    /// <returns>Zwraca notatke jako napis</returns>
    string dodaj_notatke();
    /// <summary>
    /// Funkcja ktora dodaje lokalizacje do wydarzenia
    /// </summary>
    /// <returns>Zwraca lokalizacje jako napis</returns>
    string dodaj_lokalizacje();
    /// <summary>
    /// Funkcja ktora dodaj tytul do wydarzenia
    /// </summary>
    /// <returns>zwraca lokalizacje jako napis</returns>
    string dodaj_tytul();
    /// <summary>
    /// Funkcja ktora odpowiada za decyzje o powtarzaniu wydarzenia
    /// </summary>
    /// <returns>Zwraca powtarzanie w postaci kodu</returns>
    Powtarzanie Zasada();
    /// <summary>
    /// Funkcja ktora wykorzystuje powtarzanie do sprawdzania ktory dzien ma sie powtarzac
    /// </summary>
    /// <returns>Zwraca zapis kodu w zaleznosci jaki dzien wpisalismy</returns>
    string Jaki_dzien();


};
