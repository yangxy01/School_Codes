//// 丑陋数：1或正整数，素数因子只包含2，3，5。
//// 输入正整数n(<2000)，输出第n个丑陋数。
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <utility>
//using namespace std;
//
//typedef pair<unsigned long, int> node_type;
//
//int main()
//{
//    vector<unsigned long> result(2000);
//    priority_queue< node_type, vector<node_type>, greater<node_type> > Q;  //大顶堆，升序
//
//    Q.push(make_pair(1, 2));
//    for (int i = 0; i < 2000; i++)
//    {
//        node_type node = Q.top();    //取队头
//        Q.pop();
//
//        switch (node.second)
//        {
//        case 2:
//            Q.push(make_pair(node.first * 2, 2));   //*2
//        case 3:
//            Q.push(make_pair(node.first * 3, 3));   //*3
//        case 5:
//            Q.push(make_pair(node.first * 5, 5));   //*5
//        }
//        result[i] = get<0>(node);   //get<0>, get<1>    //first入结果数组
//    }
//
//    int n;
//    cin >> n;
//    while (n > 0)
//    {
//        cout << result[n - 1] << endl;
//        cin >> n;
//    }
//
//    system("pause");
//    return 0;
//}
//
///*
//1,2    1*2(2),2    1*2*2(4),2    1*3*3(9),3
//       1*3(2),3    1*2*3(6),3    1*3*5(15),5
//       1*5(5),5    1*2*5(10),5
//*/