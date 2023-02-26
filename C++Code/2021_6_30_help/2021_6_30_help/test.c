#define _CRT_SECURE_NO_WARNINGS 1
#include<stream.h>

int main()
{
	int m, n, i, j, tmp;
	scanf("%d %d", &m, &n);
	int a[100][100];
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = a[j][i];
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d", a[i][j]);
		}
	}
	return 0;
}