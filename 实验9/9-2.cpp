#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Tel
{
private:
	string telNum;
	string name;
	char type;
	bool state;
public:
	Tel(string telNum1, string name1, char type1, bool state1);
	void print();
	~Tel();
	friend bool issame(string telNum, Tel* tel);
};

Tel::Tel(string telNum1, string name1, char type1, bool state1)
{
	telNum = telNum1;
	name = name1;
	type = type1;
	state = state1;
	cout << telNum << " constructed." << endl;
}

void Tel::print()
{
	cout << "Phone=" << telNum << "--";
	cout << "Type=" << type << "--";
	if (state == true) cout << "State=use--";
	else cout << "State=unuse--";
	cout << "Owner=" << name << endl;
}
Tel::~Tel()
{
	cout << telNum << " destructed." << endl;
}

bool issame(string telNum, Tel* tel)
{
	if (telNum == tel->telNum) return true;
	else return false;
}

int main()
{
	string telnum;
	string name;
	char type;
	bool state;
	
	cin >> telnum >> type >> state >> name;
	Tel tel1(telnum, name, type, state);
	cin >> telnum >> type >> state >> name;
	Tel tel2(telnum, name, type, state);
	cin >> telnum >> type >> state >> name;
	Tel tel3(telnum, name, type, state);
	
	int t;
	cin >> t;
	string tell;
	for (size_t i = 0; i < t; i++)
	{
		cin >> tell;
		if (issame(tell, &tel1)) tel1.print();
		else if (issame(tell, &tel2)) tel2.print();
		else if (issame(tell, &tel3)) tel3.print();
		else cout << "wrong number." << endl;
	}
}
