///*
//每天上午，比尔会收到若干张帐单（也可能一张也没收到），每一张
//都有一定的面额。下午，他会从目前还没有支付的帐单中选出面额最大
//和最小的两张，并把它们付清。还没有支付的帐单会被保留到下一天。
//现在比尔已经知道他每天收到帐单的数量和面额，请你帮他给出支付的顺序。
//比尔保证最后一天全部付清。
//*/
//#include <set>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    multiset<int> billset;
//    int t, n, e;
//
//    cin >> t;    //t天
//
//    while (t--)
//    {
//        cin >> n;     //每天账单数
//
//        while (n--)
//        {
//            cin >> e;
//            billset.insert(e);     //升序插入账单
//        }
//        if (t > 0)
//        {
//            cout << *billset.begin() << " " << *(--billset.end()) << endl;   //最小金额，最大金额
//            billset.erase(billset.begin());
//            billset.erase(--billset.end());
//        }
//        else
//        {
//            for (auto x : billset)       //最后一天，付清账单
//                cout << x << " ";
//            cout << endl;
//
//        }
//    }
//    system("pause");
//    return 0;
//}
///*
//4
//3 3 6 5
//2 4 2
//3 7 1 7
//1 10
//*/
//
