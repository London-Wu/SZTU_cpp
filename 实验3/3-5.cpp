#include <iostream>
#include <string>
using namespace std;

struct Answer{
	int id;
	string ans1;
	string ans2;
	string ans3;
};

int isCheat(string str1, string str2)
{
	int length11 = str1.length();
	int length12 = str2.length();
	double sameinans1=0;
	for(int i=0;i<min(length11,length12);i++)
	{
		if(str1[i]==str2[i]) sameinans1++;
	}
	if(sameinans1/min(length11,length12)>=0.9) return 1;
	else return 0;
}

int AnsCmp(Answer *a1, Answer *a2)
{
	if(isCheat(a1->ans1, a2->ans1)) return 1;
	else if(isCheat(a1->ans2, a2->ans2)) return 2;
	else if(isCheat(a1->ans3, a2->ans3)) return 3;
	else return 0;
}

int main()
{
	int t;
	cin >> t;
	
	Answer ans[20];
	for(int i=0;i<t;i++)
	{
		cin >> ans[i].id;
		cin >> ans[i].ans1;
		cin >> ans[i].ans2;
		cin >> ans[i].ans3;
	}
	
	for(int i=0;i<t;i++)
	{
		for(int j=i+1;j<t;j++)
		{
			int res = AnsCmp(&ans[i], &ans[j]);
			if(res)
			{
				cout << ans[i].id << ' ' << ans[j].id << ' ' << res << endl;
			}
		}
	}
	
	
	return 0;
}
