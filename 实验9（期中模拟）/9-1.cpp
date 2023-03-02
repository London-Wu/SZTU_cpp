#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Robot
{
private:
	
	string name;
	int healthVol, damageVol, defVol;
	char type;
	int level;
	
public:
	
	Robot(string name1, char type1, int Level1);
	void print();
	friend bool transf(Robot *r1, char type1);
	
};

Robot::Robot(string name1, char type1, int level1)
{
	type = type1;
	level = level1;
	name = name1;
	
	if (type == 'N')
	{
		healthVol = 5 * level;
		damageVol = 5 * level;
		defVol = 5 * level;
	}
	else if (type == 'A')
	{
		healthVol = 5 * level;
		damageVol = 10 * level;
		defVol = 5 * level;
	}
	else if (type == 'D')
	{
		healthVol = 5 * level;
		damageVol = 5 * level;
		defVol = 10 * level;
	}
	else if (type == 'H')
	{
		healthVol = 50 * level;
		damageVol = 5 * level;
		defVol = 5 * level;
	}
}

void Robot::print()
{
	cout << name << "--" << type << "--";
	cout << level << "--" << healthVol << "--";
	cout << damageVol << "--" << defVol << endl;
}

bool transf(Robot *r1, char type1)
{
	bool istransf;
	if (r1->type == type1) istransf = false;
	else
	{
		r1->type = type1;
		istransf = true;
	}
	
	if (r1 -> type == 'N')
	{
		r1 -> healthVol = 5 * r1 -> level;
		r1 -> damageVol = 5 * r1 -> level;
		r1 -> defVol = 5 * r1 -> level;
	}
	else if (r1 -> type == 'A')
	{
		r1 -> healthVol = 5 * r1 -> level;
		r1 -> damageVol = 10 * r1 -> level;
		r1 -> defVol = 5 * r1 -> level;
	}
	else if (r1 -> type == 'D')
	{
		r1 -> healthVol = 5 * r1 -> level;
		r1 -> damageVol = 5 * r1 -> level;
		r1 -> defVol = 10 * r1 -> level;
	}
	else if (r1 -> type == 'H')
	{
		r1 -> healthVol = 50 * r1 -> level;
		r1 -> damageVol = 5 * r1 -> level;
		r1 -> defVol = 5 * r1 -> level;
	}
	
	return istransf;
}

int main()
{
	int t;
	cin >> t;
	
	string name;
	char type;
	int level;
	char new_type;
	
	int transf_num = 0;
	
	for (size_t i = 0; i < t; i++)
	{
		cin >> name >> type >> level;
		Robot robot(name, type, level);
		cin >> new_type;
		if ( transf(&robot, new_type) ) transf_num++;
		robot.print();
	}
	
	cout << "The number of robot transform is " << transf_num;
	
	return 0;
}
