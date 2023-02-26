#define _CRT_SECURE_NO_WARNINGS 1

//array练习
#include <array>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	array<int, 10>  arr;

	arr.fill(10);   //10个10

	//输出所有元素
	for (auto x : arr)
		cout << x << " ";
	cout << endl;

	arr[3] = 20;  //[]访问
	for (auto x : arr)
		cout << x << " ";
	//for_each(begin(arr),end(arr),[](int x){cout<<x<<" ";});    第三讲理解
	cout << endl;

	cout << get<3>(arr) << endl;   //get访问，第3个元素

	//与arr1交换。vector也支持swap
	array<int, 10> arr1({ 1, 2, 3, 4, 6, 7 });   //初始化列表初始化
	arr.swap(arr1);
	for (auto x : arr)
		cout << x << " ";
	cout << endl;

	//输出第一个元素,data返回指向第一个元素的指针
	cout << *arr.data() << endl;
	system("pause");
	return 0;
}




////实现一组数的按位置插入、删除、查找元素。
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//void display(vector<int> v); //输出数据
//bool insert(vector<int> &v, int i, int e);   //按位置插入，插入位置：1~长度+1
//bool deleteelem(vector<int> &v, int e);  //按元素值删除元素
//
//int main()
//{
//	vector<int> vec;     //无元素对象，需要push_back
//	int n, e, m, index;
//
//	//数组初始化
//	cin >> n;       //输入元素数
//	while (n--)     //输入n个数，入vector
//	{
//		cin >> e;
//		vec.push_back(e);
//	}
//	display(vec);   //输出数组中的元素
//
//	//按位置插入
//	cout << "------insert-----------------" << endl;
//	cin >> m;      //次数
//	while (m--)
//	{
//		cin >> index >> e;     //输入下标位置index和元素值e
//		if (!insert(vec, index, e))   //调插入函数，返回true或false
//			cout << "error!" << endl;
//		else
//			display(vec);
//	}
//
//	//按元素值删除
//	cout << "---------delete e---------" << endl;
//	cin >> m;        //次数
//	while (m--)
//	{
//		cin >> e;      //元素值
//		if (!deleteelem(vec, e))     //调删除函数，返回true或false
//			cout << "error!" << endl;
//		else
//			display(vec);
//	}
//
//	//按范围删除
//	cout << "----------delete range------------" << endl;
//	int first, last;
//	cin >> first >> last; //stl中基于范围的操作都是半开区间[first,last)
//	vec.erase(begin(vec) + first, begin(vec) + last);
//	display(vec);
//
//	//删除最后一个元素
//	cout << "------------pop back--------------" << endl;
//	vec.pop_back(); //删除最后一个元素
//	display(vec);
//	system("pause");
//	return 0;
//}
//
////输出数
//void display(vector<int> v)
//{
//	cout << "data: len = " << v.size() << " : ";
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//}
//
////按位置插入，插入位置1-长度+1
//bool insert(vector<int> &v, int i, int e)
//{
//	if (i < 1 || i >(int)v.size() + 1)      //位置不正确
//		return false;
//	v.insert(begin(v) + i - 1, e);           //insert插入
//	return 1;
//}
//
////按元素值删除元素
//bool deleteelem(vector<int> &v, int e)
//{
//	for (auto it = begin(v); it != end(v); it++)    //遍历数组
//	if (*it == e)          //找到
//	{
//		v.erase(it);         //删除
//		return true;
//	}
//	return false;
//}
//
///*
//4 10 20 30 40
//5
//0 15
//1 15
//2 55
//7 100
//10 14
//3
//15
//30
//25
//1 4   //不能超下标范围
//*/
