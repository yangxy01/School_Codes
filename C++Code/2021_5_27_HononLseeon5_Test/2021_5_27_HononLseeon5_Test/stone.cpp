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
//    priority_queue<int, vector<int>, greater<int>>  q;    //��������С���ѣ�ȨֵС�����ȳ�����
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
//        num1 = q.top();     //ȡ������ʯ��
//        q.pop();
//        num2 = q.top();
//        q.pop();
//        q.push(num1 + num2);  //�ϲ������ȶ���
//        sum += num1 + num2;   //�������
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
