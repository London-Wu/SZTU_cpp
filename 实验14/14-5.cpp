#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Num4
{
private:
	int num10;
public:
	Num4(int n);
	friend Num4 operator+(const Num4& n1, const Num4& n2);
	friend ostream& operator<<(ostream &os, const Num4& n);
};

Num4::Num4(int n=0)
{
	num10 = 0;
	for (int i = 0; n != 0; i++)
	{
		num10 += (n % 10) * pow(4, i);
		n /= 10;
	}
}

int num10to4(int num10)
{
	int n = num10, res = 0;
	for (int i = 0; n != 0; i++)		
	{
		res += (n%4) * pow(10, i);
		n /= 4;
	}
	
	return res;
}

Num4 operator+(const Num4& n1, const Num4& n2)
{
	int num = n1.num10 + n2.num10;
	Num4 res(num10to4(num));
	return res;
}

ostream& operator<<(ostream& os, const Num4& n)
{
	int num = num10to4(n.num10);
	os << num;
	return os;
}

int main()
{
	int t;
	cin >> t;
	int num;
	Num4 n4(0);
	for (size_t i = 0; i < t; i++)
	{
		cin >> num;
		Num4 n(num);
		n4 = n4 + n;
	}
	cout << n4;
	
	return 0;
}
