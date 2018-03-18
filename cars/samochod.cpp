#include <iostream>
#include "car.h"
#include <string>
#include <string.h>


using namespace std;

int main()
{
	car s[2];

	for(int i=0; i<2; i++)
	{
		s[i].wczytaj();
	}

	for(int i=0; i<2; i++)
	{	
		cout<<endl;
		s[i].wypisz();
	}

	system("pause");
}
