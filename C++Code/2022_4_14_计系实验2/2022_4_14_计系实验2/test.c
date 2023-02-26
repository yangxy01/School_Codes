#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int isAsciiDigit(int x) {
	int a = 0x30;
	int b = 0x39;
	int c = (x + (~a + 1)) >> 31;
	printf("c:%d\n", (~c & 1));
	int d = (b + (~x + 1)) >> 31;
	printf("d:%d\n", (~d & 1));
	return ~(c & 1) & ~(d & 1);
}
int isLessOrEqual(int x, int y) {
	int a = (x >> 31) & 1;
	int b = (y >> 31) & 1;
	int c = !(~a & b);

	return c & (!(y + (~x + 1)) >> 31 & 1);
}

int conditional(int x, int y, int z) {
	int a = 0xFF + (0xFF << 8);
	int b = a + (a << 16);
	int c = !(x & b);
	int d = (c | ((x >> 31) & 1));//ÊÇ·ñ<=0
	
	x = d & z;
	x = !d & y;
	return x;
}

int main()
{
	/*int ret = conditional(2, 4,5);
	printf("answer:%d\n", ret);*/

	int x = 4, y = 5;
	while (1)
	{
		scanf("%d%d", &x, &y);
		int ret = isLessOrEqual(x, y);
		printf("answer:%d\n", ret);
	}
	
}