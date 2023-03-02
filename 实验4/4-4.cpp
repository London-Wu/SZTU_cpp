#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cat{
private:
	string _name;
	int _weight;
	
public:
	string getName();
	int getWeight();
	void set(string iname, double iweight);
};

void Cat::set(string iname, double iweight)
{
	_name = iname;
	_weight = iweight;
}

string Cat::getName() {return _name;}
int Cat::getWeight() {return _weight;}

void cat_sort(Cat *catsp, int n)
{
	Cat temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(catsp[j].getWeight() > catsp[j+1].getWeight())
			{
				temp = catsp[j];
				catsp[j] = catsp[j+1];
				catsp[j+1] = temp;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	
	string inpname;
	int inpweig;
	Cat *cats = new Cat[n];
	
	for(int i=0;i<n;i++)
	{
		cin >> inpname >> inpweig;
		cats[i].set(inpname, inpweig);
	}
	
	cat_sort(cats, n);
	
	for(int i=0;i<n;i++)
	{
		cout << cats[i].getName() << " ";
	}
	
	delete[] cats;
	
	
	return 0;
}
