#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class CDate
{
private:
	int year, month, day;
public:
	CDate();
	CDate(int, int, int);
	CDate(int);
	operator int();
	void print();
};

CDate::CDate()
{
	year = 1900; month = 1; day = 1;
}

CDate::CDate(int date)
{
	year = date / 10000; month = date % 10000 / 100; day = date % 100;
}

CDate::CDate(int y, int m, int d)
{
	year = y; month = m; day = d;
}

CDate::operator int()
{
	return year * 10000 + month * 100 + day;
}

void CDate::print()
{
	cout << year << "年";
	cout << setw(2) << setfill('0') << month << "月";
	cout << setw(2) << setfill('0') << day << "日" << endl;
}

int main()
{
	int t, t1, t2;
	CDate c1, c2;
	cin >> t;
	while (t--)
	{
		cin >> t1 >> t2;
		c1 = t1;
		c2 = t2;
		((c1 > c2) ? c1 : c2).print(); //日期大的输出，在代码c1 > c2中，会自动把c1和c2转换为整数进行比较
	}
	return 0;
}
