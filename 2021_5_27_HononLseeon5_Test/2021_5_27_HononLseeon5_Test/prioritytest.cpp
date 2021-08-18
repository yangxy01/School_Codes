//#define _CRT_SECURE_NO_WARNINGS 1
//#include <queue>
//#include <algorithm>
//#include <iostream>
//#include <functional>
//using namespace std;
//
//int main()
//{
//	//priority_queue<string> mypq;    //默认less, 从大到小出队列，大顶堆，与下句定义等价
//	//priority_queue<string,vector<string>,less<string>> mypq;    
//	priority_queue<string, vector<string>, greater<string>> mypq;  //如果改为greater,小顶堆，从小到大出队列
//	mypq.push("orange");
//	mypq.emplace("strawberry");
//	mypq.emplace("apple");
//	mypq.emplace("pear");
//
//	while (!mypq.empty())          //字典降序输出
//	{
//		cout << mypq.top() << endl;
//		mypq.pop();
//	}
//	system("pause");
//	return 0;
//}