#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Rational {
public:
	Rational(int a = 0, int b = 1) {
		int c;
		c = Common_Divisor(a, b);
		X = a / c;
		Y = b / c;
	}
	Rational Add(Rational &r);
	Rational Sub(Rational &r);
	Rational Mul(Rational &r);
	Rational Div(Rational &r);
	void Print() {
		cout << X << "/" << Y << endl;
	}
	void PrintPoint() {
		if (Y == 0)
			exit(0);
		cout << double(X) / Y << endl;
	}
private:
	int X, Y;
	int Common_Divisor(int a, int b);
};

Rational Rational::Add(Rational &r) {
	int a, b;
	a = this->X*r.Y + this->Y*r.X;
	b = this->Y*r.Y;
	Rational Z(a, b);
	return Z;
}

Rational Rational::Sub(Rational &r) {
	int a, b;
	a = this->X*r.Y - this->Y*r.X;
	b = this->Y*r.Y;
	Rational Z(a, b);
	return Z;
}

Rational Rational::Mul(Rational &r) {
	int a, b;
	a = this->X*r.X;
	b = this->Y*r.Y;
	Rational Z(a, b);
	return Z;
}

Rational Rational::Div(Rational &r) {
	int a, b;
	a = this->X*r.Y;
	b = this->Y*r.X;
	Rational Z(a, b);
	return Z;
}

int Rational::Common_Divisor(int a, int b) {
	int c;
	do {
		c = a % b;
		a = b;
		b = c;
	} while (c != 0);
	return a;
}

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Rational x(x1, y1), y(x2, y2);
	x.Add(y).Print();
	x.Sub(y).Print();
	x.Mul(y).Print();
	x.Div(y).Print();
	x.Add(y).PrintPoint();
	return 0;
}


//#include<iostream>
//using namespace std;
//class Complex
//{
//	float x, y;
//public:
//	void add(Complex& C)
//	{
//		x += C.x;
//		y += C.y;
//	}
//};

//class Point
//{
//	double x, y;
//public:
//	Point(double x_val=0, double y_val=0)
//	{
//		x = x_val;
//		y = y_val;
//	}
//	virtual void draw()
//	{
//		cout << "Point:x=" << x << ",y=" << y << "" << endl;
//	}
//	friend class Line;
//	friend class Circle;
//};
//
//class Line :public Point
//{
//	Point pa;
//	Point pb;
//public:
//	Line(Point& p1, Point& p2) :pa(p1.x, p1.y), pb(p2.x, p2.y){}
//	void draw()
//	{
//		cout << "Line:(Point:x=" << pa.x << ",y=" << pa.y 
//			<< ";Point:x=" << pb.x << ",y=" << pb.y << ")" << endl;
//	}
//};
//
//class Circle :public Point
//{
//	Point p;
//	double r;
//public:
//	Circle(Point& p1, double r_val) :p(p1.x, p1.y)
//	{
//		r = r_val;
//	}
//	void draw()
//	{
//		cout << "Circle:(radius:" << r << ";orgin:Point:x=" 
//			<< p.x << ",y=" << p.y << ")" << endl;
//	}
//};
//
//int main()
//{
//	double x1, y1, x2, y2, r;
//	cin >> x1 >> y1 >> x2 >> y2 >> r;
//	Point p1(x1, y1);
//	Point p2(x2, y2);
//	Line L(p1, p2);
//	Circle c(p2, r);
//	p1.draw();
//	L.draw();
//	c.draw();
//	return 0;
//}