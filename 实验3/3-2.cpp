#include <iostream>
using namespace std;

void find(int *num, int n, int &minIndex, int &maxIndex)
{
	minIndex = 0;
	maxIndex = 0;
	for(int i=0;i<n;i++)
	{
		if(num[i] < num[minIndex]) minIndex = i;
		if(num[i] > num[maxIndex]) maxIndex = i;
	}
}

int main()
{
	int t;
	cin >> t;
	int len, minIn, maxIn;
	int &minInR = minIn, &maxInR = maxIn;
	for(int i=0;i<t;i++)
	{
		cin >> len;
		int *nums = new int[len];
		for(int j=0;j<len;j++)
		{
			cin >> nums[j];
		}
		find(nums, len, minInR, maxInR);
		cout << "min=" << nums[minIn] << " minindex=" << minIn << endl;
		cout << "max=" << nums[maxIn] << " maxindex=" << maxIn << endl;
		cout << endl;
		
		delete[] nums;
	}
	
	return 0;
}
