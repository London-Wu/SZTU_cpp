#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Set
{
private:
	int n;
	int* data;
public:
	Set(int n1);
	Set(int n1, int* datas);
	~Set();
	friend Set operator+(const Set& s1, const Set& s2);
	friend Set operator-(const Set& s1, const Set& s2);
	friend Set operator*(const Set& s1, const Set& s2);
	friend ostream& operator<<(ostream& os, const Set &s);
};

Set::Set(int n1 = 1)
{
	n = n1;
	data = new int[n];
}

Set::Set(int n1, int* datas)
{
	n = n1;
	data = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		data[i] = datas[i];
	}
}

bool isinset(int n, int *datas, int data_len)
{
	for (size_t i = 0; i < data_len; i++)
	{
		if (n == datas[i]) return true;
	}
	return false;
}

Set::~Set()
{
	delete[] data;
}

Set operator*(const Set& s1, const Set& s2)
{
	int samenums[100], same = 0;
	for (size_t i = 0; i < s1.n; i++)
	{
		if (isinset(s1.data[i], s2.data, s2.n))
		{
			samenums[same] = s1.data[i];
			same++;
		}
	}
	
	for (size_t i = 0; i < s2.n; i++)
	{
		if (isinset(s2.data[i], s1.data, s1.n) && !isinset(s2.data[i], samenums, same))
		{
			samenums[same] = s2.data[i];
			same++;
		}
	}
	
	return Set(same, samenums);;
}

Set operator-(const Set& s1, const Set& s2)
{
	int diffnums[100], diff = 0;
	for (size_t i = 0; i < s1.n; i++)
	{
		if (!isinset(s1.data[i], s2.data, s2.n))
		{
			diffnums[diff] = s1.data[i];
			diff++;
		}
	}
	
	return Set(diff, diffnums);
}

Set operator+(const Set& s1, const Set& s2)
{
	int allnums[100], all = 0;
	for (size_t i = 0; i < s1.n; i++)
	{
		allnums[all] = s1.data[i];
		all++;
	}
	for (size_t i = 0; i < s2.n; i++)
	{
		if (!isinset(s2.data[i], allnums, all))
		{
			allnums[all] = s2.data[i];
			all++;
		}
	}
	
	Set s(all, allnums);
	return Set(all, allnums);
}

ostream& operator<<(ostream& os, const Set &s)
{
	for (size_t i = 0; i < s.n; i++)
	{
		os << s.data[i];
		if (i != s.n-1) os << ' ';
	}
	
	return os;
}

int main()
{
	int t; cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		int s1n, s2n, s1data[100], s2data[100];
		cin >> s1n;
		for (size_t j = 0; j < s1n; j++)
		{
			cin >> s1data[j];
		}
		cin >> s2n;
		for (size_t j = 0; j < s2n; j++)
		{
			cin >> s2data[j];
		}
		Set s1(s1n, s1data), s2(s2n, s2data);
		
		cout << "A:" << s1 << endl;
		cout << "B:" << s2 << endl;
		cout << "A+B:" << s1 + s2 << endl;
		cout << "A*B:" << s1 * s2 << endl;
		cout << "(A-B)+(B-A):" << (s1 - s2) + (s2 - s1);
		if (i != t - 1) cout << endl << endl;
	}
	
	return 0;
}
