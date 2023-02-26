//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//#include<string>
//#include <algorithm>
//using namespace std;
//struct Student
//{
//	string name;
//	int age;
//	int score;
//	Student(string name, int age, int score)
//	{
//		this->name = name;
//		this->age = age;
//		this->score = score;
//	}
//};
//
//struct cmp
//{
//	bool operator()(Student& a, Student& b)
//	{
//		if (a.score != b.score)return a.score<b.score;
//		if (a.name != b.name)return a.name < b.name;
//		return a.age<b.age;
//		//if (a.score == b.score)
//		//{
//		//	if (a.name == b.name)
//		//	{
//		//		return a.age<b.age;
//		//	}
//		//	else
//		//		return a.name < b.name;
//		//}
//		////如果分数相同则按号码升序排列
//		//else
//		//	return a.score<b.score;
//	}
//};
//
//
//void display(Student a)
//{
//	cout << a.name << " " << a.age << " " << a.score << endl;
//}
//
//int main()
//{
//	int score;
//	string name;
//	int age;
//	vector<Student>vec;
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> name >> age >> score;
//		vec.push_back(Student(name, age, score));
//	}
//	sort(vec.begin(), vec.end(), cmp());
//	for_each(vec.begin(), vec.end(), [](Student a)
//	{
//		cout << a.name << " " << a.age << " " << a.score << endl;
//	});
//
//	return 0;
//}
//
