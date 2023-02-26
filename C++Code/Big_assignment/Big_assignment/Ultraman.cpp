#include"Ultraman.h"

Ultraman::Ultraman(int rank_val)
{
	rank = rank_val;
	HP = 10 * rank_val;
	damage = 3 * rank_val;
	money = 10 * rank_val;
	exp = 0;
}

void Ultraman::Display()
{
	cout << "rank=" << rank << " hp=" << HP << " damage=" << damage << " exp="
		<< exp << " money=" << money << endl;
}
ostream& operator<<(ostream& out, Ultraman& Uobj)
{
	out << "°ÂÌØÂü×´Ì¬(rank=" << Uobj.rank << " hp=" << Uobj.HP
		<< " damage=" << Uobj.damage << " exp=" << Uobj.exp
		<< " money=" << Uobj.money << ")"<<endl;
	return out;
}
void Ultraman::operator++()//ÖØÔØ++
{
	rank*=2;
	HP = 10 * rank;
	damage = 3 * rank;
	money*=2;
	exp*=2;
}
void Ultraman::operator--()//ÖØÔØ--
{
	HP/=2;
	damage /= 2;
	money /= 2;
	exp /= 2;
}
bool Ultraman::operator<(Monster& Mon)
{
	if (Mon.Getrank() < rank)
	{
		HP += Mon.GetHP()/2;
		damage += Mon.Getdamage() / 2;
		money += Mon.Getmoney() / 2;
		exp += Mon.Getexp() / 2;
		return true;
	}
	else
		return false;
}
bool Ultraman::operator==(Monster& Mon)
{
	if (Mon.Getrank() == rank)
	{
		HP += Mon.GetHP();
		damage += Mon.Getdamage();
		money += Mon.Getmoney();
		exp += Mon.Getexp();
		return true;
	}
	else
		return false;
}
void Ultraman::attacked(int damage){ HP -= damage; }


int Ultraman::escape() 
{ 
	if (HP <= 10)
	{
		money = 0;
		return 1;
	}
	return 0;
}

void Ultraman::restore()
{
	if (HP < 5 * rank)
	{
		while (money >= 10)
		{
			HP++;
			money -= 10;
			if (HP == 10 * rank)
				break;
		}
	}
}
void Ultraman::win(int m, int e)
{
	money += m;
	exp += e;
}
void Ultraman::upgrade()
{
	while(exp >= 10 * rank)
	{
		exp -= 10 * rank;
		rank++;
		HP = 10 * rank;
		damage = 3 * rank;
	}
}

int Ultraman::Getrank() { return rank; }
int Ultraman::GetHP() { return HP; }
int Ultraman::Getdamage() { return damage; }
int Ultraman::Getmoney() { return money; }
int Ultraman::Getexp() { return exp; }
