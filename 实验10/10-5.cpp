#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

class Person
{
protected:
	string name;
	int age;
public:
	Person(string name1, int age1);
	void set(string name1, int age1);
	void display();
};

Person::Person(string name1=" ", int age1=0) 
{ name = name1; age = age1;}

void Person::set(string name1, int age1)
{ name = name1; age = age1;}

void Person::display()
{
	cout << name << ' ' << age << endl;
}

class LisStu: public Person
{
protected:
	int dailyScore, examScore, finalScore;
	char state;
public:
	LisStu(string name1, int age1, int dailyScore1, int examScore1);
	void display();
};

class LisFreeStu: public Person
{
protected:
	int examScore;
	char state;
public:
	LisFreeStu(string name, int age, int examScore);
	void display();
};

LisStu::LisStu(string name1, int age1, int dailyScore1, int examScore1)
{
	name = name1; age = age1;
	dailyScore = dailyScore1;
	examScore = examScore1;
	finalScore = 0.4*dailyScore + 0.6*examScore;
	if(finalScore >= 85) state = 'A';
	else if(finalScore >= 75 && finalScore < 85) state = 'B';
	else if(finalScore >= 65 && finalScore < 75) state = 'C';
	else if(finalScore >= 60 && finalScore < 65) state = 'D';
	else state = 'F';
}

LisFreeStu::LisFreeStu(string name1, int age1, int examScore1)
{
	name = name1; age = age1;
	examScore = examScore1;
	if(examScore >= 85) state = 'A';
	else if(examScore >= 75 && examScore < 85) state = 'B';
	else if(examScore >= 65 && examScore < 75) state = 'C';
	else if(examScore >= 60 && examScore < 65) state = 'D';
	else state = 'F';
}

void LisStu::display()
{
	cout << name << ' ' << age << ' ' << state << endl;
}

void LisFreeStu::display()
{
	cout << name << ' ' << age << ' ' << state << endl;
}

int main()
{
	int t; cin >> t;
	string name;
	int age;
	char type;
	int ds, es;
	
	for(int i=0;i<t;i++)
	{
		cin >> type;
		if(type == 'R')
		{
			cin >> name >> age >> ds >> es;
			LisStu stu(name, age, ds, es);
			stu.display();
		}
		else if(type == 'S')
		{
			cin >> name >> age >> es;
			LisFreeStu stu(name, age, es);
			stu.display();
		}
	}
	
	return 0;
}
