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
//	int  data[10]{1, 2, 3, 4, 5};      //���飬10��Ԫ�أ�1��2��3��4��5��0��0��
//
//	cout << "-------- asc---------" << endl;
//	sort(data, data + 10);           //��������
//	display(data);
//
//	cout << "-------- des, lambda---------" << endl;
//	sort(data, data + 10, [](int lhs, int rhs){return lhs > rhs; });   //lambda���ʽ����������
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
//
//
//
//////����һ������
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
////	//Ĭ������ <
////	sort(v.begin(), v.end());
////	PrintV(v); // 1 2 3 4 5 6
////
////	//���� >
////	sort(v.begin(), v.end(), greater<int>());
////	PrintV(v); // 6 5 4 3 2 1
////
////	//���� <
////	sort(v.begin(), v.end(), less<int>());
////	PrintV(v); // 1 2 3 4 5 6
////	return 0;
////}
