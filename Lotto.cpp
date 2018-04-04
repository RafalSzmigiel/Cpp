#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

//zmienne globalne
int zbior_liczb = 49;	// zbior liczb z ktorych bedzeiemy losowac
int ile_losowac = 6;	// ile numerow chcemy wylosowac
int ile_juz_wylosowano=0;

//tablica dynamiczna
int *liczby_wylosowane = new int[ile_losowac+1];

bool flaga;
int n;


int main()
{
	cout<<"------------------------------------------------------\n";
	cout<<"\twitaj w kolekturze Lotto !"<<endl;
	cout<<"------------------------------------------------------\n\n";
	for(n=1 ;n<=49; n++)
	{
		cout<<"["<<n<<"]";
		if(n%7)				// operator % daje nam reszte z dzielenia przez 7, gdy reszta = 0 warunek nie spe³niony
			cout<<"\t";
		else
			cout<<"\n\n";
	}
	cout<<"------------------------------------------------------\n";

	int szczesliwe_liczby[6];
	int liczba_zmienna;
	int ile_juz_wybrano=0;

	cout<<"Wybierz 6 szczesliwych liczb!\n\n";
	for(int i=0;i<6;i++)
	{

	
		do{

		flaga=true;
		cout<<"podaj ["<<i+1<<"] liczbe: ";
		cin>>liczba_zmienna;
		
		if((liczba_zmienna<1)  || (liczba_zmienna>49))
		{
			cout<<"Podales liczbe z poza zbioru losowania!\n";
			flaga=false;
		}

		for(int j=0; j<=ile_juz_wybrano;j++)
		{
			if(liczba_zmienna==szczesliwe_liczby[j])
			{
				cout<<"Podales drugi raz ta sama liczbe!\n";
				flaga=false;
			}
		}

		if(flaga==true)
			{
				// liczba ktora sie nie powtarza wkladamy do tablicy
				
				szczesliwe_liczby[ile_juz_wybrano]=liczba_zmienna;
				ile_juz_wybrano++;
			}

		}while(flaga!=true);

			

	}


	cout<<endl;

	srand(time(NULL));

	//LOSOWANIE BEZ POWTÓRZEÑ//
	for(int i=1; i<=ile_losowac; i++)
	{
		do
		{
			int liczba=rand()%zbior_liczb+1;

			flaga=true;

			
			for(int j=1; j<=ile_juz_wylosowano; j++)
			{	
				// czy liczba nie zosta³a juz wczesniej wylosowana
				if(liczba==liczby_wylosowane[j])
					flaga=false;
			}

			if(flaga=true)
			{
				// liczba ktora sie nie powtarza wkladamy do tablicy
				ile_juz_wylosowano++;
				liczby_wylosowane[ile_juz_wylosowano]=liczba;
			}

		}while(flaga!=true);

	}
	cout<<"\n======================================================\n";
	cout<<"Uwaga zaczynamy losowanie !!!"<<endl;
	cout<<"Twoje szczesliwe numery to:\n";
	cout<<"------------------------------------------------------\n";
		for(int i=1; i<=ile_losowac; i++)
		{
			Sleep(3000);
			cout<<liczby_wylosowane[i]<<"	";
		}
	cout<<"\n======================================================\n";
	int lotto=0;
	int numery[6];
	cout<<"twoje trafione numery: ";
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(szczesliwe_liczby[j]==liczby_wylosowane[i])
				{
					lotto++;
					cout<<liczby_wylosowane[i];

				}
		}
	}

	cout<<"\n\ntrafiles: "<<lotto<<endl;
	cout<<"------------------------------------------------------\n";
	
	for(int i=0;i<lotto;i++)


		delete [] liczby_wylosowane;

	_getch();
}