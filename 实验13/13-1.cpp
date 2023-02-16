#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class CTime
{
private:
	int hour, minute, second;
public:
	CTime(int h, int m, int s);
	CTime(const CTime &t);
	CTime operator++();
	CTime operator--(int);
	void display();
};

CTime::CTime(int h, int m, int s)
{
	hour = h; minute = m; second = s;
}

CTime::CTime(const CTime &t)
{
	hour = t.hour;
	minute = t.minute;
	second = t.second;
}

CTime CTime::operator++()
{
	if((++second) == 60)
	{
		second = 0;
		if((++minute) == 60)
		{
			minute = 0;
			if((++hour) == 12)	hour = 0;
		}
	}
	return *this;
}

CTime CTime::operator--(int)
{
	CTime t(hour, minute, second);
	if(--second == -1)
	{
		second = 59;
		if(--minute == -1)
		{
			minute = 59;
			if(--hour == -1) hour = 11;
		}
	}
	
	return t;
}

void CTime::display()
{
	cout << hour << ':' << minute << ':' << second << endl;
}


int main()
{
	int h, m, s;
	cin >> h >> m >> s;
	CTime t(h, m, s);
	
	int n;
	cin >> n;
	int ope;
	for(int i=0;i<n;i++)
	{
		cin >> ope;
		for(int i=0;ope>0 && i<ope;i++)
		{
			++t;
		}
		for(int i=0;ope<0 && i<(-ope);i++){
			t--;
		}
		t.display();
	}
	
	return 0;
}
