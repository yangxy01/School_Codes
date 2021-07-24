//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//class Member 
//{   
//protected:
//	int no, credit;
//	string name;
//public:
//	Member(int nov = 0, string n = "no", int creditv = 0)
//		:no(nov), credit(creditv), name(n){}
//	virtual void add(int money){ credit += money; }
//	virtual int Exchange(int num)
//	{
//		int ret;
//		if (num <= credit)
//		{
//			ret = num / 100;
//			credit -= (ret * 100);
//		}
//		else
//		{
//			ret = credit / 100;
//			credit %= 100;
//		}	
//		return ret;
//	}
//	virtual void Display()
//	{
//		cout << "普通会员" << no << "--" << name << "--" << credit << endl;
//	}
//};
//
//class VIP :public Member
//{  
//protected:
//	int add_rate, change_rate;
//public:
//	VIP(int nov = 0, string n = "no", int creditv = 0,int addr = 0, int chr = 0)
//		:Member(nov, n,creditv), add_rate(addr), change_rate(chr){}
//	virtual void add(int money){ credit += (money*add_rate); }
//	virtual int Exchange(int num)
//	{
//		int ret;
//		if (num <= credit)
//		{
//			ret = num / change_rate;
//			credit -= (ret * change_rate);
//		}
//		else
//		{
//			ret = credit / change_rate;
//			credit %= change_rate;
//		}
//		return ret;
//	}
//	virtual void Display()
//	{
//		cout << "贵宾会员" << no << "--" << name << "--" << credit << endl;
//	}
//
//};
//
//int main()
//{
//	Member * pm; //创建一个基类对象指针
//	int no, credit,consume,num,ret;
//	string name;
//	int add_rate, change_rate;
//	cin >> no >> name >> credit;
//	Member M(no, name, credit);
//	pm = &M;
//	cin >> consume >> num;
//	pm->add(consume);
//	ret=pm->Exchange(num);
//	pm->Display();
//
//	cin >> no >> name >> credit >> add_rate >> change_rate;
//	VIP V(no, name, credit, add_rate, change_rate);
//	pm = &V;
//	cin >> consume >> num;
//	pm->add(consume);
//	ret = pm->Exchange(num);
//	pm->Display();
//
//	return 0;
//
//}