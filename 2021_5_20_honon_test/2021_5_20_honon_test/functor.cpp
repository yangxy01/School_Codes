//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <vector>
//#include <functional> 
//#include <algorithm>
//#include <numeric>
//using namespace std;
//
//void display(int num[]);
//int fun(int lhs, int rhs) { return lhs + rhs * rhs; }
//struct sfun
//{
//	int operator() (int &lhs, int &rhs)
//	{
//		return lhs + rhs * rhs;
//	}
//}funobject;
//
//int main()
//{
//	int  data[10]{1, 2, 3, 4, 5};      //数组，10个元素，1，2，3，4，5，0，0，
//
//	cout << "-------- asc---------" << endl;
//	sort(data, data + 10);           //升序排序
//	display(data);
//
//	cout << "-------- des, lambda---------" << endl;
//	sort(data, data + 10, [](int lhs, int rhs){return lhs > rhs; });   //lambda表达式，降序排序
//	display(data);
//
//	cout << "-------- des---------" << endl;
//	sort(data, data + 10, greater<int>());    //降序排序
//	display(data);
//
//	cout << "---------accumulate--------" << endl;
//	int sum = accumulate(data, data + 10, 0, minus<int>());   //minus仿函数，accumulate：算法，累和，
//	//int sum1 = accumulate(data, data+10, 10, plus<int>());      //求和 , 初值10
//	int sum1 = accumulate(data, data + 10, 10);      //求和 , 初值10
//	int sum2 = accumulate(data, data + 10, 0, fun);  //求各元素的平方和 , 函数指针
//	//int sum3 = accumulate(data, data+10, 0, sfun());  //求各元素的平方和 , 自定义仿函数
//	int sum3 = accumulate(data, data + 10, 0, funobject);  //求各元素的平方和 , 自定义仿函数
//	cout << sum << " " << sum1 << " " << sum2 << " " << sum3 << endl;
//
//	system("pause");
//	return 0;
//}
//
//
//void display(int num[10])
//{
//	for (int i = 0; i<10; i++)
//		cout << num[i] << " ";
//	cout << endl;
//}
//
//
//
//////排序一组数据
////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <functional>
////using namespace std;
////
////void PrintV(const vector<int>& v)
////{
////	int size = v.size();
////	for (int i = 0; i < size; ++i)
////	{
////		cout << v[i] << " ";
////	}
////	cout << endl;
////}
////int main()
////{
////	vector<int> v = { 3, 2, 1, 6, 5, 4 };
////	//默认升序 <
////	sort(v.begin(), v.end());
////	PrintV(v); // 1 2 3 4 5 6
////
////	//降序 >
////	sort(v.begin(), v.end(), greater<int>());
////	PrintV(v); // 6 5 4 3 2 1
////
////	//升序 <
////	sort(v.begin(), v.end(), less<int>());
////	PrintV(v); // 1 2 3 4 5 6
////	return 0;
////}
