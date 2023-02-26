#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class B{
	int b_value;
public:
	B(int b = 1){b_value = b;}
	~B(){ cout << "destory" << endl; }
};
class A{
	int a_value;
	B bobj;
public:
	A(){}
	~A(){}
};

int main()
{
	A aobj;
	return 0;
}


//int main()
//{
//	string str1 = "abc.txt.zip";
//	int pos = str1.rfind(".");
//	cout << str1.substr(pos) << endl;
//	return 0;
//}

//inline int CorrespondingDay(int year, int month)
//{
//	static int a1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if ((month == 2) && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
//	{
//		return a1[month - 1] + 1;
//	}
//	return a1[month - 1];
//}
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	int operator-(const Date& d)
//	{
//		int count = 1;
//		Date max = *this;
//		Date min = d;
//		if (max < min)
//		{
//			max = d;
//			min = *this;
//		}
//		while (!(max == min))
//		{
//			min++;
//			count++;
//		}
//		return count;
//	}
//
//	void operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void operator++(int)
//	{
//		_day++;
//		if (_day > CorrespondingDay(_year, _month))
//		{
//			_day -= CorrespondingDay(_year, _month);
//			_month++;
//			if (_month > 12)
//			{
//				_year++;
//				_month = 1;
//			}
//		}
//	}
//
//	bool operator==(const Date& d)
//	{
//		if (_year == d._year&&_month == d._month&&_day == d._day)
//			return true;
//		return false;
//	}
//
//	bool operator<(const Date& d)
//	{
//		if (_year < d._year)
//			return true;
//		else if (_year == d._year)
//		{
//			if (_month < d._month)
//				return true;
//			else if (_month == d._month)
//			{
//				if (_day < d._day)
//					return true;
//			}
//		}
//		return false;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	char str1[9], str2[9];
//	int y1, m1, d1, y2, m2, d2;
//	while (cin >> str1 >> str2)
//	{
//		sscanf(str1, "%4d%2d%2d", &y1, &m1, &d1);
//		sscanf(str2, "%4d%2d%2d", &y2, &m2, &d2);
//		Date date1(y1, m1,d1);
//		Date date2(y2, m2, d2);
//		int ret = date1 - date2;
//		cout << ret << endl;
//	}
//	return 0;
//}