#include "Fabryka.h"
#include "Powtarzanie.h"
#include "Sterowanie.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

#pragma warning(disable : 4996)

Wydarzenie Fabryka::StworzWydarzenie()
{
    Wydarzenie w;

    w.data_start = Data_zapisu_od();
    w.data_end = Data_zapisu_do();
    w.powtarzanie = Zasada();
    w.notatka = dodaj_notatke();
    w.tytul = dodaj_tytul();
    w.lokalizacja = dodaj_lokalizacje();
    w.created = AktualnaData();
    return w;
}

Wydarzenie Fabryka::modyfikuj_wydarzenie(const Wydarzenie &oryginalneWydarzenie) {
    Wydarzenie nowe;
    nowe.data_start = oryginalneWydarzenie.data_start;
    nowe.data_end = oryginalneWydarzenie.data_end;
    nowe.tytul = oryginalneWydarzenie.tytul;
    nowe.notatka = oryginalneWydarzenie.notatka;
    nowe.lokalizacja = oryginalneWydarzenie.lokalizacja;
    nowe.created = oryginalneWydarzenie.created;

    auto menu_modyfikacji =
      "Co chcesz Modyfikowac ?\n" 
      "1.Data rozpoczecia.\n"
      "2.Data zakonczenia.\n"
      "3.Tytul wydarzenia.\n"
      "4.Notatka.\n"
      "5.Lokalizacja.\n"
      "6.Zakoncz edycje.\n"
      "Podaj numer akcji:\t";

    while (true)
    {
        auto wpisz = pobierzLiczbe(menu_modyfikacji);
        if (wpisz == 1)
        {
          nowe.data_start = Data_zapisu_od();
        } 
        else if (wpisz == 2)
        {
          nowe.data_end = Data_zapisu_do();
        } 
        else if (wpisz == 3)
        {
          nowe.tytul = dodaj_tytul();
        } 
        else if (wpisz == 4)
        {
          nowe.notatka = dodaj_notatke();
        } 
        else if (wpisz == 5)
        {
          nowe.lokalizacja = dodaj_lokalizacje();
        }
        else if (wpisz == 6)
        {
            break;
        }
        else {
          cout << "Nie ma takiej opcji.\n\n";
        }
    }
    return nowe;
}

bool Fabryka::czy_przestepny(int rok)
{
    if ((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0) return true;
    else return false;
}

/*
void Kalendarz::wyswietl()
{
    cout << "Podaj Rok do wyœwietlenia i numer miesiac [1 -- 12] " << endl;
    cin >> rok;
    cin >> miesiac;
    cout << endl << endl;

    //Tutaj liczenie pierwszego dnia roku
    int x, y, z;

    x = (rok - 1) / 4;
    y = (rok - 1) / 100;
    z = (rok - 1) / 400;

    PierwszyDzienMiesiac = (rok + x - y + z) / 7;

    cout << rok << endl;


    //Tutaj wypisywanie miesiecy;
    if (miesiac == 1)
    {
        IleDni = 31;
        cout << " Styczen " << "   " << " 31 dni" << endl;
    }
    if (miesiac == 2)
    {
        if (czy_przestepny(rok) == true)
        {
            IleDni = 29;
            cout << " Luty " << "   " << " 29 dni" << endl;
        }
        else
        {
            IleDni = 28;
            cout << " Luty " << "   " << " 28 dni" << endl;
        }
    }
    if (miesiac == 3)
    {
        IleDni = 31;
        cout << " Marzec " << "   " << " 31 dni" << endl;
    }
    if (miesiac == 4)
    {
        IleDni = 30;
        cout << " Kwiecien " << "   " << " 30 dni" << endl;
    }
    if (miesiac == 5)
    {
        IleDni = 31;
        cout << " Maj " << "   " << " 31 dni" << endl;
    }
    if (miesiac == 6)
    {
        IleDni = 30;
        cout << " Czerwiec " << "   " << " 30 dni" << endl;
    }
    if (miesiac == 7)
    {
        IleDni = 31;
        cout << " Lipiec " << "   " << " 31 dni" << endl;
    }
    if (miesiac == 8)
    {
        IleDni = 31;
        cout << " Sierpien " << "   " << " 31 dni" << endl;
    }
    if (miesiac == 9)
    {
        IleDni = 30;
        cout << " Wrzesien " << "   " << " 30 dni" << endl;
    }
    if (miesiac == 10)
    {
        IleDni = 31;
        cout << " Pazdziernik " << "   " << " 31 dni" << endl;
    }
    if (miesiac == 11)
    {
        IleDni = 30;
        cout << " Listopad " << "   " << " 30 dni" << endl;
    }
    if (miesiac == 12)
    {
        IleDni = 31;
        cout << " Grudzien " << "   " << " 31 dni" << endl;
    }
}
*/

string Fabryka::dodaj_tytul()
{
    return pobierzString("Podaj Tytul swojego wydarzenia: ");
}

string Fabryka::dodaj_notatke() 
{
    if (takCzyNie("Czy chcesz dodac notatke do swojego wydarzenia? [T/N]"))
    {
        return pobierzString("Nizej wpisz swoja notatke: ");
    }
    else
    {
        return "Brak Notatki";
    }
}

string Fabryka::dodaj_lokalizacje()
{
    if (takCzyNie("Czy chcesz dodac lokalizacje do swojego wydarzenia? [T/N] \t "))
    {
        auto miasto = pobierzString("Podaj lokalizacje swojego wydarzenia:\nMiasto: ");
        auto kraj = pobierzString("Kraj: ");
        return miasto + "/, " + kraj;
    }
    else
    {
        return "Brak lokalizacji";
    }
    
}

DataZGodzina Fabryka::dodaj_data()
{
    cin >> rok;

    while (rok < 1)
    {
        cout << "Podaj rok z naszej ery" << "\n";
        cin >> rok;
    }

    cin >> miesiac;
    while (miesiac > 12)
    {
        cout << "Nie ma takiego miesiaca " << "\n";
        cin >> miesiac;
    }

    if (miesiac == 1)
    {
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
            cin >> dzien;
        }
    }

    if (miesiac == 2)
    {
        if (czy_przestepny(rok) == true)
        {
            cin >> dzien;
            while (dzien >= 29)
            {
                cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
                cin >> dzien;
            }
        }
        else
        {
            cin >> dzien;
            while (dzien >= 28)
            {
                cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
                cin >> dzien;
            }
        }
    }

    if (miesiac == 3)
    {
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
            cin >> dzien;
        }
    }

    if (miesiac == 4)
    {
        cin >> dzien;
        while (dzien > 30)
        {
            cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
            cin >> dzien;
        }
    }

    if (miesiac == 5)
    {
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
            cin >> dzien;
        }

    }

    if (miesiac == 6)
    {
        cin >> dzien;
        while (dzien > 30)
        {
            cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
            cin >> dzien;
        }
    }

    if (miesiac == 7)
    {
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
            cin >> dzien;
        }
    }

    if (miesiac == 8)
    {
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
            cin >> dzien;
        }
    }

    if (miesiac == 9)
    {
        cin >> dzien;
        while (dzien > 30)
        {
            cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
            cin >> dzien;
        }
    }

    if (miesiac == 10)
    {
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
            cin >> dzien;
        }
    }

    if (miesiac == 11)
    {
        cin >> dzien;
        while (dzien > 30)
        {
            cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
            cin >> dzien;
        }
    }

    if (miesiac == 12)
    {
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu: " << "\n";
            cin >> dzien;
        }
    }

    DataZGodzina data;
    data.rok = rok;
    data.miesiac = miesiac;
    data.dzien = dzien;

    return data;
}

DataZGodzina Fabryka::dodaj_godzine()
{
    int godzina;
    int minuta;
    int sekunda;

    cin >> godzina;
    
    while (godzina >=24)
    {
        cout << "Nie ma takiej godziny " << "\n";
        cin >> godzina;
    }

    cin >> minuta;
    while (minuta >= 60)
    {
        cout << "Nie ma tylu minut " << "\n";
        cin >> minuta;
    }

    cin >> sekunda;
    while (sekunda >= 60)
    {
        cout << "Nie ma tylu sekund " << "\n";
        cin >> sekunda;
    }
    cin.ignore();

    DataZGodzina data;
    data.godzina = godzina;
    data.minuta = minuta;
    data.sekunda = sekunda;
    return data;
}

DataZGodzina Fabryka::Data_zapisu_od()
{
    cout << "Podaj od kiedy chcialbys dodac wydarzenie?" << "\n";
    cout << "Zapisz ja w formacie [np 2021 12 23}" << "\n";
    cout << "Po wpisanym roku wcisnij ENTER etc..." << "\n";

    auto data = Fabryka::dodaj_data();
    cout << endl;
    cout << "Podaj od ktorej ma byc to wydarzenie w formacie [13 30 00]: " << "\n";
    cout << "Po wpisanej godzinie wcisnij ENTER etc..." << "\n";
    auto godzina = Fabryka::dodaj_godzine();

    DataZGodzina dataIgodzina;
    dataIgodzina.rok     = data.rok;
    dataIgodzina.miesiac = data.miesiac;
    dataIgodzina.dzien   = data.dzien;
    dataIgodzina.godzina = godzina.godzina;
    dataIgodzina.minuta  = godzina.minuta;
    dataIgodzina.sekunda = godzina.sekunda;

    return dataIgodzina;
}

DataZGodzina Fabryka::Data_zapisu_do()
{
    cout << "Podaj do kiedy chcialbys dodac wydarzenie?" << "\n";
    cout << "Zapisz ja w formacie [2021 05 17]" << "\n";
    cout << "Po wpisanym roku wcisniej ENTER etc..." << "\n";
    auto data = Fabryka::dodaj_data();

    cout << endl;
    cout << "Podaj do ktorej ma byc to wydarzenie w formacie [12 00 00] : " << "\n";
    auto godzina = Fabryka::dodaj_godzine();

    DataZGodzina dataIgodzina;
    dataIgodzina.rok     = data.rok;
    dataIgodzina.miesiac = data.miesiac;
    dataIgodzina.dzien   = data.dzien;
    dataIgodzina.godzina = godzina.godzina;
    dataIgodzina.minuta  = godzina.minuta;
    dataIgodzina.sekunda = godzina.sekunda;

    return dataIgodzina;
}

DataZGodzina Fabryka::AktualnaData()
{
    time_t czas_m;
    time(&czas_m);
    tm* czas = localtime(&czas_m);
    rok = czas->tm_year + 1900;

    miesiac = czas->tm_mon + 1;
    dzien = czas->tm_mday;
    godzina = czas->tm_hour;
    minuta = czas->tm_min;
    sekunda = czas->tm_sec;

    DataZGodzina dataIgodzina;
    dataIgodzina.rok     = rok;
    dataIgodzina.miesiac = miesiac;
    dataIgodzina.dzien   = dzien;
    dataIgodzina.godzina = godzina;
    dataIgodzina.minuta  = minuta;
    dataIgodzina.sekunda = sekunda;

    return dataIgodzina;
}

string Fabryka::Jaki_dzien()
{
    auto dzien = pobierzString("Wpisz nazwe dnia tygodnia ktory ma sie powtarzac (bez polskich znakow)  np [sroda]\n");

    if (dzien == "poniedzialek")
    {
        return "BYDAY=MO";
    }
    if (dzien == "wtorek")
    {
        return "BYDAY=TU";
    }
    if (dzien == "sroda")
    {
        return "BYDAY=TH";
    }
    if (dzien == "czwartek")
    {
        return "BYDAY=WE";
    }
    if (dzien == "piatek")
    {
        return "BYDAY=FR";
    }
    if (dzien == "sobota")
    {
        return "BYDAY=SA";
    }
    if (dzien == "niedziela")
    {
        return "BYDAY=SU";
    }

    return "error";
}

Powtarzanie Fabryka::Zasada()
{
    Powtarzanie powtarzanie;
    int cyfra = -1;

    if (takCzyNie("Czy chcesz dodac powtarzanie wydarzenia? [T/N]")) {
        powtarzanie.powtarzaj = true;
        cyfra = pobierzLiczbe("Wbierz sposob powtarzania sie wydarzenia\n1.Dziennie\n2.tygodniowo\n3.Miesiecznie\n");

        while (cyfra < 1 || cyfra > 3) {
          cyfra = pobierzLiczbe("Wbierz sposob powtarzania sie wydarzenia\n1.Dziennie\n2.tygodniowo\n3.Miesiecznie\n");
        }
        powtarzanie.typ = static_cast<TypPowtarzania>(cyfra);

        do {
          if (powtarzanie.ktoryDzien == "error") {
            cout << "Nie ma takiego dnia\n";
          }
          powtarzanie.ktoryDzien = Jaki_dzien();
        } while (powtarzanie.ktoryDzien == "error");
    }
    else {
      powtarzanie.powtarzaj = false;
    }

    return powtarzanie;
}

