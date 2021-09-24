//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//struct Stock
//{
//	int year;
//	int month;
//	int day;
//	string state;
//	int price1;
//	int price2;
//};
//
//bool cmp(const Stock &a, const Stock &b)
//{
//	return a.day < b.day;
//}
//
//int main()
//{
//	int N, M;
//	int year;
//	int month;
//	int day;
//	string state;
//	int price1,price2 = 0;
//	char ch;
//	cin >> N >> M;
//	vector<Stock> vec1;
//	vector<Stock> vec2;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> year >> ch >> month >> ch >> day;
//		cin >> state >> price1 >> price2;
//		Stock S = { year, month, day, state, price1, price2 };
//		if (S.state == "open")
//			vec1.push_back(S);
//		else
//			vec2.push_back(S);
//	}
//	sort(vec1.begin(), vec1.end(), cmp);
//	sort(vec2.begin(), vec2.end(), cmp);
//	for (int i = M - 1; i < vec1.size(); i++)
//	{
//		int sum1 = 0,sum2=0;
//		for (int k = i, j = 0; j < M; j++,k--)
//		{
//			sum1 += vec1[k].price1;
//			sum2 += vec1[k].price2;
//		}
//		sum1 /= M;
//		sum2 /= M;
//		cout << vec1[i].year << "/" << vec1[i].month << "/" << vec1[i].day << " ";
//		cout << "open" << " " << sum1 << " " << sum2 << endl;
//	}
//
//	for (int i = M - 1; i < vec2.size(); i++)
//	{
//		int sum1 = 0, sum2 = 0;
//		for (int k = i, j = 0; j < M; j++, k--)
//		{
//			sum1 += vec2[k].price1;
//			sum2 += vec2[k].price2;
//		}
//		sum1 /= M;
//		sum2 /= M;
//		cout << vec2[i].year << "/" << vec2[i].month << "/" << vec2[i].day << " ";
//		cout << "close" << " " << sum1 << " " << sum2 << endl;
//	}
//
//	return 0;
//}