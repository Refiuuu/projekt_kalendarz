#include "Powtarzanie.h"
/**
* \file Powtarzanie.cpp
* \brief Plik zrodlowy modulu Powtarzanie
*/

/// <summary>
/// Funkcja ktora tworzy wpis powtarzania odpowiednio dla formatu ICAL
/// </summary>
/// <returns>Zwraca napis w ktorym sa informacje o powtarzaniu</returns>
string Powtarzanie::stworzWpis() {
  if (this->powtarzaj) {
    switch (this->typ) {
      case DZIENNIE:
            return "DAILY;" + this->ktoryDzien;
        break;
      case TYGODNIOWO:
            return "WEEKLY;" + this->ktoryDzien;
        break;
      case MIESIECZNIE:
            return "MONTHLY;" + this->ktoryDzien;
        break;
    }
  } else {
    return "";
  }
}

