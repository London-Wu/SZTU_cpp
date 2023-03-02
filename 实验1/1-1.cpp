#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a, b, c;
	int* ap, * bp, * cp, * t;
	for (int i = 0;i < n;i++) 
	{
		cin >> a >> b >> c;
		ap = &a;bp = &b;cp = &c;
		if (*ap < *bp)
		{
			t = ap;
			ap = bp;
			bp = t;
		}
		if (*ap < *cp) {
			t = ap;
			ap = cp;
			cp = t;
		}
		if (*bp < *cp) {
			t = bp;
			bp = cp;
			cp = t;
		}
		
		cout << *ap << " " 
		<< *bp << " " 
		<< *cp << endl;
	}
	
	return 0;
}
