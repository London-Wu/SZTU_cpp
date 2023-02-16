#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

class Str
{
private:
	char* p;
public:
	Str();
	Str(char* s);
	~Str();
	friend bool operator >(Str&, Str&);
	friend bool operator <(Str&, Str&);
	friend bool operator ==(Str&, Str&);
	void show()
	{
		cout << p;
	}
};

Str::Str()
{
	p = new char[10];
}

Str::Str(char *s)
{
	p = new char[strlen(s)];
	strcpy(p, s);
}

Str::~Str()
{
	delete[] p;
}

bool operator> (Str& s1, Str& s2)
{
	for(int i=0;i<min(strlen(s1.p), strlen(s2.p));i++)
	{
		if(s1.p[i] < s2.p[i]) return false;
		if(s1.p[i] > s2.p[i]) return true;
	}
	if(strlen(s1.p) > strlen(s2.p)) return true;
	return false;
}

bool operator< (Str& s1, Str& s2)
{
	for(int i=0;i<min(strlen(s1.p), strlen(s2.p));i++)
	{
		if(s1.p[i] > s2.p[i]) return false;
		if(s1.p[i] < s2.p[i]) return true;
	}
	if(strlen(s1.p) < strlen(s2.p)) return true;
	return false;
}

bool operator== (Str& s1, Str& s2)
{
	for(int i=0;i<min(strlen(s1.p), strlen(s2.p));i++)
	{
		if(s1.p[i] != s2.p[i]) return false;
	}
	if(strlen(s1.p) != strlen(s2.p)) return false;
	return true;
}


int main()
{
	char a[20], b[20], c[20];
	cin.getline(a, 20, '\n');
	cin.getline(b, 20, '\n');
	cin.getline(c, 20, '\n');
	Str A(a), B(b), C(c);
	
	if(A>B)
	{
		A.show(); cout << endl;
	}
	else
	{
		B.show(); cout << endl;
	}
	if(A<C)
	{
		A.show(); cout << endl;
	}
	else
	{
		C.show(); cout << endl;
	}
	if(B==C)
	{
		B.show(); cout << endl;
	}
	else
	{
		C.show(); cout << endl;	
	}
	return 0;
}
