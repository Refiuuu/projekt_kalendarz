#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "Wydarzenie.h"

class Export
{
public:
    bool export_do_pliku(string nazwa_pliku, vector<Wydarzenie> wydarzenia_zapis);
private:
    void zapiszWydarzenie(Wydarzenie& w, ofstream& plik);
};
