#include <iostream>
using namespace std;

int strcmpp(char* chs1, char* chs2);

int strcmpp(char* chs1, char* chs2)
{
	char* poi1 = chs1;
	char* poi2 = chs2;
	int chs1_large = 0, chs2_large = 0;
	while (1)
	{
		if (*poi1 == '\0' && *poi2 != '\0')
		{
			return -1;
		}
		else if (*poi2 == '\0' && *poi1 != '\0')
		{
			return 1;
		}
		else if(*poi1 == '\0' && *poi2 == '\0')
		{
			if (chs1_large > chs2_large) return 1;
			else if (chs1_large < chs2_large) return -1;
			else return 0;
		}
		else
		{
			if (*poi1 > *poi2) chs1_large++;
			else if (*poi1 < *poi2) chs2_large++;
			poi1++;
			poi2++;
		}
		
	}
}

int main()
{
	int t;
	char chs1[22], chs2[22];
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		getchar();
		cin >> chs1 >> chs2;
		
		cout << strcmpp(chs1, chs2) << endl;
	}
	
	return 0;
}
