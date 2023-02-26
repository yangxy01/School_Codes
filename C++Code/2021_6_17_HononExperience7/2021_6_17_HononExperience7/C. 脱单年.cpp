//#include<iostream>
//#include<set>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		set<int> myset;
//		int year;
//		int save,now;
//		cin >> year;
//		save = year;
//		if (save >= 1000)//1211
//		{
//			now = year;
//			while (1)
//			{
//				int flag = 1;
//				while (year)
//				{
//					auto it = myset.insert(year % 10);
//					if (it.second == false)
//					{
//						flag = 0;
//						break;
//					}
//					year /= 10;
//				}
//				myset.clear();
//				if (flag == 1)
//				{
//					cout << "From " << save << ", the offsingle year is " << now << endl;
//					break;
//				}
//				else
//				{
//					now++;
//					year = now;
//					continue;
//				}
//			}
//		}
//		else if (save < 1000 && save > 987)
//		{
//			year = 1000;
//			now = year;
//			while (1)
//			{
//				int flag = 1;
//				while (year)
//				{
//					auto it = myset.insert(year % 10);
//					if (it.second == false)
//					{
//						flag = 0;
//						break;
//					}
//					year /= 10;
//				}
//				myset.clear();
//				if (flag == 1)
//				{
//					cout << "From 0" << save << ", the offsingle year is " << now << endl;
//					break;
//				}
//				else
//				{
//					now++;
//					year = now;
//					continue;
//				}
//			}
//		}
//		else if (save <= 987 && save >= 100)//0120
//		{
//			now = year;
//			while (1)
//			{
//				int flag = 1;
//				while (year)
//				{
//					myset.insert(0);
//					auto it = myset.insert(year % 10);
//					if (it.second == false)
//					{
//						flag = 0;
//						break;
//					}
//					year /= 10;
//				}
//				myset.clear();
//				if (flag == 1)
//				{
//					cout << "From 0" << save << ", the offsingle year is 0" << now << endl;
//					break;
//				}
//				else
//				{
//					now++;
//					year = now;
//					continue;
//				}
//			}
//		}
//		else if (save < 100 && save >= 10)//0056
//		{
//			year = 100;
//			now = year;
//			while (1)
//			{
//				int flag = 1;
//				while (year)
//				{
//					myset.insert(0);
//					auto it = myset.insert(year % 10);
//					if (it.second == false)
//					{
//						flag = 0;
//						break;
//					}
//					year /= 10;
//				}
//				myset.clear();
//				if (flag == 1)
//				{
//					cout << "From 00" << save << ", the offsingle year is 0" << now << endl;
//					break;
//				}
//				else
//				{
//					now++;
//					year = now;
//					continue;
//				}
//			}
//		}
//		else if (save < 10)//0001
//		{
//		year = 100;
//		now = year;
//		while (1)
//		{
//			int flag = 1;
//			while (year)
//			{
//				myset.insert(0);
//				auto it = myset.insert(year % 10);
//				if (it.second == false)
//				{
//					flag = 0;
//					break;
//				}
//				year /= 10;
//			}
//			myset.clear();
//			if (flag == 1)
//			{
//				cout << "From 000" << save << ", the offsingle year is 0" << now << endl;
//				break;
//			}
//			else
//			{
//				now++;
//				year = now;
//				continue;
//			}
//		}
//		}
//	}
//
//	return 0;
//}
