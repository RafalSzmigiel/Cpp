#include <iostream>
#include <string>
#include <string.h>

#include "car.h"

using namespace std;


void car::wczytaj()
{
	cout<<"Marka : ";
	cin>>marka;
	cout<<"Model : ";
	cin>>model;
	cout<<"Rocznik : ";
	cin>>rocznik;
	cout<<"Przebieg (km) : ";
	cin>>przebieg;

}

void car::wypisz()
{
	cout<<endl<<marka<<" "<<model<<endl;
	cout<<rocznik<<endl;
	cout<<przebieg<<endl;
}


car::car(string mar,string mod,int r,long p)
{
	marka=mar;
	model=mod;
	rocznik=r;
	przebieg=p;
}
car::~car()
{
	cout<<"destruktor kasuje obiekty";
}