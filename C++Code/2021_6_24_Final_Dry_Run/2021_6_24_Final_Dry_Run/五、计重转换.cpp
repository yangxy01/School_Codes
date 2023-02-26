//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include <cstring>
//using namespace std;
//
//class CN; //��ǰ����
//class EN; //��ǰ����
//class Weight
//{ //������
//protected:
//	char kind[20]; //��������
//	int gram; //��
//public:
//	Weight(char tk[] = "no name", int tg = 0)
//	{
//		strcpy(kind, tk);
//		gram = tg;
//	}
//	virtual void Print(ostream & out) = 0; //�����ͬ���͵ļ�����Ϣ
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
//		out << "�й�����:" << jin << "��" << liang << "��" << qian << "Ǯ" << gram << "��" << endl;
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
//		out << "Ӣ������:" << bang << "��" << angsi << "��˾" << dalan << "����" << gram << "��" << endl;
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
//int main()//������
//{
//	int tw;
//	CN cn(0, 0, 0, 0, "�й�����");
//	cin >> tw;
//	cn.Convert(tw); //������Ŀ���ת���й�����
//	cout << cn;
//	//����Ӣ�����������en
//
//	//���������Ӧ������˾���������ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind
//	EN en(0, 0, 0, 0, "Ӣ������");
//	cin >> tw;
//	en.Convert(tw); //������Ŀ���ת��Ӣ������
//	cout << en;
//	cn = en; //��Ӣ������ת���й�����
//	cout << cn;
//	return 0;
//
//}
//
//
//
