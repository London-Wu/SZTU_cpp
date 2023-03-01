#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Account
{
private:
	static float count; // 账户总余额
	static float interestRate;
	string accno, accname;
	float balance;
public:
	Account(string ac, string an, float ba);
	void deposit(float amount); // 存款
	void withdraw(float amount); // 取款
	float getBalance(); // 获取账户余额
	void show(); // 显示账户所以基本信息
	static float getCount(); // 获取账户总余额
	static void setInterestRate(float rate); // 设置利率
	static float getInterestRate(); // 获取利率
	friend void update(Account &a);
};

float Account::count = 0;
float Account::interestRate = 0;

Account::Account(string ac, string an, float ba)
{
	accno = ac; accname = an; balance = ba;
	count += ba;
}

void Account::deposit(float amount)
{
	balance += amount;
	count += amount;
}

void Account::withdraw(float amount)
{
	balance -= amount;
	count -= amount;
}

float Account::getBalance() { return balance;}

void Account::show()
{
	cout << accno << ' ' << accname << ' ';
} 

float Account::getCount() { return count;}

void Account::setInterestRate(float rate) { interestRate = rate;}

float Account::getInterestRate() { return interestRate;}

void update(Account &a)
{
	a.count += a.balance * a.interestRate;
	a.balance = a.balance + a.balance * a.interestRate;
}

int main()
{
	float rate;
	cin >> rate;
	Account::setInterestRate(rate);
	
	int t;
	cin >> t;
	
	string accno;
	string accname;
	float bal;
	float deamo;
	float wiamo;
	
	for(int i=0;i<t;i++)
	{
		cin >> accno >> accname >> bal;
		Account ac(accno, accname, bal);
		ac.show();
		
		cin >> deamo >> wiamo;
		ac.deposit(deamo);
		cout << ac.getBalance() << ' ';
		update(ac);
		cout << ac.getBalance() << ' ';
		ac.withdraw(wiamo);
		cout << ac.getBalance() << endl;
	}
	cout << Account::getCount();
	
	
	return 0;
}
