//#include<iostream>
//#include<iomanip>
//#include<string>
//using namespace std;
//class Shape
//{
//public:
//	virtual double Area() = 0;
//};
//class Circle :public Shape
//{
//	double r;
//public:
//	Circle(double r_value) :r(r_value) {}
//	double Area()
//	{
//		return 3.14 * r * r;
//	}
//};
//class Square :public Shape
//{
//	double L;
//public:
//	Square(double L_value) :L(L_value) {}
//	double Area()
//	{
//		return L * L;
//	}
//};
//class Rectangle :public Shape
//{
//	double a,b;
//public:
//	Rectangle(double va, double vb) :a(va),b(vb) {}
//	double Area() { return a*b; }
//};
//
//int main()
//{
//	int t;
//	double r, L, a, b;
//	cin >> t;
//	while (t--)
//	{
//		Shape* p[3];
//		for (int i = 0; i < 3; i++) { p[i] = NULL; }
//		cin >> r >> L >> a >> b;
//		p[0] = new Circle(r);
//		p[1] = new Square(L);
//		p[2] = new Rectangle(a,b);
//		for (int i = 0; i < 3; i++)
//		{
//			double ret=p[i]->Area();
//			cout <<fixed<<setprecision(2)<< ret << endl;
//		}
//		for (int i = 0; i < 3; i++) { delete p[i]; }
//	}
//
//	return 0;
//}
