//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//using namespace std;
//class Str
//{
//	char*p;
//public:
//	Str(){ p = NULL;}
//	Str(char*s)
//	{
//		p = new char[strlen(s)];
//		strcpy(p, s);
//	}
//	void dislpay()
//	{
//		cout << p << endl;
//	}
//	friend bool operator>(Str&s1, Str&s2);
//	friend bool operator<(Str&s1, Str&s2);
//	friend bool operator==(Str&s1, Str&s2);
//	~Str()
//	{
//		if (p)
//		{
//			delete[]p;
//		}
//	}
//};
//
//bool operator>(Str&s1, Str&s2)
//{
//	if (strcmp(s1.p, s2.p) > 0)
//		return true;
//	return false;
//}
//bool operator<(Str&s1, Str&s2)
//{
//	if (strcmp(s1.p, s2.p) < 0)
//		return true;
//	return false;
//}
//bool operator==(Str&s1, Str&s2)
//{
//	if (strcmp(s1.p, s2.p) == 0)
//		return true;
//	return false;
//}
//
//int main()
//{
//	char str[100];
//	cin.getline(str, 100, '\n');
//	Str s1(str);
//	cin.getline(str, 100, '\n');
//	Str s2(str);
//	cin.getline(str, 100, '\n');
//	Str s3(str);
//	if (s1 > s2)s1.dislpay();
//	else s2.dislpay();
//	if (s1 < s3)s1.dislpay();
//	else s3.dislpay();
//	if (s2 == s3)s2.dislpay();
//	else s3.dislpay();
//
//	return 0;
//}