#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
using namespace std;

//struct card
//{
//	char str[50];
//	int Serial;
//};
//
//int getSerial(char *str)
//{
//	int high, low;
//	if (strstr(str, "黑桃")) 
//		high = 4;
//	if (strstr(str, "红桃")) 
//		high = 3;
//	if (strstr(str, "梅花")) 
//		high = 2;
//	if (strstr(str, "方块")) 
//		high = 1;
//
//	if (strstr(str, "A")) 
//		low = 13;
//	if (strstr(str, "K")) 
//		low = 12;
//	if (strstr(str, "Q")) 
//		low = 11;
//	if (strstr(str, "J")) 
//		low = 10;
//	if (strstr(str, "10")) 
//		low = 9;
//	if (strstr(str, "9")) 
//		low = 8;
//	if (strstr(str, "8")) 
//		low = 7;
//	if (strstr(str, "7")) 
//		low = 6;
//	if (strstr(str, "6")) 
//		low = 5;
//	if (strstr(str, "5")) 
//		low = 4;
//	if (strstr(str, "4")) 
//		low = 3;
//	if (strstr(str, "3")) 
//		low = 2;
//	if (strstr(str, "2")) 
//		low = 1;
//	return (high* 13 + low);
//}
//
//
//int main()//F. 扑克牌排序（结构体）
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, i;
//		cin >> n;
//		card*p = new card[n];
//		for (i = 0; i < n; i++)
//		{
//			cin >> (p + i)->str;
//		}
//
//		for (int i = 0; i < n; i++)
//		{
//			if (strstr((p + i)->str, "大王") != NULL)
//			{
//				//cout << "大王" << " ";
//				(p + i)->Serial = 9999;
//			}
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (strstr((p + i)->str, "小王") != NULL)
//			{
//				//cout << "小王" << " ";
//				(p + i)->Serial = 9998;
//			}
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (strstr((p + i)->str, "大王") != NULL
//				|| strstr((p + i)->str, "小王") != NULL)
//			{
//				continue;
//			}
//			else
//			{
//				(p + i)->Serial = getSerial((p + i)->str );
//			}
//		}
//		int j;
//		for (i = 0; i< n - 1; i++)
//		{
//			for (j = 0; j< n-1-i; j++)
//			{
//				if ((p + j)->Serial <(p + j+1)->Serial)
//				{
//					card temp = *(p + j);
//					*(p + j) = *(p + j + 1);
//					*(p + j + 1) = temp;
//				}
//			}
//		}
//		for (i = 0; i < n-1; i++)
//		{
//			cout << (p + i)->str << " ";
//		}
//		cout << (p + i)->str ;
//		cout << endl;
//		delete[]p;
//		p = NULL;
//	}
//	return 0;
//}







struct paper
{
	int num;
	char exe1[100];
	char exe2[100];
	char exe3[100];
};

int func(paper*, paper*);
double judge(char*, char*);


int main()//E. 抄袭查找（结构体+指针+函数）????
{
	int t,i,j;
	cin >> t;
	paper*pr=new paper[t];
	for (i = 0; i < t; i++)
	{
		cin >> (pr + i)->num;
		cin>> (pr + i)->exe1 >> (pr + i)->exe2 >> (pr + i)->exe3;
	}
	for (i = 0; i < t; i++)
	{
		for (j = i + 1; j < t; j++)
		{
			int ret = func(pr + i, pr + j);
			if (ret != 0)
				cout << (pr + i)->num << " " 
				<< (pr + j)->num << " " << ret << endl;
		}
	}
	
	return 0;
}
double judge(char*s1, char*s2)
{
	int len = 0;
	int count = 0;
	while (*(s1 + len) != '\0' && *(s2 + len) != '\0')
	{
		if (*(s1 + len) == *(s2 + len))
			count++;
		len++;
	}
	double r = count*1.0 / len;
	return r;
}
int func(paper*p1, paper*p2)
{
	double ret = judge(p1->exe1, p2->exe1);
	if (ret >= 0.9)
		return 1;
	ret = judge(p1->exe2, p2->exe2);
	if (ret >= 0.9)
		return 2;
	ret = judge(p1->exe3, p2->exe3);
	if (ret >= 0.9)
		return 3;
	return 0;
}







//struct Birth
//{
//	int year;
//	int mon;
//	int day;
//};
//int main()//D. 谁是老二（结构体）????
//{
//	int t,i,j;
//	cin >> t;
//	Birth Bir[10];
//	int sum[10] = { 0 };
//	for (i = 0; i < t;i++)
//	{
//		cin >> Bir[i].year >> Bir[i].mon >> Bir[i].day;
//	}
//	for (i = 0; i < t-1; i++)
//	{
//		for (j = 0; j < t - i - 1; j++)
//		{
//			if (Bir[j].year>Bir[j + 1].year)
//			{
//				Birth tmp = Bir[j];
//				Bir[j] = Bir[j + 1];
//				Bir[j + 1] = tmp;
//			}
//		}
//	}
//	for (i = 0; i < t; i++)
//	{
//		sum[i] = (Bir[i].year - Bir[0].year) * 366
//			+ Bir[i].mon * 30 + Bir[i].day;
//	}
//	int min = 0;
//	for (i = 0; i < t; i++)
//	{
//		if (sum[i] < sum[min])
//			min = i;
//	}
//	sum[min] = 99999;
//	int second = min;
//	for (i = 0; i < t; i++)
//	{
//		if (sum[i] < sum[second])
//			second = i;
//	}
//	
//	cout << Bir[second].year << "-"
//		<< Bir[second].mon << "-"
//		<< Bir[second].day << endl;
//
//	return 0;
//}



//void find(int *num, int n, int &minIndex, int &maxIndex)
//{
//	int i;
//	for (i = 1; i < n; i++)
//	{
//		if (num[i]>num[maxIndex])
//			maxIndex = i;
//		if (num[i] < num[minIndex])
//			minIndex = i;
//	}
//}
//int main()//C. 求最大值最小值（引用）
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n,min=0,max=0;
//		cin >> n;
//		int i;
//		int*num=new int [n];
//		for (i = 0; i < n; i++)
//			cin >> num[i];
//		find(num, n, min, max);
//		cout << "min=" << num[min] << " " << "minindex=" << min << endl;
//		cout << "max=" << num[max] << " " << "maxindex=" << max << endl;
//		
//		delete[]num;
//	}
//
//	return 0;
//}




//void func(int &x, int &y, int &z)
//{
//	int tmp;
//	if (y > x)
//	{
//		tmp = x;
//		x = y;
//		y = tmp;
//	}
//	if (z > x)
//	{
//		tmp = x;
//		x = z;
//		z = tmp;
//	}
//	if (z > y)
//	{
//		tmp = y;
//		y = z;
//		z = tmp;
//	}
//}
//
//int main()//B. 三数论大小（引用）
//{
//	int a, b, c,t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> a >> b >> c;
//		func(a, b, c);
//		cout << a << " " << b << " " << c << endl;
//	}
//
//	return 0;
//}







//int func1(int n)
//{
//	return n*n;
//}
//float func2(float n)
//{
//	return sqrt(n);
//}
//void func3(char*str)
//{
//	while ((*str) != '\0')
//	{
//		if ((*str) >= 'a' && (*str) <= 'z')
//			*str = *str + 'A'-'a';
//		str++;
//	}
//}
//	
//int main()//A. 函数调用（函数指针）
//{
//	int t;
//	cin >> t;
//	char ch;
//
//	int (*p1)(int n);//定义函数指针
//	float(*p2)(float n);
//	void(*p3)(char*);
//	p1 = func1;
//	p2 = func2;
//	p3 = func3;
//
//	while (t--)
//	{
//		cin >> ch;
//		if (ch == 'I')
//		{
//			int n;
//			cin >> n;
//			int ret = p1(n);//调用函数指针
//			cout << ret << endl;
//		}
//		else if (ch == 'F')
//		{
//			float n;
//			cin >> n;
//			float ret = p2(n);
//			cout << ret << endl;
//		}
//		else if (ch == 'S')
//		{
//			char str[20];
//			cin >> str;
//			p3(str);
//			cout << str << endl;
//		}
//
//	}
//	return 0;
//}