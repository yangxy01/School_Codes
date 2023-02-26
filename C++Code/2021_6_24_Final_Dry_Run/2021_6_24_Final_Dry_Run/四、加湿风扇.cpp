#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
class Appliances
{
protected:
	int num, power;
public:
	Appliances(int n = 0, int p = 0) :num(n), power(p){}
	void Display(){ cout << "num" << " " << power << endl; }
};

class fans :virtual public Appliances
{
protected:
	int direction,grade;
public:
	fans(int n = 0, int p = 0, int d=0, int g=0)
		:Appliances(n, p), direction(d), grade(g){}
	void Dircontrol(int k){ direction = k; }
	void Gracontrol(int k){ grade = k; }
};

class Humidifier :virtual public Appliances
{
protected:
	float now, max;
public:
	Humidifier(int n = 0, int p = 0, float nowv=0.0,float maxv=0.0)
		:Appliances(n, p), now(nowv), max(maxv){}
	int warning()
	{
		if (now >= max*0.5){ return 1; }
		else if (now < max*0.1){ return 3; }
		else return 2;
	}	
};

class HumidFans :public fans, public Humidifier
{
protected:
	int level;
public:
	HumidFans(int n = 0, int p = 0, int d = 0, int g = 0, float nowv = 0.0, float maxv = 0.0, int levelv = 0)
		:fans(n, p, d, g), Humidifier(n, p, nowv, maxv), Appliances(n, p)
	{
		level = levelv;
	}
	void AdjustLevel(int k)
	{
		level = k;
		if (k == 1)
		{
			Dircontrol(0);
			Gracontrol(k);
		}
		else if (k == 2)
		{
			Dircontrol(1);
			Gracontrol(k);
		}
		else if (k == 3)
		{
			Dircontrol(1);
			Gracontrol(k);
		}
	}
	void Display()
	{
		cout << "��ʪ����--��λ" << level << endl;
		cout << "���" << num << "--����" << power << "W" << endl;
		if (direction == 0){ cout << "���򴵷�"; }
		else if (direction == 1){ cout << "��ת����"; }
		cout << "--����"<<grade<<"��" << endl;
		cout << "ʵ��ˮ����"<<now<<"��";
		if (warning() == 1){ cout << "--ˮ������" << endl; }
		else if(warning() == 2){ cout << "--ˮ��ƫ��" << endl; }
		else if (warning() == 3){ cout << "--ˮ������" << endl; }
	}
};



int main()
{
	int t, num, power, direction, grade,level;
	float now, max;
	cin >> t;
	while (t--)
	{
		cin >> num >> power >> direction >> grade >> now >> max >> level;
		HumidFans H(num, power, direction, grade, now, max, level);
		cin >> level;
		H.AdjustLevel(level);
		H.Display(); 
	}

	return 0;
}