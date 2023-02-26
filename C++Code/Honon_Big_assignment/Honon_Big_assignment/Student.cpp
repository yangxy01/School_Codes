/*
*文件名：[Student.cpp]
* 作者：杨翔裕
* 描述：接口的实现
* 开发环境：VS2019
*/

#include"Student.h"

list<student> Data;

//重载比较规则
struct cmp
{
	bool operator()(student& A, student& B)
	{
		return A.number < B.number;//按学号排序
	}
};

//1.从文档中读取学生信息存到链表
//注：文件读写为绝对路径
void LoadDate()
{
	//先清屏
	system("cls");
	string name_val,number_val,sex_val;
	int age_val;
	ifstream finput("c:\\temp\\data.txt", ios::in);
	student s;
	//读取文件直到文档末尾
	while (!finput.eof())
	{
		finput >> name_val >> number_val >> sex_val >> age_val;
		//如果读取失败跳出循环
		if (finput.fail())
		{
			break;
		}
		s.name = name_val;
		s.number = number_val;
		s.sex = sex_val;
		s.age = age_val;
		Data.push_back(s);
	}
	cout << "[学生信息导入成功]" << endl;
	finput.close();
	system("pause");
	system("cls");
}

//2.打印班级学生信息
void Display()
{
	system("cls");
	//判断是否为空链表
	if (Data.empty())
		cout << "[当前系统无学生信息] 请选择->1.录入学生信息"<<endl ;
	//不是空链表进行打印
	else
	{
		cout << " ________________________________________________________" << endl;
		for (auto it : Data)
		{
			cout << "|姓名:" << it.name << "  |  "
				<< "学号:" << it.number << "  |  "
				<< "性别:" << it.sex << "  |  "
				<< "年龄:" << it.age << " |" << endl;
			cout << "|_____________|___________________|___________|__________|" << endl;
		}	
		cout << endl << "[学生信息展示完毕]" << endl;
	}
	system("pause");
	system("cls");
}

//3.统计学生人数
void CountStudent()
{
	system("cls");
	int num = Data.size();
	cout << "[学生总人数为：" << num <<"]"<< endl ;
	system("pause");
	system("cls");
}

//4.查找学生信息
void FindStudent() 
{
	system("cls");
	//判断是否为空链表
	if (Data.empty())
	{
		cout << "[当前系统无学生信息] 请选择->1.录入学生信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	string message;//用来存储输入的学号或姓名
	cout << "请输入查找学生学号或姓名：" << endl;
	cin >> message;
	cin.ignore(100, '\n');
	int flag = 1;//用于下面做判断，标记输入的名字或学号是否合法
	for (auto it : Data)
	{
		//按学号查找该学生
		if (it.number == message)
		{
			cout << " ________________________________________________________" << endl;
			cout << "|姓名:" << it.name << "  |  "
				<< "学号:" << it.number << "  |  "
				<< "性别:" << it.sex << "  |  "
				<< "年龄:" << it.age << " |" << endl;
			cout << "|_____________|___________________|___________|__________|" << endl;
			flag = 0;
			break;
		}
		//按姓名查找该学生
		else if(it.name == message)
		{
			cout << " ________________________________________________________" << endl;
			cout << "|姓名:" << it.name << "  |  "
				<< "学号:" << it.number << "  |  "
				<< "性别:" << it.sex << "  |  "
				<< "年龄:" << it.age << " |" << endl;
			cout << "|_____________|___________________|___________|__________|" << endl;
			flag = 0;
			break;
		}
	}
	if(flag)//如果无该学生
		cout << "[信息输入有误或系统中无该学生]" << endl;
	system("pause");
	system("cls");
}

//5.增加学生信息
void AddStudent()
{
	system("cls");
	string name_val, number_val, sex_val;
	int age_val,n;
	student s;
	ofstream foutput("c:\\temp\\data.txt",ios::app);
	cout << "[请输入要增加学生个数：]" << endl;
	cin >> n;
	//循环n次增加学生信息
	while (n--)
	{
		cout << "请输入学生姓名：" << endl;
		//循环直到名字读入正确
		while (1)
		{
			int flag = 1;
			cin >> name_val;
			if (name_val.length() > 8)
			{
				flag = 0;//标志着无法插入，因为该姓名不合法，最多支持四个字
				cout << "[姓名不合法,请重新输入：]" << endl;
				continue;
			}
			if (flag) { break; }
		}
		
		cout << "请输入学生学号：" << endl;
		//循环直到学号读入正确
		while (1)
		{
			int flag = 1;
			cin >> number_val;
			if (number_val.length() != 10)
			{
				cout << "[学号格式输入错误,请重新输入学号：]" << endl;
				continue;
			}
			for (auto it : Data)
			{
				if (it.number == number_val)
				{
					flag = 0;//标志着无法插入，因为该学号学生已经存在
					cout << "[该学号已存在,请重新输入学号：]" << endl;
					break;
				}
			}
			if (flag) { break; }//插入成功进行下一个学生插入
			else
			{
				continue;//插入不成功，重来
			}
		}
		

		cout << "请输入学生性别：" << endl;
		cin >> sex_val;
		cout << "请输入学生年龄：" << endl;
		cin >> age_val;
		s.name = name_val;
		s.number = number_val;
		s.sex = sex_val;
		s.age = age_val;
		Data.push_back(s);
		//更改文档中的学生资料
		foutput << name_val << " " << number_val << " " << sex_val << " " << age_val << endl;
		
		cout << " __________________________________________________________" << endl;
		cout << "|姓名:" << s.name << "    |  "
			<< "学号:" << s.number << "  |  "
			<< "性别:" << s.sex << "  |  "
			<< "年龄:" << s.age << " |" << endl;
		cout << "|_______________|___________________|___________|__________|" << endl;
		cout <<endl<< "[学生信息录入成功]" << endl;
	}
	foutput.close();
	cin.ignore(100, '\n');
	system("pause");
	system("cls");
}

//6.修改学生信息
void ChangeStudent()
{
	system("cls");
	//判断链表是否为空
	if (Data.empty())
	{
		cout << "[当前系统无学生信息] 请选择->1.录入学生信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	string name_val, number_val, sex_val;
	int age_val,flag;
	cout << "[请输入学生姓名或学号：]" << endl;
	//循环读入姓名或学号
	while (1)
	{
		string message;
		cin >> message;
		flag = 0;
		//如果输入的是学号，处理根据学号来修改,学号长度为10
		if (message.length() == 10)
		{
			//查找该学号是否存在
			for (auto it : Data)
			{
				if (it.number == message)
				{
					flag = 1;//标志着该学号学生存在
					break;
				}
			}
			//该学号学生不存在
			if (flag == 0){cout << "[该学号不存在,请重新输入学号]" << endl;  continue;}
			//该学号学生存在
			else
			{
				//开始读入修改的数据
				cout << "请输入修改后的学生姓名：" << endl;
				//循环直到名字读入正确
				while (1)
				{
					flag = 1;
					cin >> name_val;
					if (name_val.length() > 8)
					{
						flag = 0;//标志着无法插入，因为该姓名不合法，最多支持四个字
						cout << "[姓名不合法,请重新输入：]" << endl;
						continue;
					}
					if (flag) { break; }
				}
				cout << "请输入修改后的学生学号：" << endl;
				//循环直到学号读入正确
				while (1)
				{
					flag = 1;
					cin >> number_val;
					if (number_val.length() != 10)
					{
						cout << "[学号格式输入错误,请重新输入学号：]" << endl;
						continue;
					}
					for (auto it : Data)//查找修改学号是否存在
					{
						//后续修改可改为原学号
						if (it.number == number_val && number_val != message)
						{
							flag = 0;//标志着无法插入，因为该学号学生已经存在
							cout << "[该学号已存在,请重新输入：]" << endl;
							break;
						}
					}
					if (flag) { break; }//插入成功则结束
					else
					{
						continue;//插入不成功，重来
					}
				}
				cout << "请输入修改后的学生性别：" << endl;
				cin >> sex_val;
				cout << "请输入修改后的学生年龄：" << endl;
				cin >> age_val;
				for (auto&it : Data)//修改链表中该学生的信息
				{
					if (it.number == message)
					{
						it.name = name_val;
						it.number = number_val;
						it.sex = sex_val;
						it.age = age_val;
						break;
					}
				}
				//打印修改后的信息
				cout << " ________________________________________________________" << endl;
				cout << "|姓名:" << name_val << "  |  "
					<< "学号:" << number_val << "  |  "
					<< "性别:" << sex_val << "  |  "
					<< "年龄:" << age_val << " |" << endl;
				cout << "|_____________|___________________|___________|__________|" << endl;
				cout <<endl<< "[学生信息修改成功]" << endl;

				//修改原文本
				ofstream foutput("c:\\temp\\data.txt",ios::out);
				for (auto it : Data)
					foutput << it.name << " " << it.number << " " << it.sex << " " << it.age << endl;

				foutput.close();
				break;
			}
		}
		//如果输入的是姓名，处理根据姓名来修改
		else
		{
			string num;
			//循环找该学生是否存在
			for (auto it : Data)
			{
				if (it.name == message)
				{
					flag = 1;//标志着该学生存在
					num = it.number;//记住该学号，后续修改可改为原学号，即只改该学生其他信息
					break;
				}
			}
			//该学生不存在
			if (flag == 0){ cout << "[该学生不存在,请重新输入姓名]" << endl;  continue;}
			//该学生存在
			else
			{
				//开始读入修改的数据
				cout << "请输入修改后的学生姓名：" << endl;
				//循环直到名字读入正确
				while (1)
				{
					flag = 1;
					cin >> name_val;
					if (name_val.length() > 8)
					{
						flag = 0;//标志着无法插入，因为该姓名不合法，最多支持四个字
						cout << "[姓名不合法,请重新输入：]" << endl;
						continue;
					}
					if (flag) { break; }
				}
				cout << "请输入修改后的学生学号：" << endl;
				//循环直到学号读入正确
				while (1)
				{
					flag = 1;
					cin >> number_val;
					if (number_val.length() != 10)
					{
						cout << "[学号格式输入错误,请重新输入学号：]" << endl;
						continue;
					}
					//查找修改学号是否存在
					for (auto it : Data)
					{
						//后续修改可改为原学号
						if (it.number == number_val && number_val != num)
						{
							flag = 0;//标志着无法插入，因为该学号学生已经存在
							cout << "[该学号已存在,请重新输入：]" << endl;
							break;
						}
					}
					//插入成功则结束
					if (flag) { break; }
					//插入不成功，重来
					else
					{
						continue;
					}
				}
				cout << "请输入修改后的学生性别：" << endl;
				cin >> sex_val;
				cout << "请输入修改后的学生年龄：" << endl;
				cin >> age_val;
				//修改链表中该学生的信息
				for (auto &it : Data)
				{
					if (it.name == message)
					{
						it.name = name_val;
						it.number = number_val;
						it.sex = sex_val;
						it.age = age_val;
						break;
					}
				}
				//打印修改后的信息
				cout << " __________________________________________________________" << endl;
				cout << "|姓名:" << name_val << "  |  "
					<< "学号:" << number_val << "  |  "
					<< "性别:" << sex_val << "  |  "
					<< "年龄:" << age_val << " |" << endl;
				cout << "|_______________|___________________|___________|__________|" << endl;
				cout <<endl<< "[学生信息修改成功]" << endl;

				//修改原文本
				ofstream foutput("c:\\temp\\data.txt", ios::out);
				for (auto it : Data)
					foutput << it.name << " " << it.number << " " << it.sex << " " << it.age << endl;

				foutput.close();
				break;
			}
		}
	}
	cin.ignore(100, '\n');
	system("pause");
	system("cls");
}

//7.删除学生信息
void DeleteStudent()
{
	system("cls");
	//判断链表是否为空
	if (Data.empty())
	{
		cout << "[当前系统无学生信息] 请选择->1.录入学生信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	int flag;
	cout << "[请输入学生姓名或学号：]" << endl;
	//循环读入学生姓名或学号
	while (1)
	{
		string message;
		cin >> message;
		flag = 0;
		//如果输入的是学号，处理根据学号来修改
		if (message.length() == 10)
		{
			//查找该学号是否存在
			for (auto it : Data)
			{
				if (it.number == message)
				{
					flag = 1;//标志着该学号学生存在
					break;
				}
			}
			//该学号学生不存在
			if (flag == 0) { cout << "[该学号不存在,请重新输入学号]" << endl;  continue; }
			//该学号学生存在
			else
			{
				list<student>::iterator it;
				for (it = Data.begin(); it != Data.end(); it++)
				{
					if (it->number == message) { Data.erase(it); break; }
				}
				cout << "[删除成功] 请返回查看->2.打印班级学生信息" << endl;
				//修改原文本
				ofstream foutput("c:\\temp\\data.txt", ios::out);
				for (auto it : Data)
					foutput << it.name << " " << it.number << " " << it.sex << " " << it.age << endl;

				foutput.close();
				break;
			}
		}
		//如果输入的是姓名，处理根据姓名来修改
		else
		{
			string num;
			//循环查找该名字是否存在
			for (auto it : Data)
			{
				if (it.name == message)
				{
					flag = 1;//标志着该学生存在
					num = it.number;//记住该学号，后续修改可改为原学号，即只改该学生其他信息
					break;
				}
			}
			//该学生不存在
			if (flag == 0) { cout << "[该学生不存在,请重新输入姓名]" << endl;  continue; }
			//该学生存在
			else
			{
				list<student>::iterator it;
				for (it = Data.begin(); it != Data.end(); it++)
				{
					if (it->name == message) { Data.erase(it); break; }
				}
				cout << "[删除成功] 请返回查看->2.打印班级学生信息" << endl;
				//修改原文本
				ofstream foutput("c:\\temp\\data.txt", ios::out);
				for (auto it : Data)
					foutput << it.name << " " << it.number << " " << it.sex << " " << it.age << endl;

				foutput.close();
				break;
			}
		}
	}
	
	cin.ignore(100, '\n');
	system("pause");
	system("cls");
}

//8.按学号排升序
void SortStudent()
{
	system("cls");
	//判断链表是否为空
	if (Data.empty())
	{
		cout << "[当前系统无学生信息] 请选择->1.录入学生信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	//仿函数排序，升序
	Data.sort(cmp());
	cout << "[排序成功] 请返回查看->2.打印班级学生信息" << endl;
	system("pause");
	system("cls");
}
