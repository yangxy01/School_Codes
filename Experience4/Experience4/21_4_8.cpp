#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

//F. 五子棋简单实现（类和对象）
class Gobang
{
public:
	void Initsetboard();
	void Displayboard();
	void setboard(char,int, int);
	void checkwin(char, int, int);
private:
	char checkerboard[15][15] ;

};
void Gobang::Initsetboard()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
			checkerboard[i][j] = '0';
	}
}
void Gobang::Displayboard()
{
	int i, j;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 14; j++)
		{
			cout << checkerboard[i][j]<<" ";
		}
		cout << checkerboard[i][j] << endl;
	}
}
void Gobang::setboard(char ch,int x, int y)
{
	if (x<1 || x>15 || y<1 || y>15)
		return;
	else if (checkerboard[x - 1][y - 1] != '0')
		return;
	else if (ch == 'u')
		checkerboard[x - 1][y - 1] = '#';
	else
		checkerboard[x - 1][y - 1] = '@';
}
void Gobang::checkwin(char ch, int x, int y)
{
	int i, j,t=5;
	//行
	while (t--)
	{

	}
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Gobang go;
		go.Initsetboard();
		int n,x,y;
		char ch;
		cin >> n;
		while (n--)
		{
			cin >> ch >> x >> y;
			go.setboard(ch, x, y);
			
		}
		go.Displayboard();
		cout << endl;
	}
	return 0;
}








////E. 月份查询（类与对象+引用）
//class Tdate
//{
//private :
//	int year;
//	int month;
//	int day;
//
//public:
//	void set(int, int, int);
//	void mon();
//	int date();
//};
//
//void Tdate::set(int y, int m, int d)
//{
//	year = y;
//	month = m;
//	day = d;
//}
//void Tdate::mon()
//{
//	char str[13][15] = { "January", "February", "March", "April",
//		"May", "June", "July", "August", "September",
//		"October", "November", "December", "January" };
//	cout <<"This month is "<< str[month - 1] 
//		<<" and next month is "<< str[month] << endl;
//}
//int Tdate::date()
//{
//	int flag=0,sum=0,i;
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		flag = 1;
//	int m1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int m2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (flag)
//	{
//		for (i = month-1; i < 12; i++)
//		{
//			sum += m2[i];
//		}
//		sum -= day;
//	}
//	else
//	{
//		for (i = month - 1; i < 12; i++)
//		{
//			sum += m1[i];
//		}
//		sum -= day;
//	}
//	return sum;
//}
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		int year;
//		int month;
//		int day;
//		cin >> year >> month >> day;
//		Tdate date;
//		date.set(year, month, day);
//		date.mon();
//		int sum = date.date();
//		cout << "There are " << sum << " days to the end of the year" << endl;
//	}
//	return 0;
//}








////C. 存折类定义（类与对象）
//class CAccount
//{
//private:
//	long account;
//	char name[10];
//	float balance;
//
//public:
//	void set(long, char[], float);
//	void deposit(float);
//	void cheak();
//	void withdraw(float);
//};
//
//void CAccount::set(long l, char s[], float f)
//{
//	account = l;
//	strcpy(name, s);
//	balance = f;
//}
//
//void CAccount::deposit(float m)
//{
//	balance += m;
//	cout << "saving ok!" << endl;
//}
//void CAccount::cheak()
//{
//	cout << name << "'s balance is " << balance << endl;
//}
//void CAccount::withdraw(float m)
//{
//	if (m > balance)
//		cout << "sorry! over limit!" << endl;
//	else
//	{
//		balance -= m;
//		cout << "withdraw ok!" << endl;
//	}
//}
//
//int main()
//{
//	long account;
//	char name[10];
//	float balance;
//	float m1, m2;
//	int t = 2;
//	while (t--)
//	{
//		cin >> account >> name >> balance >> m1 >> m2;
//		CAccount S;
//		S.set(account, name, balance);
//		S.cheak();
//		S.deposit(m1);
//		S.cheak();
//		S.withdraw(m2);
//		S.cheak();
//	}
//	return 0;
//}







////B. 学生类定义（类和对象）
//class Student
//{
//private:
//	char name[20];
//	int snumber;
//	char academy[20];
//	char major[20];
//	char sex[10];
//	char address[20];
//	char tel[20]; 
//
//public:
//	void setname(char str[])
//	{
//		strcpy(name, str);
//	}
//	void getname()
//	{
//		cout << name<<" ";
//	}
//	void setsnumber(int num)
//	{
//		snumber = num;
//	}
//	void getsnumber()
//	{
//		cout << snumber << " ";
//	}
//
//	void setacademy(char str[])
//	{
//		strcpy(academy, str);
//	}
//	void getacademy()
//	{
//		cout << academy << " ";
//	}
//
//	void setmajor(char str[])
//	{
//		strcpy(major, str);
//	}
//	void getmajor()
//	{
//		cout << major << " ";
//	}
//
//	void setsex(char str[])
//	{
//		strcpy(sex, str);
//	}
//	void getsex()
//	{
//		cout << sex << " ";
//	}
//
//	void setaddress(char str[])
//	{
//		strcpy(address, str);
//	}
//	void getaddress()
//	{
//		cout << address << " ";
//	}
//	void settel(char str[])
//	{
//		strcpy(tel, str);
//	}
//	void gettel()
//	{
//		cout << tel ;
//	}
//
//};
//
//int main()
//{
//	int t;
//	char name[20];
//	int snumber;
//	char academy[20];
//	char major[20];
//	char sex[10];
//	char address[20];
//	char tel[20];
//	cin >> t;
//	while (t--)
//	{
//		Student S;
//		cin >> name >> snumber >> academy >> major >> sex >> address >> tel;
//		S.setname(name);
//		S.getname();
//		S.setsnumber(snumber);
//		S.getsnumber();
//		S.setacademy(academy);
//		S.getacademy();
//		S.setmajor(major);
//		S.getmajor();
//		S.setsex(sex);
//		S.getsex();
//		S.setaddress(address);
//		S.getaddress();
//		S.settel(tel);
//		S.gettel();
//		cout << endl;
//	}
//	return 0;
//}







////A. 身体评估（类与对象）
//class Health
//{
//public:
//	int BMI(double, double);
//	double BRF(double, double);
//private:
//	char str[20];
//	double height;
//	double weight;
//	double waistline;
//};
//
//int Health::BMI(double x, double y)
//{
//	int z = x / (y*y)+0.5;
//	return z;
//}
//
//double Health::BRF(double a, double b)
//{
//	return (a*0.74-(b*0.082+34.89))/b;
//}
//
//int main()
//{
//	int t;
//	char str[20];
//	double height;
//	double weight;
//	double waistline;
//	cin >> t;
//	while (t--)
//	{
//		Health per;
//		cin >> str >> height >> weight >> waistline;
//		int bmi = per.BMI(weight, height);
//		double brf = per.BRF (waistline,weight);
//		cout << str << "'s BMI: " << bmi << "--";
//		cout<< setprecision(2) <<"BFR: "<< brf << endl;
//	}
//	return 0;
//}