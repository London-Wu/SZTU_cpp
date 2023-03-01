#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class VipCard
{
protected:
	int id1; int jf1; 
public:
	VipCard(int id1);
	void xiadan(float m);
};

VipCard::VipCard(int id11)
{
	id1 = id11; jf1 = 0;
}

void VipCard::xiadan(float m)
{
	jf1 += m;
}

class Credit
{
protected:
	int id2, ed;
	float jf2;
	string name;
	float je;
public:
	Credit(int id22, string name, int ed1);
	void xiaofei(float m);
	void tuikuan(float m);
};

Credit::Credit(int id22, string name1, int ed1)
{
	id2 = id22; name = name1; ed = ed1;
	jf2 = 0; je = 0;
}

void Credit::xiaofei(float m)
{
	if (m <= ed)
	{
		je += m; ed -= m;
		jf2 += m;
	}
}

void Credit::tuikuan(float m)
{
	je -= m; ed += m;
	jf2 -= m;
}

class VipCredit: public Credit, public VipCard
{
public:
	VipCredit(int id11, int id22, string name1, int ed1);
	void xiadan3(float m);
	void change(float m);
	void display();
};

VipCredit::VipCredit(int id11, int id22, string name1, int ed1):\
VipCard(id11), Credit(id22, name1, ed1){}

void VipCredit::xiadan3(float m)
{
	VipCard::xiadan(m);
	Credit::xiaofei(m);
}

void VipCredit::change(float m)
{
	jf1 += m / 2;
	jf2 -= m;
}

void VipCredit::display()
{
	cout << id1 << ' ' << jf1 << endl;
	
	cout << id2 << ' ' << name << ' ' << je << ' ';
	cout << fixed << setprecision(0) << jf2 << endl;
}


int main()
{
	int id1, id2;
	string name;
	int ed;
	cin >> id1 >> id2 >> name >> ed;
	VipCredit vc(id1, id2, name, ed);
	
	char opr;
	int n;
	float m;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> opr >> m;
		if (opr == 'o')
		{
			vc.xiadan(m); vc.xiaofei(m);
		}
		else if (opr == 'c') vc.xiaofei(m);
		else if (opr == 'q') vc.tuikuan(m);
		else if (opr == 't') vc.change(m);
	}
	vc.display();
	
	return 0;
}
