#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//Lucky
int isLucky(char word[],int len)
{
	int count1[26] = { 0 };
	int count2[26] = { 0 };
	int num = 0,max=0,min=99;
	for (int i = 0; i < len; i++)
	{
		if (word[i] >= 'a'&&word[i] <= 'z')
		{
			num = word[i] - 'a';
			count1[num]++;
		}
		else
		{
			num = word[i] - 'A';
			count2[num]++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (count1[i]>0 && count1[i] > max)
			max = count1[i];
		if (count1[i]>0 && count1[i] < min)
			min = count1[i];
	}
	int sub = max - min;
	if (sub > 2)
	{
		for (int i = 2; i < sub; i++)
		{
			if (sub%i == 0)
				return -1;
		}
		return sub;
	}
	else if (sub == 2)
		return 2;
	else
		return -1;
}

int main()
{
	char word[30];
	int N;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%s", word);
		int len = strlen(word);
		int ret = isLucky(word,len);
		if (ret == -1)
			printf("No Answer\n-1\n");
		else
		{
			printf("Lucky Word\n%d\n",ret);
		}
	}

	return 0;
}



////ÆË¿ËÅÆ
//int main()
//{
//	int CardS[14] = { 0 }, CardH[14] = { 0 }, CardC[14] = { 0 }, CardD[14] = { 0 };
//	char ch;
//	int n,num;
//	scanf("%d", &n);
//	getchar();
//	while (n--)
//	{
//		scanf("%c%d", &ch,&num);
//		getchar();
//		if (ch == 'S')
//			CardS[num - 1]++;
//		else if (ch == 'H')
//			CardH[num - 1]++;
//		else if (ch == 'C')
//			CardC[num - 1]++;
//		else if (ch == 'D')
//			CardD[num - 1]++;
//	}
//	for (int i = 0; i <13; i++)
//	{
//		if (CardS[i] == 0)
//			printf("S %d\n", i+1);
//	}
//	for (int i = 0; i <13; i++)
//	{
//		if (CardH[i] == 0)
//			printf("H %d\n", i + 1);
//	}
//	for (int i = 0; i <13; i++)
//	{
//		if (CardC[i] == 0)
//			printf("C %d\n", i + 1);
//	}
//	for (int i = 0; i <13; i++)
//	{
//		if (CardD[i] == 0)
//			printf("D %d\n", i + 1);
//	}
//
//	return 0;
//}


//¾ØÕó×ªÖÃ
//int main()
//{
//	int t, m, n, i, j, k, a[20][20], b[20][20];
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d %d", &n, &m);
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < m; j++)
//			{
//				scanf("%d", &a[i][j]);
//			}
//		}
//		for (i = 0; i < n; i++)
//		{
//
//			for (j = 0; j < m; j++)
//			{
//				b[j][i] = a[i][j];
//			}
//			
//		}
//		for (i = 0; i < m; i++)
//		{
//			for (j = 0; j < n - 1; j++)
//			{
//				printf("%d ", b[i][j]);
//			}
//			printf("%d\n", b[i][j]);
//		}
//	}
//	
//
//	return 0;
//}