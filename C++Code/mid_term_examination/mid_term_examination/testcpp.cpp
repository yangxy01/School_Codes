#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//E. ����ң�أ���̬+��Ԫ��������ģ�⡿
class Remote;
class TV
{
	int vol;
	int channel;
	int mode;
public:
	TV(){ vol = 50; channel = 99; mode = 1; }
	friend class Remote;
};
class Remote
{
	static int DVDnum;
public:
	static int getDVDnum();
	void change(TV&p, int m, int chan, int vol)
	{
		vol += p.vol;
		if (vol <= 0)p.vol = 0;
		else if (vol >= 100)p.vol = 100;
		else p.vol = vol;

		if (m == 2)
		{
			p.mode = 2;
			if (p.vol>0)
			DVDnum++;
			
		}
		else
		{
			p.channel = chan;
			p.mode = 1;
		}
		
	}
	void display(TV&p)
	{
		if (p.mode == 2)cout << "DVDģʽ";
		else cout << "TVģʽ";
		cout << "--Ƶ��" << p.channel << "--����" << p.vol << endl;
	}
};
int Remote::DVDnum = 0;
int Remote::getDVDnum()
{
	return DVDnum;
}

int main()
{
	int n;
	cin >> n;
	TV*ptv = new TV[n];
	int t,i,mode,channel,vol;
	cin >> t;
	Remote R;
	while (t--)
	{
		cin >> i >> mode >> channel >> vol;
		R.change(ptv[i], mode, channel, vol);
		cout << "��"<<i<<"�ŵ��ӻ�--";
		R.display(ptv[i]);
	}
	cout << "���ŵ��ӵĵ��ӻ�����Ϊ" << n - Remote::getDVDnum()<<endl;
	cout << "����DVD�ĵ��ӻ�����Ϊ" << Remote::getDVDnum()<<endl;
	delete[]ptv;
	return 0;
}






//C. ����绰��������������������ģ�⡿
//class tel
//{
//	int num;
//	char type;
//	int state;
//	string name;
//public:
//	tel(int n = 0, char t = 'c', int s = 0, string names = "0") :num(n), type(t), state(s), name(names)
//	{
//		cout << num<<" constructed." << endl;
//	}
//	void print()
//	{
//		cout << "Phone=" << num << "--Type=" << type;
//		if (state == 1)cout << "--State=use";
//		else cout << "--State=unuse";
//		cout << "--Owner=" << name << endl;
//	}
//	~tel()
//	{
//		cout <<num<< " destructed." << endl;
//	}
//	int getnum()
//	{
//		return num;
//	}
//};
//
//int main()
//{
//	int num;
//	char type;
//	int state;
//	string name;
//	cin >> num >> type >> state >> name;
//	tel t1(num, type, state, name);
//	cin >> num >> type >> state >> name;
//	tel t2(num, type, state, name);
//	cin >> num >> type >> state >> name;
//	tel t3(num, type, state, name);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> num;
//		if (num == t1.getnum())
//		{
//			t1.print();
//		}
//		else if (num == t2.getnum())
//		{
//			t2.print();
//		}
//		else if (num == t3.getnum())
//		{
//			t3.print();
//		}
//		else
//			cout << "wrong number." << endl;
//
//	}
//}