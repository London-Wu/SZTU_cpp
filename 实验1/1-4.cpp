#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	char str1[100], str2[100], str3[100];
	int begin1, end1;
	char res[100];
	
	char *poi_str;
	char *poi_res;
	
	while(t--)
	{
		poi_res = res;
		cin >> str1 >> str2 >> str3;
		
		cin >> begin1 >> end1;
		poi_str = str1;
		for(int j=begin1-1; j<end1; j++)
		{
			*poi_res = *(poi_str+j);
			poi_res++;
		}
		
		cin >> begin1 >> end1;
		poi_str = str2;
		for(int j=begin1-1; j<end1; j++)
		{
			*poi_res = *(poi_str+j);
			poi_res++;
		}
		
		cin >> begin1 >> end1;
		poi_str = str3;
		for(int j=begin1-1; j<end1; j++)
		{
			*poi_res = *(poi_str+j);
			poi_res++;
		}
		
		*poi_res = '\0';
		cout << res << endl;
	}
	
	return 0;
}
