#include <iostream>
#include <string>
#include <iomanip> //必须包含这个头文件
using namespace std;

int main()

{
	int t;
	cin >> t;
	char a[50], b[50], c[50];
	int begin1, end1;
	int begin2, end2;
	int begin3, end3;
	int newlength;
	int length1, length2, length3;
	for (int i = 0;i < t;i++)
	{
		getchar();
		cin >> a >> b >> c;
		
		cin >> begin1 >> end1;
		cin >> begin2 >> end2;
		cin >> begin3 >> end3;
		
		char* ap = a, * bp = b, * cp = c;
		ap += begin1 - 1;
		bp += begin2 - 1;
		cp += begin3 - 1;
		
		length1 = end1 - begin1+1;
		length2 = end2 - begin2+1;
		length3 = end3 - begin3+1;
		newlength = length1 + length2 + length3;
		char* newstr = new char[newlength + 1];
		
		for (int j = 0;j < length1;j++)
		{
			*(newstr + j) = *ap;
			ap++;
		}
		for (int j = length1;j < length1 + length2;j++)
		{
			*(newstr + j) = *bp;
			bp++;
		}
		for (int j = length1+length2;j < length1 + length2 + length3;j++)
		{
			*(newstr + j) = *cp;
			cp++;
		}
		
		*(newstr + newlength) = '\0';
		cout << newstr << endl;
		delete[] newstr;
		
	}
	
	return 0;
}
