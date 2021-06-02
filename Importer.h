#pragma once

#include "Wydarzenie.h"
#include "Powtarzanie.h"
#include <vector>
#include <string>

/**
* \file Importer.h
* \brief Plik naglowkowy modulu Importer
*/

using namespace std;
/// <summary>
/// Enumeracja ktora przechowuje wazne typy znajdujace sie w pliku .ics
/// </summary>
enum IcsType {
    BEGIN_VCALENDAR,
    END_VCALENDAR,
    BEGIN_VEVENT,
    END_VEVENT,
    DTSTART,
    DTEND,
    DESCRIPTION,
    LOCATION,
    SEQUENCE,
    RRULE,
    SUMMARY,
    PRODID,
    VERSION,
    CALSCALE,
    METHOD,
    XWRCALNAME,
    CREATED,
    STATUS,
    TRANSP,
    ERROR = -1
      
};
/// <summary>
/// Importer odpowiada za wczytywanie oraz rozszyfrowywanie pliku .ics
/// </summary>
class Importer {

public:
    /// <summary>
    /// Funkcja odpowiadajaca za wczytywanie z pliku
    /// </summary>
    vector<Wydarzenie> wczytaj(string Wczytaj);
   
    /** \brief Wczytanie nazwy pliku z ktorego bedziemy korzystac
    */
    string wczytaj_nazwe();
  
private:
   /** \brief Pobranie powtarzania z pliku
   */
    Powtarzanie wez_powtarzalnosc(string linia);
    /** \brief Sprawdzanie dnia powtarzania
    */
    
    void sprawdzDzienPowtarzania(Powtarzanie &powtarzanie, string linia);
    /** \brief Sprawdzanie jakie wystepuje powtarzanie
    */
    void sprawdzPowtarzalnosc(Powtarzanie &powtarzanie, string linia);
    /** \brief Wykrywanie typu z enumeracji w pliku
    */
    IcsType wykryj_typ(string linia);

    /** \brief Ustawianie pola enumeracji na odpowiednim polu do zapisu
    */
    void ustaw_pole(IcsType typ, string linia, Wydarzenie &wydarzenie);
   
};
