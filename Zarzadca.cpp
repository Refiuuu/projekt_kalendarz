#include "Zarzadca.h"

/**
* \file  Zarzadca.cpp
* \brief Plik zrodlowy modulu Zatrzadca
*/


/// <summary>
/// Funkcja ktora przekazuje wydarzenia
/// </summary>
/// <param name="nowe_wydarzenia">Wydarzenie do przekazania </param>
void Zarzadca::DodajWydarzenia(vector<Wydarzenie> &nowe_wydarzenia)
{
  for (auto nowe : nowe_wydarzenia) {
    DodajWydarzenie(nowe);
  }
}


/// <summary>
/// Funckja ktora dodaje wydarzenia na koniec listy
/// </summary>
/// <param name="wydarzenia">Wydarzenie ktora ma byc dodane na koniec listy</param>

void Zarzadca::DodajWydarzenie(Wydarzenie &wydarzenia)
{
  lista.push_back(wydarzenia);
}

/// <summary>
/// Funkcja ktora odpowiada za usuwanie wydarzenia wskazanego przez uzytkownika
/// </summary>
/// <param name="numerwydarzenia">Numer wydarzenia do usuniecia</param>
void Zarzadca::UsunWydarzenia(int numerwydarzenia)
{
  numerwydarzenia = numerwydarzenia - 1;
  if (numerwydarzenia < lista.size() && numerwydarzenia >= 0) {
    auto pozycja = lista.begin() + numerwydarzenia;
    lista.erase(pozycja);
  }
}

/// <summary>
/// Wyswietla podane wydarzenie
/// </summary>
/// <param name="wydarzenie">Wydarzenie</param>
void Zarzadca::wyswietl(Wydarzenie &wydarzenie) {
    cout << wydarzenie.str() << endl;
}

/// <summary>
/// Wyswietla liste wydarzen
/// </summary>
/// <param name="lista">Lista</param>
void Zarzadca::pokazListe(vector<Wydarzenie>& lista) {
    for (int i = 1; i <= lista.size(); i++) {
        cout << i << ": " << lista.at(i - 1).str() << endl;
    }
}

/// <summary>
/// Funkcja odpowiadajaca za modyfikowanie wskazanego wydarzenia z listy
/// </summary>
/// <param name="wydarzenie">Wydarzenie</param>
/// <param name="numer">Numer wydarzenia</param>
void Zarzadca::Modyfikuj(Wydarzenie wydarzenie, int numer)
{
  numer = numer - 1;
  if (numer < lista.size() && numer >= 0) {
    lista.at(numer) = wydarzenie;
  }
}

/// <summary>
/// Podanie listy zapisanych wydarzen
/// </summary>
/// <returns>Zwraca liste</returns>
vector<Wydarzenie> Zarzadca::Podajliste()
{
	return lista;
}


/// <summary>
/// Funkcja ktora usuwa wszystkie dane z listy
/// </summary>
/// <param name="wydarzenie">Lista wydarzen</param>
void Zarzadca::Usun(vector<Wydarzenie>& wydarzenie)
{
    lista.clear();
}

/// <summary>
/// Funckja ktora sprawdza czy data rozpoczecia wydarzenia miesci sie w ustawionym zakresie
/// </summary>
/// <param name="w">Wydarzenie</param>
/// <param name="od_data">Data rozpoczecia wydarzenia</param>
/// <param name="do_data">Data zakonczenia wydarzenia</param>
/// <returns></returns>
bool Zarzadca::CzyWZakresie(Wydarzenie &w, DataZGodzina &od_data, DataZGodzina &do_data) {
    auto teraz = DataZGodzina::aktualnaData();

    auto data_wydarzenia = w.data_start.do_zapisu();
    auto od_str = od_data.do_zapisu();
    auto do_str = do_data.do_zapisu();

    return data_wydarzenia >= od_str && data_wydarzenia <= do_str;
}

/// <summary>
/// Funkcja ktora filtruje wydarzenia dla podanego zakresu
/// </summary>
/// <param name="od_data">Data rozpoczecia wydarzenia</param>
/// <param name="do_data">Data zakonczenia wydarzenia</param>
/// <returns>Zwraca odfiltrowana liste</returns>

vector<Wydarzenie> Zarzadca::FiltrujOdDo(DataZGodzina od_data, DataZGodzina do_data) {
  auto odfiltowane = vector<Wydarzenie>();
  for (auto wydarzenie : lista) {
    if (CzyWZakresie(wydarzenie, od_data, do_data)) {
        odfiltowane.push_back(wydarzenie);
    }
  }
  return odfiltowane;
}


