#include <iostream>
#include <string>
using namespace std;

class CAccount{
public:
	long account;
	char *name;
	float balance;
	
	void input(long ipacc, char* ipnam, float ipbal);
	void deposit(float amount);
	void withdraw(float amount);
	void check();
};

void CAccount::input(long ipacc, char *ipnam, float ipbal)
{
	account = ipacc;
	name = ipnam;
	balance = ipbal;
}

void CAccount::deposit(float amount)
{
	balance+=amount;
	cout << "saving ok!" << endl;
}

void CAccount::withdraw(float amount)
{
	if(amount <= balance)
	{
		balance-=amount;
		cout << "withdraw ok!" << endl;
	}
	else
	{
		cout << "sorry! over limit!" << endl;
	}
}

void CAccount::check()
{
	cout << name << "'s balance is " << balance << endl;
}

int main()
{
	long account;
	char name[10];
	float balance;
	float amount;
	CAccount accs[2];
	for(int i=0;i<2;i++)
	{
		cin >> account >> name >> balance;
		accs[i].input(account, name, balance);
		accs[i].check();
		cin >> amount;
		accs[i].deposit(amount);
		accs[i].check();
		cin >> amount;
		accs[i].withdraw(amount);
		accs[i].check();
	}
	
	return 0;
}
