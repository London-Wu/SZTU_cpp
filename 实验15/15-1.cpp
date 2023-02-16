#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

template<class T>
T smax(T *nums)
{
	T maxnum = nums[0];
	for(int i=1;i<5;i++)
	{
		if(nums[i] > maxnum)
		{
			maxnum = nums[i];
		}
	}
	return maxnum;
}

int main()
{
	int intnums[5];
	float flnums[5];
	long longnums[5];
	
	for(int i=0;i<5;i++)
	{
		cin >> intnums[i];
	}
	cout << smax(intnums) << endl;
	
	for(int i=0;i<5;i++)
	{
		cin >> flnums[i];
	}
	cout << smax(flnums) << endl;
	
	for(int i=0;i<5;i++)
	{
		cin >> longnums[i];
	}
	cout << smax(longnums) << endl;
	
	return 0;
}
