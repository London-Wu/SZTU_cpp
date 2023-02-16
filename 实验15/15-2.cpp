#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

template <class T>
int find(int n, T *nums, T key)
{
	for(int i=0;i<n;i++)
	{
		if(nums[i] == key) return i;
	}
	return -1;
}

int main()
{
	int t; cin >> t;
	char type;
	int n;
	for(int i=0;i<t;i++)
	{
		cin >> type >> n;
		if(type == 'I')
		{
			int nums[n], key;
			for(int j=0;j<n;j++)
			{
				cin >> nums[j];
			}
			cin >> key;
			cout << find(n, nums, key)+1 << endl;
		}
		else if(type == 'D')
		{
			double nums[n], key;
			for(int j=0;j<n;j++)
			{
				cin >> nums[j];
			}
			cin >> key;
			cout << find(n, nums, key)+1 << endl;
		}
		else if(type == 'C')
		{
			char nums[n], key;
			for(int j=0;j<n;j++)
			{
				cin >> nums[j];
			}
			cin >> key;
			cout << find(n, nums, key)+1 << endl;
		}
		else if(type == 'S')
		{
			string nums[n], key;
			for(int j=0;j<n;j++)
			{
				cin >> nums[j];
			}
			cin >> key;
			cout << find(n, nums, key)+1 << endl;
		}
		
	}
	
	return 0;
}
