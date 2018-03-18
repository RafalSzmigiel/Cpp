#include <iostream>

using namespace std;

class Punkt
{
    string nazwa;
    float x,y;

public:
    Punkt(string n = "punkt" , float a = 4 , float b = 5)
    {
        nazwa = n;
        x = a;
        y = b;
    }
    void wyswietl()
    {
        cout<<nazwa<<" : "<<x<<" , " <<y<<endl;
    }
};

class Kolo : public Punkt
{
    string nazwa;
    float r;

public:
    Kolo(string nk = "Kolo" , string np = "punkcik" ,float a = 1, float b = 1, float pr = 10) : Punkt(np,a,b)
    {
        nazwa = nk;
        r = pr;
    }
    void wyswietl()
    {
        cout<<"kolo o nazwie : "<<nazwa<<endl;
        cout<<"srodek kola : ";
        Punkt::wyswietl();
        cout<<"promien kola : "<<r<<endl;
    }
};


int main()
{
    Punkt p1;

    p1.wyswietl();

    Kolo k1;

    k1.wyswietl();

    return 0;
}
