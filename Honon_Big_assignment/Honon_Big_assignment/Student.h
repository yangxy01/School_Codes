#pragma once
#include<iostream>
#include <fstream>
/*
*文件名：[Student.h]
* 作者：杨翔裕
* 描述：接口，结构体声明
* 开发环境：VS2019
*/
#include <algorithm>
#include<list>
#include<string>
using namespace std;

struct student
{
	string name;
	string number;
	string sex;
	int age;
};

//1.从文档中读取学生信息存到链表
void LoadDate();
//2.打印班级学生信息
void Display();
//3.统计学生人数
void CountStudent();
//4.查找学生信息
void FindStudent();
//5.增加学生信息
void AddStudent();
//6.修改学生信息
void ChangeStudent();
//7.删除学生信息
void DeleteStudent();
//8.按学号排升序
void SortStudent();
