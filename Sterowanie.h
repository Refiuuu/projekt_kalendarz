#pragma once

#include <string>


/**
* \file Sterowanie.h
* \brief Plik naglowkowy modulu Sterowanie
*/

using namespace std;
/// <summary>
/// Funkcja ktora pobiera wpisany napis z konsoli
/// </summary>
/// <param name="wiadomosc">Co ma zostac wypisane w konsoli</param>
/// <returns>Zwraca wpisany w konsoli napis</returns>

string pobierzString(const char* wiadomosc);
/// <summary>
/// Funkcja ktora pobiera wpisany znak z konsoli
/// </summary>
/// <param name="wiadomosc">Co ma zostac wypisane w konsoli</param>
/// <returns></returns>
char pobierzZnak(const char* wiadomosc);
/// <summary>
/// Funkcja ktora pobiera wpisana liczbe z konsoli
/// </summary>
/// <param name="wiadomosc">Co ma zostac wypisane w konsoli</param>
/// <returns></returns>
int pobierzLiczbe(const char* wiadomosc);
/// <summary>
/// Funkcja ktora pobiera wpisany numer z konsoli
/// </summary>
/// <param name="wiadomosc">Co ma zostac wypisane w konsoli</param>
/// <param name="max">Okresla wartosc maksymalna do wpisania</param>
/// <returns></returns>
int pobierzNumer(const char* wiadomosc, int max);

/// <summary>
/// Funkcja ktora pobiera decyzja Tak/Nie
/// </summary>
/// <param name="wiadomosc">Co ma zostac wypisane w konsoli</param>
/// <returns>Zwraca bool decyzji</returns>
bool takCzyNie(const char* wiadomosc);
