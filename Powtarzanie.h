#pragma once

#include <string>

/**
* \file Powtarzanie.h
* \brief Plik naglowkowy modulu Powtarzanie
*/

using namespace std;
/// <summary>
/// Enumeracja ktora odpowiada za przypisanie odpowiedniego powtarzania odpowiednio do wpisanej cyfry
/// </summary>
enum TypPowtarzania {
  DZIENNIE = 1, TYGODNIOWO = 2, MIESIECZNIE = 3
};
/// <summary>
/// Klasa ktora odpowiada za wszystko zwiazane z powtarzaniem.
/// </summary>
class Powtarzanie {
public:

   /** \brief Zmienna bool powtarzaj odpowiada za zapis powtarzania do pliku
   */
  bool powtarzaj = false;
  /** \brief Typ powtarzania
  */
  TypPowtarzania typ;
  /** \brief Ktory dzien powtarzania
  */
  string ktoryDzien;

  /// <summary>
  /// Funksja ktora tworzy zakodowany dla formatu ICAL wpis do pliku
  /// </summary>
  /// <returns>Powtarzanie w postaci napisu</returns>
  string stworzWpis();

};
