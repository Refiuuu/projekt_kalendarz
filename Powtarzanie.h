#pragma once

#include <string>

using namespace std;

enum TypPowtarzania {
  DZIENNIE = 1, TYGODNIOWO = 2, MIESIECZNIE = 3
};

class Powtarzanie {
public:
  bool powtarzaj;
  TypPowtarzania typ;
  string ktoryDzien;

  string stworzWpis();
};
