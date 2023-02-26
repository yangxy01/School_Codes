//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//using namespace std;

//struct Point
//{
//	int x;
//	int y;
//};
//struct Line
//{
//	Point a;
//	Point b;
//};
//
//void direction(const Line &L, const Point &P)
//{
//	if ((L.b.x - L.a.x)*(P.x - L.a.x) - (L.b.y - L.a.y)*(P.y - L.a.y) > 0)
//		cout << "clockwise" << endl;
//	else if ((L.b.x - L.a.x)*(P.x - L.a.x) - (L.b.y - L.a.y)*(P.y - L.a.y)<0)
//		cout << "anti clockwise" << endl;
//	else
//		cout << "intersect" << endl;
//}
//
//int main()
//{
//	int t;
//	cin >>t;
//	while (t--)
//	{
//		int x1, x2, y1, y2;
//		int x, y;
//		cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
//		Line L = { { x1, y1 }, { x2, y2 } };
//		Point P = { x, y };
//		direction(L, P);
//	}
//	return 0;
//}