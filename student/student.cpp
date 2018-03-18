#include "student.h"
#include "czlowiek.h"

Student::Student(string ki, string wy, int in , int se , string im , string na , int wi , char pl) : Czlowiek(im,na,wi,pl)
{
    kierunek = ki;
    wydzial = wy;
    indeks = in;
    semestr = se;
}
Student::~Student()
{

}


string Student::get_kierunek()
{
    return kierunek;
}
void Student::set_kierunek(string ki)
{
    kierunek = ki;
}

string Student::get_wydzial()
{
    return wydzial;
}
void Student::set_wydzial(string wy)
{
    wydzial = wy;
}

int Student::get_indeks()
{
    return indeks;
}
void Student::set_indeks(int in)
{
    indeks=in;
}

int Student::get_semestr()
{
    return semestr;
}
void Student::set_semestr(int se)
{
    semestr = se;
}
