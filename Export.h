#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Wydarzenie.h"


using namespace std;
/// <summary>
/// Export odpowiada za zapis pliku o podanej nazwie do odpowiedniego formatu.
/// </summary>
class Export
{
public:
    bool export_do_pliku(string nazwa_pliku, vector<Wydarzenie> & wydarzenia);

private:
    void zapisz_wydarzenie(Wydarzenie &wydarzenie, ofstream &plik);
    
};
