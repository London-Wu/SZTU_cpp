#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CVector
{
private:
	int *data;
	int n;
public:
	CVector();
	CVector(int n1, int a[]);
	CVector(const CVector &v);
	void output();
	~CVector();
	friend CVector add(const CVector v1, const CVector v2);
};

CVector::CVector()
{
	data = new int[5];
	for(int i=0;i<5;i++)
	{
		data[i] = i;
	}
}

CVector::CVector(int n1, int a[])
{
	n = n1;
	data = new int[n];
	for(int i=0;i<n;i++)
	{
		data[i] = a[i];
	}
}

CVector::CVector(const CVector& v)
{
	n = v.n;
	data = new int[n];
	for(int i=0;i<n;i++)
	{
		data[i] = v.data[i];
	}
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
	for(int i=0;i<t;i++)
	{
		cin >> n;
		for(int j=0;j<n;j++)
		{
			cin >> data[j];
		}
		CVector v1(n, data);
		
		for(int j=0;j<n;j++)
		{
			cin >> data[j];
		}
		CVector v2(n, data);
		CVector res(add(v1, v2));
		v1.output();
		v2.output();
		res.output();
	}
	
	return 0;
}
