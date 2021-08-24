#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
//---------A. 购物车（复合类）----------
class Commodity
{
private:
	string ID;
	string name;
	string col;
	string size;
	double price;
	double num;
public:
	Commodity()
	{
		num = 0; 
		price = 0;
	}
	string& getID() { return ID; }
	string& getname() { return name; }
	string& getcolour() { return col; }
	string& getsize() { return size; }
	double& getprice() { return price; }
	double& getnum() { return num; }

	double sum() 
	{ 
		return price * num; 
	}
	void print();
	~Commodity(){}
};

class trolley
{
	Commodity* com;
	int tot;
	double totalPrice;
	int length;
	int Maxlen;
public:
	void Delete(string& k);
	void up(string&k);
	void down(string&k);
	void print();
	~trolley()
	{}
};


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		trolley T;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			if (str == "ADD")
			{
				
			}
			else if (str == "UP")
			{
				string s;
				cin >> s;
				T.up(a);
			}
			else if (str == "DOWN")
			{
				string s;
				cin >> s;
				T.down(a);
			}
			else if (str == "DELETE")
			{
				string s;
				cin >> s;
				T.Delete(a);
			}
		}
		T.print();
		cout << endl;
	}
	return 0;
}



class Commodity
{
private:
	string num;
	string name;
	string colour;
	string size;
	double price;
	double count;
public:
	Commodity() :count(0), price(0){}
	string& getnum() { return num; }
	string& getname() { return name; }
	string& getcolour() { return colour; }
	string& getsize() { return size; }
	double& getprice() { return price; }
	double& getcount() { return count; }

	double sum() { return price * count; }
	void print();
	~Commodity(){}
};
class Shopping_car
{
private:
	int num_all;
	Commodity C[300];
public:
	Shopping_car() :num_all(0){}
	void Delete(string& a);
	void add(string& a, string& b, string& c, string& d, double& e, double& f);
	void up(string& a);
	void down(string &a);
	void print();
	~Shopping_car(){}
};
void Shopping_car::add(string& a, string& b, string& c, string& d, double& e, double& f)
{
	for (int i = 0; i < num_all; i++)
	{
		if (C[i].getnum() == a&&C[i].getcount() != 0)
		{
			C[i].getcount() += f;
			return;
		}
	}
	for (int i = num_all; i != -1; i--)
	{
		C[i + 1] = C[i];
	}
	C[0].getnum() = a;
	C[0].getname() = b;
	C[0].getsize() = c;
	C[0].getcolour() = d;
	C[0].getprice() = e;
	C[0].getcount() = f;
	num_all++;
	return;
}
void Shopping_car::down(string& a)
{
	for (int i = 0; i < num_all; i++)
	{
		if (C[i].getnum() == a)
		{
			C[i].getcount()--;
		}
	}
}
void Shopping_car::up(string& a)
{
	for (int i = 0; i < num_all; i++)
	{
		if (C[i].getnum() == a)
		{
			C[i].getcount()++;
		}
	}
}
void Shopping_car::Delete(string& a)
{
	for (int i = 0; i < num_all; i++)
	{
		if (C[i].getnum() == a)
		{
			C[i].getcount() = 0;
		}
	}
}
void Commodity::print()
{
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << name << "," << size << "," << colour << "," << price << "," << (int)count << "," << sum() << endl;
}
void Shopping_car::print()
{
	double money = 0;
	int num_all1 = 0;
	cout << "商品清单:\n" << "商品,颜色,尺码,单价,数量,小计\n";

	for (int i = 0; i <num_all; i++)
	{
		if (C[i].getcount() > 0)
		{
			C[i].print();
			money += C[i].sum();
			num_all1 += C[i].getcount();
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "----------\n";
	cout << num_all1 << "件商品,总商品金额" << money << endl;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Shopping_car S;
		for (int i = 0; i < n; i++)
		{
			string input;
			cin >> input;
			if (input == "ADD")
			{
				string a, b, c, d;
				double e, f;
				cin >> a >> b >> c >> d >> e >> f;
				S.add(a, b, c, d, e, f);
			}
			else if (input == "UP")
			{
				string a;
				cin >> a;
				S.up(a);
			}
			else if (input == "DOWN")
			{
				string a;
				cin >> a;
				S.down(a);
			}
			else if (input == "DELETE")
			{
				string a;
				cin >> a;
				S.Delete(a);
			}
		}
		S.print();
		cout << endl;
	}
}





////------------B. Point&Circle(复合类与构造)----------
//class Point
//{
//	double x, y;
//public:
//	Point(double x_value = 0, double y_value = 0)
//	{
//		x = x_value;
//		y = y_value;
//	}
//	double getX()
//	{
//		return x;
//	}
//	double getY()
//	{
//		return y;
//	}
//	void setXY(double x_value, double y_value)
//	{
//		x = x_value;
//		y = y_value;
//	}
//	
//
//};
//
//
//
//class Circle
//{
//	double radius;
//	Point centre;
//public:
//	Circle(double x_value = 0, double y_value = 0, double r_value = 0)
//	{
//		centre =Point(x_value, y_value);
//		radius = r_value;
//	}
//
//	void setXY(double x_value=0, double y_value=0)
//	{
//		centre.setXY(x_value, y_value);
//	}
//
//	int Getaddress(Point& p)
//	{
//		double dis2 = 0;
//		dis2 = (centre.getX() - p.getX())*(centre.getX() - p.getX()) +
//			(centre.getY() - p.getY())*(centre.getY() - p.getY());
//		if (dis2 <= radius*radius)
//			return 1;
//		else
//			return 0;
//	}
//
//};
//
//
//
//int main()
//{
//	int i, j;
//	int x, y, r, n;//圆的坐标半径
//	cin >> x >> y >> r;
//	Circle C(x, y, r);//构造圆对象
//
//	cin >> n;//组数
//	Point* p = new Point[n];
//	for (i = 0; i < n; i++)
//	{
//		cin >> x >> y;//点
//		p[i] = Point(x, y);
//		int ret = C.Getaddress(p[i]);
//		if (ret == 1)
//		{
//			cout << "inside" << endl;
//		}
//		else
//		{
//			cout << "outside" << endl;
//		}
//	}
//	//改变圆心
//	cout << "after move the centre of circle:" << endl;
//	cin >> x >> y;
//	C.setXY(x, y);
//
//	for (i = 0; i < n; i++)
//	{
//		int ret = C.Getaddress(p[i]);
//		if (ret == 1)
//		{
//			cout << "inside" << endl;
//		}
//		else
//		{
//			cout << "outside" << endl;
//		}
//	}
//
//	
//
//	return 0;
//}



//---------- - C.生日打折（复合类构造）---------------
//class Date
//{
//	int year, month, day;
//public:
//	Date(int y=0, int m=0, int d=0) :year(y), month(m), day(d){}
//	int getyear()
//	{
//		return year;
//	}
//	int getmonth()
//	{
//		return month;
//	}
//	int getday()
//	{
//		return day;
//	}
//	
//};
//
//class VIP
//{
//	int id;
//	Date birth;
//	int cost;
//public:
//	VIP(int id = 0, int y = 0, int m = 0, int d = 0,int c=0) :birth(y, m, d)
//	{
//		this->id = id;
//		cost = c;
//	}
//	double discount(Date&date)
//	{
//		int flag = 1;
//		if (birth.getmonth() != date.getmonth())
//			flag = 0;
//		if (birth.getday() != date.getday())
//			flag = 0;
//		if (flag == 1)
//		{
//			return 0.5;
//		}
//		return 0.95;
//	}
//	int getID()
//	{
//		return id;
//	}
//
//};
//
//
//int main()
//{
//	int year, month, day;
//	cin >> year >> month >> day;
//	Date today(year, month, day);//创建今天对象
//
//	int n, id ,cost;//n个会员及id和消费
//	cin >> n;
//	VIP*p = new VIP[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> id >> year >> month >> day >>cost;
//		p[i] = VIP(id, year, month, day, cost);
//		double ret=p[i].discount(today);
//		//cout << ret << endl;
//		cout << p[i].getID() << "'s consumption is " << int(cost*ret)<<endl;
//	}
//
//
//	delete [] p;
//	return 0;
//}





////-------------D. 删除重复元素（结构体+链表+类）-----------
//class List
//{
//	
//};





////----------E. 身份证设定（复合类+拷贝构造）----------
//class birthday
//{
//	int year, month, day;
//public:
//	birthday(int y=0, int m=0, int d=0) :year(y), month(m), day(d){} 
//	void print()
//	{
//		cout << "type=2 birth=" << year << "."
//			<< setfill('0') << setw(2) << month << "."
//			<< setw(2) << day << endl;
//	}
//	int getyear()
//	{
//		return year;
//	}
//};
//
//class PID
//{
//	int type;
//	string number;
//	birthday bir;
//public:
//	PID(int type_value , string str , birthday b) :bir(b)
//	{
//		number = str;
//		type = type_value;
//	}
//	PID(PID&pid)
//	{
//		this->type = pid.type;
//		this->number = pid.number;
//		bir = pid.bir;
//		int length = number.length();
//		if (length == 15)
//		{
//			this->type = 2;
//			int y = pid.bir.getyear();
//			number.insert(6, to_string(y), 0, 2);
//			int n = 0, sum = 0;
//			for (int i = 0; i < 17; i++)
//			{
//				n += number[i] - '0';
//			}
//			sum = n % 10;
//			if (sum == 0)
//				number.append("X");
//			else
//				number.append(to_string(sum));
//		}
//	}
//	void print()
//	{
//		cout << "ID=" << number << endl;
//	}
//
//};
//
//
//int main()
//{
//	int t, type, year, month, day;
//	string str;
//	cin >> t;
//	while (t--)
//	{
//		cin >> type >>str>> year>> month>> day;
//		birthday bir(year, month, day);
//		bir.print();
//		PID pid1(type, str, bir);
//		PID pid2(pid1);
//		pid2.print();
//
//	}
//
//
//	return 0;
//}





////-----------F. 立方体碰撞检测（复合类+动态对象数组+析构）----------
//
//class CPoint
//{
//	int x, y, z;
//public:
//	//CPoint() = default;
//	CPoint(int x_value = 0, int y_value = 0, int z_value = 0)
//	{
//		x = x_value;
//		y = y_value;
//		z = z_value;
//	}
//	/*CPoint& operator=(CPoint& a)
//	{
//		x = a.x;
//		y = a.y;
//		z = a.z;
//	}*/
//	int getX()
//	{
//		return x;
//	}
//	int getY()
//	{
//		return y;
//	}
//	int getZ()
//	{
//		return z;
//	}
//	~CPoint() = default;
//};
//
//class CCube
//{
//	CPoint *point;
//public:
//	CCube()//:point(nullptr){}
//	{
//		point = NULL;
//	}
//	CCube& operator=(CCube& a)
//	{
//		//point = a.point;
//		point = new CPoint[2];
//		point[0] = a.point[0];
//		point[1] = a.point[1];
//		return *this;
//	}
//	CCube(CPoint &point_a, CPoint &point_b)
//	{
//		point = new CPoint[2];
//		CPoint t1(point_a.getX(), point_a.getY(), point_a.getZ());
//		point[0] = t1;
//		CPoint t2(point_b.getX(), point_b.getY(), point_b.getZ());
//		point[1] = t2;
//	}
//	int collide(CCube &r)
//	{
//		//cout <<"aaa" <<r.point[1].getX() << endl;
//		if (point[0].getX()>r.point[1].getX())
//			return 0;
//		if (point[1].getX()<r.point[0].getX())
//			return 0;
//		if (point[0].getY()>r.point[1].getY())
//			return 0;
//		if (point[1].getY()<r.point[0].getY())
//			return 0;
//		if (point[0].getZ()<r.point[1].getZ())
//			return 0;
//		if (point[1].getZ()>r.point[0].getZ())
//			return 0;
//		return 1;
//	}
//	~CCube()
//	{
//		delete[]point;
//	}
//};
//
//int main()
//{
//	int k;
//	cin >> k;
//	while (k--)
//	{
//		int t = 2;
//		CCube*pcube = new CCube[t];
//		int x, y, z;
//		for (int i = 0; i < t; i++)
//		{
//			cin >> x >> y >> z;
//			CPoint p1(x, y, z);
//			cin >> x >> y >> z;
//			CPoint p2(x, y, z);
//			CCube a(p1, p2);
//			pcube[i] = a;
//		}
//
//		int ret = pcube[0].collide(pcube[1]);
//		if (ret == 1)
//			cout << "collide" << endl;
//		else
//			cout << "have distance" << endl;
//		delete[] pcube;
//	}
//	
//	return 0;
//}