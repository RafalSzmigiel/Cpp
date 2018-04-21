#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

	int n=0;
	int zmienna=1;
	bool flaga=false;

	do{

	cout<<"podaj n: ";
	cin>>n;

	if(n>0)
		flaga=true;
	else
		cout<<"podales ujemna liczbe\n";
		
	}while(flaga==0);


	while(n>0)
	{
		zmienna=zmienna*n;
		n--;
	};

	cout<<zmienna<<endl;

	system("pause");
	return EXIT_SUCCESS;
}