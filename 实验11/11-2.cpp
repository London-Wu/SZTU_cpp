#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class Vehicle
{
protected:
	string no; //编号
public:
	virtual void display() = 0; //应收费用
};

class Car : public Vehicle
{
protected:
	int pasNum, weight;
public:
	Car(string no1 ,int pasNum1, int weight1);
	void display();
};

Car::Car(string no1, int pasNum1, int weight1):pasNum(pasNum1), weight(weight1)
{ no = no1;}
void Car::display()
{
	cout << no << ' ' << pasNum * 8 + weight * 2 << endl;
}

class Truck : public Vehicle
{
protected:
	int weight;
public:
	Truck(string no1, int weight1);
	void display();
};

Truck::Truck(string no1, int weight1):weight(weight1){ no = no1; }

void Truck::display()
{
	cout << no << ' ' << weight * 5 << endl;
}

class Bus : public Vehicle
{
protected:
	int pasNum;
public:
	Bus(string no1, int pasNum1);
	void display();
};

Bus::Bus(string no1, int pasNum1) :pasNum(pasNum1) { no = no1; }

void Bus::display()
{
	cout << no << ' ' << pasNum * 30 << endl;
}

int main()
{
	int t;
	cin >> t;
	Vehicle* pv;
	int pasNum, weight;
	int type;
	string no;
	
	for (size_t i = 0; i < t; i++)
	{
		cin >> type;
		cin >> no;
		if (type == 1)
		{
			cin >> pasNum >> weight;
			pv = new Car(no, pasNum, weight);
			pv->display();
		}
		else if (type == 2)
		{
			cin >> weight;
			pv = new Truck(no, weight);
			pv->display();
		}
		else
		{
			cin >> pasNum;
			pv = new Bus(no, pasNum);
			pv->display();
		}
	}
	
	return 0;
}
