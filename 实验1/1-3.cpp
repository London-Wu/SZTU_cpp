#include <iostream>

#include <iomanip> //必须包含这个头文件

using namespace std;

int main()

{
	int t;
	char type;
	int len;
	
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		cin >> type >> len;
		if (type == 'I') {
			int* arrey = new int[len];
			for (int j = 0;j < len;j++) {
				cin >> *arrey;
				arrey++;
			}
			arrey -= len;
			float sum=0;
			for (int j = 0;j < len;j++) {
				sum += *arrey++;
			}
			cout << sum / len << endl;
			arrey -= len;
			delete[](arrey);
		}
		
		else if (type == 'C') {
			char* arrey = new char[len];
			for (int j = 0;j < len;j++) {
				cin >> *arrey;
				arrey++;
			}
			arrey -= len;
			char max = *arrey;
			for (int j = 0;j < len;j++) {
				if (max < *arrey) {
					max = *arrey;
				}
				arrey++;
			}
			cout << max << endl;
			arrey -= len;
			delete[](arrey);
		}
		
		
		else if (type == 'F') {
			float* arrey = new float[len];
			for (int j = 0;j < len;j++) {
				cin >> *arrey;
				arrey++;
			}
			arrey -= len;
			float min = *arrey;
			for (int j = 0;j < len;j++) {
				if (min > *arrey) {
					min = *arrey;
				}
				arrey++;
			}
			arrey -= len;
			cout << min << endl;
			delete[](arrey);
			
		}
		
	}
	
	
	return 0;
}
