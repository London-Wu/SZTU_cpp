#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

class Date
{
protected:
	int year, month, day;
public:
	void setDate(int y, int m, int d);
	friend int compareDate(const Date &d1, const Date &d2);
};

void Date::setDate(int y, int m, int d)
{ year = y; month = m; day = d;}

int compareDate(const Date &d1, const Date &d2)
{
	int dd1 = d1.year*10000 + d1.month*100 + d1.day;
	int dd2 = d2.year*10000 + d2.month*100 + d2.day;
	if(dd1 < dd2) return 1;
	else if(dd1 == dd2) return 0;
	else return -1;
}

class Time
{
protected:
	int hour, minute, second;
public:
	void setTime(int h, int m, int s);
	friend int compareTime(const Time &t1, const Time &t2);
};

void Time::setTime(int h, int m, int s)
{ hour = h; minute = m; second = s;}

int compareTime(const Time &t1, const Time &t2)
{
	int dd1 = t1.hour*10000 + t1.minute*100 + t1.second;
	int dd2 = t2.hour*10000 + t2.minute*100 + t2.second;
	if(dd1 < dd2) return 1;
	else if(dd1 == dd2) return 0;
	else return -1;
}

class Work: public Date, public Time
{
protected:
	int id;
public:
	Work(int id1, int y, int m, int d, int hh, int mm, int ss);
	bool before(const Work& w1, const Work& w2);
	void print();
	friend bool before(const Work&w1,const Work&w2);
};

Work::Work(int id1, int y, int m, int d, int hh, int mm, int ss)
{
	id = id1;
	setDate(y, m, d);
	setTime(hh, mm, ss);
}

bool before(const Work& w1, const Work& w2)
{
	int cd = compareDate(w1, w2);
	if(cd == 1) return 1;
	else if(cd == -1) return 0;
	else
	{
		int ct = compareTime(w1, w2);
		if(ct == 1) return 1;
		else return 0;
	}
}

void Work::print() {cout<<"The urgent Work is No."<<id<<": "<<year<<"/"<<setw(2)<<setfill('0')<<month<<"/"<<setw(2)<<setfill('0')<<day<<' '<<setw(2)<<setfill('0')<<hour<<':'<<setw(2)<<setfill('0')<<minute<<':'<<setw(2)<<setfill('0')<<second<<endl;}


int main()
{
	int ID,year,month,day,hour,minute,second;
	cin>>ID>>year>>month>>day>>hour>>minute>>second;
	Work w1(ID,year,month,day,hour,minute,second);
	while(1)
	{
		cin>>ID;
		if(ID==0)
			break;
		cin>>year>>month>>day>>hour>>minute>>second;
		Work w2(ID,year,month,day,hour,minute,second);
		if(before(w1,w2)==0)
			w1=w2;	
	}
	w1.print();
	return 0;
}
