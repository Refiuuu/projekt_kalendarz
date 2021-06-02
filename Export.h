#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include "Wydarzenie.h"

/** 
* \file Export.h
* \brief Plik naglowkowy modulu Export
*/



using namespace std;
/// <summary>
/// Export odpowiada za zapis pliku o podanej nazwie do odpowiedniego formatu.
/// </summary>
class Export
{
public:
    /// <summary>
    /// Funkcja exportuje wszystkie wydarzenia do pliku
    /// </summary>
    /// <param name="nazwa_pliku">Zapis pliku o podanej nazwie</param>
    /// <param name="wydarzenia">Lista wydarzen</param>
    /// <returns></returns>
    bool export_do_pliku(string nazwa_pliku, vector<Wydarzenie> & wydarzenia);
private:
    /// <summary>
    /// Zapisuje jedno wydarzenie 
    /// </summary>
    /// <param name="wydarzenie">Wydarzenie do zapisania</param>
    /// <param name="plik">Plik do zapisu</param>
    void zapisz_wydarzenie(Wydarzenie &wydarzenie, ofstream &plik);
    
};
