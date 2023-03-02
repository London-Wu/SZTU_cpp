#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()

{
	int t;
	cin >> t;
	int ret[50][50];
	for (int i = 0;i < t;i++)
	{
		for (int j = 0;j < 2;j++) 
		{
			for (int k = 0;k < 3;k++) 
			{
				cin >> ret[j][k];
			}
		}
		
		int** p = new int*[3];
		for (int j = 0;j < 3;j++) 
		{
			*(p+j) = new int[2];
		}
		
		for (int j = 0;j < 3;j++)
		{
			**(p + j) = *(*ret + 2 - j);
			*(* (p + j) + 1) = *(*(ret + 1) + 2 - j);
		}
		
		for (int j = 0;j < 3;j++) 
		{
			for (int k = 0;k < 2;k++) 
			{
				cout << *(*(p + j) + k) << " ";
			}
			cout << endl;
		}
	}
	
	
	return 0;
}
