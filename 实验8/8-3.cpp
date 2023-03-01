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
	~CVector();
	static int getSum();
	static void clsum();
	friend CVector add(const CVector v1, const CVector v2);
};

int CVector::sum = 0;

CVector::CVector()
{
	int s = 0;
	data = new int[5];
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
	data = new int[n];
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
	data = new int[n];
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
		if(i!=n-1) cout << data[i] << ' ';
		else cout << data[i] << endl;
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

CVector add(const CVector v1, const CVector v2)
{
	for(int i=0;i<v1.n;i++)
	{
		v1.data[i] += v2.data[i];
	}
	return v1;
}

int main()
{
	int t;
	cin >> t;
	
	int n, data[100];
	int t2;
	for(int i=0;i<t;i++)
	{
		cin >> t2;
		CVector::clsum();
		for(int j=0;j<t2;j++)
		{
			cin >> n;
			for(int k=0;k<n;k++)
			{
				cin >> data[k];
			}
			CVector v(n, data);
			v.output();
		}
		cout << CVector::getSum() << endl;
		CVector::clsum();
	}
	
	return 0;
}
