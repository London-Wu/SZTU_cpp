#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class BaseAccount
{
protected:
	string name;
	string account;
	int balance;
public:
	BaseAccount();
	BaseAccount(string name1, string account1, int balance1);
	virtual void deposit(int amount);
	virtual void withdraw(int amount);
	virtual void display();
};

BaseAccount::BaseAccount(){}

BaseAccount::BaseAccount(string name1, string account1, int balance1)
{
	name = name1; account = account1; balance = balance1;
}

void BaseAccount::deposit(int amount) { balance += amount; }
void BaseAccount::withdraw(int amount)
{
	if (amount > balance) { cout << "insufficient" << endl; }
	else balance -= amount;
}
void BaseAccount::display()
{
	cout << name << ' ' << account << " Balance:" << balance << endl;
}

class BasePlus:public BaseAccount
{
protected:
	int limit, limitsum;
public:
	BasePlus(string name1, string account1, int balance1);
	void deposit(int amount);
	void withdraw(int amount);
	void display();
};

BasePlus::BasePlus(string name1, string account1, int balance1)
{
	name = name1; account = account1, balance = balance1;
	limit = 5000;
	limitsum = 0;
}

void BasePlus::deposit(int amount)
{
	if (limitsum > 0)
	{
		limitsum -= amount;
		if (limitsum < 0)
		{
			balance += (-limitsum);
			limitsum = 0;
		}
	}
	else balance += amount;
}

void BasePlus::withdraw(int amount)
{
	if (balance < amount)
	{
		if (limitsum + (amount - balance) > limit) cout << "insufficient" << endl;
		else
		{
			limitsum += (amount - balance);
			balance = 0;
		}
	}
	else balance -= amount;
}

void BasePlus::display()
{
	cout << name << ' ' << account << " Balance:" << balance << " limit:" << limit-limitsum << endl;
}



int main()
{
	int t;
	cin >> t;
	BaseAccount* acc;
	string name, account;
	int balance;
	int amount;
	
	for (size_t i = 0; i < t; i++)
	{
		cin >> name >> account >> balance;
		if (account[1] == 'A') acc = new BaseAccount(name, account, balance);
		else acc = new BasePlus(name, account, balance);
		
		cin >> amount;
		acc->deposit(amount);
		cin >> amount;
		acc->withdraw(amount);
		cin >> amount;
		acc->deposit(amount);
		cin >> amount;
		acc->withdraw(amount);
		acc->display();
	}
	
	return 0;
}
