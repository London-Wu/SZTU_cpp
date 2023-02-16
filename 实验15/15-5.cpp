#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

template <class T>
void next_sort(T *nums, int n)
{
	int mark_index, i;
	for(i=n-1; i>0; i--)
	{
		if(nums[i] > nums[i-1])
		{
			mark_index = i-1;
			break;
		}
	}
	
	// 没有降序，已是最大值
	if(i == 0)
	{
		reverse(nums, nums+n);
	}
	else
	{
		T temp;
		for(int i=n-1;i>mark_index;i--)
		{
			if(nums[i] > nums[mark_index])
			{
				temp = nums[i];
				nums[i] = nums[mark_index];
				nums[mark_index] = temp;
				reverse(nums + mark_index+1, nums + n);
				break;
			}
		}
	}
}

int main()
{
	int t; cin >> t;
	char type;
	int n;
	for(int i=0;i<t;i++)
	{
		cin >> type >> n;
		if(type == 'C')
		{
			char nums[n];
			for(int j=0;j<n;j++)
			{
				cin >> nums[j];
			}
			next_sort(nums, n);
			for(int j=0;j<n-1;j++)
			{
				cout << nums[j] << ' ';
			}
			cout << nums[n-1] << endl;
		}
		else if(type == 'I')
		{
			int nums[n];
			for(int j=0;j<n;j++)
			{
				cin >> nums[j];
			}
			next_sort(nums, n);
			for(int j=0;j<n-1;j++)
			{
				cout << nums[j] << ' ';
			}
			cout << nums[n-1] << endl;
		}
		else if(type == 'D')
		{
			double nums[n];
			for(int j=0;j<n;j++)
			{
				cin >> nums[j];
			}
			next_sort(nums, n);
			for(int j=0;j<n-1;j++)
			{
				cout << nums[j] << ' ';
			}
			cout << nums[n-1] << endl;
		}
		else if(type == 'S')
		{
			string nums[n];
			for(int j=0;j<n;j++)
			{
				cin >> nums[j];
			}
			next_sort(nums, n);
			for(int j=0;j<n-1;j++)
			{
				cout << nums[j] << ' ';
			}
			cout << nums[n-1] << endl;
		}
	}
	
	return 0;
}
