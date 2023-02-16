#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

template <class T>
bool sort_reg(T t1, T t2)
{
	return t1 < t2;
}

template <class T>
bool sort_reg2(T t1, T t2)
{
	return t1 > t2;
}

template <class T>
void ssort(T *nums, int n, int beg, int endd)
{	
	if(beg < 0) // 修正beg
	{
		beg = 0;
	}
	else if(beg > n) beg = n;
	
	if(endd < 0) // 修正end
	{
		endd = 0;
	}
	else if(endd > n) endd = n;
	if(beg > endd) return;
	
	sort(nums+beg, nums+endd, sort_reg<T>);
}

int main()
{
	int t; cin >> t;
	string type;
	char cha;
	int n, beg, endd;
	for(int i=0;i<t;i++)
	{
		cin >> type >> n >> cha >> beg >> cha >> endd >> cha >> cha;
		if(type == "int")
		{
			int nums[n];
			for(int j=0;j<n;j++)
			{
				cin >> nums[j];
			}
			ssort(nums, n, beg, endd);
			
			cout << '[';
			for(int j=0;j<n-1;j++)
			{
				cout << nums[j] << ", ";
			}
			cout << nums[n-1] << ']' << endl;
		}
		else if(type == "string")
		{
			string nums[n];
			for(int j=0;j<n;j++)
			{
				cin >> nums[j];
			}
			ssort(nums, n, beg, endd);
			
			cout << '[';
			for(int j=0;j<n-1;j++)
			{
				cout << nums[j] << ", ";
			}
			cout << nums[n-1] << ']' << endl;
		}
		else if(type == "float")
		{
			float nums[n];
			for(int j=0;j<n;j++)
			{
				cin >> nums[j];
			}
			ssort(nums, n, beg, endd);
			
			cout << '[';
			for(int j=0;j<n-1;j++)
			{
				cout << nums[j] << ", ";
			}
			cout << nums[n-1] << ']' << endl;
		}
		
	}	
	return 0;
}
