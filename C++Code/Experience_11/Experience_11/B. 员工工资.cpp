//#include<iostream>
//#include<string>
//using namespace std;
//
//class Employee
//{
//protected:
//	string name;
//	string position;
//	int level;
//	int year;
//	int sal;
//public:
//	Employee(string n = "no", string p = "no", int l = 0, int y = 0) :
//		name(n), position(p), level(l), year(y) {sal = 0;}
//	virtual int salary()
//	{
//		sal = 1000 + 500 * level + 50 * year;
//		return sal;
//	}
//
//};
//
//class Teamleader :public Employee
//{
//public:
//	Teamleader(string n = "no", string p = "no", int l = 0, int y = 0):
//		Employee(n,p,l,y){}
//	int salary()
//	{
//		sal = 3000 + 800 * level + 100 * year;
//		return sal;
//	}
//
//};
//
//class Manager :public Employee
//{
//public:
//	Manager(string n = "no", string p = "no", int l = 0, int y = 0) :
//		Employee(n, p, l, y) {}
//	int salary()
//	{
//		sal = 5000 + 1000 * (level +  year);
//		return sal;
//	}
//
//};
//
//int main()
//{
//	int t;
//	string name;
//	string position;
//	int level;
//	int year;
//	cin >> t;
//	while (t--)
//	{
//		Employee* p = NULL;
//		cin >> name >> position >> level >> year;
//		if (position == "Employee")
//		{
//			if(level<=0|| year <= 0){ cout << "error grade or year." << endl; }
//			else
//			{
//				p = new Employee(name, position, level, year);
//				int ret=p->salary();
//				cout << name << ":" << position << ",Salary:" << ret << endl;
//			}
//		}
//		else if (position == "Teamleader")
//		{
//			if (level <= 0 || year <= 0) { cout << "error grade or year." << endl; }
//			else
//			{
//				p = new Teamleader(name, position, level, year);
//				int ret = p->salary();
//				cout << name << ":" << position << ",Salary:" << ret << endl;
//			}
//		}
//		else if (position == "Manager")
//		{
//			if (level <=0 || year <=0 ) { cout << "error grade or year." << endl; }
//			else
//			{
//				p = new Manager(name, position, level, year);
//				int ret = p->salary();
//				cout << name << ":" << position << ",Salary:" << ret << endl;
//			}
//		}
//		
//		else
//		{
//			cout << "error position." << endl;
//		}
//		delete p;
//	}
//	return 0;
//}
