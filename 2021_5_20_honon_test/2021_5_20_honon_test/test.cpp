#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
using namespace std;

//student sort
//����һ������<�����
struct student
{
	string name;
	int age;
	bool operator<(const student &rhs) //*this rhs������������
	{
		if (age != rhs.age) //����Ľ���
			return age > rhs.age;
		return name < rhs.name; //������ȣ��������ֵ�����
	}
};

//���������º�������������
struct cmp
{
	bool operator()(const student &lhs, const student &rhs)
	{
		if (lhs.age != rhs.age) //ͬ�ϣ����併��������ȣ���������
			return lhs.age > rhs.age;
		return lhs.name < rhs.name;
	}
};

//������������ָ��
bool compare(const student &lhs, const student &rhs)
{
	if (lhs.age != rhs.age) //ͬ�ϣ����併��������ȣ���������
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
	sort(begin(s), end(s)); //����һ������<�����
	display(s);

	s = s1;
	sort(begin(s), end(s), cmp()); //���������º�������������
	display(s);

	s = s1;
	sort(begin(s), end(s), compare); //������������ָ��
	display(s);

	s = s1;
	sort(begin(s), end(s), [](const student &lhs, const student &rhs) -> bool { if (lhs.age != rhs.age)
		return lhs.age > rhs.age;
	return lhs.name < rhs.name; });


	//�����ģ�lambda���ʽ, ���併��
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
//		[min, max](int &x) {                //ֵ���ݲ���min, max
//			if (x >= min && x <= max)
//				x = 2 * x;
//		}(num);                             //ʵ��num
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
//	cout << typeid(boys).name() << endl;    //���boys����
//	cout << typeid(girls).name() << endl;
//	cout << typeid(totalChild()).name() << endl;   //���totalChild()�������
//
//	cout << totalChild() << endl;    //���lambda���
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
//	auto by_val_lambda = [=] { return j + 1; };     //ֵ���ݣ�����ʱȷ��ֵ
//	auto by_ref_lambda = [&] { return j + 1; };     //���ô��ݣ�����ʱȷ��ֵ
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
//	int  data[10]{1, 2, 3, 4, 5};      //���飬10��Ԫ�أ�1��2��3��4��5��0��0��
//
//	cout << "-------- asc---------" << endl;
//	sort(data, data + 10);           //��������
//	display(data);
//
//	cout << "-------- des, lambda---------" << endl;
//	sort(data, data + 10, [](int lhs, int rhs){return lhs >= rhs; });   //lambda���ʽ����������
//	display(data);
//
//	cout << "-------- des---------" << endl;
//	sort(data, data + 10, greater<int>());    //��������
//	display(data);
//
//	cout << "---------accumulate--------" << endl;
//	int sum = accumulate(data, data + 10, 0, minus<int>());   //minus�º�����accumulate���㷨���ۺͣ�
//	//int sum1 = accumulate(data, data+10, 10, plus<int>());      //��� , ��ֵ10
//	int sum1 = accumulate(data, data + 10, 10);      //��� , ��ֵ10
//	int sum2 = accumulate(data, data + 10, 0, fun);  //���Ԫ�ص�ƽ���� , ����ָ��
//	//int sum3 = accumulate(data, data+10, 0, sfun());  //���Ԫ�ص�ƽ���� , �Զ���º���
//	int sum3 = accumulate(data, data + 10, 0, funobject);  //���Ԫ�ص�ƽ���� , �Զ���º���
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

