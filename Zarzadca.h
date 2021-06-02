#pragma once
#include "Wydarzenie.h"
#include <vector>

using namespace std;

/**
* \file Zarzadca.h
* \brief Plik naglowkowy modulu Zarzadca
*/

/// <summary>
/// Zarzadca odpowiada za zarzadzanie programem, tzn (przechowuje liste wydarzen i podaje ja odpowiednio do funkcji)
/// </summary>

class Zarzadca
{
public:
	/** \brief Dodawanie wydarzen na koniec listy
	*/

	/// <summary>
	/// Dodawanie wydarzenia do listy
	/// </summary>
	/// <param name="nowe_wydarzenia">Lista Wydarzen</param>
	void DodajWydarzenia(vector<Wydarzenie> &nowe_wydarzenia);

	/// <summary>
	/// Dodaj wydarzenie
	/// </summary>
	/// <param name="wydarzenia">Wydarzenie</param>
	/// 
	void DodajWydarzenie(Wydarzenie &wydarzenia);

	/** \brief Usuwanie wydarzen z listy
	*/
	void UsunWydarzenia(int numerwydarzenia);

	/** \brief Modyfikowanie wydarzen z listy
	*/
	void Modyfikuj(Wydarzenie wydarzenie, int numer);

	/** \brief Struktura ktora wywoluje zapisana liste wydarzen
	*/
	vector<Wydarzenie> Podajliste();

  /** \brief Filtruje wydarzenia należące do podanego zakresu dat
   */
  vector<Wydarzenie> FiltrujOdDo(DataZGodzina od_data, DataZGodzina do_data);

	/** \brief Funkcja usuwa cala liste wydarzen
	*/
	void Usun(vector<Wydarzenie>& lista);

	void pokazListe(vector<Wydarzenie>& lista);

	void wyswietl(Wydarzenie& wydarzenie);

private:
	/** \brief Funkcja ktora przechowuje liste wydarzen
	*/
	vector<Wydarzenie> lista;

  bool CzyWZakresie(Wydarzenie &w, DataZGodzina &od_data, DataZGodzina &do_data);

};

