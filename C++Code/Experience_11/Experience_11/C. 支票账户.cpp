//#include<iostream>
//#include<string>
//using namespace std;
//class BaseAccount
//{
//protected:
//	string name;
//	string account;
//	int banlance;
//public:
//	BaseAccount(string n="no", string a = "no",int b=0):
//		name(n),account(a),banlance(b){}
//	virtual void deposit(int money) { banlance += money; }
//	virtual void withdraw(int money)
//	{
//		if (money > banlance)
//			cout << "insufficient" << endl;
//		else
//			banlance -= money;
//	}
//	virtual void Display()
//	{
//		cout << name << " " << account << " " << "Balance:" << banlance << endl;
//	}
//};
//
//class BasePlus:public BaseAccount
//{
//	int limit;
//	int limit_sum;
//public:
//	BasePlus(string n = "no", string a = "no", int b = 0) :
//		BaseAccount(n, a, b) 
//	{
//		limit = 5000;
//		limit_sum = 0;
//	}
//	virtual void deposit(int money)
//	{
//		banlance += money;
//	}
//	virtual void withdraw(int money)
//	{
//		if (money > banlance)
//		{
//			if (money > banlance + limit - limit_sum)
//				cout << "insufficient" << endl;
//			else
//			{
//				limit_sum = limit_sum+money - banlance;
//				banlance = 0;				
//			}
//		}
//		else
//			banlance -= money;
//	}
//	virtual void Display()
//	{
//		cout << name << " " << account << " " << "Balance:" << banlance
//			<<" limit:"<<limit-limit_sum<< endl;
//	}
//};
//
//int main()
//{
//	int t;
//	string name;
//	string account;
//	int banlance;
//	cin >> t;
//	while (t--)
//	{
//		BaseAccount* p = NULL;
//		cin >> name >> account >> banlance;
//		if (account.substr(0, 2) == "BA")
//		{
//			p = new BaseAccount(name, account, banlance);
//		}
//		else
//		{
//			p = new BasePlus(name, account, banlance);
//		}
//		int money;
//		cin >> money;
//		p->deposit(money);
//		cin >> money;
//		p->withdraw(money);
//		cin >> money;
//		p->deposit(money);
//		cin >> money;
//		p->withdraw(money);
//		p->Display();
//		delete p;
//	}
//	return 0;
//}