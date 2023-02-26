//#define _CRT_SECURE_NO_WARNINGS 1
//#include <queue>
//#include <iostream>
//#include <string>
//#include<functional>
//#include <utility>
//using namespace std;
//
//class rectangle
//{
//	int length;
//	int width;
//	string name;
//public:
//	rectangle() {length = 0; width= 0;}
//	rectangle(string n, int l, int w) { name = n; length = l; width = w; }
//	bool operator<(const rectangle& obj)const
//	{
//		return (length * width) < (obj.length * obj.width);
//	}
//	int getarea()
//	{
//		return length * width;
//	}
//	string getname()
//	{
//		return name;
//	}
//};
//
//int main()
//{
//	int length,width,n;
//	string name;
//	priority_queue<rectangle>myq;
//	cin >> n;
//	int m = n;
//	while (n--)
//	{
//		cin >> name >> length >> width;
//		rectangle obj(name, length, width);
//		myq.push(obj);
//	}
//	while (m--)
//	{
//		rectangle tmp = myq.top();
//		cout << tmp.getname() << "--" << tmp.getarea() << endl;
//		myq.pop();
//	}
//
//	return 0;
//}