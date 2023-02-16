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

template <class T>
void get_max_vote(int n, T *votes)
{
	T candis[n];
	int candis_votes_num[n] = {0};
	int candis_num = 0;
	
	for(int i=0;i<n;i++)
	{
		int find_candi = find(candis_num, candis, votes[i]);
		if(find_candi == -1)
		{
			candis[candis_num] = votes[i];
			candis_votes_num[candis_num]++;
			candis_num++;
		}
		else
		{
			candis_votes_num[find_candi]++;
		}
	}
	
	int max_index = 0;
	for(int i=0;i<candis_num;i++)
	{
		if(candis_votes_num[i] > candis_votes_num[max_index])
		{
			max_index = i;
		}
	}
	cout << candis[max_index] << ' ' << candis_votes_num[max_index] << endl;
	
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
			int votes[20];
			for(int j=0;j<n;j++)
			{
				cin >> votes[j];
			}
			get_max_vote(n, votes);
		}
		else if(type == 'C')
		{
			char votes[20];
			for(int j=0;j<n;j++)
			{
				cin >> votes[j];
			}
			get_max_vote(n, votes);
		}
		else if(type == 'S')
		{
			string votes[20];
			for(int j=0;j<n;j++)
			{
				cin >> votes[j];
			}
			get_max_vote(n, votes);
		}
		
	}
	
	return 0;
}
