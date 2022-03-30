//#include<iostream>
//#include<cmath>
//using namespace std;
//
//double BinarySearch(double num)
//{
//	double left = 0;
//	double right = num;
//	double mid = (left + right) / 2;
//	while (abs(mid * mid - num) >= 0.00001)
//	{
//		if (mid * mid > num)
//			right = mid;
//		else if (mid * mid < num)
//			left = mid;
//		mid = (left + right) / 2;
//	}
//	return mid;
//	return 0;
//}
//
//int main()
//{
//	int m;
//	cin >> m;
//	while (m--)
//	{
//		double num;
//		cin >> num;
//		double ret= BinarySearch(num);
//		printf("%.3lf\n", ret);
//	}
//	return 0;
//}