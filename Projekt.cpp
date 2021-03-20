
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include "Class.h"
using namespace std;

int main() 
{
    Kalendarz tak;
    ICS taak;

    string znak;

   

    while (znak != "c")
    {
        
        cout << "Witaj w kalendarzu ALFA, zaraz zostanie wyswietlone menu mozliwych operacji :)" << "\n";
        cout << "Aby przejsc dalej wcisnij q:" << "\t";

        cin >> znak;
        while (znak != "q")
        {
            cout << "napisz q:" << "\t";
            cin >> znak;
        }
        cout << endl;

        cout << "1.Wyswietlanie eventow zapisanych w pliku .ics " << "\n" << "2.Dodanie eventu do pliku .ics" << "\n" << "3.Usuniecie eventu z pliku .ics";
        
        cout << endl;

        cin >> znak;

        if (znak == "1")
        {
            taak.wczytaj();
            cin >> znak;
            if (znak == "q") continue;
        }

        if (znak == "2")
        {
            string c = tak.dodaj_notatke();

           string a = tak.Data_zapisu_od();

           cout << endl << endl << a;

           string b = tak.Data_zapisu_do();

           cout << endl << b;
            cin >> znak;
            if (znak == "q") continue;
        }
    }

    
   
   /*
   cout << endl << endl;

    taak.wczytaj("");

    cout << endl;
    */

    return 0;
}