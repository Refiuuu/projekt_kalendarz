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

void Zarzadca::Usun(vector<Wydarzenie>& wydarzenie)
{
    lista.clear();
}

bool Zarzadca::CzyWZakresie(Wydarzenie &w, DataZGodzina &od_data, DataZGodzina &do_data) {
    auto teraz = DataZGodzina::aktualnaData();

    auto data_wydarzenia = w.data_start.do_zapisu();
    auto od_str = od_data.do_zapisu();
    auto do_str = do_data.do_zapisu();

    return data_wydarzenia >= od_str && data_wydarzenia <= do_str;
}

vector<Wydarzenie> Zarzadca::FiltrujOdDo(DataZGodzina od_data, DataZGodzina do_data) {
  auto odfiltowane = vector<Wydarzenie>();
  for (auto wydarzenie : lista) {
    if (CzyWZakresie(wydarzenie, od_data, do_data)) {
        odfiltowane.push_back(wydarzenie);
    }
  }
  return odfiltowane;
}


