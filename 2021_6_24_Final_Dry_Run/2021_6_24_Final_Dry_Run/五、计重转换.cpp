//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include <cstring>
//using namespace std;
//
//class CN; //提前声明
//class EN; //提前声明
//class Weight
//{ //抽象类
//protected:
//	char kind[20]; //计重类型
//	int gram; //克
//public:
//	Weight(char tk[] = "no name", int tg = 0)
//	{
//		strcpy(kind, tk);
//		gram = tg;
//	}
//	virtual void Print(ostream & out) = 0; //输出不同类型的计重信息
//};
//
//class CN : public Weight 
//{ 
//protected:
//	int jin,liang, qian;
//public:
//	CN(int j, int l, int q, int tg = 0,char tk[] = "no name") :Weight(tk, tg)
//	{
//		jin=j;
//		liang = l;
//		qian = q;
//	}
//	void Convert(int g)
//	{
//		jin = g / 500;
//		g -= (jin * 500);
//		liang = g / 50;
//		g -= (liang * 50);
//		qian = g / 5;
//		g -= (qian * 5);
//		gram = g;
//	}
//	virtual void Print(ostream & out) 
//	{
//		out << "中国计重:" << jin << "斤" << liang << "两" << qian << "钱" << gram << "克" << endl;
//	}
//	CN& operator=(EN& e);
//};
//
//class EN : public Weight 
//{ 
//protected:
//	int bang, angsi, dalan;
//public:
//	EN(int b, int a, int d, int tg = 0, char tk[] = "no name") :Weight(tk, tg)
//	{
//		bang=b;
//		angsi = a;
//		dalan = d;
//	}
//	void Convert(int g)
//	{
//		bang = g/ 512;
//		g-= (bang * 512);
//		angsi = g / 32;
//		g -= (angsi * 32);
//		dalan = g / 2;
//		g -= (dalan * 2);
//		gram = g;
//	}
//	int getGram()
//	{
//		return gram + bang * 512 + angsi * 32 + dalan * 2;
//	}
//	virtual void Print(ostream & out) 
//	{
//		out << "英国计重:" << bang << "磅" << angsi << "盎司" << dalan << "打兰" << gram << "克" << endl;
//	}
//};
//CN& CN::operator=(EN& e)
//{
//	int newgram = e.getGram();
//	this->Convert(newgram);
//	return *this;
//}
//
//ostream& operator<<(ostream&out, Weight& W)
//{
//	W.Print(out);
//	return out;
//}
//
//int main()//主函数
//{
//	int tw;
//	CN cn(0, 0, 0, 0, "中国计重");
//	cin >> tw;
//	cn.Convert(tw); //把输入的克数转成中国计重
//	cout << cn;
//	//创建英国计重类对象en
//
//	//构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
//	EN en(0, 0, 0, 0, "英国计重");
//	cin >> tw;
//	en.Convert(tw); //把输入的克数转成英国计重
//	cout << en;
//	cn = en; //把英国计重转成中国计重
//	cout << cn;
//	return 0;
//
//}
//
//
//
