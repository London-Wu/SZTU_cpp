#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point{
public:
	double x;
	double y;
	
	double getX();
	double getY();
	Point(){}
	Point(double ix, double iy);
};

Point::Point(double ix, double iy)
{
	x = ix;
	y = iy;
}

double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}

class Circle{
public:
	Point cent_of_cir;
	double radius;
	
	void setCenter(Point icenter);
	void setRadius(double iradius);
	double getArea();
	double getLength();
};

void Circle::setCenter(Point icenter)
{
	cent_of_cir = icenter;	
}

void Circle::setRadius(double iradius)
{
	radius = iradius;
}

double Circle::getArea()
{
	return 3.14*radius*radius;
}

double Circle::getLength()
{
	return 2*3.14*radius;
}


int main()
{
	double x, y, r;
	cin >> x >> y >> r;
	Point center(x,y);
	Circle cir;
	cir.setCenter(center);
	cir.setRadius(r);
	
	double area = cir.getArea();
	double length = cir.getLength();
	cout << fixed << setprecision(2) << area << " ";
	cout << fixed << setprecision(2) << length << endl;
	
	cin >> x >> y;
	Point point(x,y);
	double dis = sqrt(pow(point.x-center.x,2)+pow(point.y-center.y,2));
	if(dis<cir.radius) cout << "yes" << endl;
	else cout << "no" << endl;
	
	return 0;
}
