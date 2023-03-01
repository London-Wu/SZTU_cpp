#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class C2D
{
protected:
	int x, y;
public:
	C2D(int x1, int y1);
	float getDistance();
};

C2D::C2D(int x1 = 0, int y1 = 0)
{
	x = x1; y = y1;
}

float C2D::getDistance()
{
	return sqrt(x*x+y*y);
}

class C3D: public C2D
{
protected:
	int z;
public:
	C3D(int x1, int y1, int z1);
	float getDistance();
};

C3D::C3D(int x1=0, int y1=0, int z1=0)
{
	x = x1; y = y1; z = z1;
}

float C3D::getDistance()
{
	return sqrt(x*x + y*y + z*z);
}



int main()
{
	int x, y, z;
	cin >> x >> y;
	C2D c2(x, y);
	cout << c2.getDistance() << endl;
	
	cin >> x >> y >> z;
	C3D c31(x, y, z);
	cout << c31.getDistance() << endl;
	cin >> x >> y >> z;
	C3D c32(x, y, z);
	cout << c32.getDistance() << endl;
	
	c2 = c32;
	cout << c2.getDistance() << endl;
	
	return 0;
}
