#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CVehicle
{
protected:
	int max_speed, speed, weight;
public:
	CVehicle(int m, int s, int w);
	void display();
};

CVehicle::CVehicle(int m, int s, int w)
{ max_speed = m; speed = s; weight = w;}

void CVehicle::display()
{
	cout << "Vehicle:" << endl;
	cout << "max_speed:" << max_speed << endl;
	cout << "speed:" << speed << endl;
	cout << "weight:" << weight << endl;
	cout << endl;
}

class CBicycle: virtual public CVehicle
{
protected:
	int height;
public:
	CBicycle(int m, int s, int w, int h);
	void display();
};

CBicycle::CBicycle(int m, int s, int w, int h):\
CVehicle(m, s, w) { height = h; }

void CBicycle::display()
{
	cout << "Bicycle:" << endl;
	cout << "max_speed:" << max_speed << endl;
	cout << "speed:" << speed << endl;
	cout << "weight:" << weight << endl;
	cout << "height:" << height << endl;
	cout << endl;
}

class CMotocar: virtual public CVehicle
{
protected:
	int seat_num;
public:
	CMotocar(int m, int s, int w, int sn);
	void display();
};

CMotocar::CMotocar(int m, int s, int w, int sn):\
CVehicle(m, s, w) { seat_num = sn; }

void CMotocar::display()
{
	cout << "Motocar:" << endl;
	cout << "max_speed:" << max_speed << endl;
	cout << "speed:" << speed << endl;
	cout << "weight:" << weight << endl;
	cout << "seat_num:" << seat_num << endl;
	cout << endl;
}

class CMotocycle: public CBicycle, public CMotocar
{
public:
	CMotocycle(int m, int s, int w, int h, int sn);
	void display();
};

CMotocycle::CMotocycle(int m, int s, int w, int h, int sn):\
CVehicle(m, s, w), CBicycle(m, s, w, h), CMotocar(m, s, w, sn)
{}

void CMotocycle::display()
{
	cout << "Motocycle:" << endl;
	cout << "max_speed:" << max_speed << endl;
	cout << "speed:" << speed << endl;
	cout << "weight:" << weight << endl;
	cout << "height:" << height << endl;
	cout << "seat_num:" << seat_num << endl;
}

int main()
{
	int m, s, w;
	int h;
	int sn;
	cin >> m >> s >> w;
	CVehicle cv(m, s, w);
	cv.display();
	
	cin >> h;
	CBicycle cb(m, s, w, h);
	cb.display();
	
	cin >> sn;
	CMotocar cm(m, s, w, sn);
	cm.display();
	
	CMotocycle cmc(m, s, w, h, sn);
	cmc.display();
	
	return 0;
}
