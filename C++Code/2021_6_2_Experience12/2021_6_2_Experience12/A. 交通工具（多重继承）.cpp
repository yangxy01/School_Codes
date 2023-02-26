//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class CVehicle
//{
//protected:
//	int max_speed;
//	int speed;
//	int weight;
//public:
//	CVehicle(int m=0, int s=0, int w=0) :max_speed(m), speed(s), weight(w){}
//	void display()
//	{
//		cout << "Vehicle:" << endl;
//		cout << "max_speed:" << max_speed << endl;
//		cout << "speed:" << speed << endl;
//		cout << "weight:" << weight << endl<<endl;
//	}
//};
//
//class CBicycle :virtual public CVehicle
//{
//protected:
//	int height;
//public:
//	CBicycle(int m, int s, int w,int h) :CVehicle(m, s, w), height(h){}
//	void display()
//	{
//		cout << "Bicycle:" << endl;
//		cout << "max_speed:" << max_speed << endl;
//		cout << "speed:" << speed << endl;
//		cout << "weight:" << weight << endl;
//		cout << "height:" << height << endl << endl;
//	}
//};
//
//class CMotocar :virtual public CVehicle
//{
//protected:
//	int seat_num;
//public:
//	CMotocar(int m, int s, int w, int sn) :CVehicle(m, s, w), seat_num(sn){}
//	void display()
//	{
//		cout << "Motocar:" << endl;
//		cout << "max_speed:" << max_speed << endl;
//		cout << "speed:" << speed << endl;
//		cout << "weight:" << weight << endl;
//		cout << "seat_num:" << seat_num << endl << endl;
//	}
//};
//
//class CMotocycle :public CBicycle, public CMotocar
//{
//public:
//	CMotocycle(int m, int s, int w, int h, int sn) :CVehicle(m, s, w), CBicycle(m, s, w, h), CMotocar(m, s, w, sn){}
//	void display()
//	{
//		cout << "Motocycle:" << endl;
//		cout << "max_speed:" << max_speed << endl;
//		cout << "speed:" << speed << endl;
//		cout << "weight:" << weight << endl;
//		cout << "height:" << height << endl ;
//		cout << "seat_num:" << seat_num << endl ;
//	}
//};
//
//int main()
//{
//	int max_speed;
//	int speed;
//	int weight;
//	int height;
//	int seat_num;
//	cin >> max_speed >> speed >> weight;
//	CVehicle CV(max_speed, speed, weight);
//	CV.display();
//	cin >> height;
//	CBicycle CB(max_speed, speed, weight, height);
//	CB.display();
//	cin >> seat_num;
//	CMotocar CM(max_speed, speed, weight, seat_num);
//	CM.display();
//
//	CMotocycle CMC(max_speed, speed, weight, height, seat_num);
//	CMC.display();
//
//	return 0;
//}
//
