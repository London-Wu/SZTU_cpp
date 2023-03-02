#include <iostream>
#include <string>
using namespace std;

class Student{
public:
	string name;
	string id;
	string gen;
	string collage;
	string tel;
	
	void input();
	string get_name();
	
};

void Student::input()
{
	cin >> name >> id >> gen >> collage >> tel;
}

string Student::get_name()
{
	return name;
}

int main()
{
	int t;
	cin >> t;
	
	Student Stus[10];
	
	for(int i=0;i<t;i++)
	{
		Stus[i].input();
	}
	
	for(int i=0;i<t;i++)
	{
		cout << Stus[i].get_name() << endl;
	}
	
	return 0;
}
