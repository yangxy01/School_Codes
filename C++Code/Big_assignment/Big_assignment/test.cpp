#include"Monster.h"
#include"Ultraman.h"

int main()
{
	int ograd;//�������ĵȼ�ֵ
	cin >> ograd;
	Ultraman Uman(ograd);
	int t;
	cin >> t;//����Ҫ��Ĺ��޸�����
	while (t--&& Uman.GetHP()>10)//ֻҪ������û��Ҳû���ܣ��ͼ�������޵�ս��
	{
		cout << Uman;//��ʾ����������ǰ״̬
		Monster* p;
		char c = 0;
		while (1) 
		{
			cin >> c;
			if (c == 'B') { p = new Boss(); break; }
			else if (c == 'M') { int r; cin >> r; p = new Monster(r); break; }
			else cout << "�����������������" << endl;
		}
		p->Display();	//��ʾ���޵�ǰ״̬

		int pick; cin >> pick;//�Ƿ�ʰȡħ����,��0ʰȡ��0��ʰȡ
		if (pick) 
		{//���ʰȡħ����
			while (1) 
			{
				cin >> c;//����Ҫʹ�õ�ħ����
				if (c == 'G') 
				{
					cout << "****���³�˫****" << endl;
					++Uman;
					cout << "****�ɹ�����****" << endl;
					cout << Uman;
					break;
				}
				else if (c == 'B') 
				{
					cout << "****��������****" << endl;
					--Uman;
					cout << "****���Ҽ���****" << endl;
					cout << Uman;
					break;
				}
				else if (c == 'X') 
				{
					cout << "****���Ǵ�****" << endl;
					if (Uman < (*p)) cout << "****�󹦸��****" << endl;
					else cout << "****��δ�ɹ�****" << endl;
					cout << Uman;
					break;
				}
				else if (c == 'Y') 
				{
					cout << "****��Ե���****" << endl;
					if (Uman == (*p))cout << "****��Ե�з�****" << endl;
					else cout << "****��Ե�޷�****" << endl;
					cout << Uman;
					break;
				}
				else cout << "����������ħ��������" << endl;
			}
		}

		//����ս����־flagΪtrue������ս��ѭ�����������£�
		int flag = 1;
		while (flag) //��ս��δ�����ͼ���
		{
			p->attacked(Uman.Getdamage());//����������1�Σ����ޱ�����		
			if (p->GetHP() > 0)  //����û��
			{
				Uman.attacked(p->Getdamage()/2);//���޷���1��
				if (Uman.GetHP() > 10)		//����������ֵ���ڵ㣬������
					Uman.restore();//��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
				else 
				{	//���������ܣ������"lose"���س�
					Uman.escape();
					cout << "lose" << endl;
					Uman.Display();//���������״̬		
					flag = 0;//ֹͣս��					
				}
			}
			else //��������
			{
				Uman.win(p->Getmoney(), p->Getexp());	//������ʤ���������"win"���س�
				cout << "win" << endl;
				Uman.upgrade();//����������
				p->lose();//�������ս����Ϣ
				flag = 0;//ֹͣս��	
			}
		}


	}
	system("pause");
	return 0;
}

