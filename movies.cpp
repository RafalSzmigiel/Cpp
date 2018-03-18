#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct film
{
    int numer;          // numer w bazie
    string tytul;
    string rezyser;
    string gatunek;
    int rok ;
    double cena;
};

// dodawanie filmow do bazy dannych - wszystko znajduje sie w pliku .txt

void dodaj_do_bazy(char *in, film *s, int n)
{
    ofstream plik;
    plik.open(in);          // otwieranie pliku

    for(int i=0; i<n; ++i)
    {
        s[i].numer = i + 1;
        plik<<s[i].numer<<endl;
        cout<<"podaj tytul filmu : \n";
        cin>>s[i].tytul;
        plik<<s[i].tytul<<endl;
        cout<<"podaj rezysera filmu : \n";
        cin>>s[i].rezyser;
        plik<<s[i].rezyser<<endl;
        cout<<"podaj gatunek filmu : \n";
        cin>>s[i].gatunek;
        plik<<s[i].gatunek<<endl;
        cout<<"rok produkcji filmu : \n";
        cin>>s[i].rok;
        plik<<s[i].rok<<endl;
        cout<<"podaj cene fimu : \n";
        cin>>s[i].cena;
        plik<<s[i].cena<<endl;


    }

    plik.close();       // zamykanie pliku
}

// funkcja liczy rozmiar tablicy struktor ( yciaga z pliku zapisane juz tam filmy)
// do ktorej pisujemy dane o filmach
int rozmiar (char *in)

{
    int numer, rok;
    double cena;
    string tytul, rezyser, gatunek;

    ifstream plik;
    plik.open(in);

    int rozm = 0;

    while (!plik.eof())
    {
        plik>>numer;
        plik>>tytul;
        plik>>rezyser;
        plik>>gatunek;
        plik>>rok;
        plik>>cena;

        rozm +=1;

    }

    plik.close();
    return rozm;
}

//funkcja yciaga nam filmy z pliku do tablicy struktor
void zpliku(char *in,film *s, int n )
{
    ifstream plik;
    plik.open(in);

    for(int i=0; i<n; ++i)
    {
        plik>>s[i].numer;
        plik>>s[i].tytul;
        plik>>s[i].rezyser;
        plik>>s[i].gatunek;
        plik>>s[i].rok;
        plik>>s[i].cena;
    }
}
// wypisanie filmo na ekranie
void wypisz(film *s, int n)
{
    for(int i = 0; i<n ; ++i )
    {
        cout<<"NR. "            <<s[i].numer<<endl;
        cout<<"Tytul Filmu : "  <<s[i].tytul<<endl;
        cout<<"Rezyser : "      <<s[i].rezyser<<endl;
        cout<<"Gatunek Filmu : "<<s[i].gatunek<<endl;
        cout<<"Rok produkcji : "<<s[i].rok<<endl;
        cout<<"Cena : "         <<s[i].cena<<endl;
    }
}
//sortowanie filmow po cenie
void sort(film *s, int n)

{
    film sor;
    for(int i=0 ; i<n ; ++i)
    {
        for(int j=0 ; j<n-1 ; ++j)
        {
            if(s[j].cena > s[j+1].cena)
            {
                sor=s[j+1];
                s[j+1]=s[j];
                s[j]=sor;
            }
        }
    }
}


int main(int argc,char **argv)
{
    int znak;

    argv [1] = "film.txt";

    do
    {
        cout<<"\n";
        cout<<"--------Witaj w bazie filmow !!!-------- \n";
        cout<<"**************************************** \n";

        cout<<"\nWybierz jedna z nastepujacych opcji :\n\n";
        cout<<"utworz plik............................1 \n";
        cout<<"dopisanie nowego filmu.................2 \n";
        cout<<"wypisanie wszystkich filmow............3 \n";
        cout<<"sortowanie filmow po cenie.............4 \n";

        cout<<"\n";

        cout<<"wyjscie z programu.....................0 \n\n";

        cout<<"co chcesz robic ? : ";

        cin>>znak;

        switch(znak)
        {
        case 1:
            {

            int n;
			cout<<"Ile filmow zapisac w bazie ?\n\n";
			cin>>n;
			film *s = new film [n];
			dodaj_do_bazy(argv[1],s,n);
			delete [] s;
			break;
            }
        case 2:
            {
                int ile;
                cout<<"ile filmow chczesz dopisac do bazy ? \n\n";
                cin>>ile;

                int roz = rozmiar(argv[1])+ile-1;
                int rozm = rozmiar(argv[1])-1;

                film *s = new film [roz];
			zpliku(argv[1],s,rozm);

			for(int i=rozm;i<roz;++i)
            {
                s[i].numer= i+1;
                cout<<"podaj tytul filu : \n";
                cin>>s[i].tytul;
                cout<<"jak nazywa sie rezyser: \n";
                cin>>s[i].rezyser;
                cout<<"podaj gatunek filmu  \n";
                cin>>s[i].gatunek;
                cout<<"Rok produkcji : \n";
                cin>>s[i].rok;
                cout<<"podaj cene filmu : \n";
                cin>>s[i].cena;

            }
            ofstream plik;
			plik.open(argv[1]);
			for(int i=0;i<roz;++i)
            {
                plik<<s[i].numer<<endl;
                plik<<s[i].tytul<<endl;
                plik<<s[i].rezyser<<endl;
                plik<<s[i].gatunek<<endl;
                plik<<s[i].rok<<endl;
                plik<<s[i].cena<<endl;
            }
            plik.close();
            delete [] s;
            break;

            }
        case 3:
            {
                cout<<"filmy w bazie :\n\n";

			int n = rozmiar(argv[1])-1;
			film *s = new film [n];
			zpliku(argv[1],s,n);
			wypisz(s,n);

			delete [] s;
			break;
            }
        case 4:
            {
             cout<<"filmy z bazy posortowane po cenie :\n\n";
			int n = rozmiar(argv[1])-1;
			film *s = new film [n];
			zpliku(argv[1],s,n);
			sort(s,n);
			wypisz(s,n);

			delete [] s;
			break;
            }
        case 0:
            {
                cout<<"\nDziekuje :) i Dowidzenia .!\n";

            }
        }

    }while(znak != 0);
    return 0;


    }
