//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//class CPeople
//{
//protected:
//	char id[20];
//	char name[10];
//public:
//	CPeople(){}
//	CPeople(char*pid,char*pna)
//	{
//		strcpy(id, pid);
//		strcpy(name, pna);
//	}
//
//};
//class CInternetUser :virtual public CPeople
//{
//protected:
//	char password[20];
//public:
//	CInternetUser() :CPeople(){}
//	CInternetUser(char*i_xm, char*i_id, char*i_mm) :CPeople(i_xm, i_id)
//	{
//		strcpy(password, i_mm);
//	}
//	void registerIn(char* i, char* n, char* p)
//	{
//		strcpy(id, i);
//		strcpy(name, n);
//		strcpy(password, p);
//	}
//	bool login(char* i_id, char* ib_mm) 
//	{ 
//		return strcmp(i_id, id) == 0 && strcmp(ib_mm, name) == 0; 
//	}
//};
//
//class CBankCustomer :virtual public CPeople
//{
//protected:
//	double balance;
//public:
//	CBankCustomer() :CPeople(){}
//	CBankCustomer(char*b_xm, char*b_id) :CPeople(b_xm, b_id){}
//	void openAccount(char* n, char* i)
//	{
//		strcpy(id, i);
//		strcpy(name, n);
//	}
//	void deposit(double money) { balance += money; }
//	bool withdraw(double money)
//	{ 
//		if (balance >= money)
//		{
//			balance -= money;
//			return 1;
//		}
//		return 0; 	
//	}
//};
//
//class CInternetBankCustomer :public CInternetUser, public CBankCustomer
//{
//protected:
//	double balance;
//	double yesterday_balance;
//	double today_earning;
//	double today_interest;
//	double yesterday_interest;
//public:
//	CInternetBankCustomer() :CBankCustomer(), CInternetUser()
//	{
//		balance = 0;
//		yesterday_balance = 0;
//		today_earning = 0;
//		today_interest = 0;
//		yesterday_interest = 0;
//	}
//	bool deposit(double p)
//	{
//		if (p > CBankCustomer::balance) 
//			return 0;
//		else
//		{
//			balance += p;
//			CBankCustomer::balance -= p;
//		}
//		return 1;
//	}
//	bool withdraw(double p)
//	{
//		if (p > balance) 
//			return 0;
//		else
//		{
//			balance -= p;
//			CBankCustomer::balance += p;
//		}
//		return 1;
//	}
//	void print()
//	{
//		cout << "Name: " << CBankCustomer::name << " ID: " <<
//			CBankCustomer::id << "\nBank balance: " << CBankCustomer::balance;
//		cout << "\nInternet bank balance: " << yesterday_balance << endl;
//};
//
//int main()
//{
//	int t, no_of_days, i;
//	char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
//	double money, interest;
//	char op_code;
//
//	//输入测试案例数t
//	cin >> t;
//	while (t--)
//	{
//		//输入互联网用户注册时的用户名,id,登陆密码
//		cin >> i_xm >> i_id >> i_mm;
//		CInternetUser CInUser(i_xm, i_id, i_mm);
//
//		//输入银行开户用户名,id
//		cin >> b_xm >> b_id;
//		CBankCustomer CBanCus(b_xm, b_id);
//
//		//输入互联网用户登陆时的id,登陆密码
//		cin >> ib_id >> ib_mm;
//
//		CInternetBankCustomer ib_user;
//
//		ib_user.Inregister(i_xm, i_id, i_mm);
//		ib_user.openAccount(b_xm, b_id);
//
//		if (ib_user.login(ib_id, ib_mm) == 0)  //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
//		{
//			cout << "Password or ID incorrect" << endl;
//			continue;
//		}
//
//		//输入天数
//		cin >> no_of_days;
//		for (i = 0; i < no_of_days; i++)
//		{
//			//输入操作代码, 金额, 当日万元收益
//			cin >> op_code >> money >> interest;
//			switch (op_code)
//			{
//			case 'S':  //从银行向互联网金融帐户存入
//			case 's':
//				if (ib_user.deposit(money) == 0)
//				{
//					cout << "Bank balance not enough" << endl;
//					continue;
//				}
//				break;
//			case 'T':  //从互联网金融转入银行帐户
//			case 't':
//				if (ib_user.withdraw(money) == 0)
//				{
//					cout << "Internet bank balance not enough" << endl;
//					continue;
//				}
//				break;
//			case 'D':  //直接向银行帐户存款
//			case 'd':
//				ib_user.CBankCustomer::deposit(money);
//				break;
//			case 'W':  //直接从银行帐户取款
//			case 'w':
//				if (ib_user.CBankCustomer::withdraw(money) == 0)
//				{
//					cout << "Bank balance not enough" << endl;
//					continue;
//				}
//				break;
//			default:
//				cout << "Illegal input" << endl;
//				continue;
//			}
//			ib_user.setInterest(interest);
//			ib_user.calculateProfit();
//			//输出用户名,id
//			//输出银行余额
//			//输出互联网金融账户余额
//			ib_user.print();
//		}
//	}
//}
//
//
//
