#pragma once
#include <string>
#include "czlowiek.h"

using namespace std;

class Tutor : public Czlowiek
{
    string tytul_naukowy;
    int liczba_publikacji;

public:

    Tutor(string = "Inzynier" , int = 13 , string = "Rafal" , string = "Szmigiel" , int = 21 , char 'm');
    ~Tutor();

    string get_tytul_naukowy();
    void set_tytul naukowy(string);

    int get_liczba_publikacji();
    void set_liczba_publikacji(int);

};
