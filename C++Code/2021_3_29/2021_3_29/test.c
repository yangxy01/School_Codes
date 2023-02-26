#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()//观察整型数放入浮点数
{
	int a = 9;
	float b = a;
	float c = 100.25;
	printf("%f\n", a);
}



//int main()
//{
//	double area, s, permimeter, a, b, c;
//	scanf("%lf %lf %lf", &a, &b, &c);
//	if (a + b > c && a + c>b && b + c>a)
//	{
//		s = ((a + b + c) / 2);
//		area = sqrt(s*(s - a)*(s - b)*(s - c));
//		permimeter = (a + b + c);
//		printf("area = %.2lf; perimeter = %.2lf\n", area, permimeter);
//	}
//	else
//		printf("These sides do not correspond to a valid triangle\n");
//	return 0;
//}