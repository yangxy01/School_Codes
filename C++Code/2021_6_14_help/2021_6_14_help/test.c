#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	int a;
	a = (-5) % 2;
	printf("%d\n", a);
	//int n, i;
	//char name[11][11], id[11][6];
	//double score[10];//改成double
	//double ave, sum = 0;
	//scanf("%d", &n);
	//for (i = 0; i < n; i++)
	//{
	//	scanf("%s %s %lf", &id[i], &name[i], &score[i]);
	//	sum += score[i];
	//}

	//ave = sum / n;
	//printf("%.2lf", ave);
	//for (i = 0; i < n; i++)
	//{
	//	if (score[i] < ave)
	//	{
	//		printf("%s %s", id[i], name[i]);
	//	}
	//}
	//return 0;
}





//#define MAXN 10
//
//void f(long int x, char*p);
//int main()
//{
//	long int x;
//	char s[MAXN] = "";
//	scanf("%ld", &x);
//	f(x, s);
//	printf("%s\n", s);
//	return 0;
//}
//void f(long int x, char*p)
//{
//	int num = 0;
//	int count = 0;
//	char ch;
//	while (x)//以100为例子
//	{
//		num = x % 16;
//		if (num == 10){ ch = 'A'; }
//		else if (num == 11){ ch = 'B'; }
//		else if (num == 12){ ch = 'C'; }
//		else if (num == 13){ ch = 'D'; }
//		else if (num == 14){ ch = 'E'; }
//		else if (num == 15){ ch = 'F'; }
//		else{ ch = num+'0'; }
//		p[count] = ch;
//		count++;
//		x /= 16;
//	}
//	//现在搞完了，p里面存的是46，应该是64，所以反转一下
//	char p2[MAXN] = "";
//	int i = 0;
//	while (1)
//	{
//		if (count <= 0)
//		{
//			p2[i] = '\0';// 记得加
//			break;
//		}
//		p2[i] = p[count - 1];
//		i++;
//		count--;			
//	}
//	strcpy(p, p2);//拷贝字符串
//}
//
//
//
//
//
//
//
//////--------------------------------------------------------
//////11001100100101000001010101110010
////int main()
////{
////	char str[33];
////	int count = 0;
////	int sum = 0;
////	for (int i = 0; i < 32; i++)
////	{
////		scanf("%c", &str[i]);
////		count++;
////		sum = sum * 2;
////		sum+= (str[i] - '0');
////		if (count == 8)
////		{
////			if (i<24)
////				printf("%d.", sum);
////			else
////				printf("%d\n", sum);
////			count = 0;
////			sum = 0;
////			
////		}
////		
////	}
////	
////}
//
//
////
//////=======================================================
////int isLeapYear(int year)
////{
////	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
////		return 1;//是闰年返回1
////	return 0;
////}
/////*
////2017/1/1/0
////2017/10/17
////*/
////
////int main()
////{
////	int y1, m1, d1,today;
////	int y2, m2, d2;
////
////	//平年每个月多少天
////	int a1[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
////	//闰年每个月多少天
////	int a2[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
////
////	char ch;
////	int t = 2;
////	while (t--)
////	{
////		int sum = 0;//累计天数
////		scanf("%d", &y1);
////		ch = getchar();
////		scanf("%d", &m1);
////		ch = getchar();
////		scanf("%d", &d1);
////		ch = getchar();
////		scanf("%d", &today);
////		ch = getchar();
////		scanf("%d", &y2);
////		ch = getchar();
////		scanf("%d", &m2);
////		ch = getchar();
////		scanf("%d", &d2);
////		ch = getchar();
////		
////		if (y1 == y2)//同一年
////		{
////			if (isLeapYear(y1))
////			{
////				sum += a2[m1 - 1] - d1;
////				for (int i = m1 + 1; i < m2; i++)
////					sum += a2[i - 1];
////				sum += d2;
////			}
////			else
////			{
////				sum += a1[m1 - 1] - d1;
////				for (int i = m1 + 1; i < m2; i++)
////					sum += a1[i - 1];
////				sum += d2;
////			}
////		}
////		else//不同一年
////		{
////			if (isLeapYear(y1))//先处理起始年
////			{
////				sum += a2[m1 - 1] - d1;
////				for (int i = m1 + 1; i < 12; i++)
////					sum += a2[i - 1];
////			}
////			else
////			{
////				sum += a1[m1 - 1] - d1;
////				for (int i = m1 + 1; i < 12; i++)
////					sum += a1[i-1];
////			}
////			for (int k = y1 + 1; k < y2; k++)//处理剩下年,除去最后一年
////			{
////				if (isLeapYear(k))
////				{
////					for (int i = 1; i < 12; i++)
////						sum += a2[i - 1];
////				}
////				else
////				{
////					for (int i = 1; i < 12; i++)
////						sum += a1[i - 1];
////				}
////			}
////
////			//处理最后一年
////			if(isLeapYear(y2))//先处理起始年
////			{
////				for (int i = 1; i < m2; i++)
////					sum += a2[i - 1];
////				sum += d2;
////			}
////			else
////			{
////				for (int i = 1; i < m2; i++)
////					sum += a1[i - 1];
////				sum += d2;
////			}
////		}
////
////
////		sum += today;
////		int result=sum % 7;
////		switch (result)
////		{
////		case 0:
////			printf("%d/%d/%d是星期日\n", y2, m2, d2);;
////			break;
////		case 1:
////			printf("%d/%d/%d是星期一\n", y2, m2, d2);;
////			break;
////		case 2:
////			printf("%d/%d/%d是星期二\n", y2, m2, d2);;
////			break;
////		case 3:
////			printf("%d/%d/%d是星期三\n", y2, m2, d2);;
////			break;
////		case 4:
////			printf("%d/%d/%d是星期四\n", y2, m2, d2);;
////			break;
////		case 5:
////			printf("%d/%d/%d是星期五\n", y2, m2, d2);;
////			break;
////		case 6:
////			printf("%d/%d/%d是星期六\n", y2, m2, d2);;
////			break;
////		default:
////			break;
////		}
////	}
////
////	return 0;
////}
//
//
//
////#define MAXN 20
////void CountOff(int n, int m, int out[]);
////int main()
////{
////	int out[MAXN], n, m;
////	int i;
////	scanf("%d %d", &n, &m);
////	CountOff(n, m, out);
////	for (i = 0; i < n; i++)
////		printf("%d ", out[i]);
////	printf("\n");
////	return 0;
////}
////
////void CountOff(int n, int m, int out[])
////{
////	for (int j = 0; j < n; j++)//让每个人都为0，作为还没出去的标志
////	{
////		out[j] = 0;
////	}
////
////	int outnumber = 0;//统计出去了有多少个人
////	int count = 0;//数数
////	int i = -1;//下标,代表人,待会进去i++刚好从0开始
////	while (outnumber<n)//出去的人不到n个就继续
////	{
////		count++;
////		i++;//下一个人
////		if (i>=n)//判断是不是超出了
////		{
////			i = 0;//重头找人
////		}
////		while (out[i] != 0)//如果我不等于0，就下一个人，直到这个人是0
////		{
////			i++;
////			if (i>n)//判断是不是超出了
////			{
////				i = -1;//重头找人，待会i++刚好为0
////			}
////		}
////		if (count == m)//数到的数等于m
////		{
////			outnumber++;//出去了有这么多个人
////			out[i] = outnumber;//i这个人是第outnumber个出去的
////			count = 0;//重头数，待会count++刚好为1
////		}
////	}
////
////}