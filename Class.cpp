#include "Class.h"

bool Kalendarz::czy_przestepny(int rok)
{
    if ((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0) return true;
    else return false;
}

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

string Kalendarz::dodaj_tytul()
{
    string nazwa;
    cout << "Podaj Tytul swojego wydarzenia:" << "\t";
    cin >> nazwa;
    string  Nazwa = "SUMMARY:" + nazwa;
    return string(Nazwa);
}

string Kalendarz::dodaj_notatke()
{
    bool CzyTak = false;
    string nazwa;
    cout << "Czy chcesz dodac notatke do swjego wydarzenia ? [T/N}" << endl;

    cin >> nazwa;
    if (nazwa == "T")
    {
        cout << "Nizej wpisz swoja notatke:" << endl;
        cin >> nazwa;
    }
    else
    {
      
    }

    return string(nazwa);
}

string Kalendarz::dodaj_lokalizacje()
{
    string miasto;
    string kraj;

    cout << "Podaj lokalizacje swojego wydarzenia: " << "\n";

    cout << "Miasto: " << "\t"; cin >> miasto;
    cout << endl;
    cout << "Kraj: " << "\t"; cin >> kraj;

    return string(miasto + "/" + "," + " " + kraj);

}

string Kalendarz::dodaj_data()
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

string Kalendarz::dodaj_godzine()
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

        string bla = ("T" + Godzina + Minuta + Sekunda + "Z");
        return bla;
}

string Kalendarz::Data_zapisu_od()
{
    cout << "Podaj od kiedy chcialbys dodac wydarzenie?" << "\n";
    cout << "Zapisz ja w formacie [RRRRMDD]" << "\n";
    cout << "Po wpisanym roku wcisniej ENTER etc..." << "\n";

    string a = Kalendarz::dodaj_data();
    cout << endl;
    cout << "Podaj od ktorej ma byc to wydarzenie w formacie godzina minuta sekunda : " << "\n";
    string b = Kalendarz::dodaj_godzine();

    return string ("DTSTART:" + a + b);
}

string Kalendarz::Data_zapisu_do()
{
    cout << "Podaj do kiedy chcialbys dodac wydarzenie?" << "\n";
    cout << "Zapisz ja w formacie [RRRRMDD]" << "\n";
    cout << "Po wpisanym roku wcisniej ENTER etc..." << "\n";

    string a = Kalendarz::dodaj_data();
    cout << endl;
    cout << "Podaj do ktorej ma byc to wydarzenie w formacie godzina minuta sekunda : " << "\n";
    string b = Kalendarz::dodaj_godzine();
    return string("DTEND:" + a + b);
}

vector<Wydarzenie> ICS::wczytaj()
{
    string nazwaPliku;
    cout << "PODAJ NAZWE PLIKU DO WYSWIETLENIA:" << endl;

    cin >> nazwaPliku;
    nazwaPliku += ".ics";

    ifstream plik;

    plik.open(nazwaPliku);
    
    string linia;
    string tytul;
    string notatka;
    string data;
    string godzina;
    string lokalizacja;
    string powtarzalnosc;

    bool koniec = false;

    Wydarzenie* wydarzenie = nullptr;

    vector<Wydarzenie*> ww = vector<Wydarzenie*>();

    while (!plik.eof())
    {
        if (plik.good())
        {
            getline(plik, linia);
            auto typ = jakiTyp(linia);

            
            if (typ == IcsType::BEGIN_VEVENT) {
                wydarzenie = new Wydarzenie();
                cout << endl;
            }

            if (typ == IcsType::DTSTART) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie->strDTSTART() << endl;
            }

            if (typ == IcsType::DTEND) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie->strDTEND() << endl;
            }

            if (typ == IcsType::CREATED) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie->strCREATED() << endl;
            }

            if (typ == IcsType::DESCRIPTION) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie->strDESCRIPTION() << endl;
            }

            if (typ == IcsType::LOCATION) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie->strLOCATION() << endl;
            }

            if (typ == IcsType::SEQUENCE) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie->strSEQUENCE() << endl;
            }

            if (typ == IcsType::SUMMARY) {
                wezDetal(typ, linia, wydarzenie);
                cout << wydarzenie->strSUMMARY() << endl;
            }

            if (typ == IcsType::END_VEVENT) {
                ww.push_back(wydarzenie);
            }
        }
    }
    plik.close();

    //if (koniec == false) {
    //    throw "brak znacznieka konca";
    //}

    return std::vector<Wydarzenie>();

}

IcsType ICS::jakiTyp(string linia)
{
    if (linia.find("BEGIN:VEVENT") != -1)
    {
        return IcsType::BEGIN_VEVENT;
    }

    if (linia.find("END:VEVENT") != -1)
    {
        return IcsType::END_VEVENT;
    }

    if (linia.find("DESCRIPTION") != -1) {
        return IcsType::DESCRIPTION;
    }

    if (linia.find("SUMMARY") != -1) {
        return IcsType::SUMMARY;
    }

    if (linia.find("LOCATION") != -1) {
        return IcsType::LOCATION;
    }
   
    if (linia.find("DTSTART") != -1) {
        return IcsType::DTSTART;
    }
    
    if (linia.find("DTEND") != -1) {
        return IcsType::DTEND;
    }

    if (linia.find("CREATED") != -1) {
        return IcsType::CREATED;
    }

    if (linia.find("SEQUENCE") != -1) {
        return IcsType::SEQUENCE;
    }

    if (linia.find("STATUS") != -1) {
        return IcsType::STATUS;
    }

    if (linia.find("TRANSP") != -1) {
        return IcsType::TRANSP;
    }
      
}


void test() {
  for (int i = 0; i < 10; i++) {
    cout << "poszlo";
  }
}
 
string wezDane(string linia) {
    return linia.substr(linia.find(':') + 1);
}

string getDate(string date) {

    string rok;
    string miesiac;
    string dzien;
    string godzina;
    string minuta;
    string sekunda;
        

    rok = date.substr(0, 4);
    miesiac = date.substr(4,2);
    dzien = date.substr(6,2);
    godzina = date.substr(9, 2);
    minuta = date.substr(11, 2);
    sekunda = date.substr(13, 2);

    std::tm tm;
    tm.tm_year = atoi(rok.c_str());
    tm.tm_mon = atoi(miesiac.c_str());

    return string(rok + "-" + miesiac + "-" + dzien + "  " + godzina + ":" + minuta + ":" + sekunda);
   

}

void ICS::wezDetal(IcsType typ, string linia, Wydarzenie* wydarzenie)
{
    switch (typ) {
    case IcsType::DESCRIPTION:
        wydarzenie->notatka = wezDane(linia);
        break;
    case IcsType::SUMMARY:
        wydarzenie->tytul = wezDane(linia);
        break;
    case IcsType::LOCATION:
        wydarzenie->lokalizacja = wezDane(linia);
        break;
    case IcsType::DTSTART:
        wydarzenie->data_start = getDate(wezDane(linia));
        break;
    case IcsType::DTEND:
        wydarzenie->data_end = getDate(wezDane(linia));
        break;
    case IcsType::CREATED:
        wydarzenie->created = getDate(wezDane(linia));
        break;
    case IcsType::SEQUENCE:
        wydarzenie->sequence = wezDane(linia);
        break;
    }
}


void zapisz(Kalendarz k)
{
    
    


}
