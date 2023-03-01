#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

const float PI = 3.14159265;

class Shape
{
public:
	virtual float area();
};

float Shape::area() { return 0.0; }

class Circle : public Shape
{
protected:
	float r;
public:
	Circle(float r1);
	float area();
};

Circle::Circle(float r1) :r(r1) {}

float Circle::area() { return r * r * PI; }

class Square :public Shape
{
protected:
	float l;
public:
	Square(float l1);
	float area();
};

Square::Square(float l1):l(l1){}

float Square::area() { return l * l; }

class Rectangle :public Shape
{
protected:
	float c, k;
public:
	Rectangle(float c1, float k1);
	float area();
};

Rectangle::Rectangle(float c1, float k1): c(c1), k(k1){}

float Rectangle::area() { return c * k; }


int main()
{
	int t;
	cin >> t;
	Shape *shapes[3];
	float r, l, c, k;
	
	for (size_t i = 0; i < t; i++)
	{
		cin >> r >> l >> c >> k;
		shapes[0] = new Circle(r);
		shapes[1] = new Square(l);
		shapes[2] = new Rectangle(c, k);
		
		for (size_t j = 0; j < 3; j++)
		{
			cout << fixed << setprecision(2) << shapes[j]->area() << endl;
		}
		
	}
	
	return 0;
}
