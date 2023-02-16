#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

int getMax(int *nums, int n)
{
	int max_index = 0;
	for(int i=0;i<n;i++)
	{
		if(nums[i] > nums[max_index])
		{
			max_index = i;
		}
	}
	return nums[max_index];
}

class Poly
{
private:
	int n; // 项数
	int max_item; //最高项
	int *xs; // 系数(哈希表)
	int *zs; //有效指数项（除去0）
public:
	Poly(int n, int *xs1, int *zs1);
	Poly(int n1, int max_item1, int *xs1, int *zs1);
	~Poly();
	Poly operator+(const Poly& p);
	Poly operator-(const Poly& p);
	Poly operator*(const Poly& p);
	friend ostream& operator<<(ostream &os, const Poly &p);
};

Poly::Poly(int n1, int *xs1, int *zs1)
{
	n = n1;
	zs = new int[n];
	for(int i=0;i<n;i++)
	{
		zs[i] = zs1[i];
	}
	
	max_item = getMax(zs, n); //最高项次数
	xs = new int[max_item+1];
	memset(xs, 0, (max_item+1)*sizeof(int)); //所有项设为0
	for(int i=0;i<n;i++)
	{
		xs[zs1[i]] = xs1[i];
	}
}

Poly::Poly(int n1, int max_item1, int *xs1, int *zs1)
{
	n = n1; max_item = max_item1;
	zs = new int[n];
	for(int i=0;i<n;i++)
	{
		zs[i] = zs1[i];
	}
	
	xs = new int[max_item+1];
	for(int i=0;i<max_item+1;i++)
	{
		xs[i] = xs1[i];
	}
}

Poly::~Poly()
{
	delete[] xs;
	delete[] zs;
}

Poly Poly::operator+(const Poly& p)
{	
	int new_max_item = max(max_item, p.max_item); // 两个多项式中的最高项次数
	int new_xs[100], new_zs[100], new_n = 0;
	memset(new_xs, 0, sizeof(new_xs));
	
	if(n==1 && zs[0]==0 && xs[0]==0 && p.n==1 && zs[0]==0 && xs[0]==0)
		return Poly(1,0,new_xs,new_zs); // 0+0
	
	if(max_item >= p.max_item)
	{
		for(int i=0; i<=p.max_item; i++)
		{
			new_xs[i] = xs[i] + p.xs[i];
			if(new_xs[i] != 0) new_zs[new_n++] = i;
		}
		for(int i=p.max_item+1; i<=max_item; i++)
		{
			new_xs[i] = xs[i];
			if(new_xs[i] != 0) new_zs[new_n++] = i;
		}
	}
	else
	{
		for(int i=0; i<=max_item; i++)
		{
			new_xs[i] = xs[i] + p.xs[i];
			if(new_xs[i] != 0) new_zs[new_n++] = i;
		}
		for(int i=max_item+1; i<=p.max_item; i++)
		{
			new_xs[i] = p.xs[i];
			if(new_xs[i] != 0) new_zs[new_n++] = i;
		}
	}
	
	if(new_max_item==0 && new_xs[0]==0) new_n++;
	
	return Poly(new_n, new_max_item, new_xs, new_zs);
}

Poly Poly::operator-(const Poly& p)
{
	int new_max_item = max(max_item, p.max_item); // 两个多项式中的最高项次数
	int new_xs[100], new_zs[100], new_n = 0;
	memset(new_xs, 0, sizeof(new_xs));
	
	if(n==1 && zs[0]==0 && xs[0]==0 && p.n==1 && zs[0]==0 && xs[0]==0)
		return Poly(1,0,new_xs,new_zs); // 0-0
	
	if(max_item >= p.max_item)
	{
		for(int i=0; i<=p.max_item; i++)
		{
			new_xs[i] = xs[i] - p.xs[i];
			if(new_xs[i] != 0) new_zs[new_n++] = i;
		}
		for(int i=p.max_item+1; i<=max_item; i++)
		{
			new_xs[i] = xs[i];
			if(new_xs[i] != 0) new_zs[new_n++] = i;
		}
	}
	else
	{
		for(int i=0; i<=max_item; i++)
		{
			new_xs[i] = xs[i] - p.xs[i];
			if(new_xs[i] != 0) new_zs[new_n++] = i;
		}
		for(int i=max_item+1; i<=p.max_item; i++)
		{
			new_xs[i] = -p.xs[i];
			if(new_xs[i] != 0) new_zs[new_n++] = i;
		}
	}
	if(new_max_item==0 && new_xs[0]==0) new_n++;
	
	return Poly(new_n, new_max_item, new_xs, new_zs);
}

Poly Poly::operator*(const Poly& p)
{		
	int new_max_item = zs[0], new_n = 0;
	int new_xs[100], new_zs[100];
	memset(new_xs, 0, sizeof(new_xs));
	
	
	if(n==1 && zs[0]==0 && xs[0]==0)
		return Poly(1,0,new_xs, new_zs);
	else if(p.n==1 && p.zs[0]==0 && p.xs[0]==0)
		return Poly(1,0,new_xs, new_zs);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<p.n; j++)
		{
			//指数相加， 系数相乘，同次数合并同类项
			new_xs[zs[i] + p.zs[j]] += xs[zs[i]] * p.xs[p.zs[j]];
			if(new_max_item < (zs[i] + p.zs[j]) ) new_max_item = zs[i] + p.zs[j]; 
		}
	}
	
	
	for(int i=0; i<=new_max_item; i++)
	{
		if(new_xs[i] != 0) new_zs[new_n++] = i;
	}
	
	if(new_max_item==0 && new_xs[0]==0) new_n++;
	
	return Poly(new_n, new_max_item, new_xs, new_zs);
}

ostream& operator<<(ostream &os, const Poly &p)
{
	for(int i=0;i<p.n;i++) // 对于每项
	{
		//只有常数项且为0
		if(p.max_item == 0)
		{
			os << p.xs[0]; return os;
		}
		// 系数输出 
		if(p.xs[p.zs[i]] == 1 && i==0)
		{
			if(p.zs[i] == 0) os << '1';
		}
		else if(p.xs[p.zs[i]] == 1)
		{
			if(p.zs[i] == 0) os << "+1";
			else os << '+';
		}
		else if(p.xs[p.zs[i]] == -1)
		{
			if(p.zs[i] == 0) os << "-1";
			else os << '-';
		}
		else if(p.xs[p.zs[i]] > 1 && i==0) //对于首项的系数为+的情况
		{
			os << p.xs[p.zs[i]];
		}
		else if(p.xs[p.zs[i]] > 1)
		{
			os << '+' << p.xs[p.zs[i]]; // 非首项且系数为+输出+号
		}
		else if(p.xs[p.zs[i]] < -1)
		{
			os << p.xs[p.zs[i]]; // 系数为- 数字已自带-号
		}
		
		//指数输出
		if(p.zs[i] == 0) continue;
		else if(p.zs[i] == 1) os << 'x';
		else if(p.zs[i] > 1) os << "x^" << p.zs[i];
		else os << "x^(" << p.zs[i] << ')';
	}
	
	return os;
}

int main()
{
	int t; cin >> t;
	int xs1[100], zs1[100], n1;
	int xs2[100], zs2[100], n2;
	for(int i=0;i<t;i++)
	{
		cin >> n1;
		for(int j=0;j<n1;j++)
		{
			cin >> xs1[j] >> zs1[j];
		}
		Poly p1(n1, xs1, zs1);
		//cout << p1 << endl;
		
		cin >> n2;
		for(int j=0;j<n2;j++)
		{
			cin >> xs2[j] >> zs2[j];
		}
		Poly p2(n2, xs2, zs2);
		//cout << p2 << endl;
		
		cout << p1 + p2 << endl;
		cout << p1 - p2 << endl;
		cout << p1 * p2 << endl;
		
	}
	
	return 0;
}
