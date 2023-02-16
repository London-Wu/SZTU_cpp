#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

template <class T>
class Code
{
private:
	T codes[6];
public:
	Code(T* codee);
	bool isvalid();
};

template <class T>
Code<T>::Code(T* codee)
{
	for(int i=0;i<6;i++)
	{
		codes[i] = codee[i];
	}
}

template <class T>
bool Code<T>::isvalid()
{
	for(int i=0;i<5;i++)
	{
		if(codes[i] > codes[i+1])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	char type;
	bool isvalid_value;
	while(cin >> type)
	{
		if(type == 'c')
		{
			char chas[6];
			for(int j=0;j<6;j++)
			{
				cin >> chas[j];
			}
			Code<char> c1(chas);
			isvalid_value = c1.isvalid();
		}
		else if(type == 'i')
		{
			int chas[6];
			for(int j=0;j<6;j++)
			{
				cin >> chas[j];
			}
			Code<int> c1(chas);
			isvalid_value = c1.isvalid();
		}
		else if(type == 'f')
		{
			float chas[6];
			for(int j=0;j<6;j++)
			{
				cin >> chas[j];
			}
			Code<float> c1(chas);
			isvalid_value = c1.isvalid();
		}
		if(isvalid_value) cout << "Valid" << endl;
		else cout << "Invalid" << endl;
	}
	
	return 0;
}
