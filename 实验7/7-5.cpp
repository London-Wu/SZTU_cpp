#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Time;

class Date
{
private:
	int year, month, day;
	
public:
	Date();
	Date(int iyear, int imonth, int iday);
	friend void display(const Date &d, const Time &t);
	
};

class Time
{
private:
	int hour, min, sec;
	
public:
	Time();
	Time(int ihour, int imin, int isec);
	friend void display(const Date &d, const Time &t);
};

Date::Date():year(1900), month(1), day(1){}
Date::Date(int iyear, int imonth, int iday)
{ year = iyear; month = imonth; day = iday;}

Time::Time():hour(0), min(0), sec(0){}
Time::Time(int ihour, int imin, int isec)
{ hour = ihour; min = imin; sec = isec;}

void display(const Date &d, const Time &t)
{
	cout << setw(4) << setfill('0') << d.year << '-';
	cout << setw(2) << setfill('0') << d.month << '-';
	cout << setw(2) << setfill('0') << d.day << ' ';
	cout << setw(2) << setfill('0') << t.hour << ':';
	cout << setw(2) << setfill('0') << t.min << ':';
	cout << setw(2) << setfill('0') << t.sec << endl;
}

int main()
{
	int t;
	cin >> t;
	int year, month, day, hour, min, sec;
	
	for(int i=0;i<t;i++)
	{
		cin >> year >> month >> day >> hour >> min >> sec;
		Date date(year, month ,day);
		Time time(hour, min, sec);
		display(date, time);
	}
	
	return 0;
}
