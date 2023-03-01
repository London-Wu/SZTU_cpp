#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class Animal
{
protected:
	string name;
	int age;
public:
	virtual void Speak() = 0;
};


class Tiger:public Animal
{
public:
	Tiger(string name1, int age1);
	void Speak();
};

Tiger::Tiger(string name1, int age1)
{
	name = name1; age = age1;
}

void Tiger::Speak()
{
	cout << "Hello,I am " << name << ",AOOO." << endl;
}

class Dog :public Animal
{
public:
	Dog(string name1, int age1);
	void Speak();
};

Dog::Dog(string name1, int age1)
{
	name = name1; age = age1;
}

void Dog::Speak()
{
	cout << "Hello,I am " << name << ",WangWang." << endl;
}

class Duck :public Animal
{
public:
	Duck(string name1, int age1);
	void Speak();
};

Duck::Duck(string name1, int age1)
{
	name = name1; age = age1;
}

void Duck::Speak()
{
	cout << "Hello,I am " << name << ",GAGA." << endl;
}

class Pig :public Animal
{
public:
	Pig(string name1, int age1);
	void Speak();
};

Pig::Pig(string name1, int age1)
{
	name = name1; age = age1;
}

void Pig::Speak()
{
	cout << "Hello,I am " << name << ",HENGHENG." << endl;
}


int main()
{
	int t;
	cin >> t;
	string type, name;
	int age;
	Animal* ani;
	
	for (size_t i = 0; i < t; i++)
	{
		cin >> type >> name >> age;
		if (type == "Tiger")
		{
			ani = new Tiger(name, age); ani->Speak();
		}
		else if (type == "Pig")
		{
			ani = new Pig(name, age); ani->Speak();
		}
		else if (type == "Duck")
		{
			ani = new Duck(name, age); ani->Speak();
		}
		else if (type == "Dog")
		{
			ani = new Dog(name, age); ani->Speak();
		}
		else cout << "There is no " << type << " in our Zoo." << endl;
	}
	
	return 0;
}
