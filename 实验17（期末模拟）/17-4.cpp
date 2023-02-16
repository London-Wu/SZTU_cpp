#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Elapp // 家电
{
protected:
	int id; // 编号
	int power; // 功率
public:
	Elapp(int id1, int power1);
	virtual void print() = 0; // 打印
};

Elapp::Elapp(int id1, int power1)
{
	id = id1;
	power = power1;
}

class Fan:virtual public Elapp // 电风扇 
{
protected:
	int dir, wind; // 风向 风力
public:
	Fan(int id1, int power1, int dir1, int wind1);
	void dir_ctrl(int dir1); // 0表示定向吹风，为1表示旋转吹风
	void wind_ctrl(int wind1); // 风力级别，例如1级、2级、3级等
};

Fan::Fan(int id1, int power1, int dir1, int wind1):Elapp(id1, power1)
{
	dir = dir1;
	wind = wind1;
}

void Fan::dir_ctrl(int dir1)
{ 
	dir = dir1; // 0表示定向吹风，为1表示旋转吹风
}

void Fan::wind_ctrl(int wind1)
{
	wind = wind1;
}

class Humidifier:virtual public Elapp // 加湿器
{
protected:
	float rel_capty, max_capty; // 实际容量  最大容量
public:
	Humidifier(int id1, int power1, float r1, float m1);
	int ealWarn();
};

Humidifier::Humidifier(int id1, int power1, float r1, float m1) :Elapp(id1, power1)
{
	rel_capty = r1;
	max_capty = m1;
}

int Humidifier::ealWarn()
{
	/*实际水容量不小于最大水容量的50%，则返回1
	小于50%且不小于10%则返回2
	小于10%则返回3*/
	if (rel_capty >= 0.5 * max_capty)
	{
		return 1;
	}
	else if (rel_capty >= 0.1 * max_capty && rel_capty < 0.5 * max_capty)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}


class DriFan : public Fan, public Humidifier // 加湿风扇
{
protected:
	int gear; // 挡位
public:
	DriFan(int id1, int power1, int d1, int w1, float r1, float m1, int g1);
	void setGear(int gear1); // 调整挡位
	void print();
};

DriFan::DriFan(int id1, int power1, int d1, int w1, float r1, float m1, int g1) :
	Elapp(id1, power1),
	Fan(id1, power1, d1, w1),
	Humidifier(id1, power1, r1, m1)
{
	gear = g1;

}

void DriFan::setGear(int gear1)
{
	/*1、参数为0，不做其他属性修改
	2、参数为1，设置定向吹风且风力1级
	3、参数为2，设置旋转吹风且风力2级
	4、参数为3，设置旋转吹风且风力3级*/
	gear = gear1;
	if (gear == 1)
	{
		dir = 0;
		wind = 1;
	}
	else if (gear == 2)
	{
		dir = 1;
		wind = 2;
	}
	else if (gear == 3)
	{
		dir = 1;
		wind = 3;
	}
}

void DriFan::print()
{
	cout << "加湿风扇--档位" << gear << endl;
	cout << "编号" << id << "--功率" << power << 'W' << endl;
	if (dir == 0)
	{
		cout << "定向吹风";
	}
	else if (dir == 1)
	{
		cout << "旋转吹风";
	}
	cout << "--风力" << wind << "级" << endl;
	cout << "实际水容量" << rel_capty << "升--";
	int war = ealWarn();
	if (war == 1)
	{
		cout << "水量正常" << endl;
	}
	else if (war == 2)
	{
		cout << "水量偏低" << endl;
	}
	else if (war == 3)
	{
		cout << "水量不足" << endl;
	}

}

int main()
{
	int t;
	cin >> t;
	int id, power, dir, wind, rc, mc, g, cg;
	while (t--)
	{
		cin >> id >> power >> dir >> wind >> rc >> mc >> g;
		DriFan d(id, power, dir, wind, rc, mc, g);
		cin >> cg;
		d.setGear(cg);
		d.print();
	}
}