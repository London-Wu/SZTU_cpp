#include <iostream>
#include <iomanip>

using namespace std;

bool isleapyear(int year)
{
	if(year % 400 == 0) return 1;
	else if(year % 4 == 0 && year % 100 != 0) return 1;
	else return 0;
}

class Date
{
private:
	
	int year, month, day;
	
public:
	
	Date();
	Date(int y, int m, int d);
	int getYear();
	int getMonth();
	int getDay();
	void setDate(int y, int m, int d);
	void print();
	void addOneDay();
	
};

Date::Date() { year=1900; month=1; day=1;}
Date::Date(int y, int m, int d) { year=y; month=m; day=d;}
int Date::getYear() { return year;}
int Date::getMonth() { return month;}
int Date::getDay() { return day;}
void Date::setDate(int y, int m, int d) { year=y; month=m; day=d;}
void Date::print()
{
	cout << year << "/";
	cout << setw(2) << setfill('0') << month << "/";
	cout << setw(2) << setfill('0') << day << endl;
}
void Date::addOneDay()
{
	int daysnum[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(isleapyear(year)) daysnum[2]++;
	if(day == daysnum[month])
	{
		month++;
		day = 1;
	}
	else day++;
	if(month == 13)
	{
		month = 1;
		year++;
	}
}

int main()
{
	int t;
	cin >> t;
	
	int inp_y, inp_m, inp_d;
	Date date;
	for(int i=0;i<t;i++)
	{
		cin >> inp_y >> inp_m >> inp_d;
		date.setDate(inp_y, inp_m, inp_d);
		cout << "Today is ";
		date.print();
		date.addOneDay();
		cout << "Tomorrow is ";
		date.print();
	}
	
	return 0;
}
