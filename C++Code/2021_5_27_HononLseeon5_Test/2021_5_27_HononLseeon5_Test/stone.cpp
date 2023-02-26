//#include <iostream>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//#define f(i,l,r) for(i=(l);i<=(r);i++)
//#define ff(i,r,l) for(i=(r);i>=(l);i--)
//
//int main()
//{
//    priority_queue<int, vector<int>, greater<int>>  q;    //降序排序，小顶堆，权值小的优先出队列
//    int n, e, num1, num2;
//
//    cin >> n;
//    while (n--)
//    {
//        cin >> e;
//        q.push(e);
//    }
//
//    int sum = 0;
//    while (q.size() > 1)
//    {
//        num1 = q.top();     //取出两堆石子
//        q.pop();
//        num2 = q.top();
//        q.pop();
//        q.push(num1 + num2);  //合并入优先队列
//        sum += num1 + num2;   //计算代价
//    }
//    cout << sum << endl;
//
//    system("pause");
//    return 0;
//}
//
///*
//7
//13 7 8 16 21 4 18
//*/
////233
