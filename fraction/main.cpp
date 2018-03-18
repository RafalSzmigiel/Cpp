#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	Fraction ulamek;
	ulamek.set_licznik(12);
	ulamek.set_mianownik(4);
	cout<<ulamek.get_licznik();
	cout<<endl<<ulamek.get_mianownik();

	system("pause");
}