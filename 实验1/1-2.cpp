#include <iostream>

#include <iomanip> //必须包含这个头文件

using namespace std;

int main()

{
	//double a = 3.141596;
	//cout << fixed << setprecision(3) << a << endl;  //输出小数点后3位
	
	const float DO = 6.2619;
	const float EU = 6.6744;
	const float JP = 0.0516;
	const float HK = 0.8065;
	
	const float* pDO = &DO;
	const float* pEU = &EU;
	const float* pJP = &JP;
	const float* pHK = &HK;
	int t;
	char input;
	float rmb,res;
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		cin >> input >> rmb;
		if (input == 'D') {
			res = rmb * (*pDO);
		}
		else if (input == 'E') {
			res = rmb * (*pEU);
		}
		else if (input == 'Y') {
			res = rmb * (*pJP);
		}
		else if (input == 'H') {
			res = rmb * (*pHK);
		}
		cout << fixed << setprecision(4) << res << endl;
	}
	
	
	return 0;
}
