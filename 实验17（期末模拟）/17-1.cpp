#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// 普通会员类
class Member
{
protected:
	int id, score;
	string name;
public:
	Member(string name1, int id1, int score1);
	virtual void add(int amount);
	virtual int exchange(int exscore);
	virtual void print();
};

Member::Member(string name1 = "", int id1 = 0, int score1 = 0)
{
	name = name1;
	id = id1;
	score = score1;
}

void Member::add(int amount)
{
	score += amount;
}

int Member::exchange(int exscore)
{
	int examount = exscore / 100;
	score = score - exscore + exscore % 100;
	return examount;
}

void Member::print()
{
	cout << "普通会员" << id << "--" << name << "--" << score << endl;
}

// 贵宾会员类
class VIP:public Member
{
protected:
	int addProp; // 累加比例
	int excProp; // 兑换比例
public:
	VIP(string name1, int id1, int score1, int addProp1, int excProp1);
	void add(int amount);
	int exchange(int exscore);
	void print();
};

VIP::VIP(string name1, int id1, int score1, int addProp1, int excProp1)
{
	name = name1;
	id = id1;
	score = score1;
	addProp = addProp1;
	excProp = excProp1;
}

void VIP::add(int amount)
{
	score += addProp * amount;
}

int VIP::exchange(int exscore)
{
	int examount = exscore / excProp;

	score = score - exscore + exscore % excProp;
	return examount;
}

void VIP::print()
{
	cout << "贵宾会员" << id << "--" << name << "--" << score << endl;
}


int main()
{
	// 创建一个基类对象指针
	Member* pm;
	string name;
	int id, score;
	int amount, exch;
	int addp, excp;

	// 输入数据，创建普通会员对象mm
	cin >> id >> name >> score;
	Member mm(name, id, score);

	// 使用指针pm执行以下操作：
	// 1、pm指向普通会员对象mm
	pm = &mm;
	// 2、输入数据，通过pm执行积分累加和积分兑换
	cin >> amount >> exch;
	pm->add(amount);
	pm->exchange(exch);
	// 3、通过pm调用打印方法输出
	pm->print();

	// 输入数据，创建贵宾会员对象vv
	cin >> id >> name >> score >> addp >> excp;
	VIP vv(name, id, score, addp, excp);
	// 使用指针pm执行以下操作：
	// 1、pm指向贵宾会员对象vv
	pm = &vv;
	// 2、输入数据，通过pm执行积分累加和积分兑换
	cin >> amount >> exch;
	pm->add(amount);
	pm->exchange(exch);
	// 3、通过pm调用打印方法输出
	pm->print();

	return 0;
}