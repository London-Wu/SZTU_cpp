#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class Group
{
public:
	virtual int add(int x, int y) = 0; // 输出加法的运算结果
	virtual int sub(int x, int y) = 0; // 输出减法的运算结果
};

class Group1 : public Group
{
public:
	int add(int x, int y);
	int sub(int x, int y);
};

int Group1::add(int x, int y) { return x + y; }
int Group1::sub(int x, int y) { return x - y; }

class Group2 : public Group
{
public:
	int add(int x, int y);
	int sub(int x, int y);
};

int Group2::add(int x, int y) { return x + y; }
int Group2::sub(int x, int y)
{
	int bit_flag = 1;
	int sub_bit;
	int res = 0;
	while (1)
	{
		if (x == 0 && y == 0) break;
		int x1 = x % 10, y1 = y % 10;
		sub_bit = x1 - y1;
		if (sub_bit < 0) sub_bit = 10 + sub_bit;
		res += sub_bit * bit_flag;
		bit_flag *= 10;
		x /= 10, y /= 10;
	}
	return res;
}

class Group3:public Group2
{
public:
	int add(int x, int y);
	int sub(int x, int y);
};

int Group3::add(int x, int y)
{
	int bit_flag = 1;
	int res = 0;
	while (1)
	{
		if (x == 0 && y == 0) break;
		int x1 = x % 10, y1 = y % 10;
		res += ((x1 + y1) % 10) * bit_flag;
		bit_flag *= 10;
		x /= 10, y /= 10;
	}
	return res;
}
int Group3::sub(int x, int y)
{
	int bit_flag = 1;
	int sub_bit;
	int res = 0;
	while (1)
	{
		if (x == 0 && y == 0) break;
		int x1 = x % 10, y1 = y % 10;
		sub_bit = x1 - y1;
		if (sub_bit < 0) sub_bit = 10 + sub_bit;
		res += sub_bit * bit_flag;
		bit_flag *= 10;
		x /= 10, y /= 10;
	}
	return res;
}


int main()
{
	int t;
	cin >> t;
	Group* g;
	int type, x, y;
	char cha;
	
	for (size_t i = 0; i < t; i++)
	{
		cin >> type >> x >> cha >> y;
		if (type == 1) g = new Group1;
		else if (type == 2) g = new Group2;
		else g = new Group3;
		
		if (cha == '+') cout << g->add(x, y) << endl;
		else cout << g->sub(x, y) << endl;
	}
	
	return 0;
}
