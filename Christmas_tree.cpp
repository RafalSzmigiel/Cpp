#include <iostream>

using namespace std;

int main()
{
	int wysokosc;
	cout<<"podaj jaka wysokosc ma miec choinka : ";
	cin>>wysokosc;
	cout<<endl;

	for(int i =0; i<wysokosc ; i++)
	{
		for(int j=0; j<wysokosc-i ; j++)	cout<<" ";

		for(int j=0; j<i*2-1 ; j++)	 cout<<"*";

		cout<<endl;
	}

	for(int i=0;i<wysokosc-1;i++)	cout<<" ";

	cout<<"#";

	cout<<endl<<endl;

	system ("pause");
}