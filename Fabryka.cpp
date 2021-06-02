#include "Fabryka.h"
#include "Powtarzanie.h"
#include "Sterowanie.h"
#include "Zarzadca.h"
#include <cstdlib>
#include <iostream>
#include <string>

/**
* \file Fabryka.cpp
* \brief Plik zrodlowy modulu Fabryka
*/



/// <summary>
/// Tworzenie jednego wydarzenia o zapisanych unikatowych parametrach
/// </summary>
/// <returns>Zwtraca zapisane parametry dla danego wydarzenia</returns>
Wydarzenie Fabryka::StworzWydarzenie()
{
    Wydarzenie w;

    w.data_start = Data_zapisu_od();
    w.data_end = Data_zapisu_do();
    system("cls");
    w.powtarzanie = Zasada();
    system("cls");
    w.notatka = dodaj_notatke();
    system("cls");
    w.tytul = dodaj_tytul();
    system("cls");
    w.lokalizacja = dodaj_lokalizacje();
    system("cls");
    w.created = DataZGodzina::aktualnaData();
    return w;
}
/// <summary>
/// Funkcja odpowiada za modyfikacje wybranego wydarzenia
/// </summary>
/// <param name="oryginalneWydarzenie">Wybrane wydarzenie do modyfikacji</param>
/// <returns></returns>
Wydarzenie Fabryka::modyfikuj_wydarzenie(const Wydarzenie &oryginalneWydarzenie) {
    Wydarzenie nowe;
    Zarzadca zarzadca;
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
          system("cls");
          nowe.data_start = Data_zapisu_od();
        } 
        else if (wpisz == 2)
        {
          system("cls");
          nowe.data_end = Data_zapisu_do();
        } 
        else if (wpisz == 3)
        {
          system("cls");
          nowe.tytul = dodaj_tytul();
        } 
        else if (wpisz == 4)
        {
          system("cls");
          nowe.notatka = dodaj_notatke();
        } 
        else if (wpisz == 5)
        {
          system("cls");
          nowe.lokalizacja = dodaj_lokalizacje();
        }
        else if (wpisz == 6)
        {
            system("cls");
            break;
        }
        else {
          cout << "Nie ma takiej opcji.\n\n";
        }
    }
    return nowe;
}
/// <summary>
/// Funkcja sprawdza czy podany rok jest przestepny
/// </summary>
/// <param name="rok">Podany rok</param>
/// <returns></returns>
bool Fabryka::czy_przestepny(int rok)
{
    if ((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0) return true;
    else return false;
}
/// <summary>
/// Funkcja odpowiada za tworzenie tytulu
/// </summary>
string Fabryka::dodaj_tytul()
{
    return pobierzString("Podaj Tytul swojego wydarzenia: ");
}

/// <summary>
/// Funkcja ta odpowiada tworzenie notatki
/// </summary>
string Fabryka::dodaj_notatke() 
{
    if (takCzyNie("Czy chcesz dodac notatke do swojego wydarzenia? [T/N]  "))
    {
        return pobierzString("Nizej wpisz swoja notatke: ");
    }
    else
    {
        return "Brak Notatki";
    }
}

/// <summary>
/// Funkcja ta odpowiada tworzenie lokalizacji
/// </summary>
string Fabryka::dodaj_lokalizacje()
{
    if (takCzyNie("Czy chcesz dodac lokalizacje do swojego wydarzenia? [T/N]  "))
    {
        auto miasto = pobierzString("Podaj lokalizacje swojego wydarzenia:\nMiasto: ");
        auto kraj = pobierzString("Kraj: ");
        return miasto + "\, " + kraj;
    }
    else
    {
        return "Brak lokalizacji";
    }
    
}

/// <summary>
/// Funkcja ta odpowiada tworzenie daty
/// </summary>

DataZGodzina Fabryka::dodaj_data()
{

    cout << "ROK:  ";
    cin >> rok;
    auto aktualnyRok = DataZGodzina::aktualnaData().rok;
    while (rok < aktualnyRok)
    {
        cout << "Podaj rok:  ";
        cin >> rok;
    }

    cout << "MIESIAC:  ";
    cin >> miesiac;

    while (miesiac > 12)
    {
        cout << "Nie ma takiego miesiaca:  ";
        cin >> miesiac;
    }

    if (miesiac == 1)
    {
        cout << "DZIEN:  ";
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu:  ";
            cin >> dzien;
        }
    }

    if (miesiac == 2)
    {
        if (czy_przestepny(rok) == true)
        {
            cout << "DZIEN:  ";
            cin >> dzien;
            while (dzien >= 29)
            {
                cout << "Nie ma tylu dni w tym miesiacu:  ";
                cin >> dzien;
            }
        }
        else
        {
            cout << "DZIEN:  ";
            cin >> dzien;
            while (dzien >= 28)
            {
                cout << "Nie ma tylu dni w tym miesiacu:  ";
                cin >> dzien;
            }
        }
    }

    if (miesiac == 3)
    {
        cout << "DZIEN:  ";
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu:  ";
            cin >> dzien;
        }
    }

    if (miesiac == 4)
    {
        cout << "DZIEN:  ";
        cin >> dzien;
        while (dzien > 30)
        {
            cout << "Nie ma tylu dni w tym miesiacu:  ";
            cin >> dzien;
        }
    }

    if (miesiac == 5)
    {
        cout << "DZIEN:  ";
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu:  ";
            cin >> dzien;
        }

    }

    if (miesiac == 6)
    {
        cout << "DZIEN:  ";
        cin >> dzien;
        while (dzien > 30)
        {
            cout << "Nie ma tylu dni w tym miesiacu:  ";
            cin >> dzien;
        }
    }

    if (miesiac == 7)
    {
        cout << "DZIEN:  ";
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu: ";
            cin >> dzien;
        }
    }

    if (miesiac == 8)
    {
        cout << "DZIEN:  ";
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu:  ";
            cin >> dzien;
        }
    }

    if (miesiac == 9)
    {
        cout << "DZIEN:  ";
        cin >> dzien;
        while (dzien > 30)
        {
            cout << "Nie ma tylu dni w tym miesiacu:  ";
            cin >> dzien;
        }
    }

    if (miesiac == 10)
    {
        cout << "DZIEN:  ";
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu:  ";
            cin >> dzien;
        }
    }

    if (miesiac == 11)
    {
        cout << "DZIEN:  ";
        cin >> dzien;
        while (dzien > 30)
        {
            cout << "Nie ma tylu dni w tym miesiacu:  ";
            cin >> dzien;
        }
    }

    if (miesiac == 12)
    {
        cout << "DZIEN:  ";
        cin >> dzien;
        while (dzien > 31)
        {
            cout << "Nie ma tylu dni w tym miesiacu:  ";
            cin >> dzien;
        }
    }

    DataZGodzina data;
    data.rok = rok;
    data.miesiac = miesiac;
    data.dzien = dzien;

    return data;
}

/// <summary>
/// Funkcja ta odpowiada tworzenie godziny
/// </summary>
DataZGodzina Fabryka::dodaj_godzine()
{
    int godzina;
    int minuta;
    int sekunda;

    cout << "GODZINA:  ";
    cin >> godzina;

    while (godzina >= 24)
    {
        cout << "Nie ma takiej godziny:  ";
        cin >> godzina;
    }
    cout << "MINUTA:  ";
    cin >> minuta;
    while (minuta >= 60)
    {
        cout << "Nie ma tylu minut:  ";
        cin >> minuta;
    }
    cout << "SEKUNDA:  ";
    cin >> sekunda;
    while (sekunda >= 60)
    {
        cout << "Nie ma tylu sekund:  ";
        cin >> sekunda;
    }
    cin.ignore();

    DataZGodzina data;
    data.godzina = godzina;
    data.minuta = minuta;
    data.sekunda = sekunda;
    return data;
}

/// <summary>
/// Funkcja ta odpowiada zlaczenie w jedna calosc daty i godziny od kiedy ma trwac wydarzenie 
/// </summary>
DataZGodzina Fabryka::Data_zapisu_od()
{
    cout << "Podaj od kiedy chcialbys dodac wydarzenie?" << "\n";
    cout << "Zapisz ja w formacie [np 2021 12 23][Rok Miesiac Dzien]" << "\n";
    cout << "Po wpisanym roku wcisnij ENTER etc..." << "\n";

    auto data = Fabryka::dodaj_data();

    cout << endl;
    cout << "Podaj od ktorej ma byc to wydarzenie w formacie [13 30 00][Godzina Minuta Sekunda]" << "\n";
    cout << "Po wpisanej godzinie wcisnij ENTER etc..." << "\n";
    auto godzina = Fabryka::dodaj_godzine();

    DataZGodzina dataIgodzina;
    dataIgodzina.rok = data.rok;
    dataIgodzina.miesiac = data.miesiac;
    dataIgodzina.dzien = data.dzien;
    dataIgodzina.godzina = godzina.godzina;
    dataIgodzina.minuta = godzina.minuta;
    dataIgodzina.sekunda = godzina.sekunda;

    return dataIgodzina;
}

/// <summary>
/// Funkcja ta odpowiada zlaczenie w jedna calosc daty i godziny do kiedy ma trwac wydarzenie 
/// </summary>
DataZGodzina Fabryka::Data_zapisu_do()
{
    cout << "\nPodaj do kiedy chcialbys dodac wydarzenie?" << "\n";
    cout << "Zapisz ja w formacie [2021 05 17][Rok Miesiac Dzien]" << "\n";
    cout << "Po wpisanym roku wcisniej ENTER etc..." << "\n";
    auto data = Fabryka::dodaj_data();
    cout << endl;
    cout << "Podaj do ktorej ma byc to wydarzenie w formacie [12 00 00][Godzina Minuta Sekunda]" << "\n";
    auto godzina = Fabryka::dodaj_godzine();

    DataZGodzina dataIgodzina;
    dataIgodzina.rok = data.rok;
    dataIgodzina.miesiac = data.miesiac;
    dataIgodzina.dzien = data.dzien;
    dataIgodzina.godzina = godzina.godzina;
    dataIgodzina.minuta = godzina.minuta;
    dataIgodzina.sekunda = godzina.sekunda;

    return dataIgodzina;
}

/// <summary>
/// Funkcja ktora zamienia wpisany dzien tygodnia na odpowiedni format dla ICAL 
/// </summary>
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
/// <summary>
/// Funkcja ta odpowiada za wszystkie akcje zwiazane z powtarzaniem
/// </summary>
Powtarzanie Fabryka::Zasada()
{
    Powtarzanie powtarzanie;
    int cyfra = -1;

    if (takCzyNie("Czy chcesz dodac powtarzanie wydarzenia? [T/N]  ")) {
        powtarzanie.powtarzaj = true;
        cyfra = pobierzLiczbe("Wbierz sposob powtarzania sie wydarzenia\n1.Dziennie\n2.Tygodniowo\n3.Miesiecznie\n");

        while (cyfra < 1 || cyfra > 3) {
          cyfra = pobierzLiczbe("Wbierz sposob powtarzania sie wydarzenia\n1.Dziennie\n2.Tygodniowo\n3.Miesiecznie\n");
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

