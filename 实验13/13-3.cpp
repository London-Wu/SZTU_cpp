#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
class CRectangle;
class Point
{
private:
	int x, y;
public:
	Point(int xx, int yy);
	void set(int xx, int yy);
	friend bool operator==(const Point& p1, const Point &p2);
	friend bool operator>=(const Point& p1, const Point &p2); //点另一个点的右下方
	friend bool operator<=(const Point& p1, const Point &p2); //点另一个点的左上方
	friend bool operator>(const Point& p1, const Point &p2); //点另一个点的右下方
	friend bool operator<(const Point& p1, const Point &p2); //点另一个点的左上方
	
	friend bool operator*(const Point& p, const CRectangle &rec); //判断点是否在矩形内
	int getX() const;
	int getY() const;
};

Point::Point(int xx=0 ,int yy=0)
{
	x = xx; y = yy;
}

void Point::set(int xx, int yy)
{
	x = xx; y = yy;
}

bool operator==(const Point& p1, const Point &p2)
{
	if(p1.x == p2.x && p1.y == p2.y) return true;
	else return false;
}

bool operator>=(const Point& p1, const Point &p2)
{
	if(p1.x >= p2.x && p1.y <= p2.y) return true;
	else return false;
}

bool operator<=(const Point& p1, const Point &p2)
{
	if(p1.x <= p2.x && p1.y >= p2.y) return true;
	else return false;
}

bool operator>(const Point& p1, const Point &p2)
{
	if(p1.x > p2.x && p1.y < p2.y) return true;
	else return false;
}

bool operator<(const Point& p1, const Point &p2)
{
	if(p1.x < p2.x && p1.y > p2.y) return true;
	else return false;
}

int Point::getX() const {return x;}
int Point::getY() const {return y;}

class CRectangle
{
private:
	Point leftPoint, rightPoint;
public:
	CRectangle(int x1, int y1, int x2, int y2);
	friend bool operator==(const CRectangle& r1, const CRectangle& r2);
	friend bool operator>(const CRectangle& r1, const CRectangle& r2);
	friend bool operator*(const Point& p, const CRectangle &rec);
	friend bool operator*(const CRectangle& r1, const CRectangle& r2);
	friend ostream& operator<<(ostream& os, const CRectangle& rec);
	explicit operator int();
};

CRectangle::CRectangle(int x1, int y1, int x2, int y2)
{
	leftPoint.set(x1, y1);
	rightPoint.set(x2, y2);
}


bool operator==(const CRectangle& r1, const CRectangle& r2)
{
	if(r1.leftPoint == r2.leftPoint && r1.rightPoint == r2.rightPoint) return true;
	else return false;
}

bool operator>(const CRectangle& r1, const CRectangle& r2)
{
	if(r2.leftPoint >= r1.leftPoint && r2.rightPoint <= r1.rightPoint) return true;
	else return false;
}

bool operator*(const Point& p, const CRectangle &rec)
{
	if(p >= rec.leftPoint && p <= rec.rightPoint) return true;
	else return false;
}

bool operator*(const CRectangle& r1, const CRectangle& r2)
{
	for(int i = r1.leftPoint.getX(); i<=r1.rightPoint.getX(); i++)
	{
		for(int j = r1.rightPoint.getY(); j<=r1.leftPoint.getY(); j++)
		{
			if( (Point(i, j) * r2) ) return true;
		}
	}
	return false;
}

ostream& operator<<(ostream& os, const CRectangle& rec)
{
	os << rec.leftPoint.getX() << ' ' << rec.leftPoint.getY() << ' ';
	os << rec.rightPoint.getX() << ' ' << rec.rightPoint.getY();
	
	return os;
}

CRectangle::operator int()
{
	return (rightPoint.getX() - leftPoint.getX()) * (leftPoint.getY() - rightPoint.getY());
}

int main()
{
	int t, x1, x2, y1, y2;
	cin >> t;
	while (t--)
	{
		// 矩形1的左上角、右下角
		cin >> x1 >> y1 >> x2 >> y2;
		CRectangle rect1(x1, y1, x2, y2);
		// 矩形2的左上角、右下角
		cin >> x1 >> y1 >> x2 >> y2;
		CRectangle rect2(x1, y1, x2, y2);
		// 输出矩形1的坐标及面积
		cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
		// 输出矩形2的坐标及面积
		cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;
		if (rect1 == rect2)
		{
			cout << "矩形1和矩形2相等" << endl;
		}
		else if (rect2 > rect1)
		{
			cout << "矩形2包含矩形1" << endl;
		}
		else if (rect1 > rect2)
		{
			cout << "矩形1包含矩形2" << endl;
		}
		else if (rect1 * rect2)
		{
			cout << "矩形1和矩形2相交" << endl;
		}
		else
		{
			cout << "矩形1和矩形2不相交" << endl;
		}
		cout << endl;
	}
	return 0;
}
