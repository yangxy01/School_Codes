//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str;
//	string strxx="x^2";
//	string strx = "x";
//	string str1,str2,str3;
//	while (cin >> str)
//	{
//		int a = 0, b = 0, c = 0;
//		int pos1, pos2, pos3;
//		pos1 = str.find(strxx);
//		if (pos1 == string::npos)//如果没有a
//		{
//			pos2 = str.find(strx);
//			if (pos2 == string::npos)//如果没有b
//			{
//				if (str[0] == '-')
//				{
//					str = str.substr(1);
//					c = stoi(str);
//					c = -c;
//				}
//				else
//				{
//					if (str.size())
//					c = stoi(str);
//				}
//			}
//			else
//			{
//				str2 = str.substr(0, pos2);
//				if (str2.length() == 1) { b = -1; }
//				else if(str2.length() == 0){ b = 1; }
//				else
//				{
//					if (str2[0] == '-')
//					{
//						str2 = str2.substr(1);
//						b = stoi(str2);
//						b = -b;
//					}
//					else
//					{
//						b = stoi(str2);
//					}
//				}
//				str = str.substr(pos2+1);
//				if (str.size())
//				{
//					if (str[0] == '-')
//					{
//						str = str.substr(1);
//						c = stoi(str);
//						c = -c;
//					}
//					else
//					{
//						str = str.substr(1);
//						c = stoi(str);
//					}
//				}
//			}
//		}
//		else
//		{
//			str1 = str.substr(0, pos1);
//			if (str1.length() == 1)
//			{
//				if(str1=="-")
//				{
//					a = -1;
//				}
//				else
//				{
//					a = stoi(str1);
//				}
//			}
//			else
//			{
//				if (str1[0] == '-')
//				{
//					str1 = str1.substr(1);
//					a = stoi(str1);
//					a = -a;
//				}
//				else
//				{
//					if (str1.size())
//						a = stoi(str1);
//					else
//						a = 1;
//				}
//			}
//			
//
//			str = str.substr(pos1 + 3);
//			pos2 = str.find(strx);
//			if (pos2 == string::npos)//如果没有b
//			{
//				if (str[0] == '-')
//				{
//					str = str.substr(1);
//					c = stoi(str);
//					c = -c;
//				}
//				else
//				{
//					if(str.size())
//					c = stoi(str);
//				}
//			}
//			else
//			{
//				str2 = str.substr(0, pos2);
//				if (str2.length() == 1)
//				{
//					if (str2 == "-")
//						b = -1;
//					else
//						b = 1;
//				}
//				else
//				{
//					if (str2[0] == '-')
//					{
//						str2 = str2.substr(1);
//						b = stoi(str2);
//						b = -b;
//					}
//					else
//					{
//						b = stoi(str2);
//					}
//				}
//				str = str.substr(pos2 + 1);
//				if (str.size())
//				{
//					if (str[0] == '-')
//					{
//						str = str.substr(1);
//						c = stoi(str);
//						c = -c;
//					}
//					else
//					{
//						str = str.substr(1);
//						c = stoi(str);
//					}
//				}
//				
//			}
//		}
//		cout << a << " " << b << " " << c << endl;
//	}
//
//	return 0;
//}