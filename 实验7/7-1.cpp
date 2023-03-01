#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Point
{
private:
	double x, y;
	
public:
	Point(double xx, double yy);
	friend double Distance(Point &a, Point &b);
};

Point::Point(double xx, double yy):x(xx),y(yy){};
double Distance(Point &a, Point &b)
{
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

int main()
{
	int t;
	cin >> t;
	
	double ix, iy;
	for(int i=0;i<t;i++)
	{
		cin >> ix >> iy;
		Point p1(ix, iy);
		
		cin >> ix >> iy;
		Point p2(ix, iy);
		
		cout << fixed << setprecision(0) << Distance(p1, p2) << endl;
	}
	
	return 0;
}
