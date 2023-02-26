#include"Monster.h"
#include"Ultraman.h"

int main()
{
	int ograd;//奥特曼的等级值
	cin >> ograd;
	Ultraman Uman(ograd);
	int t;
	cin >> t;//输入要打的怪兽个数数
	while (t--&& Uman.GetHP()>10)//只要奥特曼没死也没逃跑，就继续与怪兽的战斗
	{
		cout << Uman;//显示奥特曼对象当前状态
		Monster* p;
		char c = 0;
		while (1) 
		{
			cin >> c;
			if (c == 'B') { p = new Boss(); break; }
			else if (c == 'M') { int r; cin >> r; p = new Monster(r); break; }
			else cout << "请重新输入怪兽类型" << endl;
		}
		p->Display();	//显示怪兽当前状态

		int pick; cin >> pick;//是否拾取魔法袋,非0拾取，0不拾取
		if (pick) 
		{//如果拾取魔法袋
			while (1) 
			{
				cin >> c;//输入要使用的魔法袋
				if (c == 'G') 
				{
					cout << "****好事成双****" << endl;
					++Uman;
					cout << "****成功翻倍****" << endl;
					cout << Uman;
					break;
				}
				else if (c == 'B') 
				{
					cout << "****祸不单行****" << endl;
					--Uman;
					cout << "****不幸减半****" << endl;
					cout << Uman;
					break;
				}
				else if (c == 'X') 
				{
					cout << "****吸星大法****" << endl;
					if (Uman < (*p)) cout << "****大功告成****" << endl;
					else cout << "****尚未成功****" << endl;
					cout << Uman;
					break;
				}
				else if (c == 'Y') 
				{
					cout << "****有缘相会****" << endl;
					if (Uman == (*p))cout << "****有缘有分****" << endl;
					else cout << "****无缘无分****" << endl;
					cout << Uman;
					break;
				}
				else cout << "请重新输入魔法袋类型" << endl;
			}
		}

		//设置战斗标志flag为true，启动战斗循环，具体如下：
		int flag = 1;
		while (flag) //当战斗未结束就继续
		{
			p->attacked(Uman.Getdamage());//奥特曼攻击1次，怪兽被攻击		
			if (p->GetHP() > 0)  //怪兽没死
			{
				Uman.attacked(p->Getdamage()/2);//怪兽反击1次
				if (Uman.GetHP() > 10)		//奥特曼生命值大于点，不逃跑
					Uman.restore();//奥特曼回血，在方法中判断是否需要加血
				else 
				{	//奥特曼逃跑，并输出"lose"并回车
					Uman.escape();
					cout << "lose" << endl;
					Uman.Display();//输出奥特曼状态		
					flag = 0;//停止战斗					
				}
			}
			else //怪兽死了
			{
				Uman.win(p->Getmoney(), p->Getexp());	//奥特曼胜利，并输出"win"并回车
				cout << "win" << endl;
				Uman.upgrade();//奥特曼升级
				p->lose();//输出怪兽战败信息
				flag = 0;//停止战斗	
			}
		}


	}
	system("pause");
	return 0;
}

