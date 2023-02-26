#include<iostream>
using namespace std;

class Date
{
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 1, int month = 1, int day = 1);
	Date& operator+=(int day);
	Date operator+(int day) const;
	Date& operator-=(int day);
	Date operator-(int day) const;
	Date& operator++(int);
	Date operator++() const;

	bool operator>(const Date&d) const;
	bool operator==(const Date&d) const;
	bool operator<(const Date&d) const;
	bool operator!=(const Date&d) const;

	int operator-(const Date&d) const;

	void print() const;

};
