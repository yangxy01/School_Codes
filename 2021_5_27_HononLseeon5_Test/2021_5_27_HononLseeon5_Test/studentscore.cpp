//#define _CRT_SECURE_NO_WARNINGS 1
//#include <queue>
//#include <iostream>
//#include <string>
//#include<functional>
//#include <utility>
//using namespace std;
//
//struct student
//{
//	string name;
//	int score;
//	bool operator > (const student &rhs)  const
//	{
//		return score > rhs.score;    //С���ѣ����򡣳ɼ�С�����ȳ����У��������
//	}
//
//
//};
//
//struct studentcmp
//{
//	bool operator()(const student &lhs, const student &rhs)
//	{
//		return lhs.score < rhs.score;   //�󶥶ѣ����򡣳ɼ��������ȳ����У��������
//	}
//};
//
//int main()
//{
//	priority_queue<student, vector<student>, greater<student>> q;   //operator> , ����
//	//priority_queue<student> q;   //Ĭ��less, operator<, 
//	//priority_queue<student, vector<student>, studentcmp> q;   
//
//
//	string name;
//	int n, score;
//	student s;
//
//
//	cin >> n;
//	while (n--)
//	{
//		cin >> name >> score;
//		q.push(student{ name, score });
//	}
//
//	while (!q.empty())
//	{
//		s = q.top();
//		q.pop();
//		cout << s.name << " " << s.score << endl;
//	}
//
//	system("pause");
//	return 0;
//}
//
///*
//3
//liming 97
//wangwu 95
//zhaoliang 100
//*/
//
