#include <iostream>

using namespace std;

class CFraction
{
private:
	
	int Frac_up, Frac_down;
	
public:
	
	CFraction();
	CFraction(int up_val, int down_val);
	CFraction add(const CFraction &r);
	CFraction sub(const CFraction &r);
	CFraction mul(const CFraction &r);
	CFraction div(const CFraction &r);
	int get_up() const;
	int get_down()  const;
	int getGCD();
	void simp();
	void print();
};

CFraction::CFraction() { Frac_up = 1; Frac_down = 1;}

CFraction::CFraction(int up_val, int down_val)
{
	Frac_up = up_val;
	Frac_down = down_val;
}

int CFraction::get_up() const{ return Frac_up;}
int CFraction::get_down() const{ return Frac_down;}

int CFraction::getGCD()
{
	int a = Frac_up, b = Frac_down, r;
	if(a < b) swap(a, b);
	while(b != 0)
	{
		r = a % b; a = b; b = r;
	}
	return a;
}

void CFraction::simp()
{
	int bcd = getGCD();
	Frac_up /= bcd;
	Frac_down /= bcd;
	if((Frac_down < 0 && Frac_up >= 0) || (Frac_down < 0 && Frac_up < 0))
	{
		Frac_down = -Frac_down;
		Frac_up = -Frac_up;
	}
}

CFraction CFraction::add(const CFraction &r)
{
	int res_up, res_down;
	res_down = Frac_down * r.get_down();
	res_up = Frac_up * r.get_down() + r.get_up() * Frac_down;
	CFraction res(res_up, res_down);
	res.simp();
	
	return res;
}

CFraction CFraction::sub(const CFraction &r)
{
	int res_up, res_down;
	res_down = Frac_down * r.get_down();
	res_up = Frac_up * r.get_down() - r.get_up() * Frac_down;
	CFraction res(res_up, res_down);
	res.simp();
	
	return res;
}

CFraction CFraction::mul(const CFraction &r)
{
	int res_up, res_down;
	res_down = Frac_down * r.get_down();
	res_up = Frac_up * r.get_up();
	CFraction res(res_up, res_down);
	res.simp();
	
	return res;
}

CFraction CFraction::div(const CFraction &r)
{
	int res_up, res_down;
	res_down = Frac_down * r.get_up();
	res_up = Frac_up * r.get_down();
	CFraction res(res_up, res_down);
	res.simp();
	
	return res;
}

void CFraction::print()
{
	cout << Frac_up << '/' << Frac_down << endl;
}

int main()
{
	int t;
	cin >> t;
	int inp_up, inp_down;
	char divch;
	
	for(int i=0;i<t;i++)
	{
		cin >> inp_up >> divch >> inp_down;
		CFraction C1(inp_up, inp_down);
		cin >> inp_up >> divch >>inp_down;
		CFraction C2(inp_up, inp_down);
		CFraction res;
		
		res = C1.add(C2);
		res.print();
		
		res = C1.sub(C2);
		res.print();
		
		res = C1.mul(C2);
		res.print();
		
		res = C1.div(C2);
		res.print();
		
		cout << endl;
	}
	
	return 0;
}
