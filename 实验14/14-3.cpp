#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Point
{
private:
	int x, y, z;
public:
	Point(int xx, int yy, int zz);
	friend Point operator ++(Point& a);
	friend Point operator ++(Point& a, int);
	friend Point operator --(Point& a);
	friend Point operator --(Point& a, int);
	void show();
};

Point::Point(int xx = 0, int yy = 0, int zz = 0)
{
	x = xx; y = yy; z = zz;
}

Point operator ++(Point& a)
{
	a.x++; a.y++; a.z++;
	return a;
}

Point operator ++(Point& a, int)
{
	Point cp(a.x, a.y, a.z);
	a.x++; a.y++; a.z++;
	
	return cp;
}

Point operator --(Point& a)
{
	a.x--; a.y--; a.z--;
	return a;
}

Point operator --(Point& a, int)
{
	Point cp(a.x, a.y, a.z);
	a.x--; a.y--; a.z--;
	
	return cp;
}

void Point::show()
{
	cout << "x=" << x << ' ';
	cout << "y=" << y << ' ';
	cout << "z=" << z << endl;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	Point p1(a, b, c), p2;
	
	p2 = p1++;
	p1.show(); p2.show();
	
	p1--;
	p2 = ++p1;
	p1.show(); p2.show();
	
	p1--;
	p2 = p1--;
	p1.show(); p2.show();
	
	p1++;
	p2 = --p1;
	p1.show(); p2.show();
	
	return 0;
}
