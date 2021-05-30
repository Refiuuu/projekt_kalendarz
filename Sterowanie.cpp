#include "Sterowanie.h"
#include <iostream>

string pobierzString(const char* wiadomosc) {
    char* nazwa = new char[256];
    cout << wiadomosc;

    cin.getline(nazwa, 256);

    return string(nazwa);    
}

char pobierzZnak(const char* wiadomosc) {
    char* nazwa = new char[256];
    cout << wiadomosc;

    cin.getline(nazwa, 256);

    return nazwa[0];
}

int pobierzLiczbe(const char* wiadomosc) {
    char* nazwa = new char[256];
    cout << wiadomosc;

    cin.getline(nazwa, 256);

    return atoi(nazwa);
}

bool takCzyNie(const char* wiadomosc) {
  char tcn = pobierzZnak(wiadomosc);
  while (tcn != 'T' && tcn != 'N') { 
    tcn = pobierzZnak("Prosze wybrac opcje [T/N]: \t");
  }
  if (tcn == 'T') return 1;
  else return 0;
}

int pobierzNumer(const char* wiadomosc, int max) {
    int element;
    do {
      element = pobierzLiczbe(wiadomosc);
    } while (element <= 0 && element > max);
    return element;
}
