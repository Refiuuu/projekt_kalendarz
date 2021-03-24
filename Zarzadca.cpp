#include "Zarzadca.h"

void Zarzadca::DodajWydarzenia(vector<Wydarzenie> &nowe_wydarzenia)
{
  for (auto nowe : nowe_wydarzenia) {
    DodajWydarzenie(nowe);
  }
}

void Zarzadca::DodajWydarzenie(Wydarzenie &wydarzenia)
{
  lista.push_back(wydarzenia);
}

void Zarzadca::UsunWydarzenia(int numerwydarzenia)
{
  numerwydarzenia = numerwydarzenia - 1;
  if (numerwydarzenia < lista.size() && numerwydarzenia >= 0) {
    auto pozycja = lista.begin() + numerwydarzenia;
    lista.erase(pozycja);
  }
}

void Zarzadca::Modyfikuj(Wydarzenie wydarzenie, int numer)
{
  numer = numer - 1;
  if (numer < lista.size() && numer >= 0) {
    lista.at(numer) = wydarzenie;
  }
}

vector<Wydarzenie> Zarzadca::Podajliste()
{
	return lista;
}
