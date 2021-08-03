#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;

class Str
{
	int length;
	char*p;
public:
	Str(){ length = 0; p = NULL; }
	Str(char*s, int l) :length(l)
	{
		p=new char[length + 1];
		strcpy(p, s);
	}
	Str(const Str&obj)
	{
		p = new char[obj.length + 1];
		strcpy(p, obj.p);
		length = obj.length;
	}
	Str& operator=(const Str&obj)
	{
		if (p)delete[]p;
		p = new char[obj.length + 1];
		strcpy(p, obj.p);
		length = obj.length;
		return *this;
	}
	friend Str operator+ (const Str&s1, const Str&s2);
	friend Str operator- (const Str&s1, const Str&s2);
	void show()
	{
		cout << "length=" << length << " " << p << endl;
	}
	~Str(){ if(p)delete []p; }
};
Str operator+ (const Str&s1, const Str&s2)
{
	char*newp = new char[s1.length + s2.length+ 1];
	strcpy(newp, s1.p);
	strcat(newp, s2.p);
	Str s3(newp, s1.length + s2.length);
	delete newp;
	return s3;
}
Str operator- (const Str&s1, const Str&s2)
{
	int i = 0;
	char*pc = strstr(s1.p, s2.p);
	char*newp = new char[s1.length + 1];
	for (i = 0; s1.p+i != pc; i++)
	{
		newp[i] = s1.p[i];
	}
	newp[i] = '\0';
	Str s4(newp, strlen(newp));
	delete newp;
	return s4;

}

int main()
{
	char s[100];
	int length;

	cin.getline(s,100);
	length = strlen(s);
	Str s1(s, length);

	cin.getline(s, 100);
	length = strlen(s);
	Str s2(s, length);

	Str s3 = s1 + s2;
	s3.show();
	Str s4 = s3 - s2;
	s4.show();
	s4 = s3;
	s4.show();
	return 0;
}