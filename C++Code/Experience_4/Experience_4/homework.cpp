#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>

using namespace std;

//struct Node
//{
//	int num;
//	Node*pnext = NULL;
//};
//Node*head;
//
//void create(int n);//����������
//Node* getnode();//�����ڵ㺯��
//Node* out(int&count, int k, int m);//���ֺ���
//
//int main()//H. Լɪ�򻷣��ṹ��+ѭ������
//{
//	int k, m, n;
//	while (cin >> n >> k >> m)
//	{
//		create(n);//����������
//		int count = 0;
//		while (count < n)
//		{
//			Node*p = out(count, k, m);//���ֺ���
//			cout << p->num << " ";
//		}
//		cout << endl;
//			
//	}
//	return 0;
//}
//
//void create(int n)//����������
//{
//	head = getnode();//�����ڵ㺯��
//	Node*pE = head;
//	for (int i = 1; i < n; i++)
//	{
//		Node*pS = getnode();
//		pE->pnext=pS;
//		pE = pS;
//	}
//	pE->pnext = head;//�γɱջ�
//
//}
//
//Node*getnode()//�����ڵ㺯��
//{
//	static int i = 1;
//	Node*p = new Node;
//	p->num = i;
//	p->pnext = NULL;
//	return p;
//}
//
//Node* out(int&count, int k, int m)//���ֺ���
//{
//	Node*p = head;
//	int flag = 1;
//
//}








//struct Node
//{
//	char str[30];
//	Node*pnext = NULL;
//};
//Node*head;
//
//void create(int n);//����������
//Node* getnode();//�����ڵ㺯��
//void showlist();//��ӡ����
//void bubblesort();//ð������
//
//
//
//int main()//G. �����ð�����򣨽ṹ��+����
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		create(n);//����������
//		bubblesort();//ð������
//		showlist();//��ӡ����
//	}
//	return 0;
//}
//
//
//void create(int n)//����������
//{
//	head = getnode();//�����ڵ㺯��
//	Node*pE = head;
//	for (int i = 1; i < n; i++)
//	{
//		Node*pS = getnode();
//		pE->pnext=pS;
//		pE = pS;
//	}
//
//}
//
//Node*getnode()//�����ڵ㺯��
//{
//	char s[30];
//	cin >> s;
//	Node*p = new Node;
//	strcpy(p->str, s);
//	p->pnext = NULL;
//	return p;
//}
//
//void showlist()//��ӡ����
//{
//	int count = 0;
//	Node*p = head;
//		
//	while (p)
//	{
//		cout << p->str << endl;
//		p = p->pnext;
//	}
//	cout << endl;
//}
//
//void bubblesort()//ð������
//{
//	Node *ps = NULL;
//	Node *pe = NULL;
//	ps = head;
//	while (ps != pe)
//	{
//		while (ps->pnext != pe)
//		{
//			
//			if (strcmp(ps->str, ps->pnext->str)<0)
//			{
//				char tmp[30];
//				strcmp(tmp, ps->str);
//				strcmp(ps->str, ps->pnext->str);
//				strcmp(ps->pnext->str, tmp);
//			}
//			ps = ps->pnext;
//		}
//		pe = ps;
//		ps = head;
//	}
//}







struct Node
{
	int num;
	Node*pnext = NULL;
};
Node*head;

Node*getnode();//�����ڵ㺯��
void create(int n);//����������
void reverse();//��ת����
void showlist();//��ӡ����
void  Destroy();//ɾ������


int main()//F. ����ԭ�ط�ת������)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		create(n);//����������
		if (n>1)
		reverse();//��ת����
		showlist();//��ӡ����
		Destroy();//ɾ������
	}
	return 0;
}

void create(int n)//����������
{
	head = getnode();//�����ڵ㺯��
	Node*pE = head;
	for (int i = 1; i < n; i++)
	{
		Node*pS = getnode();
		pE->pnext=pS;
		pE = pS;
	}

}

Node*getnode()//�����ڵ㺯��
{
	int e;
	cin >> e;
	Node*p = new Node;
	p->num = e;
	p->pnext = NULL;
	return p;
}

void reverse()//��ת����
{
	Node*pStart = head;
	Node*p = head;
	Node*pE2 = NULL;
	Node*pE1 = NULL;
	while (p->pnext)
		p = p->pnext;
	head = p;
	pE2 = head;
	p = pStart;
	while (p->pnext != pE2)
		p = p->pnext;
	pE1 = p;

	while (pStart != pE1)
	{
		pE2->pnext = pE1;
		pE2 = pE1;
		p = pStart;
		while (p->pnext != pE1)
			p = p->pnext;
		pE1 = p;
	}
	pE2->pnext = pE1;
	pE2 = pE1;
	pStart->pnext = NULL;
}

void showlist()//��ӡ����
{
	int count = 0;
	Node*p = head;
		
	while (p)
	{
		cout << p->num << " ";
		p = p->pnext;
	}
	cout << endl;
}

void Destroy()//ɾ������
{
	Node*p, *q;
	p = head;
	while (p != NULL)
	{
		q = p;
		p = p->pnext;
		delete q;
	}
}






//class Deletesame
//{
//public:
//	struct Node
//	{
//		int num;
//		Node*pnext = NULL;
//	};
//	Node*head = NULL;
//	void create(int n)//����������
//	{
//		head = getnode();//�����ڵ㺯��
//		Node*pE = head;
//		for (int i = 1; i < n; i++)
//		{
//			Node*pS = getnode();
//			pE->pnext = pS;
//			pE = pS;
//		}
//	}
//	Node*getnode()//�����ڵ㺯��
//	{
//		int e;
//		cin >> e;
//		Node*p = new Node;
//		p->num = e;
//		p->pnext = NULL;
//		return p;
//	}
//
//	void Deletelist()//ɾ���ظ��ڵ㺯��
//	{
//		Node *p1, *p2;
//		p1= head;
//		while (p1)
//		{
//			p2 = p1;
//			while (p2->pnext)
//			{
//				int flag = 0;
//				if (p2->pnext->num == p1->num)
//				{
//					Node *p = p2->pnext;
//					p2->pnext = p2->pnext->pnext;
//					delete(p);
//					p = NULL;
//					flag = 1;
//				}
//				if (flag == 0)
//					p2 = p2->pnext;
//			}
//			p1 = p1->pnext;
//		}
//	}
//
//
//	void showlist()//��ӡ����
//	{
//		int count = 0;
//		Node*p = head;
//		
//		while (p)
//		{
//			cout << p->num ;
//			if (p->pnext  == NULL)
//				cout << endl;
//			else
//				cout << " ";
//			p = p->pnext;
//		}
//	}
//
//	void  Destroy()//ɾ������
//	{
//		Node*p, *q;
//		p = head;
//		while (p != NULL)
//		{
//			q = p;
//			p = p->pnext;
//			delete q;
//		}
//	}
//};
//



//int main()//E. ɾ���ظ�Ԫ�أ��ṹ��+����+�ࣩ
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		Deletesame del;
//		del.create(n);
//		del.Deletelist();
//		del.showlist();
//		del.Destroy();
//
//	}
//	return 0;
//}







//struct Node
//{
//	int num;
//	Node*pnext = NULL;
//};
//Node*head = NULL;//����ȫ������ָ��
//
//void create(int n);//����������
//Node*getnode();//�����ڵ㺯��
//int DeleteList(Node *H, int i);//ɾ������
//void showlist();//��ӡ����
//Node* find(int i);//���Һ���
//
//
//int main()//D. �������ɾ��(�ṹ��+����)
//{
//	int n,m,j,num;
//	cin >> n;
//	create(n);//����������
//	showlist();//��ӡ����
//	cin >> m;
//	for (j = 0; j < m; j++)
//	{
//		cin >> num;
//		if (DeleteList(head, num))//����ɾ������
//			showlist();//��ӡ����
//		else
//			cout << "error" << endl;
//	}
//	return 0;
//}
//
//void create(int n)//����������
//{
//	head = getnode();//�����ڵ㺯��
//	Node*pE = head;
//	for (int i = 1; i < n; i++)
//	{
//		Node*pS = getnode();
//		pE->pnext=pS;
//		pE = pS;
//	}
//}
//
//Node*getnode()//�����ڵ㺯��
//{
//	int e;
//	cin >> e;
//	Node*p = new Node;
//	p->num = e;
//	p->pnext = NULL;
//	return p;
//}
//
//int DeleteList(Node *H, int i)//ɾ������
//{
//	Node*p = find(i);//���ò��Һ���
//	if (p == NULL)
//		return 0;
//	else
//	{
//		Node*pGuard = head;
//		while (pGuard->pnext != p)
//			pGuard = pGuard->pnext;
//		pGuard->pnext = p->pnext;
//		return 1;
//	}
//}
//
//void showlist()//��ӡ����
//{
//	int count = 0;
//	Node*p = head;
//	while (p)
//	{
//		p = p->pnext;
//		count++;
//	}
//	cout << count << " ";
//	p = head;
//	while (p)
//	{
//		cout << p->num ;
//		if (p->pnext  == NULL)
//			cout << endl;
//		else
//			cout << " ";
//		p = p->pnext;
//	}
//}
//
//Node* find(int i)//���Һ���
//{
//	Node*p = head;
//	int count = 1;
//	while (p)
//	{
//		if (i == count)
//			return p;
//		else
//		{
//			p = p->pnext;
//			count++;
//		}
//	}
//	return NULL;
//}





//struct Node
//{
//	int num;
//	Node*pnext = NULL;
//};
//Node*head = NULL;//����ȫ������ָ��
//
//void create();//����������
//Node* Insert(int i, int e);//���뺯��
//void showlist();//�������
//
//
//int main()//C. ������Ĳ���(�ṹ��+����)
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		create();//����������
//	}
//	return 0;
//}
//
//void create()//����������
//{
//	int i, e;
//	cin >> i >> e;
//	Node*p = Insert(i, e);
//	if (p == NULL)
//		cout << "error" <<endl;
//	else
//	{
//		showlist();//�������
//	}
//}
//
//Node* Insert(int i, int e)//���뺯��
//{
//	static int flag = 0;
//	static int count = 0;
//	if (i < 1 || i > count+1)
//		return NULL;
//	else if (i == 1 && flag==0)
//	{
//		Node*p = new Node;
//		head = p;
//		p->num = e;
//		p->pnext = NULL;
//		flag = 1;
//		count++;
//		return p;
//	}
//	else if (i == 1 && flag == 1)
//	{
//		Node*p = new Node;
//		p->num = e;
//		p->pnext = head;
//		head = p;
//		count++;
//		return p;
//	}
//	else
//	{
//		Node*p = new Node;
//		p->num = e;
//		Node*pE = head;
//		for (int j = 0; j < i-2; j++)
//		{
//			pE = pE->pnext;
//		}
//		p->pnext = pE->pnext ;
//		pE->pnext = p;
//		
//		count++;
//		return p;
//	}
//}
//
//void showlist()//�������
//{
//	Node*p = head;
//	while (p)
//	{
//		cout << p->num;
//		if (p->pnext == NULL)
//			cout << endl;
//		else
//			cout << " ";
//		p = p->pnext;
//	}
//}






//struct Node
//{
//	int num;
//	Node*pnext = NULL;
//};
//Node*head = NULL;//����ȫ������ָ��
//
//void create(int n);//����������
//Node* getNode();//�ڵ㺯��
//Node *Find(Node *H, int i);//���Һ���
//void Showlist();//�������
//
//int main()
//{
//	int n,m,i,num;
//	cin >> n;
//	create(n);//��������
//	Showlist();//�������
//	cin >> m;
//	for (i = 0; i < m; i++)
//	{
//		cin >> num;
//		Node *p=Find(head, num);
//		if (p == NULL)
//			cout << "error" << endl;
//		else
//			cout << p->num << endl;
//	}
//	return 0;
//}
//
//
//void create(int n)//����������
//{
//	//1.�㶨����
//	head = getNode();
//	Node*pE = head,*pS;
//
//	//2.�����½ڵ�
//	for (int i = 1; i < n; i++)
//	{
//		pS = getNode();
//		pE->pnext = pS;
//		pE = pS;
//	}
//	
//}
//
//
//Node* getNode()//�ڵ㺯��
//{
//	int n;
//	cin >> n;
//	Node*p = new Node;
//	p->num = n;
//	p->pnext = NULL;
//	return p;
//}
//
//
//void Showlist()//�������
//{
//	int count = 0;
//	for (Node*p = head; p; p = p->pnext)
//		count++;
//	cout << count << " ";
//	for (Node*p = head; p; p = p->pnext)
//		cout << p->num << " ";
//	cout << endl;
//}
//
//
//Node *Find(Node *H, int i)//���Һ���
//{
//	Node*p1 = H;
//	Node*p2 = H;
//	int L = 0;
//	while (p1)//���㵥�����L
//	{
//		L++;
//		p1 = p1->pnext;
//	}
//	if (i > L || i < 1)
//		return NULL;
//	else
//	{
//		L = 0;
//		while (p2)//����ͬ
//		{
//			L++;
//			if (L == i)
//				return p2;
//			p2 = p2->pnext;
//		}
//	}
//}









//struct Node
//{
//	int num;
//	Node*pnext;
//};
//Node*head=NULL;//����ȫ������ָ��
//
//void create(int n);
//int Find(Node *H, int e);
//Node*getNode(int e);
//void Showlist();
//
//int main()//A. ������Ĵ���(�ṹ��+����)
//{
//	int t;
//	cin >> t;
//	while (t--)//����
//	{
//		int n;
//		cin >> n;
//		create(n);
//		Showlist();
//		cout << endl;
//	}
//	return 0;
//}
//
//void create(int n)//�����ڵ�
//{
//	int i,e;
//	cin >> e;
//	head = getNode(e);
//	Node* pE = head;
//	for (i = 1; i < n; i++)
//	{
//		cin >> e;
//		if (Find(head, e)==1)
//			continue;
//		else
//		{
//			Node* pS = getNode(e);
//			pE->pnext = pS;
//			pS->pnext = NULL;
//			pE = pS;
//		}
//	}
//}
//
//Node*getNode(int e)
//{
//	Node*p = new Node;
//	p->num = e;
//	p->pnext = NULL;
//	return p;
//}
//
//
//int Find(Node *H, int e)
//{
//	Node*p = H;
//	while (p)
//	{
//		if (p->num == e)
//			return 1;
//		else
//		{
//			p = p->pnext;
//		}
//	}
//	return 0;
//}
//
//void Showlist()//�������
//{
//	int count = 0;
//	for (Node*p = head; p; p = p->pnext)
//		count++;
//	cout << count << " ";
//	for (Node*p = head; p; p = p->pnext)
//		cout << p->num << " ";
//}