#define _CRT_SECURE_NO_WARNINGS 1

//array��ϰ
#include <array>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	array<int, 10>  arr;

	arr.fill(10);   //10��10

	//�������Ԫ��
	for (auto x : arr)
		cout << x << " ";
	cout << endl;

	arr[3] = 20;  //[]����
	for (auto x : arr)
		cout << x << " ";
	//for_each(begin(arr),end(arr),[](int x){cout<<x<<" ";});    ���������
	cout << endl;

	cout << get<3>(arr) << endl;   //get���ʣ���3��Ԫ��

	//��arr1������vectorҲ֧��swap
	array<int, 10> arr1({ 1, 2, 3, 4, 6, 7 });   //��ʼ���б��ʼ��
	arr.swap(arr1);
	for (auto x : arr)
		cout << x << " ";
	cout << endl;

	//�����һ��Ԫ��,data����ָ���һ��Ԫ�ص�ָ��
	cout << *arr.data() << endl;
	system("pause");
	return 0;
}




////ʵ��һ�����İ�λ�ò��롢ɾ��������Ԫ�ء�
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//void display(vector<int> v); //�������
//bool insert(vector<int> &v, int i, int e);   //��λ�ò��룬����λ�ã�1~����+1
//bool deleteelem(vector<int> &v, int e);  //��Ԫ��ֵɾ��Ԫ��
//
//int main()
//{
//	vector<int> vec;     //��Ԫ�ض�����Ҫpush_back
//	int n, e, m, index;
//
//	//�����ʼ��
//	cin >> n;       //����Ԫ����
//	while (n--)     //����n��������vector
//	{
//		cin >> e;
//		vec.push_back(e);
//	}
//	display(vec);   //��������е�Ԫ��
//
//	//��λ�ò���
//	cout << "------insert-----------------" << endl;
//	cin >> m;      //����
//	while (m--)
//	{
//		cin >> index >> e;     //�����±�λ��index��Ԫ��ֵe
//		if (!insert(vec, index, e))   //�����뺯��������true��false
//			cout << "error!" << endl;
//		else
//			display(vec);
//	}
//
//	//��Ԫ��ֵɾ��
//	cout << "---------delete e---------" << endl;
//	cin >> m;        //����
//	while (m--)
//	{
//		cin >> e;      //Ԫ��ֵ
//		if (!deleteelem(vec, e))     //��ɾ������������true��false
//			cout << "error!" << endl;
//		else
//			display(vec);
//	}
//
//	//����Χɾ��
//	cout << "----------delete range------------" << endl;
//	int first, last;
//	cin >> first >> last; //stl�л��ڷ�Χ�Ĳ������ǰ뿪����[first,last)
//	vec.erase(begin(vec) + first, begin(vec) + last);
//	display(vec);
//
//	//ɾ�����һ��Ԫ��
//	cout << "------------pop back--------------" << endl;
//	vec.pop_back(); //ɾ�����һ��Ԫ��
//	display(vec);
//	system("pause");
//	return 0;
//}
//
////�����
//void display(vector<int> v)
//{
//	cout << "data: len = " << v.size() << " : ";
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//}
//
////��λ�ò��룬����λ��1-����+1
//bool insert(vector<int> &v, int i, int e)
//{
//	if (i < 1 || i >(int)v.size() + 1)      //λ�ò���ȷ
//		return false;
//	v.insert(begin(v) + i - 1, e);           //insert����
//	return 1;
//}
//
////��Ԫ��ֵɾ��Ԫ��
//bool deleteelem(vector<int> &v, int e)
//{
//	for (auto it = begin(v); it != end(v); it++)    //��������
//	if (*it == e)          //�ҵ�
//	{
//		v.erase(it);         //ɾ��
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
//1 4   //���ܳ��±귶Χ
//*/
