#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CPeople
{
protected:
	string name;
	char gender; // 性别->1男2女
	int age;
public:
	CPeople();
	CPeople(string name1, char gender1, int age1);
	void print();
};

CPeople::CPeople()
{ name = "Unknown"; gender = 0; age =0; }

CPeople::CPeople(string name1, char gender1, int age1)
{ name = name1; gender = gender1; age = age1; }

void CPeople::print()
{
	cout << "People:" << endl;
	cout << "Name: " << name << endl;
	cout << "Sex: " << gender << endl;
	cout << "Age: " << age << endl;
	cout << endl;
}

class CStudent:virtual public CPeople
{
protected:
	string id; // 学号
	float score; //入学成绩
public:
	CStudent();
	CStudent(string n, char g, int a, string i, float s);
	void print();
};

CStudent::CStudent()
{ id = "000"; score = 0;}

CStudent::CStudent(string n, char g, int a, string i, float s):\
CPeople(n, g, a)
{ id = i; score = s; }

void CStudent::print()
{
	cout << "Student:" << endl;
	cout << "Name: " << name << endl;
	cout << "Sex: " << gender << endl;
	cout << "Age: " << age << endl;
	cout << "No.: " << id << endl;
	cout << "Score: " << score << endl;
	cout << endl;
}

class CTeacher:virtual public CPeople
{
protected:
	string Position, Department;
public:
	CTeacher();
	CTeacher(string n, char g, int a, string p, string d);
	void print();
};

CTeacher::CTeacher()
{ Position = " "; Department = " ";}

CTeacher::CTeacher(string n, char g, int a, string p, string d):\
CPeople(n, g, a)
{ Position = p; Department = d; }

void CTeacher::print()
{
	cout << "Teacher:" << endl;
	cout << "Name: " << name << endl;
	cout << "Sex: " << gender << endl;
	cout << "Age: " << age << endl;
	cout << "Position: " << Position << endl;
	cout << "Department: " << Department << endl;
	cout << endl;
}

class CGradOnWork: public CStudent, public CTeacher
{
protected:
	string Direction, Tutor;
public:
	CGradOnWork();
	CGradOnWork(string n, char g, int a, string i, float s, string p, string d, string dir, string tut);
	void print();
};

CGradOnWork::CGradOnWork()
{ Direction = " "; Tutor = " "; }

CGradOnWork::CGradOnWork(string n, char g, int a, string i, float s, string p, string d, string dir, string tut):\
CPeople(n, g, a), CStudent(n, g, a, i, s), CTeacher(n, g, a, p, d)
{ Direction = dir; Tutor = tut; }

void CGradOnWork::print()
{
	cout << "GradOnWork:" << endl;
	cout << "Name: " << name << endl;
	cout << "Sex: " << gender << endl;
	cout << "Age: " << age << endl;
	cout << "No.: " << id << endl;
	cout << "Score: " << score << endl;
	cout << "Position: " << Position << endl;
	cout << "Department: " << Department << endl;
	cout << "Direction: " << Direction << endl;
	cout << "Tutor: " << Tutor;
}


int main()
{
	string name;
	char gender;
	int age;
	cin >> name >> gender >> age;
	CPeople people(name, gender, age);
	people.print();
	
	string id;
	float score;
	cin >> id >> score;
	CStudent stu(name, gender, age, id, score);
	stu.print();
	
	string pos, dep;
	cin >> pos >> dep;
	CTeacher tea(name, gender, age, pos, dep);
	tea.print();
	
	string dir, tut;
	cin >> dir >> tut;
	CGradOnWork cg(name, gender, age, id, score, pos, dep, dir, tut);
	cg.print();
	
	return 0;
}
