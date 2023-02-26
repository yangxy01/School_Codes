#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;





////-----------G. CPU调度（类与对象）-----------
////-----类定义------
//
//class Process
//{  
//	char name;
//	int time_wait;
//	int time_run;
//	int level;
//public:
//	Process(char name, int time_wait, int time_run);
//	void Display();
//	int Getlevel();
//};
//
////----类实现------
//
//Process::Process(char name, int time_wait, int time_run)
//{
//	this->name = name;
//	this->time_wait = time_wait;
//	this->time_run = time_run;
//	
//}
//void Process::Display()
//{
//	cout << name << " "
//		<< time_wait << " "
//		<< time_run << " "
//		<< Getlevel();
//}
//int Process::Getlevel()
//{
//	return time_wait / time_run;
//}
//
//
//
//
////-----主函数-----
//
//int main()
//
//{
//
//	char ch;
//	int a, b;
//	cin >> ch >> a >> b;
//	Process p1(ch, a, b);
//	int l1 = p1.Getlevel();
//	cin >> ch >> a >> b;
//	Process p2(ch, a, b);
//	int l2 = p2.Getlevel();
//	cin >> ch >> a >> b;
//	Process p3(ch,a, b);
//	int l3 = p3.Getlevel();
//
//	int max = l1;
//	if (l2 > l1)
//		max = l2;
//	if (l3 > max)
//		max = l3;
//	if (max == l1)
//		p1.Display();
//	if (max == l2)
//		p2.Display();
//	if (max == l3)
//		p3.Display();
//	cout << endl;
//
//	return 0;
//
//}










//------------F. Equation(类与对象+构造)-----------
class Equation
{
	double a, b, c;
public:
	Equation();
	Equation(double a, double b, double c);
	void set(double a, double b, double c);
	void getroot();

};
Equation::Equation()
{
	a = 1;
	b = 1;
	c = 0;
}
Equation::Equation(double a_value, double b_value, double c_value)
{
	a = a_value;
	b = b_value;
	c = c_value;
}
void Equation::set(double a_value, double b_value, double c_value)
{
	a = a_value;
	b = b_value;
	c = c_value;
}
void Equation::getroot()
{
	double x1, x2;
	double detal = b*b - 4 * a*c;
	if (detal == 0)
	{
		x1 = (-b + sqrt(detal)) / (2 * a);
		x2 = x1;
		cout << fixed << setprecision(2) << "x1=x2=" << x1 << endl;
	}
	else if (detal > 0)
	{
		x1 = (-b + sqrt(detal)) / (2 * a);
		x2 = (-b - sqrt(detal)) / (2 * a);
		cout << fixed << setprecision(2) << "x1="
			<< x1 << " x2=" << x2 << endl;
	}
	else
	{
		detal = -detal;
		cout << fixed << setprecision(2) 
			<< "x1=" << -b / (2 * a) << "+"
			<< fabs(sqrt(detal) / (2 * a)) << "i"
			<< " x2=" << -b / (2 * a) << "-" 
			<< fabs(sqrt(detal) / (2 * a)) << "i"
			<< endl;
	}
}
int main()
{
	double t,a,b,c;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		Equation x(a, b, c);
		x.getroot();
	}
}










////E. 分数类（类与构造）********重做**********
//class CFraction
//{
//private:
//	int fz, fm;
//public:
//	CFraction(int fz_val, int fm_val);
//	CFraction add(const CFraction&r);
//	CFraction sub(const CFraction&r);
//	CFraction mul(const CFraction&r);
//	CFraction div(const CFraction&r);
//	int getGCD();
//	void print();
//};
//CFraction::CFraction(int fz_val, int fm_val)
//{
//	fz = fz_val;
//	fm = fm_val;
//}
//CFraction CFraction::add(const CFraction& r) 
//{
//	return CFraction(fz * r.fm + fm * r.fz, fm * r.fm);
//}
//
//CFraction CFraction::sub(const CFraction& r) 
//{
//	return CFraction(fm * r.fz - fz * r.fm, fm * r.fm);
//}
//
//CFraction CFraction::mul(const CFraction& r) 
//{
//	return CFraction(fz * r.fz, fm * r.fm);
//}
//
//CFraction CFraction::div(const CFraction& r) 
//{
//	return CFraction(fm * r.fz, fz * r.fm);
//}
//int CFraction::getGCD()
//{
//	int r = 1;
//	int x = abs(fz);
//	int y = abs(fm);
//	int tmp = 0;
//	if (y > x)
//	{
//		tmp = x;
//		x = y;
//		y = tmp;
//	}
//	while (x%y != 0)
//	{
//		r = x%y;
//		x = y;
//		y = r;
//	}
//	return y;
//}
//void CFraction::print()
//{
//	int k = getGCD();
//	int flag1 = 0, flag2 = 0;
//	fz = fz / k;
//	fm = fm / k;
//	if (fz<0)
//		flag1 = 1;
//	if (fm < 0)
//		flag2 = 1;
//	fz = abs(fz);
//	fm = abs(fm);
//	if (flag1==flag2)
//		cout << fz << "/" << fm << endl;
//	else
//		cout <<"-"<< fz << "/" << fm << endl;
//
//}
//
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	int fz, fm;
//	char ch;
//	while (t--)
//	{
//		cin >> fz >>ch>> fm;
//		CFraction r1(fz, fm);
//		cin >> fz >> ch >> fm;
//		CFraction r2(fz, fm);
//		CFraction r3=r2.add(r1);
//		r3.print();
//		r3 = r2.sub(r1);
//		r3.print();
//		r3 = r2.mul (r1);
//		r3.print();
//		r3 = r2.div (r1);
//		r3.print();
//		cout << endl;
//		
//	}
//	return 0;
//}