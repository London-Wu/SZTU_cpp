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
	friend class CMatrix;
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

class CMatrix
{
private:
	int **data;
	int n;
public:
	CMatrix(int n1, int *data1[]);
	CVector multi(const CVector &v1);
	bool isMulti(const CVector &v1);
	void output();
	~CMatrix();
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

CMatrix::CMatrix(int n1, int *data1[])
{
	n = n1;
	data = new int*[n];
	for(int i=0;i<n;i++)
	{
		data[i] = new int[n];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			data[i][j] = data1[i][j];
		}
	}
	
}

CVector CMatrix::multi(const CVector &v1)
{
	CVector res;
	res.n = n;
	
	int s;
	for(int i=0;i<n;i++)
	{
		s = 0;
		for(int j=0;j<n;j++)
		{
			s += data[i][j] * v1.data[j];	
		}
		res.data[i] = s;
	}
	return res;
}

bool CMatrix::isMulti(const CVector &v1)
{
	return n == v1.n;
}

CMatrix::~CMatrix()
{
	for(int i=0;i<n;i++)
	{
		delete[] data[i];
	}
	delete[] data;
}


int main()
{
	int t;
	cin >> t;
	
	int n,m;
	int **dataM = new int *[100];
	int dataV[100];
	
	for(int i=0;i<t;i++)
	{
		cin >> n;
		for(int j=0;j<n;j++)
		{
			dataM[j] = new int[100];
			for(int k=0;k<n;k++)
			{
				cin >> dataM[j][k];
			}
		}
		CMatrix m1(n, dataM);
		
		cin >> m;
		for(int j=0;j<m;j++)
		{
			cin >> dataV[j];
		}
		CVector v1(m, dataV);
		
		if(m1.isMulti(v1))
		{
			CVector res(m1.multi(v1));
			res.output();
		}
		else cout << "error" << endl;
	}
	
	
	
	return 0;
}
