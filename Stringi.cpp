#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	char text[15]="kot student";
	cout<<text<<endl;

	for(int i=0;i<15;i++)
		cout<<text[i]<<"\t";

	/////////////////////////////////

	char *text2="kot student klakier";
	cout<<text2<<endl;
	text2="kot w butach";
	cout<<text2<<endl;

	/////////////////////////////////

	//wypisujemy wyraz 3 i 7 bo w tablicy znakow numerujemy od 0
	cout<<text2[2]<<" "<<text2[6]<<endl;
	
	////////////////////////////////
	//sprawdzanie plci

	string imie;
	int dlugosc_imie=0;

	cout<<"podaj imie: ";
	cin>>imie;

	dlugosc_imie=imie.length();
	cout<<"dlugosc twojego imienia to: ";
	cout<<dlugosc_imie<<endl;

	if(imie[dlugosc_imie-1]=='a')
		cout<<"pewnie jestes kobieta\n";
	else
		cout<<"pewnie jestes facetem\n";

	//////////////////////////////////////

	// odwracanie wyrazow

	string text3;
	cout<<"podaj wyraz bez spacji: ";
	cin>>text3;

	int dlugosc_text3 = text3.length();

	for(int i=dlugosc_text3-1 ; i>=0; i--)
		cout<<text3[i];

	cout<<endl;

	//getline - zapis ze spacjami

	string text4;
	cout<<"podaj napis ze spacjami: ";
	cin.ignore(); // czyscimy strumien tak aby mozna bylo tam co koliwek wlozyc
	getline(cin,text4);
	cout<<text4<<endl;
	
	int dlugosc_text4=text4.length();
	cout<<"dlugosc napisu ze spacjami to: "<<dlugosc_text4<<endl;

	/////////////////////////////////////////////////////////////////////////////

	// zmiana wielkosci liter

	string text5 = "wlazl kotek na plotek";

	transform(text5.begin(), text5.end(), text5.begin(), ::tolower);
	cout<<text5<<endl;

	transform(text5.begin(), text5.end(), text5.begin(), ::toupper);
	cout<<text5<<endl;

	///////////////////////////////////////////////////////////////////////////////

	// laczenie dwoch stringow - kokatenacja !!!

	string one = "kot ";
	string two = "w butach";
	string three = one + two;

	cout<<three<<endl;

	///////////////////////////////////////////////////////////////////////////////

	// znajdowanie wyrazu

	string text6 = "piwo na rynku po 6 zl";
	string szukaj = "po";
	size_t pozycja = text6.find(szukaj);

	if(pozycja!=string::npos)
		cout<<"znalezion na pozycji: "<<pozycja<<endl;
	else
		cout<<"nie znaleziono wyrazu"<<endl;

	/////////////////////////////////////////////////////////////////////////////////////

	// kasowanie czesci lancucha

	string text7 = "politechnika wydzial elektroniki";
	text7.erase(12,8); // wytnij od 12 znaku 8 znakow
	cout<<text7<<endl;

	//////////////////////////////////////////////////////////////////////

	// wymiana czesci textu

	string text8 = "politechnika wroclawska";
	text8.replace(13,10,"warszawska");
	cout<<text8<<endl;

	////////////////////////////////////////////////////////////////////////////

	// wstawianie do textu

	string text9 = "informatyka";
	text9.insert(0,"tele"); // w miejsece indeksu 0 tablicy dopisujemy tele
	cout<<text9<<endl;
   

	///////////////////////////////////////////////////////////////////////

	// wyciaganie textu

	string text10 = "54-129 wroclaw, ul bajana 34/3";
	string nowytext= text10.substr(16,14);
	cout<<nowytext<<endl;


	system("pause");
}