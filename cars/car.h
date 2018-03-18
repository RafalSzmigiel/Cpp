#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class car
{
private:

	string marka,model;
	int rocznik;
	long przebieg;

public:

	car(string="brak",string="brak",int=0,long=0);	//KONSTRUKTOR
	~car();											//DESTRUKTOR

	void wczytaj();
	void wypisz();
};