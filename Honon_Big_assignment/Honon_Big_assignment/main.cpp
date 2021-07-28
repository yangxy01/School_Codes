/*
*文件名：[main.cpp]
* 作者：杨翔裕
* 描述：提供菜单和调用接口
* 开发环境：VS2019
*/
//注：文件读写为绝对路径
#include"Student.h"
void menu();//菜单


int main() 
{
	while (1)
	{
		menu();//打印菜单
		
		char ch = getchar();//读取一个字符整数
		cin.ignore(100,'\n');
		if (ch == '9') { cout << "[即将退出程序]" << endl; break;}//退出系统
		cout << "Loading....." << endl;
		switch (ch)
		{
			case '1'://1.导入学生信息
				LoadDate();
				break;
			case '2'://2.打印学生信息
				Display();
				break;
			case '3'://3.统计学生人数
				CountStudent();
				break;
			case '4'://4.查找学生信息
				FindStudent();
				break;
			case '5'://5.增加学生信息
				AddStudent();
				break;
			case '6'://6.修改学生信息
				ChangeStudent();
				break;
			case '7'://7.删除学生信息
				DeleteStudent();
				break;
			case '8'://8.按学号排升序
				SortStudent();
				break;
			default:
				system("cls");    //清屏
				cout << "[输入错误，请重新输入]" << endl;
				system("pause");  //暂停
				system("cls");    //清屏
				break;
		}
		
	}

	return 0;
}


void menu()
{
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*\t\t 学生信息管理系统\t\t*" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*\t\t 1.导入学生信息\t\t\t*" << endl;
	cout << "\t\t*\t\t 2.打印学生信息\t\t\t*" << endl;
	cout << "\t\t*\t\t 3.统计学生人数\t\t\t*" << endl;
	cout << "\t\t*\t\t 4.读取学生信息\t\t\t*" << endl;
	cout << "\t\t*\t\t 5.增加学生信息\t\t\t*" << endl;
	cout << "\t\t*\t\t 6.修改学生信息\t\t\t*" << endl;
	cout << "\t\t*\t\t 7.删除学生信息\t\t\t*" << endl;
	cout << "\t\t*\t\t 8.按学号排升序\t\t\t*" << endl;
	cout << "\t\t*\t\t 9.退出系统\t\t\t*" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t \t\t 请选择功能->\t\t\t" << endl;
	
}