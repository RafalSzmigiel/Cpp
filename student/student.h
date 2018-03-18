#pragma once
#include <string>
#include "czlowiek.h"

using namespace std;

class Student : public Czlowiek
{
    string kierunek, wydzial;
    int indeks, semestr;

public:

    Student(string = "Teleinformatyka" , string = "Elektroniki" , int = 210265 , int = 2 , string = "Rafal" , string = "Szmigiel" , int = 21 , char = 'm');
    ~Student();

    string get_kierunek();
    void set_kierunek(string);

    string get_wydzial();
    void set_wydzial(string);

    int get_indeks();
    void set_indeks(int);

    int get_semestr();
    void set_semestr(int);
};
