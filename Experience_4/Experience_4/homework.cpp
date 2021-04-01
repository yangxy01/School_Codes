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
//void create(int n);//创建链表函数
//Node* getnode();//创建节点函数
//Node* out(int&count, int k, int m);//出局函数
//
//int main()//H. 约瑟夫环（结构体+循环链表）
//{
//	int k, m, n;
//	while (cin >> n >> k >> m)
//	{
//		create(n);//创建链表函数
//		int count = 0;
//		while (count < n)
//		{
//			Node*p = out(count, k, m);//出局函数
//			cout << p->num << " ";
//		}
//		cout << endl;
//			
//	}
//	return 0;
//}
//
//void create(int n)//创建链表函数
//{
//	head = getnode();//创建节点函数
//	Node*pE = head;
//	for (int i = 1; i < n; i++)
//	{
//		Node*pS = getnode();
//		pE->pnext=pS;
//		pE = pS;
//	}
//	pE->pnext = head;//形成闭环
//
//}
//
//Node*getnode()//创建节点函数
//{
//	static int i = 1;
//	Node*p = new Node;
//	p->num = i;
//	p->pnext = NULL;
//	return p;
//}
//
//Node* out(int&count, int k, int m)//出局函数
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
//void create(int n);//创建链表函数
//Node* getnode();//创建节点函数
//void showlist();//打印函数
//void bubblesort();//冒泡排序
//
//
//
//int main()//G. 链表的冒泡排序（结构体+链表）
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		create(n);//创建链表函数
//		bubblesort();//冒泡排序
//		showlist();//打印函数
//	}
//	return 0;
//}
//
//
//void create(int n)//创建链表函数
//{
//	head = getnode();//创建节点函数
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
//Node*getnode()//创建节点函数
//{
//	char s[30];
//	cin >> s;
//	Node*p = new Node;
//	strcpy(p->str, s);
//	p->pnext = NULL;
//	return p;
//}
//
//void showlist()//打印函数
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
//void bubblesort()//冒泡排序
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

Node*getnode();//创建节点函数
void create(int n);//创建链表函数
void reverse();//反转函数
void showlist();//打印函数
void  Destroy();//删除函数


int main()//F. 链表原地反转（链表)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		create(n);//创建链表函数
		if (n>1)
		reverse();//反转函数
		showlist();//打印函数
		Destroy();//删除函数
	}
	return 0;
}

void create(int n)//创建链表函数
{
	head = getnode();//创建节点函数
	Node*pE = head;
	for (int i = 1; i < n; i++)
	{
		Node*pS = getnode();
		pE->pnext=pS;
		pE = pS;
	}

}

Node*getnode()//创建节点函数
{
	int e;
	cin >> e;
	Node*p = new Node;
	p->num = e;
	p->pnext = NULL;
	return p;
}

void reverse()//反转函数
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

void showlist()//打印函数
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

void Destroy()//删除函数
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
//	void create(int n)//创建链表函数
//	{
//		head = getnode();//创建节点函数
//		Node*pE = head;
//		for (int i = 1; i < n; i++)
//		{
//			Node*pS = getnode();
//			pE->pnext = pS;
//			pE = pS;
//		}
//	}
//	Node*getnode()//创建节点函数
//	{
//		int e;
//		cin >> e;
//		Node*p = new Node;
//		p->num = e;
//		p->pnext = NULL;
//		return p;
//	}
//
//	void Deletelist()//删除重复节点函数
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
//	void showlist()//打印函数
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
//	void  Destroy()//删除函数
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



//int main()//E. 删除重复元素（结构体+链表+类）
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
//Node*head = NULL;//创建全局链首指针
//
//void create(int n);//创建链表函数
//Node*getnode();//创建节点函数
//int DeleteList(Node *H, int i);//删除函数
//void showlist();//打印函数
//Node* find(int i);//查找函数
//
//
//int main()//D. 单链表的删除(结构体+链表)
//{
//	int n,m,j,num;
//	cin >> n;
//	create(n);//创建链表函数
//	showlist();//打印函数
//	cin >> m;
//	for (j = 0; j < m; j++)
//	{
//		cin >> num;
//		if (DeleteList(head, num))//调用删除函数
//			showlist();//打印函数
//		else
//			cout << "error" << endl;
//	}
//	return 0;
//}
//
//void create(int n)//创建链表函数
//{
//	head = getnode();//创建节点函数
//	Node*pE = head;
//	for (int i = 1; i < n; i++)
//	{
//		Node*pS = getnode();
//		pE->pnext=pS;
//		pE = pS;
//	}
//}
//
//Node*getnode()//创建节点函数
//{
//	int e;
//	cin >> e;
//	Node*p = new Node;
//	p->num = e;
//	p->pnext = NULL;
//	return p;
//}
//
//int DeleteList(Node *H, int i)//删除函数
//{
//	Node*p = find(i);//调用查找函数
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
//void showlist()//打印函数
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
//Node* find(int i)//查找函数
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
//Node*head = NULL;//创建全局链首指针
//
//void create();//创建链表函数
//Node* Insert(int i, int e);//插入函数
//void showlist();//输出函数
//
//
//int main()//C. 单链表的插入(结构体+链表)
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		create();//创建链表函数
//	}
//	return 0;
//}
//
//void create()//创建链表函数
//{
//	int i, e;
//	cin >> i >> e;
//	Node*p = Insert(i, e);
//	if (p == NULL)
//		cout << "error" <<endl;
//	else
//	{
//		showlist();//输出函数
//	}
//}
//
//Node* Insert(int i, int e)//插入函数
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
//void showlist()//输出函数
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
//Node*head = NULL;//定义全局链首指针
//
//void create(int n);//创建链表函数
//Node* getNode();//节点函数
//Node *Find(Node *H, int i);//查找函数
//void Showlist();//输出函数
//
//int main()
//{
//	int n,m,i,num;
//	cin >> n;
//	create(n);//创建链表
//	Showlist();//输出函数
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
//void create(int n)//创建链表函数
//{
//	//1.搞定链首
//	head = getNode();
//	Node*pE = head,*pS;
//
//	//2.连接新节点
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
//Node* getNode()//节点函数
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
//void Showlist()//输出函数
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
//Node *Find(Node *H, int i)//查找函数
//{
//	Node*p1 = H;
//	Node*p2 = H;
//	int L = 0;
//	while (p1)//计算单链表表长L
//	{
//		L++;
//		p1 = p1->pnext;
//	}
//	if (i > L || i < 1)
//		return NULL;
//	else
//	{
//		L = 0;
//		while (p2)//找相同
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
//Node*head=NULL;//定义全局链首指针
//
//void create(int n);
//int Find(Node *H, int e);
//Node*getNode(int e);
//void Showlist();
//
//int main()//A. 单链表的创建(结构体+链表)
//{
//	int t;
//	cin >> t;
//	while (t--)//组数
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
//void create(int n)//创建节点
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
//void Showlist()//输出函数
//{
//	int count = 0;
//	for (Node*p = head; p; p = p->pnext)
//		count++;
//	cout << count << " ";
//	for (Node*p = head; p; p = p->pnext)
//		cout << p->num << " ";
//}