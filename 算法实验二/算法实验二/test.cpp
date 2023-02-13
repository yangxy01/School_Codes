//// unordered_set::find
//#include <iostream>
//#include <string>
//#include <unordered_set>
//using namespace std;
//
//struct Point
//{
//    double x;
//    double y;
//};
//
//class myhash {
//public:
//    size_t operator()(const Point& p)const 
//    {
//        return size_t((p.x+1) * 3 + (p.y+1) * 7);
//    }
//};
//
//
//class equalPoint {
//public:
//    bool operator()(const Point& p1, const Point& p2)const 
//    {
//        return p1.x == p2.x && p1.y == p2.y;
//    }
//};
//
//
//int main()
//{
//    unordered_set<Point, myhash, equalPoint> myset;
//    Point p = { 0,1 };
//    myset.insert(p);
//    if (myset.find(p) == myset.end())
//    {
//        cout << 1 << endl;
//    }
//    else
//    {
//        cout << 2 << endl;
//    }
//
//    return 0;
//}