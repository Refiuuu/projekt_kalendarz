#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "Importer.h"
#include "Fabryka.h"
#include "Wydarzenie.h"



class Delete
{
public:
     void zapis_do_pliku(string nazwa_pliku);
private:
     Importer imp;
     Fabryka fab;
     string nazwa;
     string data;
     string godzina;
     string Data;
};

