﻿
#include <iostream>
#include <string>
#include "Fabryka.h"
#include "Importer.h"
#include "Export.h"
#include "Delete.h"

using namespace std;

int main() 
{
    Importer importer;
    Export exporter;
    Delete del;

    //To jest tak tymczasowo, poźniej zostanie zmienione na liste :)

    vector<Wydarzenie> wydarzenia = vector<Wydarzenie>();

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
            wydarzenia = importer.wczytaj();
            cin >> znak;
            if (znak == "q") continue;
        }
        if (znak == "2") {
            auto zapis = exporter.export_do_pliku("dupa.txt", wydarzenia);
            cout << "zapisano" << endl;
            cin >> znak;
        }
        if (znak == "3") {
            del.zapis_do_pliku("dupa.txt");
            cout << "zapisano" << endl;
            cin >> znak;
        }
    }

    return 0;
}