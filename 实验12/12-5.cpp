#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Complex
{
private:
	float real, image;
public:
	Complex(float x = 0, float y = 0);
	friend Complex operator+(Complex&, Complex&);
	friend Complex operator-(Complex&, Complex&);
	friend Complex operator*(Complex&, Complex&);
	void show();
};

Complex::Complex(float x, float y)
{
	real = x; image = y;
}

Complex operator+ (Complex & comp1, Complex & comp2)
{
	float r = comp1.real + comp2.real;
	float i = comp1.image + comp2.image;
	Complex result(r, i);
	return result;
}

Complex operator- (Complex & comp1, Complex & comp2)
{
	float r = comp1.real - comp2.real;
	float i = comp1.image - comp2.image;
	Complex result(r, i);
	return result;
}

Complex operator* (Complex & comp1, Complex & comp2)
{
	float r = (comp1.real * comp2.real - comp1.image * comp2.image);
	float i = (comp1.image * comp2.real + comp1.real * comp2.image);
	Complex result(r, i);
	return result;
}

void Complex::show()
{
	cout << "Real=" << real << ' ' << "Image=" << image << endl;
}

int main()
{
	float real, image;
	cin >> real >> image;
	Complex comp1(real, image);
	cin >> real >> image;
	Complex comp2(real, image);
	
	Complex comp3 = comp1 + comp2;
	comp3.show();
	
	comp3 = comp1 - comp2;
	comp3.show();
	
	comp3 = comp1 * comp2;
	comp3.show();
	
	return 0;
}
