#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Point
{
private:
	double x, y;
	
public:
	Point();
	Point(double x_value, double y_value);
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnotherPoint(Point p);
};

Point::Point(){ x=0; y=0;}
Point::Point(double x_value, double y_value)
{
	x = x_value;
	y = y_value;
}
double Point::getX(){ return x;}
double Point::getY(){ return y;}
void Point::setX(double x_value){ x = x_value;}
void Point::setY(double y_value){ y = y_value;}
double Point::distanceToAnotherPoint(Point p)
{
	double p_x = p.getX();
	double p_y = p.getY();
	double distance = sqrt(pow(x-p_x, 2) + pow(y-p_y, 2));
	return distance;
}


int main()
{
	int t;
	cin >> t;
	
	double inp_x, inp_y;
	Point p1, p2;
	
	for(int i=0;i<t;i++)
	{
		cin >> inp_x >> inp_y;
		p1.setX(inp_x);
		p1.setY(inp_y);
		cin >> inp_x >> inp_y;
		p2.setX(inp_x);
		p2.setY(inp_y);
		
		cout << "Distance of Point(";
		cout << fixed << setprecision(2) << p1.getX() << ",";
		cout << fixed << setprecision(2) << p1.getY() << ") ";
		cout << "to Point(";
		cout << fixed << setprecision(2) << p2.getX() << ",";
		cout << fixed << setprecision(2) << p2.getY() << ") ";
		cout << "is ";
		cout << fixed << setprecision(2) << p1.distanceToAnotherPoint(p2) << endl;
		
	}
	
	return 0;
}
