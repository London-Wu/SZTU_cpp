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
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	void output();
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

int CDate::getYear() const{ return year;}

int CDate::getMonth() const{ return month;}

int CDate::getDay() const{ return day;}

void CDate::output()
{
	cout << year << '.' << month << '.' << day << endl;
}

class TelService
{
private:
	char numType;
	string number;
	int state;
	CDate *StopDate;
	
public:
	TelService(char inumType, string inumber, int istate);
	TelService(const TelService &cpts);
	~TelService();
	void print();
	void Stop(CDate date);
};

TelService::TelService(char inumType, string inumber, int istate)
{
	numType = inumType;
	number = inumber;
	state = istate;
	cout << "Construct a new phone " << number << endl;
}

TelService::~TelService()
{
	if(state == 3) { delete StopDate;}
}

TelService::TelService(const TelService &cpts)
{
	numType = 'D';
	number = cpts.number;
	state = cpts.state;
	if(cpts.state == 3)
	{
		StopDate = new CDate(*cpts.StopDate);
	}
	cout << "Construct a copy of phone " << number << endl;
	if(cpts.numType != 4) number.append("X");
}

void TelService::print()
{
	if(numType == 'A') cout << "类型=机构";
	else if(numType == 'B') cout << "类型=企业";
	else if(numType == 'C') cout << "类型=个人";
	else if(numType == 'D') cout << "类型=备份";
	cout << "||";
	cout << "号码=" << number << "||";
	if(state == 1) cout << "State=在用" << endl;
	else if(state == 2) cout << "State=未用" << endl;
	else if(state == 3)
	{
		cout << "State=停用 ||停机日期=";
		StopDate->output();
	}
}

void TelService::Stop(CDate date)
{
	StopDate = new CDate(date);
	state = 3;
	cout << "Stop the phone " << number << endl;
}

int main()
{
	int t;
	cin >> t;
	
	char numtype;
	string number;
	int state;
	int year, month, day;
	for(int i=0;i<t;i++)
	{
		cin >> numtype >> number >> state >> year >> month >> day;
		CDate date(year, month, day);
		TelService ts(numtype, number, state);
		ts.print();
		TelService tscp(ts);
		tscp.print();
		ts.Stop(date);
		ts.print();
		cout << "----" << endl;
	}
	
	return 0;
}
