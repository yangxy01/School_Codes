#include"Monster.h"

//----------Monster-------------------
Monster::Monster()
{
	rank = 0;
	HP = 0;
	damage = 0;
	money = 0;
	exp = 0;
}
Monster::Monster(int rank_val)
{
	rank = rank_val;
	HP = 20 * rank_val;
	damage = 2 * rank_val;
	money = 10 * rank_val;
	exp = 10 * rank_val;
}

void Monster::Display()
{
	cout << "¹ÖÊÞ×´Ì¬(rank=" << rank << " hp=" << HP
		<< " damage=" << damage << " exp=" << exp
		<< " money=" << money << ")" << endl;
}
void Monster::lose(){ cout << "Boss!Help!" << endl; }

int Monster::Getrank() { return rank; }
int Monster::GetHP() { return HP; }
int Monster::Getdamage() { return damage; }
int Monster::Getmoney() { return money; }
int Monster::Getexp() { return exp; }
void Monster::attacked(int damage) { HP -= damage; }




//----------Boss-------------------
Boss::Boss()
{
	count = 0;
	rank = 10;
	HP = 300;
	damage = 50;
	money = 1001;
	exp = 1000;
}
int Boss::XP() { cout << "XP*****" << endl; return damage * 3; }
void Boss::Display()
{
	cout << "Boss¹ÖÊÞ×´Ì¬(rank=" << rank << " hp=" << HP
		<< " damage=" << damage << " exp=" << exp
		<< " money=" << money << ")" << endl;
}
void Boss::lose() { cout << "I'll be back!" << endl; }
void Boss::attacked(int damage) 
{
	HP -= damage;
	count++;
	if (count == 5)
	{
		count = 0;
		Monster::attacked(XP());
	}	
}





////----------NMonster-------------------
//NMonster::NMonster(int rank_val)
//{
//	rank = rank_val;
//	HP = 10 * rank_val;
//	damage = 2 * rank_val;
//	money = 10 * rank_val;
//	exp = 10 * rank_val;
//}
//
//void NMonster::Display()
//{
//	cout << "rank=" << rank << " hp=" << HP << " damage=" << damage << " exp="
//		<< exp << " money=" << money << endl;
//}
//
//int NMonster::Getrank() { return rank; }
//int NMonster::GetHP() { return HP; }
//int NMonster::Getdamage() { return damage; }
//int NMonster::Getmoney() { return money; }
//int NMonster::Getexp() { return exp; }
//
//void NMonster::attacked(int damage) { HP -= damage; }
//
//
//
////------------AMonster-----------------
//AMonster::AMonster(int rank_val)
//{
//	rank = rank_val;
//	HP = 5 * rank_val;
//	damage = 4 * rank_val;
//	money = 10 * rank_val;
//	exp = 10 * rank_val;
//}
//
//void AMonster::Display()
//{
//	cout << "rank=" << rank << " hp=" << HP << " damage=" << damage << " exp="
//		<< exp << " money=" << money << endl;
//}
//void AMonster::attacked(int damage) { HP -= damage; }
//
//int AMonster::Getrank() { return rank; }
//int AMonster::GetHP() { return HP; }
//int AMonster::Getdamage() 
//{ 
//	return damage; 
//}
//int AMonster::Getmoney() { return money; }
//int AMonster::Getexp() { return exp; }
//
//
//
//
////------------DMonster-----------------
//DMonster::DMonster(int rank_val) 
//{
//	rank = rank_val;
//	HP = 20 * rank_val;
//	damage = rank_val;
//	money = 10 * rank_val;
//	exp = 10 * rank_val;
//}
//
//void DMonster::Display()
//{
//	cout << "rank=" << rank << " hp=" << HP << " damage=" << damage << " exp="
//		<< exp << " money=" << money << endl;
//}
//void DMonster::attacked(int damage) { HP -= (damage/2); }
//
//int DMonster::Getrank() { return rank; }
//int DMonster::GetHP() { return HP; }
//int DMonster::Getdamage() { return damage; }
//int DMonster::Getmoney() { return money ;}
//int DMonster::Getexp() { return exp ; }
//
//
//
//
////------------SMonster-----------------
//SMonster::SMonster(int rank_val)
//{
//	rank = rank_val;
//	HP = 10 * rank_val;
//	damage = rank_val;
//	money = 20 * rank_val;
//	exp = 20 * rank_val;
//}
//
//void SMonster::Display()
//{
//	cout << "rank=" << rank << " hp=" << HP << " damage=" << damage << " exp="
//		<< exp << " money=" << money << endl;
//}
//
//void SMonster::attacked(int damage) { HP -= damage; }
//
//int SMonster::Getrank() { return rank; }
//int SMonster::GetHP() { return HP; }
//int SMonster::Getdamage() { return damage; }
//int SMonster::Getmoney() { return money; }
//int SMonster::Getexp() { return exp; }