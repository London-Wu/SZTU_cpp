#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class TV
{
private:
	int id, mode, vol, chNum;
	static int tv_num;
	static int dvd_num;
public:
	TV();
	void print();
	friend void set(TV &tv, int mode_set, int ch, int vol_change);
	static int getTvNum();
	static int getDvdNum();
};


int TV::tv_num = 0;
int TV::dvd_num = 0;

TV::TV()
{
	mode = 1;
	vol = 50;
	chNum = 1;
	tv_num++;
	id = tv_num + dvd_num;
}

void TV::print()
{
	cout << "第" << id << "号电视机" << "--";
	if (mode == 1) cout << "TV模式" << "--";
	else cout << "DVD模式" << "--";
	cout << "频道" << chNum << "--";
	cout << "音量" << vol << endl;
}

void set(TV& tv, int mode_set, int ch, int vol_change)
{
	if (tv.mode == 1) tv.tv_num--;
	else tv.dvd_num--;
	tv.mode = mode_set;
	if (tv.mode == 1) tv.tv_num++;
	else tv.dvd_num++;
	
	tv.chNum = ch;
	
	tv.vol += vol_change;
	if (tv.vol < 0) tv.vol = 0;
	if (tv.vol > 100) tv.vol = 100;
	tv.print();
}

int TV::getTvNum() { return tv_num; }
int TV::getDvdNum() { return dvd_num;}

int main()
{
	int tvnum;
	cin >> tvnum;
	TV* tvs = new TV[tvnum];
	
	int t;
	cin >> t;
	int id, mode, ch, volc;
	for (size_t i = 0; i < t; i++)
	{
		cin >> id >> mode >> ch >> volc;
		set(tvs[id - 1], mode, ch, volc);
	}
	
	cout << "播放电视的电视机数量为" << TV::getTvNum() << endl;
	cout << "播放DVD的电视机数量为" << TV::getDvdNum() << endl;
	
	delete[] tvs;
	
	return 0;
}
