#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	int n;
	int scores[100];
	int* mid_poi; 
	int* poi;
	int inp;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> scores[j];
		}
		mid_poi = scores;
		mid_poi += n / 2;
		cout << *(mid_poi - 1) << ' ' << *(mid_poi + 1) << endl;
		cin >> inp;
		cout << *(mid_poi + inp - (n / 2) - 1) << endl;
	}
	
	return 0;
}
