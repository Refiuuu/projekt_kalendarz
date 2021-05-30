#include "Powtarzanie.h"

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

