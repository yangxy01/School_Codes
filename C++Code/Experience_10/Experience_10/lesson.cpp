#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstring>
using namespace std;
class CDate;
class COldID;
class CDate
{
private:
	int year, month, day;
public:
	CDate(int y = 0, int m = 0, int d = 0) :year(y), month(m), day(d){}
	CDate(CDate &day)
	{
		year = day.year;
		month = day.month;
		day = day.day;
	}
	void set(int year, int month, int day)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}
	bool check(); //检验日期是否合法
	bool isLeap();
	void print();
};

class COldID
{
private:
	char *p_id15, *p_name; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldID() :birthday(){ p_id15 = NULL; p_name = NULL; }
	COldID(char *p_idval, char *p_nameval, CDate &day) :birthday(day)
	{
		strcpy(p_id15, p_idval);
		strcpy(p_name, p_nameval);
	}
	void set(char *p_idval, char *p_nameval, int year, int month, int day)
	{
		strcpy(p_id15, p_idval);
		strcpy(p_name, p_nameval);
		birthday.set(year, month, day);
	}
	bool check(); //验证15位身份证是否合法
	void print();
	//~COldID();
};

class CNewID :public COldID
{
	char *p_id18;
	int issuey;
	int issuem;
	int issued;
	int validyear;
public:
	CNewID(){}
	CNewID(char*p_nameval, int year, int month, int day, char*p_id15, char*p_id18
		, int issuey, int issuem, int issued, int validyear)
	{
		set(p_id15, p_nameval, year, month, day);
		this->issuey = issuey;
		this->issuem = issuem;
		this->issued = issued;
		this->validyear = validyear;
		strcpy(this->p_id18, p_id18);
	}

};

int main()
{
	int t;
	char p_id15[21], p_name[21], p_id18[21];
	int year, month, day, issuey, issuem, issued, validyear;
	cin >> t;
	while (t--)
	{
		cin >> p_name >> year >> month >> day >> p_id15 >> p_id18
			>> issuey >> issuem >> issued >> validyear;
		CNewID Per(p_name, year, month, day, p_id15, p_id18, issuey, issuem, issued, validyear);


	}
	return 0;
}