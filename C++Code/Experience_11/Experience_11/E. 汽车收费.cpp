//#include<iostream>
//#include<iomanip>
//#include<string>
//using namespace std;
//class Vehicle
//{
//protected:
//	string no;//编号
//public:
//	Vehicle(string n):no(n){}
//	virtual void display() = 0;//应收费用
//};
//class Car :public Vehicle
//{
//	int member, weight;
//public:
//	Car(string n,int m,int w):Vehicle(n),member(m),weight(w){}
//	void display() { cout << no << " " << 8 * member + 2 * weight << endl; }
//};
//class Truck :public Vehicle
//{
//	int weight;
//public:
//	Truck(string n, int w) :Vehicle(n), weight(w) {}
//	void display() { cout << no << " " << 5 * weight << endl; }
//};
//class Bus :public Vehicle
//{
//	int member;
//public:
//	Bus(string n, int m) :Vehicle(n), member(m) {}
//	void display() { cout << no << " " << 3 * member << endl; }
//};
//
//int main()
//{
//	int t,type;
//	string no;
//	int member, weight;
//	cin >> t;
//	while (t--)
//	{
//		Vehicle* pv = NULL;
//		cin >> type>>no;
//		if (type == 1)
//		{
//			cin >> member >> weight;
//			pv = new Car(no,member, weight);
//		}
//		else if (type == 2)
//		{
//			cin >>  weight;
//			pv = new Truck(no, weight);
//		}
//		else if (type == 3)
//		{
//			cin >> member;
//			pv = new Bus(no, member);
//		}
//		pv->display();
//		delete pv;
//	}
//	return 0;
//}

