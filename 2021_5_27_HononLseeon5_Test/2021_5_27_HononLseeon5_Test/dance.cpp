//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <queue>
//using namespace std;
//
//#define f(i,l,r) for(i=(l);i<=(r);i++)
//#define ff(i,r,l) for(i=(r);i>=(l);i--)
//
//int main()
//{
//	queue<int> mq, fq;
//	int m, n, i, k;
//
//	cin >> m >> n;
//
//	f(i, 1, m)     //男士入队    
//	{
//		mq.push(i);
//	}
//	f(i, 1, n)     //女士入队
//	{
//		fq.push(i);
//	}
//
//	cin >> k;
//	f(i, 1, k)     //对舞曲数循环
//	{
//		cout << mq.front() << " " << fq.front() << endl;    //当前舞者
//		mq.push(mq.front());        //队头入队尾
//		fq.push(fq.front());        //队头入队尾
//		mq.pop();                   //队头出队
//		fq.pop();                   //队头出队
//	}
//
//	system("pause");
//	return 0;
//
//
//}
