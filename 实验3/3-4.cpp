#include <iostream>
#include <string>
using namespace std;

struct Bir{
	int year;
	int month;
	int day;
};

int BirComp(Bir bir1, Bir bir2)
{
	if(bir1.year > bir2.year) return 1;
	else if(bir1.year < bir2.year) return 0;
	
	if(bir1.month > bir2.month) return 1;
	else if(bir1.month < bir2.month) return 0;
	
	if(bir1.day >= bir2.day) return 1;
	else if(bir1.day < bir2.day) return 0;
}

int main()
{
	int t;
	cin >> t;
	Bir birs[20];
	
	for(int i=0;i<t;i++)
	{
		cin >> birs[i].year >> birs[i].month >> birs[i].day;
	}
	
	Bir fir=birs[0];
	Bir sec=birs[1];
	for(int i=1;i<t;i++)
	{
		if(BirComp(fir, birs[i]))
		{
			sec = fir;
			fir = birs[i];
		}
		else if(BirComp(sec, birs[i]))
		{
			sec = birs[i];
		}
	}
	
	cout << sec.year << '-' << sec.month << '-' << sec.day << endl;
	
	return 0;
}
