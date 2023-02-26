#pragma once
#include"Monster.h"

#include<iostream>
using namespace std;
class Ultraman
{
protected:
	int rank;
	int HP;
	int damage;
	int money;
	int exp;
public:
	Ultraman(int rank_val);

	int escape();

	void restore();
	void win(int m, int e);
	void upgrade();

	void Display();
	friend ostream& operator<<(ostream& out, Ultraman& Uobj);//重载输出
	void operator++();//重载++
	void operator--();//重载--
	bool operator<(Monster& Mon);//重载<
	bool operator==(Monster& Mon);//重载==
	void attacked(int damage);

	int Getrank();
	int GetHP();
	int Getdamage();
	int Getmoney();
	int Getexp();

};
