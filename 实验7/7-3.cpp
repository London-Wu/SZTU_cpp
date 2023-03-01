#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Complex
{
private:
	double real; // 实部
	double imag; // 虚部
public:
	Complex();
	Complex(double r, double i);
	// 友元函数，复数c1 + c2(二参数对象相加)
	friend Complex addCom(const Complex& c1, const Complex& c2);
	// 友元函数，输出类对象c的有关数据(c为参数对象)
	friend void outCom(const Complex& c);
	
	friend Complex minusCom(const Complex& c1, const Complex& c2);
};

Complex::Complex():real(0), imag(0){}

Complex::Complex(double r, double i):real(r), imag(i){}

Complex addCom(const Complex& c1, const Complex& c2)
{
	double nr = c1.real + c2.real;
	double ni = c1.imag + c2.imag;
	Complex res(nr, ni);
	return res;
}

void outCom(const Complex& c)
{
	cout << "(" << c.real << "," << c.imag << ")" << endl;
}

Complex minusCom(const Complex& c1, const Complex& c2)
{
	double nr = c1.real - c2.real;
	double ni = c1.imag - c2.imag;
	Complex res(nr, ni);
	return res;
}

int main()
{
	double ir, ii;
	cin >> ir >> ii;
	Complex c1(ir, ii);
	
	int t;
	cin >> t;
	char oper;
	for(int i=0;i<t;i++)
	{
		cin >> oper >> ir >> ii;
		Complex c2(ir, ii);
		if(oper == '+')
		{
			c1 = addCom(c1, c2);
			outCom(c1);
		}
		else if(oper == '-')
		{
			c1 = minusCom(c1, c2);
			outCom(c1);
		}
	}
	
	return 0;
}
