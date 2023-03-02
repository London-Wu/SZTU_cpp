#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Point
{
private:
	double x, y;
	
public:
	Point();
	~Point();
	Point(double x_value, double y_value);
	double getX() const;
	double getY() const;
	void setXY(double x1, double y1);
	void setX(double x_value);
	void setY(double y_value);
	double getDisTo(const Point &p);
};

Point::Point(){ x=0; y=0; cout << "Constructor." << endl;}
Point::~Point(){ cout << "Distructor." << endl;}
Point::Point(double x_value, double y_value)
{
	x = x_value;
	y = y_value;
	cout << "Constructor." << endl;
}
double Point::getX() const { return x;}
double Point::getY() const { return y;}
void Point::setX(double x_value){ x = x_value;}
void Point::setY(double y_value){ y = y_value;}
void Point::setXY(double x1, double y1) { x = x1; y = y1;}
double Point::getDisTo(const Point &p)
{
	double p_x = p.getX();
	double p_y = p.getY();
	double distance = sqrt(pow(x-p_x, 2) + pow(y-p_y, 2));
	return distance;
}


int main()
{
	int t;
	cin >> t;
	int n;
	double ix, iy;
	
	double maxdis = 0;
	double dis;
	int maxpoi_j = 0, maxpoi_k = 0;
	
	for(int i=0;i<t;i++)
	{
		maxdis = 0;
		maxpoi_j = 0;
		maxpoi_k = 0;
		
		cin >> n;
		Point *pois = new Point[n];
		for(int j=0;j<n;j++)
		{
			cin >> ix >> iy;
			pois[j].setXY(ix, iy);
		}
		
		for(int j=0;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				dis = pois[j].getDisTo(pois[k]);
				if(dis > maxdis)
				{
					maxdis = dis;
					maxpoi_j = j;
					maxpoi_k = k;
				}
			}
		}
		
		cout << "The longeset distance is ";
		cout << fixed << setprecision(2) << maxdis << ',';
		cout << "between p[" << maxpoi_j << "] and p[" << maxpoi_k <<"]." << endl;
		
		delete[] pois;
	}
	
	return 0;
}
