#include <iostream>
#include <string>
using namespace std;

class CDate
{
private:
	int year, month, day;
public:
	CDate();
	CDate(int y, int m, int d);
	CDate(const CDate &cpDate);
	void set(int y, int m, int d);
	bool isLeapYear();
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getDayofYear();
};
CDate::CDate() {year = 0; month = 0; day = 0;}

CDate::CDate(int y, int m, int d)
{ 	
	year = y, month = m,day = d;	
}

CDate::CDate(const CDate &cpDate)
{
	year = cpDate.year;
	month = cpDate.month;
	day = cpDate.day;
}

void CDate::set(int y, int m, int d)
{ 	
	year = y, month = m,day = d;	
}

bool CDate::isLeapYear()
{ 
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; 	
}

int CDate::getYear() const{ return year;}

int CDate::getMonth() const{ return month;}

int CDate::getDay() const{ return day;}

int CDate::getDayofYear()
{	
	int i, sum = day;	
	int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	
	if (isLeapYear()) a[2]++;
	
	// 求日期的天数
	for (i = 0; i < month; i++)	{ sum += a[i];}
	return sum;
}

class Software
{
private:
	string name;
	char type;
	char stoMed; //存储介质
	CDate effDate;
public:
	Software(string iname, char itype, char istoMed, CDate date);
	Software(const Software &cpSW);
	char getType();
	char getStoMed();
	string getName();
	void isexp();
};

Software::Software(string iname, char itype, char istoMed, CDate idate)
{
	name = iname;
	type = itype;
	stoMed = istoMed;
	effDate.set(idate.getYear(), idate.getMonth(), idate.getDay());	
}

Software::Software(const Software &cpSW)
{
	name = cpSW.name;
	type = 'B';
	stoMed = 'H';
	effDate.set(cpSW.effDate.getYear(), cpSW.effDate.getMonth(), cpSW.effDate.getDay());
}

char Software::getType() {return type; }
char Software::getStoMed() {return stoMed;}
string Software::getName() {return name;}
void Software::isexp()
{
	int year = effDate.getYear();
	int month = effDate.getMonth();
	int day = effDate.getDay();
	if(year==0&&month==0&&day==0)
	{
		cout << "this software has unlimited use" << endl;
	}
	else if(year*10000+month*100+day>=20150407)
	{
		CDate today(2015,4,7);
		int remday = effDate.getDayofYear()-today.getDayofYear();
		for(int i=today.getYear();i<effDate.getYear();i++)
		{
			CDate temp(i,12,31);
			remday+=temp.getDayofYear();
		}
		cout << "this software is going to be expired in " << remday << " days" << endl;
	}	
	else
	{
		cout << "this software has expired" << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	
	string name;
	char type;
	char StoMed;
	int year;
	int month;
	int day;
	for(int i=0;i<t;i++)
	{
		cin >> name >> type >> StoMed >> year >> month >> day;
		CDate date(year, month, day);
		Software sw(name, type, StoMed, date);
		cout << "name:" << sw.getName() << endl;
		if(sw.getType()=='O') cout << "type:original" << endl;
		else if(sw.getType()=='T') cout << "type:trial" << endl;
		else if(sw.getType()=='B') cout << "type:backup" << endl;
		if(sw.getStoMed()=='H') cout << "media:hard disk" << endl;
		else if(sw.getStoMed()=='U') cout << "media:USB disk" << endl;
		else if(sw.getStoMed()=='D') cout << "media:optical disk" << endl;
		sw.isexp();
		cout << endl;
		Software backup(sw);
		cout << "name:" << backup.getName() << endl;
		if(backup.getType()=='O') cout << "type:original" << endl;
		else if(backup.getType()=='T') cout << "type:trial" << endl;
		else if(backup.getType()=='B') cout << "type:backup" << endl;
		if(backup.getStoMed()=='H') cout << "media:hard disk" << endl;
		else if(backup.getStoMed()=='U') cout << "media:USB disk" << endl;
		else if(backup.getStoMed()=='D') cout << "media:optical disk" << endl;
		backup.isexp();
		cout << endl;
	}
	
	return 0;
}
