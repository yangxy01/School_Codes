#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int score[50] = { 0 };
		int n,i,seq;
		cin >> n;
		for (i = 0; i < n; i++)
		{
			cin >> score[i];
		}
		int* p = score;
		p = p + n / 2;
		//打印前后分数
		cout << *--p << ' ';
		p++;
		cout << *++p << endl;
		p--;
		//打印序号分数
		cin >> seq;
		cout << *(p + seq - (n / 2 + 1)) << endl;

	}
}


//int main()//三数论大小
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int arr[3],i, j;
//		for (i = 0; i < 3; i++)
//		{
//			cin >> arr[i];
//		}
//		int*p = arr;
//		int*p1 = new int;
//		for (i = 0; i < 2; i++)
//		{
//			for (j = 0; j < 2 - i; j++)
//			{
//				if (*(p + j) < *(p + j + 1))
//				{
//					*p1 = *(p + j);
//					*(p + j) = *(p + j + 1);
//					*(p + j + 1) = *p1;
//				}
//			}
//		}
//		for (i = 0; i < 3; i++)
//		{
//			cout << *(p + i) << ' ';
//		}
//		cout << endl;
//	}
//}


//int main()//交换两个数
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int num1 = 0, num2 = 0;
//		cin >> num1 >> num2;
//		int* p1 = &num1;
//		int* p2 = &num2;
//		int* p = NULL;
//
//		p = p1;
//		p1 = p2;
//		p2 = p;
//
//		cout << *p1 << ' ' << *p2 << endl;
//	}
//}