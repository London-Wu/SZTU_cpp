#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// 定义Fraction类
class Fraction
{
private:
	int fz, fm;
	int commonDivisor(int m, int n); // 计算最大公约数
	void contracted(); 
public:
	Fraction(int, int);
	Fraction(const Fraction&);
	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);
	void set(int, int);
	void disply();
};

int Fraction::commonDivisor(int m, int n)
{
	int temp;
	m = abs(m); n = abs(n);
	if (m < n)
	{
		temp = m; m = n; n = temp;
	}
	while (n > 0) 
	{
		temp = m % n;
		m = n;
		n = temp;
	}
	return m;    
}

void Fraction::contracted()
{
	int gys = commonDivisor(fz, fm);
	fz /= gys;
	fm /= gys;
	if (fz < 0 && fm < 0)
	{
		fz *= -1; fm *= -1;
	}
}

Fraction::Fraction(int fz1 = 0, int fm1 = 1)
{
	fz = fz1; fm = fm1;
}

Fraction::Fraction(const Fraction& frac)
{
	fz = frac.fz; fm = frac.fm;
}

Fraction Fraction::operator+(const Fraction &frac)
{
	int fm1 = fm * frac.fm;
	int fz1 = fz * frac.fm + fm * frac.fz;
	Fraction frac1(fz1, fm1);
	//frac1.contracted();
	return frac1;
}

Fraction Fraction::operator-(const Fraction &frac)
{
	int fm1 = fm * frac.fm;
	int fz1 = fz * frac.fm - fm * frac.fz;
	Fraction frac1(fz1, fm1);
	//frac1.contracted();
	return frac1;
}

Fraction Fraction::operator*(const Fraction &frac)
{
	int fm1 = fm * frac.fm;
	int fz1 = fz * frac.fz;
	Fraction frac1(fz1, fm1);
	//frac1.contracted();
	return frac1;
}

Fraction Fraction::operator/(const Fraction &frac)
{
	int fm1 = fm * frac.fz;
	int fz1 = fz * frac.fm;
	Fraction frac1(fz1, fm1);
	//frac1.contracted();
	return frac1;
}

void Fraction::set(int fz1 = 0, int fm1 = 1)
{
	fz = fz1; fm = fm1;
}

void Fraction::disply()
{
	cout << "fraction=" << fz << '/' << fm << endl;
}

int main()
{
	int fz, fm;
	cin >> fz >> fm;
	Fraction frac1(fz, fm);
	cin >> fz >> fm;
	Fraction frac2(fz, fm);
	Fraction frac3(frac1 + frac2);
	frac3.disply();
	Fraction frac4(frac1 - frac2);
	frac4.disply();
	Fraction frac5(frac1 * frac2);
	frac5.disply();
	Fraction frac6(frac1 / frac2);
	frac6.disply();
	
	
	return 0;
}
