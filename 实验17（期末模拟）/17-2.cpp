#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Metal
{
private:
	int hardness, weight, volume;
public:
	Metal(int h, int w, int v);
	Metal& operator++(); //前增量的方式实现硬化
	const Metal operator--(int); //后增量的方式实现软化
	void print();

	friend Metal operator+(Metal& m1, Metal& m2);
	friend Metal operator*(Metal& m, int bs);
};

Metal::Metal(int h, int w, int v)
{
	hardness = h;
	weight = w;
	volume = v;
}

Metal& Metal::operator++() //前增量的方式实现硬化
{
	hardness++;
	weight *= 1.1;
	volume *= 1.1;
	return *this;
}

const Metal Metal::operator--(int) //后增量的方式实现软化
{
	Metal org(*this);
	hardness--;
	weight *= 0.9;
	volume *= 0.9;
	return org;
}

void Metal::print()
{
	cout << "硬度" << hardness << "--";
	cout << "重量" << weight << "--";
	cout << "体积" << volume << endl;
}

Metal operator+(Metal& m1, Metal& m2)
{
	Metal ret(m1);
	ret.hardness += m2.hardness;
	ret.weight += m2.weight;
	ret.volume += m2.volume;
	return ret;
}

Metal operator*(Metal& m, int bs)
{
	Metal ret(m);
	ret.volume *= bs;
	return ret;
}



int main()
{
	int h, w, v, n;
	cin >> h >> w >> v;
	Metal m1(h, w, v);
	cin >> h >> w >> v;
	Metal m2(h, w, v);

	Metal m3(m1 + m2);
	m3.print();

	cin >> n;
	Metal m4(m1 * n);
	m4.print();

	++m1;
	m1.print();

	m2--;
	m2.print();

	return 0;
}