#include <iostream>

using namespace std;

class Zwierze
{
    string rodzaj;
    int wiek;
    float waga;

public:

    Zwierze(string r = "krowa" , int wi = 4 , float wa = 216.65)
    {
        rodzaj = r;
        wiek = wi;
        waga = wa;
    }

    void set_rodzaj(string r)
    {
        rodzaj = r;
    }
    void set_wiek(int wi)
    {
        wiek = wi;
    }
    void set_waga(float wa)
    {
        waga = wa;
    }

    void wyswietl()
    {
        cout<<rodzaj<<". wiek to "<<wiek<<" lata. waga = "<<waga<<" [kg]"<<endl;
    }

};

class Krowa : public Zwierze
{
    string nazwa;
    string kolor;
    float ile_mleka;

public:

    Krowa(string n = "mucika" , string k = "fioletowa" , float m = 16 , string r  = "krowa", int wi = 8 , float wa= 250.91) : Zwierze(r,wi,wa)
    {
        nazwa = n;
        kolor = k;
        ile_mleka = m;
    }

    void wyswietl()
    {
        Zwierze::wyswietl();
        cout<<"krowa sie nazywa : "<<nazwa<<" . jej kolor to "<<kolor<<" . codziennie daje "<<ile_mleka<<" litrow mleka."<<endl;
    }

};


int main()
{
    Zwierze z1("wiewiorka",2,1.76);
    z1.wyswietl();
    Zwierze z2;
    z2.wyswietl();
    Krowa k1("paula", "zielona" , 5 , "cielaczek" , 21 , 64.55 );
    k1.wyswietl();



    return 0;
}
