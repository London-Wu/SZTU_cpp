#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	char platext[100], ciptext[100], pw[100];
	char* plapoi, * cippoi, * pwpoi;
	char move_res;
	for (int i = 0; i < t; i++)
	{
		getchar();
		cin >> platext >> pw;
		
		plapoi = platext;
		cippoi = ciptext;
		pwpoi = pw;
		
		while (1)
		{
			move_res = *plapoi + (*pwpoi - '0');
			if ((move_res > 'Z' && move_res < 'a') ||
				move_res > 'z') move_res -= 26;
			*cippoi = move_res;
			
			plapoi++; cippoi++; pwpoi++;
			if (*plapoi == '\0')
			{
				*cippoi = '\0';
				break;
			}
			if (*pwpoi == '\0') pwpoi = pw;
		}
		cout << ciptext << endl;
	}
	
	return 0;
}
