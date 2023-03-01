#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class CCounter
{
protected:
	int value;
public:
	CCounter(int value1);
	void increment();
	void set(int v);
	int get();
};

CCounter::CCounter(int value1 = 0) { value = value1;}

void CCounter::increment() { value++;}

void CCounter::set(int v) { value = v;}

int CCounter::get() { return value; }

class LoopCounter: public CCounter
{
protected:
	int minValue, maxValue;
public:
	LoopCounter();
	LoopCounter(int minV, int maxV);
	void setminmax(int minV, int maxV);
	bool increment();
};

LoopCounter::LoopCounter() { minValue = 0; maxValue = 59; }

LoopCounter::LoopCounter(int minV, int maxV)
{
	minValue = minV; maxValue = maxV;
}

void LoopCounter::setminmax(int minV, int maxV)
{ minValue = minV; maxValue = maxV;}

bool LoopCounter::increment()
{
	value++;
	if(value > maxValue) { value = minValue; return 1;}
	else return 0;
}

class CClock
{
private:
	LoopCounter hour, minute, second;
public:
	CClock(int h, int m, int s);
	void increment();
	void ctime(int s);
	void print();
};

CClock::CClock(int h, int m, int s)
{
	hour.setminmax(0,23);
	hour.set(h); minute.set(m); second.set(s);
	
}

void CClock::increment()
{
	if(second.increment() == true)
	{
		if(minute.increment() == true) hour.increment();	
	}
}

void CClock::ctime(int s)
{
	for(int i=0;i<s;i++) increment();
}

void CClock::print()
{
	cout << hour.get() << ':' << minute.get() << ':' << second.get() << endl;
}

int main()
{
	int t; cin >> t;
	
	int h, m, s, time_s;
	for(int i=0;i<t;i++)
	{
		cin >> h >> m >> s;
		CClock clock(h, m, s);
		cin >> time_s;
		clock.ctime(time_s);
		clock.print();
	}
	
	return 0;
}
