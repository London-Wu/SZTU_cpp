#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

class CN; // 提前声明
class EN; // 提前声明

// 抽象类
class Weight
{
protected:
	char kind[20]; // 计重类型
	int gram; // 克
public:
	Weight(const char tk[] = "no name", int tg = 0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	virtual void print(ostream& out) = 0; // 输出不同类型的计重信息
};

// 中国计重
class CN : public Weight
{
protected:
	int jin, liang, qian;
public:
	CN(int j, int l, int q, int g,const char tk[]);
	void Convert(int gram1);
	void print(ostream& out);
};

CN::CN(int j, int l, int q, int g, const char tk[]) :
	Weight(tk, g)
{
	jin = j;
	liang = l;
	qian = q;
}

void CN::Convert(int gram1)
{
	jin = gram1 / 500;
	liang = gram1 % 500 / 50;
	qian = gram1 % 500 % 50 / 5;
	gram = gram1 % 500 % 50 % 5;
}

void CN::print(ostream& out)
{
	out << kind << ":" << jin << "斤" << liang << "两" << qian << "钱" << gram << "克" << endl;
}

// 英国计重
class EN : public Weight
{
protected:
	int pound, ounce, dalan;
public:
	EN(int p, int o, int d, int g, const char tk[]);
	void Convert(int gram1);
	void print(ostream& out);
	operator CN()const;
};

EN::EN(int p, int o, int d, int g, const char tk[]) :
	Weight(tk, g)
{
	pound = p;
	ounce = o;
	dalan = d;
}

void EN::Convert(int gram1)
{
	pound = gram1 / 512;
	ounce = gram1 % 512 / 32;
	dalan = gram1 % 512 % 32 / 2;
	gram = gram1 % 512 % 32 % 2;
}

void EN::print(ostream& out)
{
	out << kind << ":" << pound << "磅" << ounce << "盎司" << dalan << "打兰" << gram << "克" << endl;
}

EN::operator CN()const
{
	CN ret(0, 0, 0, 0, "中国计重");
	ret.Convert(512 * pound + 32 * ounce + 2 * dalan + gram);
	return ret;
}


// 以全局函数方式重载输出运算符
ostream& operator<<(ostream& os, Weight& w)
{
	// 重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用
	// 重载函数必须调用参数Weight对象的print方法
	w.print(os);
	return os;
}

// 主函数
int main()
{
	int tw;
	// 创建一个中国计重类对象cn
	// 构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind
	CN cn(0, 0, 0, 0, "中国计重");
	cin >> tw;
	cn.Convert(tw); // 把输入的克数转成中国计重
	cout << cn;

	// 创建英国计重类对象en
	// 构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
	EN en(0, 0, 0, 0, "英国计重");
	cin >> tw;
	en.Convert(tw); // 把输入的克数转成英国计重
	cout << en;
	cn = en; // 把英国计重转成中国计重
	cout << cn;
	return 0;
}