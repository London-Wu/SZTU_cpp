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
	void output();
	~CVector();
};

CVector::CVector()
{
	n = 5;
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

int main()
{
	CVector v1;
	v1.output();
	
	int n;
	cin >> n;
	int data[n];
	
	for(int i=0;i<n;i++)
	{
		cin >> data[i];
	}
	
	CVector v2(n, data);
	v2.output();
	
	return 0;
}
