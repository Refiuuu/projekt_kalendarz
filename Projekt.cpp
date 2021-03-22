
#include <iostream>
#include <string>
#include "Fabryka.h"
#include "Importer.h"
#include "Export.h"

using namespace std;

int main() 
{
    Importer importer;
    Export exporter;


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
            auto wydarzenia = importer.wczytaj();


            cin >> znak;
            if (znak == "q") continue;
        }
        if (znak == "2") {
            auto zapis = exporter.export_do_pliku();
            cout << endl;
            cin >> znak;
        }
    }

    
   
   /*
   cout << endl << endl;

    taak.wczytaj("");

    cout << endl;
    */

    return 0;
}