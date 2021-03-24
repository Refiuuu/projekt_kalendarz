#pragma once
#include "Wydarzenie.h"
#include <vector>

using namespace std;

class Zarzadca
{
public:

  void DodajWydarzenia(vector<Wydarzenie> &nowe_wydarzenia);

	void DodajWydarzenie(Wydarzenie &wydarzenia);

	void UsunWydarzenia(int numerwydarzenia);

	void Modyfikuj(Wydarzenie wydarzenie, int numer);

	vector<Wydarzenie> Podajliste();

private:
	vector<Wydarzenie> lista;

};

