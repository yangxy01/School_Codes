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
	friend ostream& operator<<(ostream& out, Ultraman& Uobj);//�������
	void operator++();//����++
	void operator--();//����--
	bool operator<(Monster& Mon);//����<
	bool operator==(Monster& Mon);//����==
	void attacked(int damage);

	int Getrank();
	int GetHP();
	int Getdamage();
	int Getmoney();
	int Getexp();

};
