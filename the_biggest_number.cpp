#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int a,b,c;

	cout<<"podaj a: ";
	cin>>a;
	cout<<"podaj b: ";
	cin>>b;
	cout<<"podaj c: ";
	cin>>c;

	if(a>b)
	{
		if(a>c)
			cout<<"a jest najwieksze";
		else
			cout<<"c jest najwieksze";
	}
	else
	{
		if(b>c)
			cout<<"b jest najwieksze";
	}


	_getch();
	return 0;
}