#include <iostream>
#include <conio.h>	//_getch();
#include <cstdlib>	//system("cls");
#include <Windows.h> //Sleep();

using namespace std;

	float a,b;
	int nr;


void menu()
{
	system("cls");
	cout<<"\n\tKalkulator!\n\n";

	cout<<"[1]	dodawanie\n";
	cout<<"[2]	odejmowanie\n";
	cout<<"[3]	mnozenie\n";
	cout<<"[4]	dzielenie\n";
	cout<<"[0]	wyjscie\n";

	cout<<"\nwybierz jedna z dostepnych opcji: ";
}
void liczby()
{
	cout<<"podaj pierwsza liczbe 'a': ";
	cin>>a;
	cout<<"podaj druga liczbe 'b': ";
	cin>>b;
}

float dodawanie(float x, float y)
{
	return x+y;
}
float odejmowanie(float x, float y)
{
	return x-y;
}
float mnozenie(float x, float y);
float dzielenie(float x, float y);



int main()
{

	while(1)
	{

	
		menu();
		cin>>nr;
		system("cls");
		switch(nr)
		{
			case 1:{
				cout<<"DODAWANIE\n\n";
				liczby();
				cout<<dodawanie(a,b);
				_getch();
				break;
				   }

			case 2:
				{
				cout<<"ODEJMOWANIE\n\n";
				liczby();
				cout<<odejmowanie(a,b);
				_getch();
				break;
				}

			case 3:
				{
				cout<<"MNOZENIE\n\n";
				liczby();
				cout<<mnozenie(a,b);
				_getch();
				break;
				}

			case 4:
				{
				cout<<"DZIELENIE\n\n";
				liczby();

				if((a==0)||(b==0))
					cout<<"\nnie dzielimy przez 0 !\n";
				else
				cout<<dzielenie(a,b);

				_getch();
				break;
				}

			case 0:
				{
					exit(0);
				}
			default:
				{
				cout<<"\nNie ma takiej opcji w kalkulatorze!\n";
				Sleep(5000);
				}
		}
	

	}

	_getch();
}

float mnozenie(float x, float y)
{
	return x*y;
}
float dzielenie(float x, float y)
{
	return x/y;
}