#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class BodyHel{
private:
	string name;
	double height;
	double weight;
	double waistline;
	
public:
	void input(string iname, double ihei, double iwei, double iwai);	
	double getBMI();
	double getBFP();
	string getName();
};

void BodyHel::input(string iname, double ihei, double iwei, double iwai)
{
	name = iname;
	height = ihei;
	weight = iwei;
	waistline = iwai;
}

double BodyHel::getBMI()
{
	return weight / pow(height,2);
}

double BodyHel::getBFP()
{
	double a = waistline * 0.74;
	double b = weight * 0.082 + 34.89;
	double z = a - b;
	return z / weight;
}

string BodyHel::getName()
{
	return name;
}

int main()
{
	int t;
	cin >> t;
	BodyHel bods[10];
	string name;
	double heig;
	double weig;
	double wais;
	
	for(int i=0;i<t;i++)
	{
		cin >> name >> heig >> weig >> wais;
		bods[i].input(name, heig, weig, wais);
	}
	
	for(int i=0;i<t;i++)
	{
		cout << bods[i].getName() << "的BMI指数为" << fixed << setprecision(0) << bods[i].getBMI();
		cout << "--";
		cout << "体脂率为" << fixed << setprecision(2) << bods[i].getBFP() << endl;
	}
	
	
	return 0;
}
