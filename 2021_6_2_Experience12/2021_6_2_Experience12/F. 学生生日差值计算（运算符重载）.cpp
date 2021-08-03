//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//class Student
//{
//	string name;
//	int year;
//	int month;
//	int day;
//	int allday;
//public:
//	Student(string n="no", int y=0, int m=0, int d=0) :name(n), year(y), month(m), day(d)
//	{
//		allday = getallday();
//	}
//	string getname()
//	{
//		return name;
//	}
//	int getallday()
//	{
//		int ret=0;
//		int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		int	b[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (isLeapYear(year))
//		{
//			for (int i = 0; i < month-1; i++)
//				ret += a[i];
//			ret += day;
//		}
//		else
//		{
//			for (int i = 0; i < month - 1; i++)
//				ret += a[i];
//			ret += day;
//		}
//		return ret;
//	}
//	int isLeapYear(int y)
//	{
//		if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
//			return 1;
//		return 0;
//	}
//	int operator-(const Student&s)
//	{
//		int maxday = 0;
//		if (s.year == year)
//		{
//			if (s.allday > allday)return s.allday - allday;
//			return allday - s.allday;
//		}
//		else if (s.year > year)
//		{
//			int gap = s.year - year;
//			if (isLeapYear(year))
//			{
//				maxday = 366 - allday + s.allday;
//				for (int i = 1; i < gap; i++)
//				{
//					if (isLeapYear(year + 1))
//					{
//						maxday += 366;
//					}
//					else
//					{
//						maxday += 365;
//					}
//				}
//			}
//			else
//			{
//				maxday = 365 - allday + s.allday;
//				for (int i = 1; i < gap; i++)
//				{
//					if (isLeapYear(year + 1))
//					{
//						maxday += 366;
//					}
//					else
//					{
//						maxday += 365;
//					}
//				}
//			}
//			
//		}
//
//		else
//		{
//			int gap = year - s.year;
//			if (isLeapYear(s.year))
//			{
//				maxday = 366 - s.allday + allday;
//				for (int i = 1; i < gap; i++)
//				{
//					if (isLeapYear(s.year + 1))
//					{
//						maxday += 366;
//					}
//					else
//					{
//						maxday += 365;
//					}
//				}
//			}
//			else
//			{
//				maxday = 365 - s.allday + allday;
//				for (int i = 1; i < gap; i++)
//				{
//					if (isLeapYear(s.year + 1))
//					{
//						maxday += 366;
//					}
//					else
//					{
//						maxday += 365;
//					}
//				}
//			}
//		}
//		return maxday;
//	}
//};
//
//int main()
//{
//	int t;
//	string name;
//	int year;
//	int month;
//	int day,maxday=0;
//	string maxname,minname;
//	cin >> t;
//	Student*p = new Student[t];
//	for (int i = 0; i < t; i++)
//	{
//		cin >> name >> year >> month >> day;
//		p[i] = Student(name, year, month, day);
//	}
//	for (int i = 0; i<t - 1; i++)
//	{
//		for (int j = i + 1; j<t; j++)
//		{
//			if (maxday<p[j] - p[i])
//			{
//				maxday = p[j] - p[i];
//				minname = p[i].getname();
//				maxname = p[j].getname();
//			}
//		}
//	}
//	cout << minname << "和" << maxname << "年龄相差最大，为" << maxday << "天。" << endl;
//
//}