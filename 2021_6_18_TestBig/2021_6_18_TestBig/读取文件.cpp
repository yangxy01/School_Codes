//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//class student
//{
//	string name;
//	int id;
//	string phone;
//public:
//	student() = default;
//	student(string nameval, int idval, string number) :name(nameval), id(idval), phone(number){}
//	void display()
//	{
//		cout << name << " " << id << " " << phone << endl;
//	}
//};
//
//int main()
//{
//	int n, id;
//	string name, phone;
//	cin >> n;
//	student *stud = new student[n];
//
//	fstream file("c:\\temp\\studinfo.txt", ios::out | ios::binary);
//	for (auto i = 0; i < n; i++)
//	{
//		cin >> id >> name >> phone;
//		stud[i] = student(name, id, phone);
//		file.write((char*)(stud + i), sizeof(student));
//	}
//
//	file.close();
//
//	file.open("c:\\temp\\studinfo.txt", ios::in | ios::binary);
//	student s;
//	while (file.peek() != EOF)
//	{
//		file.read((char *)&s, sizeof(student));
//		s.display();
//	}
//
//	file.seekg(0, ios::beg);
//	file.read((char*)&s, sizeof(student));
//	s.display();
//
//	file.seekg(5 * sizeof(student), ios::cur);
//	file.read((char*)&s, sizeof(student));
//	s.display();
//
//	system("pause");
//
//}

#include<iostream>
using namespace std;
#include<string>
int main()
{
	string s1 = "Ò»¸ö";
	cout << s1.length()<<endl;
}