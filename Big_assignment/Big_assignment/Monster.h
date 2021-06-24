#pragma once
#include<iostream>
using namespace std;
class Monster
{
protected:
	int rank;
	int HP;
	int damage;
	int money;
	int exp;
public:
	Monster();
	Monster(int rank_val);

	friend class Ultraman;
	virtual void lose();
	virtual void Display();
	int Getrank();
	int GetHP();
	int Getdamage();
	int Getmoney();
	int Getexp();
	virtual void attacked(int damage);

};

class Boss :public Monster
{
	int count;
public:
	Boss();
	int XP();
	virtual void lose();
	virtual void Display();
	virtual void attacked(int damage);
};


