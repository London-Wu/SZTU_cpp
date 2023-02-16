#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

template <class T>
class Matrix
{
private:
	int m, n;
	T mat[20][20];
public:
	Matrix(int,int);
	void set(int, int, T);
	void transport();
	void print();
};

template <class T>
Matrix<T>::Matrix(int m1, int n1)
{
	m = m1; n = n1;
}

template <class T>
void Matrix<T>::set(int i, int j, T val)
{
	mat[i][j] = val;
}

template <class T>
void Matrix<T>::transport()
{
	T mat2[n][m];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			mat2[j][i] = mat[i][j];
		}
	}
	int temp;
	temp = m; m = n; n = temp;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			mat[i][j] = mat2[i][j];
		}
	}
	
}

template <class T>
void Matrix<T>::print()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << mat[i][j];
			if(j!=n-1) cout << ' ';
		}
		if(i != m-1) cout << endl;
	}
}

int main()
{
	int t; cin >> t;
	char type;
	int m, n;
	for(int i=0;i<t;i++)
	{
		cin >> type >> m >> n;
		if(type == 'I')
		{
			int input_val;
			Matrix<int> mat(m, n);
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<n;k++)
				{
					cin >> input_val;
					mat.set(j, k, input_val);
				}
			}
			mat.transport();
			mat.print();
		}
		else if(type == 'D')
		{
			double input_val;
			Matrix<double> mat(m, n);
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<n;k++)
				{
					cin >> input_val;
					mat.set(j, k, input_val);
				}
			}
			mat.transport();
			mat.print();
		}
		else if(type == 'C')
		{
			char input_val;
			Matrix<char> mat(m, n);
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<n;k++)
				{
					cin >> input_val;
					mat.set(j, k, input_val);
				}
			}
			mat.transport();
			mat.print();
		}
		if(i!=t-1) cout << endl;
	}
	
	return 0;
}
