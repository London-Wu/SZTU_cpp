#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Equation
{
private:
	double a, b, c;
	double x1, x2;
	double xc1 = 0, xc2 = 0;
public:
	Equation();
	Equation(double ia, double ib, double ic);
	void set(double ia, double ib, double ic);
	void getRoot();
	void output();
};

Equation::Equation() { a = 1.0; b = 1.0; c = 0; }
Equation::Equation(double ia, double ib, double ic)
{
	a = ia; b = ib; c = ic;
}

void Equation::set(double ia, double ib, double ic)
{
	a = ia; b = ib; c = ic;
	xc1 = 0; xc2 = 0;
}

void Equation::getRoot()
{
	if (a == 0)
	{
		x1 = -c / b;
		x2 = -c / b;
		return;
	}
	double delta = b * b - 4 * a * c;
	if (delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
	}
	else if (delta == 0)
	{
		x1 = -b / (2 * a);
		x2 = -b / (2 * a);
	}
	else
	{
		x1 = -b / (2 * a);
		x2 = -b / (2 * a);
		xc1 = sqrt(-delta) / (2 * a);
		xc2 = -sqrt(-delta) / (2 * a);
	}
}

void Equation::output()
{
	if (x1 == x2 && xc1 == 0)
	{
		cout << "x1=x2=" << fixed << setprecision(2) << x1 << endl;
	}
	else if (xc1 != 0)
	{
		cout << "x1=" << fixed << setprecision(2) << x1;
		cout << "+" << fixed << setprecision(2) << xc1 << "i ";
		cout << "x2=" << fixed << setprecision(2) << x1;
		cout << "-" << fixed << setprecision(2) << xc1 << "i" << endl;
	}
	else
	{
		cout << "x1=" << fixed << setprecision(2) << x1 << ' ';
		cout << "x2=" << fixed << setprecision(2) << x2 << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	
	Equation equ;
	double a, b, c;
	
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b >> c;
		equ.set(a, b, c);
		equ.getRoot();
		equ.output();
	}
	
	return 0;
}
