#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CVector
{
private:
	int *data;
	int n;
	static int sum;
public:
	CVector();
	CVector(int n1, int a[]);
	CVector(const CVector &v);
	void output();
	void setn(int n1);
	void setdata(int data1[]);
	float getAve();
	~CVector();
	static int getSum();
	static void clsum();
	friend CVector add(const CVector v1, const CVector v2);
};

class CStudent
{
private:
	string name;  // 姓名
	CVector score;  // n个成绩
	
public:
	CStudent(string name1, int n1, int a1[]);
	void output();
};

int CVector::sum = 0;

CVector::CVector()
{
	int s = 0;
	data = new int[100];
	for(int i=0;i<5;i++)
	{
		data[i] = i;
		s += data[i];
	}
	sum += s;
}

CVector::CVector(int n1, int a[])
{
	int s = 0;
	n = n1;
	data = new int[100];
	for(int i=0;i<n;i++)
	{
		data[i] = a[i];
		s += data[i];
	}
	sum += s;
}

CVector::CVector(const CVector& v)
{
	n = v.n;
	int s = 0;
	data = new int[100];
	for(int i=0;i<n;i++)
	{
		data[i] = v.data[i];
		s += data[i];
	}
	sum += s;
}

void CVector::output()
{
	for(int i=0;i<n;i++)
	{
		cout << data[i] << ' ';
	}
}

CVector::~CVector()
{
	delete[] data;
}

int CVector::getSum()
{
	return sum;
}

void CVector::clsum()
{
	sum = 0;
}

void CVector::setn(int n1) { n = n1;}
void CVector::setdata(int data1[])
{
	for(int i=0;i<n;i++)
	{
		data[i] = data1[i];
	}
}

float CVector::getAve()
{
	float s = 0;
	for(int i=0;i<n;i++)
	{
		s += data[i];
	}
	return s/n;
}

CVector add(const CVector v1, const CVector v2)
{
	for(int i=0;i<v1.n;i++)
	{
		v1.data[i] += v2.data[i];
	}
	return v1;
}


CStudent::CStudent(string name1, int n1, int a1[])
{
	name = name1;
	score.setn(n1);
	score.setdata(a1);
}

void CStudent::output()
{
	cout << name << ' ';
	score.output();
	cout << fixed << setprecision(2) << score.getAve() << endl;
}

int main()
{
	string name;
	int n;
	int a[100];
	while(cin >> name)
	{
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		CStudent s(name, n, a);
		s.output();
	}
	
	return 0;
}
