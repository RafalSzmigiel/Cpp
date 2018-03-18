#include <iostream>
#include <string.h>		//	LANCUCHY ZNAKOW //	TYP STRING
#include <string>
#include <Windows.h>
#include <fstream>		//	BIBLIOTEKA ODPOWIADAJACA ZA KOMUNIKACJE Z PLIKAMI
#include <conio.h>		//	BIBLIOTEKA ODPOWIADAJACA ZA BUFOR KLAWIATURY
#include <fstream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

struct ksiazka
{
    int numer;          // numer w bazie
    string tytul;
    string autor;
    string kategoria;
    unsigned rok_wydania ;
    unsigned liczba_stron;
    double cena;
    bool wypozyczona;
};

// dodawanie ksiazek do bazy dannych - wszystko znajduje sie w pliku .txt

void dodaj_do_bazy(char *in, ksiazka *s, int n)
{
    ofstream plik;
    plik.open(in);          // otwieranie pliku

    for(int i=0; i<n; ++i)
    {
        s[i].numer = i + 1;         plik<<s[i].numer<<endl;

        cout<<"podaj tytul ksiazki : ";           cin>>s[i].tytul;            plik<<s[i].tytul<<endl;
        cout<<"podaj autora ksiazki : ";          cin>>s[i].autor;            plik<<s[i].autor<<endl;
        cout<<"jaka to kategoria : ";             cin>>s[i].kategoria;        plik<<s[i].kategoria<<endl;
        cout<<"podaj rok wydania ksiazki : ";     cin>>s[i].rok_wydania;      plik<<s[i].rok_wydania<<endl;
        cout<<"Podaj liczbe stron ksiazki : ";    cin>>s[i].liczba_stron;     plik<<s[i].liczba_stron<<endl;
        cout<<"podaj cene ksiazki : ";            cin>>s[i].cena;             plik<<s[i].cena<<endl;

        cout<<"czy ksiazka jest wypozyczona ? ( 1-tak / 0-nie )";
        cin>>s[i].wypozyczona;
        plik<<s[i].wypozyczona<<endl;


    }

    plik.close();       // zamykanie pliku
}

// funkcja liczy rozmiar tablicy struktor ( yciaga z pliku zapisane juz tam ksiazki)
// do ktorej pisujemy dane o ksiazkach
int rozmiar (char *in)

{
    int numer;
    unsigned rok_wydania,liczba_stron;
    double cena;
    string tytul, autor, kategoria;
    bool wypozyczona;

    ifstream plik;
    plik.open(in);

    int rozm = 0;

    while (!plik.eof())
    {
        plik>>numer;
        plik>>tytul;
        plik>>autor;
        plik>>kategoria;
        plik>>rok_wydania;
        plik>>liczba_stron;
        plik>>cena;
        plik>>wypozyczona;

        rozm +=1;

    }

    plik.close();
    return rozm;
}

//funkcja yciaga nam ksiazki z pliku do tablicy struktor
void zpliku(char *in, ksiazka *s, int n )
{
    ifstream plik;
    plik.open(in);

    for(int i=0; i<n; ++i)
    {
        plik>>s[i].numer;
        plik>>s[i].tytul;
        plik>>s[i].autor;
        plik>>s[i].kategoria;
        plik>>s[i].rok_wydania;
        plik>>s[i].liczba_stron;
        plik>>s[i].cena;
        plik>>s[i].wypozyczona;
    }
}
// wypisanie ksiazek na ekranie
void wypisz(ksiazka *s, int n)
{
    for(int i = 0; i<n ; ++i )
    {
        cout<<"NR. "                    <<s[i].numer<<endl;
        cout<<"Tytul :\t\t"             <<s[i].tytul<<endl;
        cout<<"Autor : \t"              <<s[i].autor<<endl;
        cout<<"Kategoria : \t"          <<s[i].kategoria<<endl;
        cout<<"Rok wydania : \t"        <<s[i].rok_wydania<<endl;
        cout<<"Liczba stron : \t"       <<s[i].liczba_stron<<endl;
        cout<<"Cena : \t\t"             <<s[i].cena<<endl;
        cout<<endl;
    }
}
//sortowanie ksiazek po cenie
void sort2(ksiazka *s,int n);
void sort(ksiazka *s, int n)        //  SORTOWANIE BABELKOWE
{
    ksiazka sor;
    for(int i=0 ; i<n ; ++i)
    {
        for(int j=0 ; j<n-1 ; ++j)
        {
            if(s[j].cena < s[j+1].cena)
            {
                sor=s[j+1];
                s[j+1]=s[j];
                s[j]=sor;
            }
        }
    }
}

void niewypozyczone(ksiazka *s,int n);
bool USUN(ksiazka* &s,int &n,int &x);


int main(int argc,char **argv)
{
    HANDLE kolor;
    kolor = GetStdHandle(STD_OUTPUT_HANDLE);

    int znak ;

    argv [1] = "baza ksiazek.txt";

    do
    {
        system("cls");

            SetConsoleTextAttribute(kolor,2);
            cout<<"============================================"<<endl;
            cout<<endl<<"\t\tBIBLIOTEKA !"<<endl<<endl;
            cout<<"============================================"<<endl;
            SetConsoleTextAttribute(kolor,7);
            cout<<endl;
            cout<<"[1] UTWORZ PLIK                              "<<endl;
            cout<<"[2] DODAJ KSIAZKE                            "<<endl;
            cout<<"[3] WYSWIETL WSZYSTKIE KSIAZKI               "<<endl;
            cout<<"[4] SORTOWANIE KSIAZEK PO CENIE              "<<endl;
            cout<<"[5] SORTOWANIE KSIAZEK PO LICZBIE STRON      "<<endl;
            cout<<"[6] KSIAZKI NIEWYPOZYCZONE                   "<<endl;
        // cout<<"[7] USUN KSIAZKE                             "<<endl;
            cout<<endl;
            cout<<"[0] WYJSCIE Z PROGRAMU                       "<<endl;
            cout<<"============================================="<<endl;

        cin>>znak;
        system("cls");

        switch(znak)
        {

        case 1:
            {
            SetConsoleTextAttribute(kolor,2);
            cout<<"============================================"<<endl;
            cout<<"\tOTWIERANIE PLIKU Z KSIAZKAMI :"<<endl;
            cout<<"============================================"<<endl;
            SetConsoleTextAttribute(kolor,7);
            cout<<endl;

            int n;
			cout<<"Ile ksiazek zapisac w bazie ?\n\n";
			cin>>n;
			ksiazka *s = new ksiazka [n];
			dodaj_do_bazy(argv[1],s,n);
			delete [] s;
			break;
            }

        case 2:
            {

            SetConsoleTextAttribute(kolor,2);
            cout<<"============================================"<<endl;
            cout<<"\tDODAJ KSIAZKE :"<<endl;
            cout<<"============================================"<<endl;
            SetConsoleTextAttribute(kolor,7);
            cout<<endl;

                int ile;
                cout<<"ile ksiazek chczesz dopisac do bazy ? \n\n";
                cin>>ile;

                int roz = rozmiar(argv[1])+ile-1;
                int rozm = rozmiar(argv[1])-1;

                ksiazka *s = new ksiazka [roz];
			zpliku(argv[1],s,rozm);

			for(int i=rozm;i<roz;++i)
            {
                s[i].numer= i+1;
                cout<<"podaj tytul : ";             cin>>s[i].tytul;
                cout<<"podaj autora : ";            cin>>s[i].autor;
                cout<<"jaka to kategoria : ";       cin>>s[i].kategoria;
                cout<<"rok wydania : ";             cin>>s[i].rok_wydania;
                cout<<"podaj liczbe stron : ";      cin>>s[i].liczba_stron;
                cout<<"podaj cene filmu : ";        cin>>s[i].cena;
                cout<<"czy ksiazka jest wypozyczona ? ( 1-tak / 0-nie )";
                cin>>s[i].wypozyczona;



            }
            ofstream plik;
			plik.open(argv[1]);
			for(int i=0;i<roz;++i)
            {
                plik<<s[i].numer<<endl;
                plik<<s[i].tytul<<endl;
                plik<<s[i].autor<<endl;
                plik<<s[i].kategoria<<endl;
                plik<<s[i].rok_wydania<<endl;
                plik<<s[i].liczba_stron<<endl;
                plik<<s[i].cena<<endl;
                plik<<s[i].wypozyczona<<endl;
            }
            plik.close();
            delete [] s;
            break;

            }

        case 3:
            {
            SetConsoleTextAttribute(kolor,2);
            cout<<"============================================"<<endl;
            cout<<"\tKSIAZKI ZAPISANE W BAZIE :"<<endl;
            cout<<"============================================"<<endl;
            SetConsoleTextAttribute(kolor,7);
            cout<<endl;

			int n = rozmiar(argv[1])-1;
			ksiazka *s = new ksiazka [n];
			zpliku(argv[1],s,n);
			wypisz(s,n);

			delete [] s;
			getch();
			break;
            }

        case 4:
            {
            SetConsoleTextAttribute(kolor,2);
            cout<<"======================================================="<<endl;
            cout<<"\tKSIAZKI POSORTOWANE PO CENIE (OD NAJDROZSZEJ):"<<endl;
            cout<<"========================================================"<<endl;
            SetConsoleTextAttribute(kolor,7);
            cout<<endl;

			int n = rozmiar(argv[1])-1;
			ksiazka *s = new ksiazka [n];
			zpliku(argv[1],s,n);
			sort(s,n);
			wypisz(s,n);

			delete [] s;
			getch();
			break;
            }

        case 5:
            {
            SetConsoleTextAttribute(kolor,2);
            cout<<"=================================================="<<endl;
            cout<<"\tKSIAZKI POSORTOWANE WEDLUG LICZBY STRON :"<<endl;
            cout<<"==================================================="<<endl;
            SetConsoleTextAttribute(kolor,7);
            cout<<endl;

			int n = rozmiar(argv[1])-1;
			ksiazka *s = new ksiazka [n];
			zpliku(argv[1],s,n);
			sort2(s,n);
			wypisz(s,n);

			delete [] s;
			getch();
			break;
            }

        case 6:
            {
                SetConsoleTextAttribute(kolor,2);
            cout<<"================================="<<endl;
            cout<<"\tKSIAZKI NIEWYPOZYCZONE :"<<endl;
            cout<<"================================="<<endl;
            SetConsoleTextAttribute(kolor,7);
            cout<<endl;

			int n = rozmiar(argv[1])-1;
			ksiazka *s = new ksiazka [n];
			zpliku(argv[1],s,n);
			niewypozyczone(s,n);

			delete [] s;
			getch();
			break;
            }

        case 7:
            {

            SetConsoleTextAttribute(kolor,2);
            cout<<"============================================"<<endl;
            cout<<"\tUSUN KSIAZKE Z BAZY :"<<endl;
            cout<<"============================================"<<endl;
            SetConsoleTextAttribute(kolor,7);
            cout<<endl;

            int n = rozmiar(argv[1])-1;
			ksiazka *s = new ksiazka [n];
			zpliku(argv[1],s,n);

			int x;
			cout<<"ktora ksiazke chcesz usunac podaj numer : ";
			cin>>x;
			if(USUN(s,n,x)==false)
            {
                cout<<"blad"<<endl;
            }

            wypisz(s,n);
			delete [] s;
			getch();
            }

        case 0:
            {
                cout<<"\nDziekuje :) i Dowidzenia .!\n";

            }
        }

    }while(znak != 0);
    return 0;


    }






void niewypozyczone(ksiazka *s,int n)
{
    for(int i=0;i<n;i++)
    {
        if(s[i].wypozyczona==0)
        {
        cout<<"NR. "                    <<s[i].numer<<endl;
        cout<<"Tytul Filmu : \t"        <<s[i].tytul<<endl;
        cout<<"Autor : \t"              <<s[i].autor<<endl;
        cout<<endl;
        }
    }
}

void sort2(ksiazka *s, int n)        //  SORTOWANIE BABELKOWE
{
    ksiazka sor;
    for(int i=0 ; i<n ; ++i)
    {
        for(int j=0 ; j<n-1 ; ++j)
        {
            if(s[j].liczba_stron > s[j+1].liczba_stron)
            {
                sor=s[j+1];
                s[j+1]=s[j];
                s[j]=sor;
            }
        }
    }
}

bool USUN(ksiazka* &s,int &n,int &x)
{
    int ilosc = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i].numer!=x)
        {
            ilosc++;
        }
    }
    ksiazka *nowa = new ksiazka[ilosc];
    if(nowa==NULL)
        return false;

    int j=0;
    for(int i=0;i<n;i++)
    {
        if(s[i].numer!=x)
        {
            nowa[j]=s[i];
            j++;
        }

        delete[] s;
        s=nowa;
        n=ilosc;
        return true;
    }
}

