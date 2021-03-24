#pragma once
#include "Wydarzenie.h"
#include "Export.h"
#include "Fabryka.h"
#include "Importer.h"
#include <vector>

using namespace std;



class Zarzadca
{
public:

    void dodaj_wydarzenia(vector<Wydarzenie> lista);

	void DodajWydarzenie(Wydarzenie wydarzenia);

	void UsunWydarzenia(int numerwydarzenia);

	void Modyfikuj(Wydarzenie wydarzenie, int numer);

	vector<Wydarzenie> Podajliste();

private:
	vector<Wydarzenie> lista;

};

