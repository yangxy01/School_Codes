#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;


////----------  B. 彩票复制（拷贝构造）------------
//class lottery
//{
//	int num;
//	int *group1;
//	int**groupn;
//public:
//	lottery(int* p, int n)
//	{
//		num = n;
//		group1 = new int[6];
//		for (int i = 0; i < 6; i++)
//		{
//			group1[i] = p[i];
//		}
//	}
//	lottery(const lottery&a)
//	{
//		this->num = a.num;
//		groupn = new int*[num+1];
//
//		int i, j;
//
//		for (i = 0; i<num+1; i++)
//			groupn[i] = new int[6];
//
//		for (j = 0; j < 6; j++)
//		{
//			groupn[0][j] = a.group1[j];
//		}
//
//
//
//		for (i = 1; i <= num; i++)
//		{
//			groupn[i][0] = groupn[i - 1][5]+1;
//			for (j = 1; j < 6; j++)
//			{
//				groupn[i][j] = groupn[i - 1][j - 1]+1;
//			}
//		}
//	}
//	void print()
//	{
//		int i, j;
//		for (i = 0; i <= num; i++)
//		{
//			for (j = 0; j < 5; j++)
//			{
//				cout << groupn[i][j] << " ";
//			}
//			cout << groupn[i][5] << endl;
//		}
//	}
//};
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int group1[6];
//		int i, num;
//		for (i = 0; i < 6; i++)
//			cin >> group1[i];
//		cin >> num;
//
//		lottery L(group1, num);
//
//		lottery L2 (L);
//
//		L2.print();
//
//
//	}
//}





////---------C. Stack(类与拷贝构造)------------
//class CStack
//{
//	int *a;
//	int size;
//	int top;
//public:
//	CStack()
//	{
//		size = 10;
//		a = new int[size];
//		top = 0;
//	}
//	CStack(int s)
//	{
//		size = s;
//		a = new int[size];
//		top = 0;
//		cout << "Constructor." << endl;
//	}
//	CStack(CStack&r_s);
//	int get(int index);
//	void push(int n);
//	int isEmpty()
//	{
//		if (top == 0)
//			return 1;
//		return 0;
//	}
//	int isFull()
//	{
//		if (top == size)
//			return 1;
//		return 0;
//	}
//	void instack(int num)
//	{
//		a[top] = num;
//		top++;
//	}
//	int pop()
//	{
//		top--;
//		return a[top];
//	}
//	~CStack()
//	{
//		delete a;
//		cout << "Destructor." << endl;
//	}
//};
//
//int main()
//{
//	int t,num;
//	cin >> t;
//	while (t--)
//	{
//		int s,s1;
//		cin >> s;
//		s1 = s;
//		CStack stack(s);
//		while (s--)
//		{
//			cin >> num;
//			if (stack.isFull() != 1)
//			{
//				stack.instack(num);
//			}
//		}
//		while (stack.isEmpty()!=1)
//		{
//			num=stack.pop();
//			cout << num ;
//			if (s1 > 1)
//			{
//				cout << " ";
//				s1--;
//			}
//			else
//			{
//				cout << endl;
//				s1--;
//			}
//		}
//	}
//	return 0;
//}






////-------------D. 最胖的加菲（类与对象+数组）-------------
////？？？？？？？重做
//class Cat
//{
//	int weight;
//	string name;
//	//char*name;
//public:
//	Cat()
//	{
//		weight = 0;
//		//name = NULL;
//		name = "null";
//	}
//	string getname()
//	{
//		return name;
//	}
//	int getweight()
//	{
//		return weight;
//	}
//	void set(string pname, int weight)
//	{
//		this->weight = weight;
//		name = pname;
//		/*int len = strlen(pname);
//		name = new char[len + 1];
//		strcpy(name,pname);*/
//	}
//	void print()
//	{
//		cout << name;
//	}
//};
//
//void swap(Cat &cat1, Cat &cat2)
//{
//	Cat tmp=cat1;
//	cat1 = cat2;
//	cat2 = tmp;
//}
//
//int main()
//{
//	int n, i, j;
//	int weight;
//	//char name[20];
//	string name;
//	cin >> n;
//	Cat*p = new Cat[n];
//	for (i = 0; i < n; i++)
//	{
//		cin >> name >> weight;
//		p[i].set(name, weight);
//	}
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (p[j].getweight()>p[j + 1].getweight())
//			{
//				swap(p[j], p[j + 1]);
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		p[i].print();
//		if (i < n - 1)
//			cout << " ";
//		else
//			cout << endl;
//	}
//	return 0;
//}








////-----------E. Point_Array(类+构造+对象数组)-----------
//class Point
//{
//	double x, y;
//public:
//	Point();
//	~Point()
//	{
//		cout << "Distructor." << endl;
//	}
//	Point(double x_value, double y_value);
//	double getX();
//	double getY();
//	void setX(double x_value);
//	void setY(double y_value);
//	double getDisTo(Point &p);
//};
//Point::Point()
//{
//	x = 0;
//	y = 0;
//	cout << "Constructor." << endl;
//}
//Point::Point(double x_value, double y_value)
//{
//	x = x_value;
//	y = y_value;
//}
//void Point::setX(double x_value)
//{
//	x = x_value;
//}
//void Point::setY(double y_value)
//{
//	y = y_value;
//}
//double Point::getX()
//{
//	return x;
//}
//double Point::getY()
//{
//	return y;
//}
//double Point::getDisTo(Point &p)
//{
//	double x1 = p.getX();
//	double y1 = p.getY();
//	double dis = 0;
//	dis = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
//	return dis;
//}
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, i, j ,indexi, indexj;
//		double max;
//		cin >> n;
//		Point *p = new Point[n];
//		double x, y;
//		for (i = 0; i < n; i++)
//		{
//			cin >> x >> y;
//			p[i].setX(x);
//			p[i].setY(y);
//		}
//		max = 0;
//		for (int i = 0; i<n; i++)
//		{
//			for (int j = i + 1; j<n; j++)
//			{
//				double dis = p[i].getDisTo(p[j]);
//				if (dis > max)
//				{
//					max = dis;
//					indexi = i;
//					indexj = j;
//				}
//			}
//		}
//		cout << "The longeset distance is " << fixed << setprecision(2) 
//			<< max << ",between p[" << indexi << "] and p[" 
//			<< indexj << "]." << endl;
//		delete[] p;
//
//	}
//
//	return 0;
//}





////---------------F. 手机取款（类与对象数组）-------------

//class account
//{
//	int ID;
//	int tel;
//	int password;
//	int balance;
//public:
//	account(int ID=0, int tel=0, int password=0, int balance=0)
//	{
//		this->ID = ID;
//		this->tel = tel;
//		this->password = password;
//		this->balance = balance;
//	}
//	int gettel()
//	{
//		return tel;
//	}		
//	int getpassword()
//	{
//		return password;
//	}
//	int getbalance()
//	{
//		return balance;
//	}
//	int getID()
//	{
//		return ID;
//	}
//	void setbalance(int money)
//	{
//		balance -= money;
//	}
//};
//
//int main()
//{
//	int n,k;
//	int ID, tel, password, balance;
//	cin >> n;
//	account*p = new account[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> ID >> tel >> password >> balance;
//		p[i] = account(ID, tel, password, balance);
//	}
//	cin >> k;
//	while (k--)
//	{
//		int draw;
//		cin >> tel >> password >> draw;
//		int telExist = 0;
//		for (int i = 0; i < n; i++)
//		{
//			if (p[i].gettel() == tel)
//			{
//				telExist = 1;
//				if (p[i].getpassword() != password)
//				{
//					cout << "密码错误" << endl;
//				}
//				else
//				{
//					if (p[i].getbalance() < draw)
//					{
//						cout << "卡号" << p[i].getID() << "--余额不足" << endl;
//					}
//					else
//					{
//						p[i].setbalance(draw);
//						cout << "卡号" << p[i].getID() << "--余额" << p[i].getbalance() << endl;
//					}
//				}
//			}
//			else
//				continue;
//		}
//		if (telExist == 0)
//		{
//			cout << "手机号不存在" << endl;
//		}
//	}
//	return 0;
//}