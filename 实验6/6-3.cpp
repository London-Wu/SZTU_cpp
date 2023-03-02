#include <iostream>
#include <cstring>
using namespace std;

class CTelNumber
{
private:
	
	char* number;
	
public:
	CTelNumber();
	CTelNumber(const CTelNumber& Obj);
	~CTelNumber();
	void output();
	
};

CTelNumber::CTelNumber()
{
	number = new char[8];
	cin >> number;
}

CTelNumber::CTelNumber(const CTelNumber& Obj)
{
	number = new char[9];
	for (int i = 0; i < 7; i++)
	{
		if (Obj.number[i] < '0' || Obj.number[i] > '9')
		{
			cout << "Illegal phone number" << endl;
			return;
		}
	}
	if (strlen(Obj.number) != 7) cout << "Illegal phone number" << endl;
	else if (Obj.number[0] >= '2' && Obj.number[0] <= '4')
	{
		for (int i = 1; i < 8; i++)
		{
			number[i] = Obj.number[i - 1];
		}
		number[8] = '\0';
		number[0] = '8';
		cout << number << endl;
	}
	else if (Obj.number[0] >= '5' && Obj.number[0] <= '8')
	{
		for (int i = 1; i < 8; i++)
		{
			number[i] = Obj.number[i - 1];
		}
		number[8] = '\0';
		number[0] = '2';
		cout << number << endl;
	}
	else cout << "Illegal phone number" << endl;
	
}

CTelNumber::~CTelNumber() { delete number; }

void CTelNumber::output() { cout << number << endl; }

int main()
{
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		
		CTelNumber tel;
		CTelNumber newtel(tel);
	}
	
	return 0;
}
