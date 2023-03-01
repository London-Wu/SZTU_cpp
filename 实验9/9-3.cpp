#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class BankAcc
{
private:
	float balance;
	float rate;
	int number;
	char type;
public:
	BankAcc(int number1, char type1, float balance1);
	void cal(); //计息
	void inq(); //查询
	BankAcc(const BankAcc& bacc);
};

BankAcc::BankAcc(int number1, char type1, float balance1)
{
	number = number1;
	type = type1;
	balance = balance1;
	rate = 0.005;
}

void BankAcc::cal()
{
	balance += balance * rate;
	cout << "Account=" << number << "--";
	cout << "sum=" << fixed << setprecision(0) << balance << endl;
}

void BankAcc::inq()
{
	cout << "Account=" << number << "--";
	if (type == 'P') cout << "Person--";
	else cout << "Enterprise--";
	cout << "sum=" << fixed << setprecision(0) << balance << "--";
	cout << "rate=" << fixed << setprecision(3) << rate << endl;
}

BankAcc::BankAcc(const BankAcc& bacc)
{
	number = bacc.number + 50000000;
	rate = 0.015;
	type = bacc.type;
	balance = bacc.balance;
}

int main()
{
	int t;
	cin >> t;
	
	int number;
	char type;
	float balance;
	char opr_code;
	
	for (size_t i = 0; i < t; i++)
	{
		cin >> number >> type >> balance;
		BankAcc bacc(number, type, balance);
		BankAcc bacc_cp(bacc);
		cin >> opr_code;
		if (opr_code == 'C') bacc.cal();
		else if(opr_code == 'P') bacc.inq();
		cin >> opr_code;
		if (opr_code == 'C') bacc_cp.cal();
		else if (opr_code == 'P') bacc_cp.inq();
	}
	
	return 0;
}
