#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

class CDate
{
private:
	int year, month, day;
public:
	CDate(int, int, int);
	bool check(); //检验日期是否合法
	bool isLeap();
	void print();
	void set(int, int, int);
	void set(CDate& date);
	int getYear();
	int getMonth();
	int getDay();
};

CDate::CDate(int y=2000, int m=1, int d=1)
{ year = y; month = m; day = d;}

bool CDate::check()
{
	bool isVaild = true;
	int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(isLeap()) daysInMonth[2]++;
	if(!(month >= 0 && month <= 12)) isVaild = false;
	if(!(day >= 0 && day <= daysInMonth[month])) isVaild = false;
	
	
	return isVaild;
}

bool CDate::isLeap()
{
	if(year % 400 == 0) return 1;
	else if(year % 4 == 0 && year % 100 != 0) return 1;
	else return 0;
}

void CDate::print()
{
	cout << year << "年" << month << "月" << day << "日";
}

void CDate::set(int y, int m, int d) { year = y; month = m; day = d;}

void CDate::set(CDate& date)
{
	year = date.year;
	month = date.month;
	day = date.day;
}

int CDate::getYear() { return year;}

int CDate::getMonth() { return month;}

int CDate::getDay() { return day;}

class COldId
{
protected:
	char* pId15, * pName; 
	CDate birthday; 
public:
	COldId();
	COldId(char* pIdVal, char* pNameVal, CDate& day);
	bool check();
	~COldId();
};

COldId::COldId()
{
	pName = new char[20];
	pId15 = new char[20];
}

COldId::COldId(char* pIdVal, char* pNameVal, CDate& day)
{
	pName = new char[20];
	pId15 = new char[20];
	strcpy(pName, pNameVal);
	strcpy(pId15, pIdVal);
	birthday.set(day);
}

COldId::~COldId() { delete[] pName; delete[] pId15;}

bool COldId::check()
{	
	if(!birthday.check()) return false; //检查日期
	if(strlen(pId15)!=15) return false; //检查长度
	for(int i=0;i<15;i++)
	{
		if(!(pId15[i]>='0' && pId15[i]<='9')) return false; //检查字符
	}
	
	// 检查是否对应
	char id1t6[7];
	int year2, month2, day2;
	sscanf(pId15, "%6s%2d%2d%2d",id1t6, &year2, &month2, &day2); 
	if(year2 != birthday.getYear()%100) return false;
	if(month2 != birthday.getMonth()) return false;
	if(day2 != birthday.getDay()) return false;
	
	return true;
}

class CNewId: public COldId
{
protected:
	char *pId18;
	CDate issueDay;
	int validYear;
public:
	CNewId(char* pIdVal,char* pIdVal18, char* pNameVal, CDate& day, CDate &issd, int valy);
	bool check();
	char getCheckCode();
	bool isInvalid(); // 是否过期
	bool isSame();
	void print();
	~CNewId();
};

CNewId::CNewId(char* pIdVal,char* pIdVal18, char* pNameVal, CDate& day, CDate &issd, int valy)
{
	pName = new char[20];
	pId15 = new char[20];
	pId18 = new char[20];
	strcpy(pName, pNameVal);
	strcpy(pId15, pIdVal);
	strcpy(pId18, pIdVal18);
	
	birthday.set(day);
	issueDay.set(issd);
	validYear = valy;
	
}

CNewId::~CNewId()
{
	delete[] pId18;
}

char CNewId::getCheckCode()
{
	int mulNums[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int sum = 0;
	for(int i=0;i<17;i++)
	{
		sum += (pId18[i]-'0')*mulNums[i];
	}
	
	int codes[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
	char check_code = codes[sum % 11];
	return check_code;
}

bool CNewId::isInvalid()
{
	int curDay10 = 20211109;
	int inValidDay10 = (issueDay.getYear() + validYear)*10000 + issueDay.getMonth()*100 + issueDay.getDay();
	if(curDay10	> inValidDay10) return false;
	else return true;
}

bool CNewId::isSame()
{
	char check_code = getCheckCode();
	char pId15t18[19];
	char pId15_0t5[7], pId15_d3[4];
	sscanf(pId15,"%6s",pId15_0t5);
	sscanf(pId15,"%*12s%3s",pId15_d3);
	sprintf(pId15t18, "%6s%4d%02d%02d%3s%c",\
		pId15_0t5,\
		birthday.getYear(), birthday.getMonth(), birthday.getDay(),\
		pId15_d3, check_code);
	if(strcmp(pId15t18, pId18)) return false;
	else return true;
}

bool CNewId::check()
{
	if(!COldId::check()) return false;
	if(strlen(pId18)!=18) return false; //检查长度
	for(int i=0;i<17;i++)
	{
		if(!(pId18[i]>='0' && pId18[i]<='9')) return false;
	}
	if(!( (pId18[17]>='0' && pId18[17]<='9') || pId18[17]=='X') ) return false; // 检查最后一位
	if(getCheckCode()!=pId18[17]) return false; // 检查校验码
	if(!isSame()) return false; //检查一致性
	if(!isInvalid()) return false; // 检查过期
	if(!issueDay.check()) return false; //检查登记时间
	
	return true;
}

void CNewId::print()
{
	cout << pId18 << ' ';
	issueDay.print();
	if(validYear == 100) cout << " 长期" << endl;
	else cout << ' ' << validYear << "年" << endl;
}

int main()
{
	int t; cin >> t;
	char name[10], pId15[16], pId18[19];
	int year, month, day, iy, im, id, vyear;
	for(int i=0;i<t;i++)
	{
		cin >> name;
		cin >> year >> month >> day;
		CDate birthday(year, month, day);
		cin >> pId15;
		cin >> pId18;
		cin >> iy >> im >> id;
		CDate issueDay(iy, im, id);
		cin >> vyear;
		CNewId id(pId15, pId18, name, birthday, issueDay, vyear);
		cout << name << endl;
		if(id.check()) id.print();
		else cout << "illegal id" << endl;
	}
	
	return 0;
}
