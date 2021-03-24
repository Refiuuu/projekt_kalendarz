#include "Fabryka.h"
#include <iostream>
#include <ctime>

#pragma warning(disable : 4996)

Wydarzenie Fabryka::StworzWydarzenie()
{
    Wydarzenie w;

    w.data_start = Data_zapisu_od();
    w.data_end = Data_zapisu_do();
    w.notatka = dodaj_notatke();
    w.tytul = dodaj_tytul();
    w.lokalizacja = dodaj_lokalizacje();
    w.created = AktualnaData();
    return w;
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
    string nazwa;
    cout << "Podaj Tytul swojego wydarzenia:" << "\t";
    cin >> nazwa;
    string  Nazwa = "SUMMARY:" + nazwa;
    return string(Nazwa);
}

string Fabryka::dodaj_notatke()
{
    bool CzyTak = false;
    string nazwa;
    string wybor;
    cout << "Czy chcesz dodac notatke do swjego wydarzenia ? [T/N}" << endl;

    cin >> wybor;
    if (wybor == "T" || wybor =="t")
    {
        cout << "Nizej wpisz swoja notatke:" << endl;
        cin >> nazwa;
    }

    return nazwa;
}

string Fabryka::dodaj_lokalizacje()
{
    string miasto;
    string kraj;

    cout << "Podaj lokalizacje swojego wydarzenia: " << "\n";

    cout << "Miasto: " << "\t"; cin >> miasto;
    cout << endl;
    cout << "Kraj: " << "\t"; cin >> kraj;

    return miasto + "/" + "," + " " + kraj;

}

string Fabryka::dodaj_data()
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

    string Dzien = to_string(dzien);
    string Rok = to_string(rok);
    string Miesiac = to_string(miesiac);

    if (dzien > 0 && dzien < 10)
    {
        Dzien = "0" + to_string(dzien);
    }

    if (miesiac > 0 && miesiac < 10)
    {
        Miesiac = "0" + to_string(miesiac);
    }

    string bla = (Rok + Miesiac + Dzien);

    return bla;
}

string Fabryka::dodaj_godzine()
{
    int godzina;
    int minuta;
    int sekunda;

    cin >> godzina;
    while (godzina >= 24)
    {
        cout << "Nie ma takiej godziny " << "\n";
        cin >> godzina;
    }
    cout << endl;

    cin >> minuta;
    while (minuta >= 60)
    {
        cout << "Nie ma tylu minut " << "\n";
        cin >> minuta;
    }
    cout << endl;

    cin >> sekunda;
    while (sekunda >= 60)
    {
        cout << "Nie ma tylu sekund " << "\n";
        cin >> sekunda;
    }

    string Godzina = to_string(godzina);
    string Minuta = to_string(minuta);
    string Sekunda = to_string(sekunda);

    if (godzina >= 0 && godzina < 10)
    {
        Godzina = "0" + Godzina;
    }

    if (minuta >= 0 && minuta < 10)
    {
        Minuta = "0" + Minuta;
    }

    if (sekunda >= 0 && sekunda < 10)
    {
        Sekunda = "0" + Sekunda;
    }

    string bla = ("T" + Godzina + Minuta + Sekunda + "Z");
    return bla;
}

string Fabryka::Data_zapisu_od()
{
    cout << "Podaj od kiedy chcialbys dodac wydarzenie?" << "\n";
    cout << "Zapisz ja w formacie [np 2021 12 23}" << "\n";
    cout << "Po wpisanym roku wcisnij ENTER etc..." << "\n";

    string a = Fabryka::dodaj_data();
    cout << endl;
    cout << "Podaj od ktorej ma byc to wydarzenie w formacie [23 34 54]: " << "\n";
    cout << "Po wpisanej godzinie wcisnij ENTER etc..." << "\n";
    string b = Fabryka::dodaj_godzine();

    return a + b;
}

string Fabryka::Data_zapisu_do()
{
    cout << "Podaj do kiedy chcialbys dodac wydarzenie?" << "\n";
    cout << "Zapisz ja w formacie [2021 11 1]" << "\n";
    cout << "Po wpisanym roku wcisniej ENTER etc..." << "\n";

    string a = Fabryka::dodaj_data();
    cout << endl;
    cout << "Podaj do ktorej ma byc to wydarzenie w formacie [12 00 00] : " << "\n";
    string b = Fabryka::dodaj_godzine();
    return a + b;
}

string Fabryka::AktualnaData()
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

    Miesiac = to_string(miesiac);
    Dzien = to_string(dzien);
    Godzina = to_string(godzina);
    Minuta = to_string(minuta);
    Sekunda = to_string(sekunda);

    if (miesiac > 0 && miesiac < 10)
    {
        Miesiac = "0" + Miesiac;
    }
    if (dzien > 0 && dzien < 10)
    {
        Dzien = "0" + Dzien;
    }
    if (godzina > 0 && godzina < 10)
    {
        Godzina = "0" + Godzina;
    }
    if (minuta > 0 && minuta < 10)
    {
        Minuta = "0" + Minuta;
    }
    if (sekunda > 0 && sekunda < 10)
    {
        Sekunda = "0" + Sekunda;
    }


    return to_string(rok) + Miesiac + Dzien + "T" + Godzina + Minuta + Sekunda + "Z";
}
