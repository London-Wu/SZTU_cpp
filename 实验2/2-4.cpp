#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	int m, n;
	int max, min;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n;
		int** mar = new int*[m];
		for (int j = 0;j < m; j++)
		{
			mar[j] = new int[n];
		}
		
		for (int j = 0;j < m;j++) {
			for (int k = 0; k < n; k++){
				cin >> mar[j][k];
			}
		}
		
		max = mar[0][0];
		min = mar[0][0];
		
		for (int j = 0; j < m; j++){
			for (int k = 0; k < n; k++){
				if (mar[j][k] > max) max = mar[j][k];
				if (mar[j][k] < min) min = mar[j][k];
			}
		}
		cout << min << ' '  << max << endl;
		delete[] mar;
	}
	
	return 0;
}
