#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class CMoney
{
private:
	int y,j,f;
public:
	CMoney(int yy, int jj, int ff);
	CMoney& operator=(const CMoney& m);
	friend CMoney operator+(const CMoney& m1, const CMoney& m2);
	friend CMoney operator-(const CMoney& m1, const CMoney& m2);
	friend ostream& operator<<(ostream& os, const CMoney& m);
	friend istream& operator>>(istream& is, CMoney& m);
};

CMoney::CMoney(int yy=0, int jj=0, int ff=0)
{
	y = yy; j = jj; f = ff;
}

CMoney& CMoney::operator=(const CMoney& m)
{
	y = m.y; j = m.j; f = m.f;
	return *this;
}

CMoney operator+(const CMoney& m1, const CMoney& m2)
{
	int y=0, j=0, f=0;
	f = m1.f + m2.f;
	j = m1.j + m2.j;
	y = m1.y + m2.y;
	if(f>=10) {f %= 10; j++;}
	if(j>=10) {j %= 10; y++;}
	
	return CMoney(y,j,f);
}

CMoney operator-(const CMoney& m1, const CMoney& m2)
{
	int y=0, j=0, f=0;
	f = m1.f - m2.f;
	j = m1.j - m2.j;
	y = m1.y - m2.y;
	if(f<0) {f += 10; j--;}
	if(j<0) {j += 10; y--;}
	
	return CMoney(y,j,f);
}



ostream& operator<<(ostream& os, const CMoney& m)
{
	os << m.y << "元" << m.j << "角" << m.f << "分";
	return os;
}

istream& operator>>(istream& is, CMoney& m)
{
	int yy, jj, ff;
	is >> yy >> jj >> ff;
	m.y = yy; m.j = jj; m.f = ff;
	return is;
}

int main()
{
	int t; cin >> t;
	string opr;
	for(int i=0;i<t;i++)
	{
		CMoney m1, m2;
		cin >> m1;
		while(1)
		{
			cin >> opr;
			if(opr == "add") {cin >> m2; m1 = m1 + m2;}
			else if(opr == "minus") {cin >> m2; m1 = m1 - m2;}
			else if(opr == "stop")
			{
				cout << m1 << endl;
				break;
			}
		}
	}
	return 0;
}
