#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;


int main()
{
	std::string orbits("365.24 29.53");
	std::string::size_type sz;     // alias of size_t

	double earth = std::stod(orbits, &sz);
	double moon = std::stod(orbits.substr(sz));
	std::cout << "The moon completes " << (earth / moon) << " orbits per Earth year.\n";
	return 0;
}




////E. Point_Array(类+构造+对象数组)
//class Point
//{
//	double x, y;
//public:
//	Point();
//	~Point()
//	{
//		cout << "Distructor." << endl;
//	}
//	Point(double xvalue, double yvalue);
//	double getX();
//	double getY();
//	void setXY(double x1, double y1)
//	{
//		x = x1;
//		y = y1;
//	}
//	void setX(double xvalue);
//	void setY(double yvalue);
//	double getDisTo(Point &p);
//};
//
//Point::Point()
//{
//	x = 0;
//	y = 0;
//	cout << "Constructor." << endl;
//}
//
//Point::Point(double xvalue, double yvalue)
//{
//	x = xvalue;
//	y = yvalue;
//}
//
//double Point::getX(){
//	return x;
//}
//
//double Point::getY(){
//	return y;
//}
//
//void Point::setX(double xvalue)
//{
//	x = xvalue;
//}
//
//void Point::setY(double yvalue)
//{
//	y = yvalue;
//}
//
//double Point::getDisTo(Point &p)
//{
//	double a, b, c, s;
//	a = (x - p.getX())*(x - p.getX());
//	b = (y - p.getY())*(y - p.getY());
//	c = a + b;
//	s = sqrt(c);
//	return s;
//}
//
//
//
//int main()
//{
//	int t, i, x, y, j, a, b, n;
//	double max;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n;
//		Point*p = new Point[n];
//		for (i = 0; i < n; i++)
//		{
//			cin >> x >> y;
//			p[i].setXY(x, y);
//		}
//
//		max = p[0].getDisTo(p[1]);
//		a = 0; b = 1;
//
//		for (i = 0; i<n; i++)
//		{
//			for (j = i + 1; j<n; j++)
//			{
//				if (p[i].getDisTo(p[j])>max)
//				{
//					max = p[i].getDisTo(p[j]);
//					a = i;
//					b = j;
//				}
//			}
//		}
//		cout << "The longeset distance is " << fixed << setprecision(2) << max << "," <<
//			"between p[" << a << "] and p[" << b << "]." << endl;
//		delete[]p;
//	}
//	
//	
//	return 0;
//}




////D. 最胖的加菲（类与对象+数组）
//class Cat
//{
//	string name;
//	int weight;
//public:
//	Cat(string n="no", int w=0) :name(n), weight(w){}
//	void set(string n, int w)
//	{
//		name=n;
//		weight=w;
//	}
//	int getweight()
//	{
//		return weight;
//	}
//	string getname()
//	{
//		return name;
//	}
//};
//int main()
//{
//	int n;
//	string name;
//	int weight;
//	cin >> n;
//	Cat* C = new Cat[n];
//	for (int i = 0; i < n;i++)
//	{
//		cin >> name >> weight;
//		C[i].set(name, weight);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			if (C[j].getweight()>C[j + 1].getweight())
//			{
//				Cat D = C[j];
//				C[j] = C[j+1];
//				C[j + 1] = D;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		string name = C[i].getname();
//		if (i < n - 1)
//			cout << name << " ";
//		else
//			cout << name << endl;
//	}
//
//	return 0;
//}


//class CStack
//{
//	int*a;
//	int size;
//	int top;
//public:
//	CStack();
//	CStack(int s);
//	CStack(CStack&r_s);
//	void push(int val);
//	int pop();
//	~CStack();
//};
//CStack::CStack(){ size = 10; top = 0; }
//CStack::CStack(int s)
//{
//	a = new int[s];
//	top = 0;
//	size = s;
//	cout << "Constructor." << endl;
//}
//CStack::CStack(CStack&r_s)
//{
//	delete[]a;
//	a = new int[r_s.size];
//	top = r_s.top;
//	for (int i = 0; i < top; i++)
//		a[i] = r_s.a[i];
//}
//CStack::~CStack()
//{
//	cout << "Destructor." << endl;
//	delete[]a;
//}
//void CStack::push(int val)
//{
//	a[top] = val;
//	top++;
//}
//int CStack::pop()
//{
//	top--;
//	return a[top];	
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		CStack S(n);
//		int x;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x;
//			S.push(x);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (i<n-1)
//				cout << S.pop() << " ";
//			else
//				cout << S.pop() <<endl;
//		}
//	}
//	return 0;
//}