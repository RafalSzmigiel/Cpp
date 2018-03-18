#pragma once
#include <string>

using namespace std;

class Czlowiek
{

    string imie, nazwisko;
    int wiek;
    char plec;

public:

    Czlowiek(string = "Rafal" , string = "Szmigiel" , int = 21 , char = 'm');
    ~Czlowiek();

    string get_imie();
    void set_imie(string);

    string get_nazwisko();
    void set_nazwisko(string);

    int get_wiek();
    void set_wiek(int);

    char get_plec();
    void set_plec(char);

};
