#include <iostream>
using namespace std;

class A
{
private:
	int a;
public:
	A();
	A(int b);
	A(const A& b);
};

A::A() 
{
	a = 0; 
	cout << "Constructed by default, value = 0" << endl;
}
A::A(int b)
{
	a = b; 
	cout << "Constructed using one argument constructor, value = " << a << endl;
}
A::A(const A& b) 
{
	a = b.a; 
	cout << "Constructed using copy constructor, value = " << a << endl;
}

int main()
{
	int t;
	cin >> t;
	
	int input;
	int a;
	for (int i = 0; i < t; i++)
	{
		cin >> input;
		if (input == 0) { A obj; }
		else if(input == 1)
		{
			cin >> a;
			A obj(a);
		}
		else if (input == 2)
		{
			cin >> a;
			A obj1(a);
			A obj2(obj1);
		}
	}
	
	return 0;
}
