//#include <set>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct stringcmp//放的过程中要满足的要求
//{
//    //set排序规则
//    bool operator()(const string& lhs, const string& rhs)
//    {
//        int count1, count2;
//        if (lhs.size() != rhs.size())    //长度升序
//            return lhs.size() < rhs.size();
//        else     //长度相等
//        {
//            count1 = count(lhs.begin(), lhs.end(), '1');    //统计1的个数
//            count2 = count(rhs.begin(), rhs.end(), '1');
//            if (count1 != count2)
//                return count1 < count2;      //1的个数升序
//            else
//                return lhs < rhs;            //1个数等，码值升序
//        }
//    }
//};
//
//
//int main()
//{
//    set<string, stringcmp>  s;
//    int n;
//    string str;
//
//    cin >> n;
//    while (n--)
//    {
//        cin >> str;
//        s.insert(str);
//    }
//
//    for (auto x : s)
//        cout << x << endl;
//
//    system("pause");
//    return 0;
//}
//
///*
//6
//10011111
//00001101
//1010101
//1
//0
//1100
//*/
//
///*
//0
//1
//1100
//1010101
//00001101
//10011111
//*/
//
