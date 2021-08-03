//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Shape
//{
//protected:
//	string name;
//	double x, y;
//public:
//	Shape(){}
//	Shape(double x_v, double y_v) :x(x_v), y(y_v){}
//	virtual void shapeName() = 0;
//	string getname(){ return name; }
//	double getX(){ return x; }
//	double getY(){ return y; }
//	virtual int getArea(){ return 0.0; }
//	virtual int getVol(){ return 0.0; }
//};
//
//class Point :public Shape
//{
//public:
//	Point(double x_v, double y_v) :Shape(x_v, y_v){}
//	void shapeName() { name = "Point"; }
//	string getname(){ return name; }
//	double getX(){ return x; }
//	double getY(){ return y; }
//	int getArea(){ return 0.0; }
//	int getVol(){ return 0.0; }
//};
//
//class Circle :public Point
//{
//protected:
//	double r;
//public:
//	Circle(double x_v, double y_v, double r_v) :Point(x_v, y_v), r(r_v){}
//	void shapeName() { name = "Circle"; }
//	string getname(){ return name; }
//	double getX(){ return x; }
//	double getY(){ return y; }
//	int getArea(){ return 3.14159*r*r; }
//	int getVol(){ return 0.0; }
//};
//
//class Cylinder :public Circle
//{
//protected:
//	double h;
//public:
//	Cylinder(double x_v, double y_v, double r_v, double h_v) :Circle(x_v, y_v, r_v), h(h_v){}
//	void shapeName() { name = "Cylinder"; }
//	string getname(){ return name; }
//	double getX(){ return x; }
//	double getY(){ return y; }
//	int getArea(){ return 3.14159*r*r * 2 + 3.14159 * 2 * r*h; }
//	int getVol(){ return h*3.14159*r*r; }
//};
//
//void print(Shape*p)
//{
//	cout << p->getname() << "--(" << p->getX() << "," << p->getY()
//		<< ")--" << p->getArea() << "--" << p->getVol() << endl;
//}
//
//int main()
//{
//	string name;
//	double x, y,r,h;
//	Shape*p[3];
//	cin >> x >> y;
//	p[0] = new Point(x, y);
//	p[0]->shapeName();
//	print(p[0]);
//
//	cin >> x >> y>>r;
//	p[1] = new Circle(x, y, r);
//	p[1]->shapeName();
//	print(p[1]);
//
//	cin >> x >> y >> r>>h;
//	p[2] = new Cylinder(x, y, r,h);
//	p[2]->shapeName();
//	print(p[2]);
//
//	return 0;
//}
//
