#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	long int nr_karty=123456789;
	int pin=1234;

	cout<<"\n------------------\n";
	cout<<"Witaj w bankomacie!\n";
	cout<<"------------------\n\n";


	cout<<"podaj numer karty: ";
	cin>>nr_karty;
	cout<<"podaj pin: ";
	cin>>pin;

	if((pin==1234)&&(nr_karty=123456789))
		cout<<"\npodales poprawny numer karty i pin";
	else
		cout<<"\npodales niepoprawny pin lub numer karty";


	_getch();
}
