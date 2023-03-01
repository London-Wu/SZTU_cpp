#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
const float PI = 3.14;

class CPoint
{
protected:
	int x, y;
public:
	CPoint(int x1, int y1);
	
};

CPoint::CPoint(int x1=0, int y1=0)
{
	x = x1; y = y1;
}

class CCircle: public CPoint
{
protected:
	int r;
public:
	CCircle(int x1, int y1, int r1);
	float getArea();
	void print();
};

CCircle::CCircle(int x1=0, int y1=0, int r1=0)
{
	x = x1; y = y1; r = r1;
}

float CCircle::getArea()
{
	return PI*pow(r, 2);
}

void CCircle::print()
{
	cout << "Circle:(" << x << ',' << y << ")," << r << endl;
}

class CCylinder: public CCircle
{
protected:
	int h;
public:
	CCylinder(int x1, int y1, int r1, int h1);
	float getVolume();
	void print();
};

CCylinder::CCylinder(int x1=0, int y1=0, int r1=0, int h1=0)
{
	x = x1; y = y1; r = r1; h = h1;
}

float CCylinder::getVolume()
{
	return getArea()*h;
}

void CCylinder::print()
{
	cout << "Cylinder:(" << x << ',' << y << "),";
	cout << r << ',' << h << endl;
}

int main()
{
	int x, y, r;
	int h;
	cin >> x >> y >> r;
	CCircle c1(x, y, r);
	c1.print();
	cout << "Area:" << fixed << setprecision(2) << c1.getArea() << endl;
	
	cin >> x >> y >> r >> h;
	CCylinder c2(x, y, r, h);
	c2.print();
	cout << "Volume:" << fixed << setprecision(2) << c2.getVolume() << endl;
	return 0;
}
