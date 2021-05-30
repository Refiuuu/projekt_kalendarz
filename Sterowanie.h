#pragma once

#include <string>

using namespace std;
/// <summary>
/// 
/// </summary>
/// <param name="wiadomosc"></param>
/// <returns></returns>
string pobierzString(const char* wiadomosc);
char pobierzZnak(const char* wiadomosc);
int pobierzLiczbe(const char* wiadomosc);
int pobierzNumer(const char* wiadomosc, int max);
bool takCzyNie(const char* wiadomosc);
