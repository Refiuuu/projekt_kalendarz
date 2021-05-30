#pragma once

#include <string>

using namespace std;

enum TypPowtarzania {
  DZIENNIE = 1, TYGODNIOWO = 2, MIESIECZNIE = 3
};
/// <summary>
/// Powtarzanie odpowiada za decyzje o zapisie powtarzania w pliku.
/// </summary>
class Powtarzanie {
public:
  bool powtarzaj = false;
  TypPowtarzania typ;
  string ktoryDzien;


  string stworzWpis();

};
