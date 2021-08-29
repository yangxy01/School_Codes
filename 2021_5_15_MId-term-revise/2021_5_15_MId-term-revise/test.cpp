#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÀà¶¨Òå¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª 
class Point
{
public:
	double x, y;
	void SetPoint(double a, double b);
	double getX();
	double getY();
};
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÀàÊµÏÖ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª 
void Point::SetPoint(double a, double b)
{
	x = a;
	y = b;
}
double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÀà¶¨Òå¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
class Circle
{
	Point p;
	double r;
public:
	void SetCenter(double a, double b);
	void SetRadius(double n);
	double getArea();
	double getLength();
	bool Contain(Point q);
};
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÀàÊµÏÖ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
void Circle::SetCenter(double a, double b)
{
	p.SetPoint(a, b);
}
void Circle::SetRadius(double n)
{
	r = n;
}
double Circle::getArea()
{
	return 3.14 * r * r;
}
double Circle::getLength()
{
	return 3.14 * 2 * r;
}
bool Circle::Contain(Point q)
{
	double dis;
	dis = sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
	return dis <= this->r;
}
//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªÖ÷º¯Êý¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª
int main()
{
	double x, y, r, a, b;
	double area, len;
	cin >> x >> y >> r >> a >> b;
	Circle c;
	Point p;
	c.SetCenter(x, y);
	c.SetRadius(r);
	p.SetPoint(a, b);
	area = c.getArea();
	len = c.getLength();
	if (c.Contain(p))
	{
		cout << area << " " << len << endl;
		cout << "yes" << endl;
	}
	else
	{
		cout << area << " " << len << endl;
		cout << "no" << endl;
	}
}