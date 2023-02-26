//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	//int score[] = {99,100,78,80,85,60,50};
//	int score[] = { 62, 41, 30, 28, 16, 22, 13, 19, 17, 15 };     //课件22页数据
//	vector<int> v(score, score + 10);
//
//	make_heap(v.begin(), v.end());        //重排v,使其构成大顶堆。因已是堆，输出原序列
//	for_each(begin(v), end(v), [](int x){cout << x << " "; });
//	cout << endl;
//
//	vector<int> vbak(v);
//
//
//	//循环排序
//	cout << "---------heap sort---------" << endl;
//	int count = 0;     //记录排序次数
//	for (auto it = begin(v), itend = end(v); itend != it; itend--)
//	{
//		cout << ++count << ":";
//		pop_heap(it, itend);   //向下调整算法
//		for_each(begin(v), end(v), [](int x){cout << x << " "; });
//		cout << endl;
//	}
//
//	cout << "---------heap sort---------" << endl;
//	sort_heap(begin(vbak), end(vbak));     //堆排序结果
//	for_each(begin(vbak), end(vbak), [](int x){cout << x << " "; });
//	cout << endl;
//
//	cout << "---------push_heap--------" << endl;
//	v.push_back(1000);   //尾端插入1000
//	push_heap(v.begin(), v.end());  //上溯调整为堆
//	for (auto x : v)       //输出
//		cout << x << " ";
//	cout << endl;
//	
//
//	system("pause");
//	return 0;
//}
//
//
//
//
