#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
#include <iomanip> 
using namespace std;




//int main()//G. 蛇形矩阵（指针与动态内存分配）
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n,i,j;
//		cin >> n;
//		int**pp = new int*[n];
//		for (int i = 0; i<n; i++)
//		{
//			pp[i] = new int[n];
//			for (int j = 0; j < n; j++)
//			{
//				pp[i][j] = 0;
//			}
//		}
//		int count = 1;
//		int r1 = 1, r2 = n;
//		int c1 = n, c2 = 1;
//		while (count <= n*n)//赋值
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (pp[r1 - 1][j] == 0)
//				{
//					pp[r1 - 1][j] = count;
//					count++;
//				}
//			}
//			for (i = 0; i < n; i++)
//			{
//				if (pp[i][c1 - 1] == 0)
//				{
//					pp[i][c1 - 1] = count;
//					count++;
//				}
//			}
//			for (j = n-1; j >= 0; j--)
//			{
//				if (pp[r2 - 1][j] == 0)
//				{
//					pp[r2 - 1][j] = count;
//					count++;
//				}
//			}
//			for (i = n-1; i >= 0; i--)
//			{
//				if (pp[i][c2 - 1] == 0)
//				{
//					pp[i][c2 - 1] = count;
//					count++;
//				}
//			}
//			r1++;
//			r2--;
//			c1--;
//			c2++;
//		}
//
//		for (int i = 0; i<n; i++)//打印
//		{
//			for (int j = 0; j<n; j++)
//			{
//				cout << pp[i][j];
//				if (j < n - 1)
//					cout << " ";
//				else
//					cout << endl;
//			}
//		}
//		cout << endl;
//		for (int i = 0; i<n; i++)
//			delete[] pp[i];
//			delete[] pp;
//	}
//	
//
//	return 0;
//}





//int main()//H. 月份查询（指针数组）
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		char*p[] = 
//		{"January", "February", "March", "April", "May", "June", "July",
//			"August", "September", "October", "November", "December" };
//		int num;
//		cin >> num;
//		if (num >= 1 && num <= 12)
//			cout << *(p + num - 1) << endl;
//		else
//			cout << "error" << endl;
//	}
//	return 0;
//}




//int main()//F. 动态数组（指针与数组）
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		char ch;
//		int n,i;
//		cin >> ch;
//		cin >> n;
//		if (ch == 'I')
//		{
//			int* arr1 = new int[n];
//			int sum = 0;
//			for (i = 0; i < n; i++)
//			{
//				cin >> *(arr1 + i);
//				sum += *(arr1 + i);
//			}
//			int aver = sum / n;
//			int*p = &aver;
//
//			cout << *p << endl;
//			delete[] arr1;
//			arr1 = NULL;
//		}
//		else if (ch == 'C')
//		{
//			char* arr2 = new char[n];
//			for (i = 0; i < n; i++)
//			{
//				cin >> *(arr2 + i);
//			}
//			char ch2 = *arr2;
//			for (i = 0; i < n; i++)
//			{
//				if (*(arr2 + i)>ch2)
//					ch2 = *(arr2 + i);
//			}
//			char *p = &ch2;
//			cout << *p << endl;
//			delete[] arr2;
//			arr2 = NULL;
//		}
//
//		else if (ch == 'F')
//		{
//			float*arr3 = new float[n];
//			float min = 999.0;
//			for (i = 0; i < n; i++)
//			{
//				cin >> *(arr3 + i);
//				if (*(arr3 + i) < min)
//					min = *(arr3 + i);
//			}
//			float *p = &min;
//			cout << *p << endl;
//			delete[] arr3;
//			arr3 = NULL;
//		}
//	}
//
//	return 0;
//}




//int isNumber(char*p)
//{
//	int sum = 0;
//	while (*p != '\0')
//	{
//		int flag = 0;
//		int i;
//		for (i = 0; i < 10; i++)
//		{
//			if ((*p-'0') == i)
//			{
//				flag = 1;
//				sum = sum * 10 + i;
//				break;
//			}
//		}
//		p++;
//		if (flag == 0)
//			return -1;
//	}
//	return sum;
//	
//}
//
//int main()//E. 数字判断（指针为函数参数）
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		char str[20];
//		cin >> str;
//		int ret=isNumber(str);
//		cout << ret << endl;
//	}
//
//	return 0;
//}





//void input(int *p, int n)
//{
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		cin >> *p++;
//	}
//}
//
//void search(int *num, int n, int *nmax, int *nmaxindex)
//{
//	int i;
//	*nmaxindex = 0;
//	*nmax = *num;
//	for (i = 0; i < n; i++)
//	{
//		if (*(num + i)>*nmax)
//		{
//			*nmax = *(num + i);
//			*nmaxindex = i;
//		}
//	}
//}
//
//int main()//D. 数组最大值（指针作为函数参数）
//{
//	int t, nmax=0, nmaxindex=0;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int*num = new int[n];
//		input(num, n);
//		search(num, n, &nmax, &nmaxindex);
//		cout << nmax <<" "<< nmaxindex << endl;
//		delete[] num;
//		num = NULL;
//	}
//	
//	return 0;
//}


//int main()//C. 三串合一（指针与字符数组）
//{
//	int t;
//	char str1[12];
//	char str2[12];
//	char str3[12];
//	cin >> t;
//	while (t--)
//	{
//		cin >> str1 >> str2 >> str3;
//		int n,i;
//		int s1, s2, s3, e1, e2, e3;
//		cin >> s1 >> e1 >> s2 >> e2 >> s3 >> e3;
//		n = e1 + e2 + e3 - s1 - s2 - s3 + 4;
//		char*p = new char [n+1];
//		for (i = 0; i < e1 - s1 + 1; i++)
//		{//cdeBCDEFdee
//			*(p+i) = *(str1+s1-1+i);
//			*(p + i + 1) = '\0';
//		}
//		for (i = 0; i < e2 - s2 + 1; i++)
//		{
//			*(p + i + e1 - s1 + 1) = *(str2 + s2 - 1 + i);
//			*(p + i + e1 - s1 + 2) = '\0';
//		}
//		for (i = 0; i < e3 - s3 + 1; i++)
//		{
//			*(p + i + e1 - s1 + 1 + e2 - s2 + 1) = *(str3 + s3 - 1 + i);
//			*(p + i + e1 - s1 + 1 + e2 - s2 + 2) = '\0';
//		}
//
//		cout << p<<endl;
//		delete[] p;
//		p = NULL;
//	}
//
//	return 0;
//}






//int my_compare(char *S, char *T)
//{
//	int len1 = strlen(S);
//	int len2 = strlen(T);
//	int count1 = 0, count2 = 0;
//	int i;
//	if (len1 > len2)
//		return 1;
//	else if (len1 < len2)
//		return -1;
//	else
//	{
//		for (i = 0; i < len1; i++)
//		{
//			if (*(S + i) > *(T + i))
//				count1++;
//			else if(*(S + i) < *(T + i))
//				count2++;
//		}
//		if (count1>count2)
//			return 1;
//		else if (count1 < count2)
//			return -1;
//		else
//			return 0;
//	}
//}
//
//
//int main()//B. 字符串比较（指针与字符）
//{
//	char S[30];
//	char T[30];
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> S >> T;
//		int ret=my_compare(S, T);
//		cout << ret << endl;
//	}
//	return 0;
//}






//int main()//A. 货币兑换（指针与常量）
//{
//	double arr[] = { 6.2619, 6.6744, 0.0516, 0.8065 };
//	const double*p = arr;
//	int t ,i;
//	double money,new_money;
//	char type;
//	cin >> t;
//	while (t--)
//	{
//		cin >> type;
//		cin >> money;
//		if (type == 'D')
//			new_money = money*(*p);
//		else if (type == 'E')
//			new_money = *(p + 1)*money;
//		else if (type == 'Y')
//			new_money = *(p + 2)*money;
//		else if (type == 'H')
//			new_money = *(p + 3)*money;
//		cout << fixed << setprecision(4) << new_money << endl;
//	}
//}
