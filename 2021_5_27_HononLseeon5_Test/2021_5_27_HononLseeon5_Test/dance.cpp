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
//	f(i, 1, m)     //��ʿ���    
//	{
//		mq.push(i);
//	}
//	f(i, 1, n)     //Ůʿ���
//	{
//		fq.push(i);
//	}
//
//	cin >> k;
//	f(i, 1, k)     //��������ѭ��
//	{
//		cout << mq.front() << " " << fq.front() << endl;    //��ǰ����
//		mq.push(mq.front());        //��ͷ���β
//		fq.push(fq.front());        //��ͷ���β
//		mq.pop();                   //��ͷ����
//		fq.pop();                   //��ͷ����
//	}
//
//	system("pause");
//	return 0;
//
//
//}
