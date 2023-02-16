#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

template <class T>
class CList
{
private:
	T nums[100];
	int length;
public:
	CList(T*, int);
	void insert(T, int);
	void del(int);
	void print();
};

template <class T>
CList<T>::CList(T* nums1, int n)
{
	length = n;
	memcpy(nums, nums1, length*sizeof(T));
}

template <class T>
void CList<T>::insert(T num1, int index)
{
	for(int i=length;i>=index;i--)
	{
		nums[i+1] = nums[i];
	}
	nums[index] = num1;
	length++;
}

template <class T>
void CList<T>::del(int index)
{
	for(int i=index;i<length-1;i++)
	{
		nums[i] = nums[i+1];
	}
	length--;
}

template <class T>
void CList<T>::print()
{
	for(int i=0;i<length-1;i++)
	{
		cout << nums[i] << ' ';
	}
	cout << nums[length-1] << endl;
}

int main()
{
	int nums[10], n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> nums[i];
	}
	CList<int> l1(nums, n);
	int insert_num, index;
	cin >> index >> insert_num;
	l1.insert(insert_num, index);
	cin >> index;
	l1.del(index);
	l1.print();
	
	float nums2[10];
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> nums2[i];
	}
	CList<float> l2(nums2, n);
	float insert_num2;
	cin >> index >> insert_num2;
	l2.insert(insert_num2, index);
	cin >> index;
	l2.del(index);
	l2.print();
	
	
	return 0;
}
