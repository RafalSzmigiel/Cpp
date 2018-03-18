#include "czlowiek.h"


Czlowiek::Czlowiek(string im, string na, int wi, char pl)
{
    imie = im;
    nazwisko = na;
    wiek = wi;
    plec = pl;
}
Czlowiek::~Czlowiek()
{

}

string Czlowiek::get_imie()
{
    return imie;
}
void Czlowiek::set_imie(string im)
{
    imie = im;
}

string Czlowiek::get_nazwisko()
{
    return nazwisko;
}
void Czlowiek::set_nazwisko(string na)
{
    nazwisko = na;
}

int Czlowiek::get_wiek()
{
    return wiek;
}
void Czlowiek::set_wiek(int wi)
{
    wiek = wi;
}

char Czlowiek::get_plec()
{
    return plec;
}
void Czlowiek::set_plec(char pl)
{
    plec = pl;
}
