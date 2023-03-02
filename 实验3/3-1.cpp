#include <iostream>
using namespace std;

void func(int &a, int &b, int &c)
{
	int temp;
	if(a<b){
		temp=a; a=b; b=temp;
	}
	if(a<c){
		temp=a; a=c; c=temp;
	}
	if(b<c){
		temp=b; b=c; c=temp;
	}
}

int main()
{
	int t;
	cin >> t;
	int a,b,c;
	int &aa=a, &bb=b, &cc=c;
	for(int i=0;i<t;i++)
	{
		cin >> a >> b >> c;
		
		func(aa,bb,cc);
		
		cout << a << ' ' << b << ' ' << c << endl;
	}
	
	return 0;
}
