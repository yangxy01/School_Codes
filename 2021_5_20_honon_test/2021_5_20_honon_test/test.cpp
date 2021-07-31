#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
using namespace std;

//student sort
//方法一，重载<运算符
struct student
{
	string name;
	int age;
	bool operator<(const student &rhs) //*this rhs满足的排序策略
	{
		if (age != rhs.age) //年龄的降序
			return age > rhs.age;
		return name < rhs.name; //年龄相等，姓名的字典升序
	}
};

//方法二，仿函数，函数对象
struct cmp
{
	bool operator()(const student &lhs, const student &rhs)
	{
		if (lhs.age != rhs.age) //同上，年龄降序，若年龄等，姓名升序
			return lhs.age > rhs.age;
		return lhs.name < rhs.name;
	}
};

//方法三，函数指针
bool compare(const student &lhs, const student &rhs)
{
	if (lhs.age != rhs.age) //同上，年龄降序，若年龄等，姓名升序
		return lhs.age > rhs.age;
	return lhs.name < rhs.name;
}

//output
void display(vector<student> s)
{
	cout << "sort result:" << endl;
	for (auto x : s)
		cout << x.name << " " << x.age << endl;
	cout << endl;
}

int main()
{
	vector<student> s1 = { { "qianwu", 20 }, { "wangwu", 21 }, { "zhaosi", 19 }, { "liming", 20 } };
	vector<student> s;

	s = s1;
	sort(begin(s), end(s)); //方法一，重载<运算符
	display(s);

	s = s1;
	sort(begin(s), end(s), cmp()); //方法二，仿函数，函数对象
	display(s);

	s = s1;
	sort(begin(s), end(s), compare); //方法三，函数指针
	display(s);

	s = s1;
	sort(begin(s), end(s), [](const student &lhs, const student &rhs) -> bool { if (lhs.age != rhs.age)
		return lhs.age > rhs.age;
	return lhs.name < rhs.name; });


	//方法四，lambda表达式, 年龄降序
	display(s);

	system("pause");
	return 0;
}





////lambda1.cpp
//int main()
//{
//	int min = 10, max = 20;
//	int num;
//	cout << "input number, ended with ctrl + z" << endl;
//	while (cin >> num)
//	{
//		[min, max](int &x) {                //值传递捕获min, max
//			if (x >= min && x <= max)
//				x = 2 * x;
//		}(num);                             //实参num
//		cout << num << endl;
//	}
//
//	system("pause");
//	return 0;
//}
//
//
//
//
////lambda2.cpp
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int boys = 4, girls = 3;
//
//	auto totalChild = [=]() -> int { return girls + boys; };
//
//	cout << typeid(boys).name() << endl;    //输出boys类型
//	cout << typeid(girls).name() << endl;
//	cout << typeid(totalChild()).name() << endl;   //输出totalChild()结果类型
//
//	cout << totalChild() << endl;    //输出lambda结果
//
//	system("pause");
//	return 0;
//}
//
//
//
//
////lambda.cpp
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int j = 12;
//
//	auto by_val_lambda = [=] { return j + 1; };     //值传递，定义时确定值
//	auto by_ref_lambda = [&] { return j + 1; };     //引用传递，调用时确定值
//
//	cout << "by_val_lambda:" << by_val_lambda() << endl;    //output: 13
//	cout << "by_ref_lambda:" << by_ref_lambda() << endl;    //output: 13
//	j += 1;
//	cout << "by_val_lambda:" << by_val_lambda() << endl;    //output: 13
//	cout << "by_ref_lambda:" << by_ref_lambda() << endl;    //output: 14
//
//	system("pause");
//	return 0;
//}
//
//
//
//
//#include <iostream>
//#include <vector>
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
//	sort(data, data + 10, [](int lhs, int rhs){return lhs >= rhs; });   //lambda表达式，降序排序
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

