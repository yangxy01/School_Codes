#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

inline int CorrespondingDay(int year, int month)
{
	static int a1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((month == 2) && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
	{
		return a1[month - 1]+1;
	}
	return a1[month - 1];
}

Date::Date(int year, int month, int day)
{
	if (year > 0)
		_year = year;
	else
		cout << "年输入错误" << endl;
	if (month > 0 && month<=12)
		_month = month;
	else
		cout << "月输入错误" << endl;
	if (day > 0 && day<=CorrespondingDay(year,month))
		_day = day;
	else
		cout << "日输入错误" << endl;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		day = -day;
		*this -= day;
		return *this;
	}
	_day += day;
	while (_day > CorrespondingDay(_year, _month))
	{
		_day -= CorrespondingDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)const
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		day = -day;
		*this += day;
		return *this;
	}
	_day -= day;
	while (_day<=0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += CorrespondingDay(_year, _month);	
	}
	return *this;
}

Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

Date& Date::operator++(int)
{
	*this += 1;
	return *this;
}

Date Date::operator++() const
{
	Date tmp(*this);
	tmp += 1;
	return tmp;
}

bool Date::operator>(const Date&d) const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator==(const Date&d) const
{
	return _year == d._year&&_month == d._month&&_day == d._day;
}

bool Date::operator<(const Date&d) const
{
	return !(*this>d) && !(*this == d);
}

bool Date::operator!=(const Date&d) const
{
	return !(*this==d);
}

int Date::operator-(const Date&d) const
{
	Date min = *this;
	Date max = d;
	int flag = -1;
	if (*this > d)
	{
		min = d; 
		max = *this;
		flag = 1;
	}
	int count = 0;
	while (min != max)
	{
		count++;
		min++;
	}
	return count*flag;
}

void Date::print() const
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}