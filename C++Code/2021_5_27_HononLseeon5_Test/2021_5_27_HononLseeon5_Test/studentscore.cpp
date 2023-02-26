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
//		return score > rhs.score;    //小顶堆，降序。成绩小者优先出队列，输出升序
//	}
//
//
//};
//
//struct studentcmp
//{
//	bool operator()(const student &lhs, const student &rhs)
//	{
//		return lhs.score < rhs.score;   //大顶堆，升序。成绩大者优先出队列，输出降序
//	}
//};
//
//int main()
//{
//	priority_queue<student, vector<student>, greater<student>> q;   //operator> , 升序
//	//priority_queue<student> q;   //默认less, operator<, 
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
