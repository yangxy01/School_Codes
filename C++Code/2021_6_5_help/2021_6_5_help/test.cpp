#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char str[100];
	//flag默认为0
	int i = 0, k = 0, m, n,p, j = 0;

	//输入
	while ((str[i] = getchar()) != '.')
	{
		i++;
	}
	str[i] = '\0';
	i = 0;
	//除去空格，找到第一个大写字母的位置
	while (str[i] != '\0')
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
		{
			m = i;//第一个大写字母的位置
			break;
		}
		i++;
	}

	for (i = m + 1; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
		{
			n = i;//第二个大写字母的位置
			break;
		}
	}


	
	//输出姓氏，从第二个大写字母开始输出
	for (j = n; str[j] != '\0'; j++)
	{
		if (str[j] == ' ')
			break;
		printf("%c", str[j]);
	}
	
	//输出 逗号 空格
	printf(", ");
	
	//输出名首字母
	printf("%c", str[m]);


	return 0;
}


//+-P-xf4+-1!#
//int main()
//{
//	char str[1000], str1[1000];
//	int i = 0, flag = 1, k = 0;
//	while ((str[i] = getchar()) != '#')
//	{
//		i++;
//	}
//	str[i] = '\0';
//	i = 1, k = 0;
//	while (str[i] != '\0')
//	{
//		if ((str[i] >= '0'&&str[i] <= '9') || (str[i] >= 'a'&&str[i] <= 'f') || (str[i] >= 'A'&&str[i] <= 'F'))
//		{
//			if (str[i - 1] == '-')
//			{
//				flag = -1;
//				break;
//			}
//			else if (str[i - 1] == '+')
//			{
//				flag = 1;
//				break;
//			}
//		}	
//		i++;
//	}
//	i = 0, k = 0;
//	while (str[i] != '\0')
//	{
//		if ((str[i] >= '0'&&str[i] <= '9') || (str[i] >= 'a'&&str[i] <= 'f') || (str[i] >= 'A'&&str[i] <= 'F'))
//		{
//			str1[k] = str[i];
//			k++;
//		}
//		i++;
//	}
//	str1[k] = '\0';
//
//	int number = 0;
//	for (i = 0; str1[i] != '\0'; i++)
//	{
//		if (str1[i] >= '0'&&str1[i] <= '9')  number = number * 16 + str1[i] - '0';
//		else if (str1[i] >= 'a'&&str1[i] <= 'f')  number = number * 16 + str1[i] - 'a' + 10;
//		else if (str1[i] >= 'A'&&str1[i] <= 'F')  number = number * 16 + str1[i] - 'A' + 10;
//	}
//	if (flag == -1)
//	{
//		printf("%d\n", -number);
//	}
//	if (flag == 1)
//	{
//		printf("%d\n", number);
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//int main()
//{
//	int n, m, x1, x2, y1, y2, i, j, k, count = 0;
//	int flag = 1;
//	char a[20][20];
//	scanf("%d", &n);
//	getchar();
//	for (i = 0; i < 2 * n; i++)
//	{
//		for (j = 0; j < 2 * n; j++)
//		{
//			scanf("%c", &a[i][j]);
//			getchar();
//		}
//	}
//	scanf("%d", &m);
//	for (k = 0; k < m; k++)
//	{
//		flag = 1;
//		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//		if ((a[x1 - 1][y1 - 1] == a[x2 - 1][y2 - 1]) && (a[x1 - 1][y1 - 1] != '*'))
//		{
//			a[x1 - 1][y1 - 1] = '*';
//			a[x2 - 1][y2 - 1] = '*';
//			for (i = 0; i < 2 * n; i++)
//			{
//				for (j = 0; j < 2 * n; j++)
//				{
//					if (a[i][j] != '*')
//						flag = 0;
//				}
//			}
//			if (flag == 1)
//			{
//				printf("Congratulations!\n");
//				break;
//			}
//			for (i = 0; i < 2 * n; i++)
//			{
//				for (j = 0; j < 2 * n - 1; j++)
//				{
//					printf("%c ", a[i][j]);
//				}
//				printf("%c\n", a[i][j]);
//			}
//		}
//
//		else
//		{
//			count++;
//			printf("Uh-oh\n");
//			if (count == 3)
//			{
//				printf("Game Over\n");
//				break;
//			}
//					
//		}
//		
//	}
//
//}
///*
//2
//I T I T
//Y T I A
//T A T Y
//I K K T
//5
//1 1 4 4
//1 1 2 3
//1 1 2 3
//2 2 4 1
//2 2 3 3
//
//*/
//
//
////int main()
////{
////	int n, m, x1, x2, y1, y2, i, j, k, count = 0;
////	int flag = 1;
////	char a[20][20];
////	scanf("%d", &n);
////	getchar();
////	for (i = 0; i < 2*n; i++)
////	{
////		for (j = 0; j < 2*n; j++)
////		{
////			scanf("%c", &a[i][j]);
////			getchar();
////		}
////	}
////	scanf("%d", &m);
////	for (k = 0; k < m; k++)
////	{
////		flag = 1;
////		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
////		if (a[x1 - 1][y1 - 1] == a[x2 - 1][y2 - 1])
////		{
////			a[x1 - 1][y1 - 1] = '*';
////			a[x2 - 1][y2 - 1] = '*';
////			for (i = 0; i < 2 * n; i++)
////			{
////				for (j = 0; j < 2 * n; j++)
////				{
////					if (a[i][j] != '*')
////						flag = 0;
////				}
////			}
////			if (flag == 1)
////			{
////				printf("Congratulations!\n");
////				break;
////			}
////			{
////				for (i = 0; i < 2 * n; i++)
////				{
////					for (j = 0; j < 2 * n-1; j++)
////					{
////						printf("%c ", a[i][j]);
////					}
////					printf("%c\n", a[i][j]);				
////				}
////			}
////		}
////		else 
////		{
////			printf("Uh-oh\n");
////			count++;
////		}
////		if (count == 3)
////		{
////			printf("Game Over\n");
////			break;
////		}
////		
////	}
////}
///*
//2
//I T I T
//Y T I A
//T A T Y
//I K K T
//11
//1 1 1 3
//4 2 4 3
//3 1 4 2
//2 2 1 2
//3 1 2 4
//4 4 3 1
//2 1 3 4
//3 3 1 4
//4 1 2 3
//2 4 3 2
//1 1 2 2
//*/