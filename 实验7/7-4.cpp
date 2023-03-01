#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>

using namespace std;

class Hotel
{
private:
	static int totalCustNum; // 顾客总人数
	static float totalEarning; // 旅店总收入
	static float rent; // 每个顾客的房租
	char *customerName; // 顾客姓名
	int customerId; // 顾客编号
public:
	// totalCustNum++，customerId按照totalCustNum生成
	Hotel(char* customer);
	~Hotel(); //记得delete customerName
	void Display(); //相应输出顾客姓名、顾客编号、总人数、总收入
	static void setRent(float irent);
};

int Hotel::totalCustNum = 0;
float Hotel::totalEarning = 0;
float Hotel::rent = 99999999; 

Hotel::Hotel(char *customer)
{
	customerName = new char[20];
	strcpy(customerName, customer);
	customerId = 20150000 + (++totalCustNum);
	totalEarning += rent;
}

Hotel::~Hotel(){ delete[] customerName; }

void Hotel::Display()
{
	cout << customerName << ' ' << customerId << ' ';
	cout << totalCustNum << ' ' << totalEarning << endl; 
}

void Hotel::setRent(float irent) { rent = irent;}

int main()
{
	int rent;
	cin >> rent;
	Hotel::setRent(rent);
	
	char name[20];
	
	while(1)
	{
		cin >> name;
		if(name[0] == '0') break;
		Hotel cus(name);
		cus.Display();
	}
	
	return 0;
}
