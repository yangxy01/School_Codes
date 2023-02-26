#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int main()
{
	long int x;
	int div;
	int flag = 0;//标记是否为负数

	char str[30];
	scanf("%ld", &x);
	
	if (x == 0)
	{
		strcpy(str,"0");//字符串为0
	}
	if (x<0)
	{
		x = -x;
		flag = 1;//是负数
	}

	int i = 0;
	while (x)
	{
		div = x % 16;
		x = x / 16;
		if ((div - 10)<0)
			str[i] = div + '0';
		else 
			str[i] = 'A' + div - 10;
		div = 0;
		i++;
		str[i] = '\0';
	}
	//reverse
	int k = strlen(str);
	for (i = 0; i<k / 2; i++)
	{
		char temp = str[i];
		str[i] = str[k - 1 - i];
		str[k - 1 - i] = temp;
	}
	if (flag == 1)
		printf("-%s\n", str);
	else
		printf("%s\n", str);
}


//int main()
//{
//	int n;
//	int count = 0;
//	int result[100];
//	scanf("%d", &n);
//	while (n)
//	{
//		result[count] = n % 10;
//		n /= 10;
//		count++;
//	}
//	for (int i = 0; i < count; i++)
//	{
//		printf("%d ", result[i]);
//	}
//	return 0;
//}



//int main()
//{
//	int i, j, t;
//	int a[10], n;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (i = 1; i < n; i++)
//	{
//		for (j = 0; j < n - i; j++)
//		{
//			if (a[j]>a[j + 1])
//			{
//				t = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = t;
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}




//int main()
//{
//	double x1, y1, x2, y2, x, y;
//	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
//	x = x1 + x2;
//	y = y1 + y2;
//	if ((x*y) != 0)
//		printf("(%.1lf, %.1lf)", x, y);
//	else if (fabs(x)<0.00001&&fabs(y)<0.00001)
//		printf("(0.0, 0.0)");
//	else if (fabs(x)<0.00001)
//		printf("(0.0, %.1lf)", y);
//	else if (fabs(y)<0.00001)
//		printf("(%.1lf, 0.0)", x);
//
//	return 0;
//}


//#include <stdio.h>
//#define MAXN 10
//struct student
//{
//	int num;
//	char name[20];
//	int score;
//	char grade;
//};
//int set_grade(struct student *p, int n)
//{
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (p[i].score >= 85 && p[i].score <= 100)
//			p[i].grade = 'A';
//		else if (p[i].score >= 70 && p[i].score <= 84)
//			p[i].grade = 'B';
//		else if (p[i].score >= 60 && p[i].score <= 69)
//			p[i].grade = 'C';
//		else if (p[i].score >= 0 && p[i].score <= 59)
//		{
//			p[i].grade = 'D';
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	struct student stu[MAXN], *ptr;
//	int n, i, count;
//	ptr = stu;
//	scanf("%d\n", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
//	}
//	count = set_grade(ptr, n);
//	printf("The count for failed (<60): %d\n", count);
//	printf("The grades:\n");
//	for (i = 0; i < n; i++)
//		printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);
//	return 0;
//}


////5 00001 huanglan 78 83 75 00002 wanghai 76 80 77 00003 shenqiang 87 83 76 10001 zhangfeng 92 88 78 21987 zhangmeng 80 82 75
//struct Stu
//{
//	char number[10];
//	char name[15];
//	int a, b, c;
//};
//
//int main()
//{
//
//	int n;
//	int max = 0;
//	struct Stu std[10],maxstu;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		int sum = 0;
//		scanf("%s%s%d%d%d", &std[i].name, &std[i].number, &std[i].a, &std[i].b, &std[i].c);
//		sum += std[i].a;
//		sum += std[i].b;
//		sum += std[i].c;
//		if (sum>max)
//		{
//			max = sum;
//			maxstu = std[i];
//		}
//	}
//	printf("%s %s %d", maxstu.name, maxstu.number, max);
//	return 0;
//}




////3 zhang 19850403 13912345678 wang 19821020 +86-0571-88018448 qian 19840619 13609876543
//struct friend
//{
//	char name[11];
//	char bir[10];
//	char phone[30];
//};
//
//int main()
//{
//	char name[11];
//	char bir[10];
//	char phone[30];
//	struct friend fri[10],tmp;
//	int n;
//	scanf("%d", &n);
//	getchar();
//	for (int i = 0; i < n;i++)
//	{
//		scanf("%s%s%s", name, bir, phone);
//		strcpy(fri[i].name , name);
//		strcpy(fri[i].bir, bir);
//		strcpy(fri[i].phone, phone);
//	}
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			if (strcmp(fri[j].bir, fri[j + 1].bir)>0)
//			{
//				tmp = fri[j];
//				fri[j] = fri[j+1];
//				fri[j + 1] = tmp;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%s %s %s\n", fri[i].name, fri[i].bir, fri[i].phone);
//	}
//
//
//	return 0;
//}

//1/2 3/4
//struct number
//{
//	int up;
//	int low;
//};
//
//int main()
//{
//	char ch;
//	struct number num1, num2;
//	scanf("%d%c%d", &num1.up, &ch, &num1.low);
//	scanf("%d%c%d", &num2.up, &ch, &num2.low);
//	if (num1.up*num2.low < num1.low*num2.up)
//	{
//		printf("%d/%d < %d/%d\n", num1.up, num1.low, num2.up, num2.low);
//	}
//	else if (num1.up*num2.low == num1.low*num2.up)
//	{
//		printf("%d/%d = %d/%d\n", num1.up, num1.low, num2.up, num2.low);
//	}
//	else
//	{
//		printf("%d/%d > %d/%d\n", num1.up, num1.low, num2.up, num2.low);
//	}
//
//	return 0;
//}


////3.5 -2.7 -13.9 8.7
//int main()
//{
//	double x1, y1, x2, y2, x, y;
//	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
//	x = x1 + x2;
//	y = y1 + y2;
//	if ((x*y) != 0)
//		printf("(%.1lf, %.1lf)\n", x, y);
//	else if (fabs(x)<0.00001&&fabs(y)<0.00001)
//		printf("(0.0, 0.0)\n");
//	else if (fabs(x)<0.00001)
//		printf("(0.0, %.1lf)\n", y);
//	else if (fabs(y)<0.00001)
//		printf("(%.1lf, 0.0)\n", x);
//	return 0;
//}

//struct Birthday
//{
//	int year;
//	int month;
//	int day;
//};
////6 1980 5 6 1981 8 3 1980 3 19 1980 5 3 1983 9 12 1981 11 23
//int main()
//{
//	struct Birthday stu[20];
//	struct Birthday secondlow;
//	int t,y,m,d,minyear=99999,sum=0;
//	int mindate = 99999, sceonddate = 99999;
//	scanf("%d", &t);
//	for (int i = 0; i < t; i++)
//	{
//		scanf("%d %d %d", &y, &m, &d);
//		stu[i].year = y;
//		stu[i].month = m;
//		stu[i].day = d;
//		if (y < minyear)
//			minyear = y;
//	}
//	for (int i = 0; i < t; i++)
//	{
//		sum = sum + (stu[i].year - minyear) * 365;
//		sum += (stu[i].month * 30);
//		sum += stu[i].day;
//		if (sum < mindate)
//			mindate = sum;
//		sum = 0;
//	}
//	sum = 0;
//	for (int i = 0; i < t; i++)
//	{
//		sum = sum + (stu[i].year - minyear) * 365;
//		sum += (stu[i].month * 30);
//		sum += stu[i].day;
//		if (sum < sceonddate&&sum>mindate)
//		{
//			sceonddate = sum;
//			secondlow = stu[i];
//		}
//		sum = 0;
//	}
//	printf("%d-%d-%d\n", secondlow.year, secondlow.month, secondlow.day);
//
//	return 0;
//}




//int main()
//{
//	char str[100];
//	scanf("%s", str);
//	int len = strlen(str);//算长度
//	int sum = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (str[i] >= 'a'&&str[i] <= 'z')
//		{
//			sum = sum + (str[i] - 'a' + 97);
//		}
//		else if (str[i] >= 'A'&&str[i] <= 'Z')
//		{
//			sum = sum + (str[i] - 'A' + 65);
//		}
//	}
//	printf("%04d\n", sum);
//
//}
