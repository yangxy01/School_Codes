#include<iostream>
using namespace std;

struct Node
{
	int coe;
	int index;
	Node* next;
};

class SList
{
private:
	Node* head;
public:
	SList()
	{
		head = BuyNode(0,0);
	}
	~SList()
	{
		if (head)
		{
			Node* p = head;
			Node* q = NULL;
			while (p)
			{
				q = p;
				p = p->next;
				delete q;
			}
		}
	}
	Node* GetPointer(int i)
	{
		if (i == 0)
			return head;
		Node* cur = head->next;
		int j = 1;
		while (cur && j < i)
		{
			cur = cur->next;
			j++;
		}
		if (cur == NULL)
			return NULL;
		return cur;
	}
	Node* BuyNode(int x,int y)
	{
		Node* newnode = new Node;
		newnode->coe = x;
		newnode->index = y;
		newnode->next = NULL;
		return newnode;
	}

	void PushBack(int x, int y)
	{
		Node* newnode = BuyNode(x,y);
		Node* tail = head;
		while (tail->next) { tail = tail->next; }
		tail->next = newnode;
	}

	int GetLength()
	{
		Node* p = head->next;
		int count = 0;
		while (p)
		{
			count++;
			p = p->next;
		}
		return count;
	}

	bool DeleteItem(int i)
	{
		if (i <= 0 || i > GetLength())
			return false;
		Node* p = GetPointer(i - 1);
		Node* q = p->next;
		p->next = p->next->next;
		if (q)
			delete q;
		return true;
	}
	bool InsertItem(int i, int x, int y)
	{
		if (i <= 0 || i > GetLength() + 1)
			return false;

		Node* newnode = BuyNode(x,y);
		if (head->next == NULL)
			PushBack(x,y);
		else
		{
			Node* p = GetPointer(i - 1);
			newnode->next = p->next;
			p->next = newnode;
		}
		return true;
	}

	
	void Traverse()
	{
		Node* q = head;
		Node* p = head->next;
		while (p)
		{
			if (p->coe == 0)
			{
				q->next = p->next;
				delete p;
				p = q->next;
				continue;
			}
			else
			{
				q = p;
				p = p->next;
			}
		}

		Node* cur = head->next;
		while (cur->next)
		{
			if (cur->coe == 0)
			{
				cur = cur->next;
				continue;
			}
			if (cur->coe < 0)
				cout << "(" << cur->coe << ")";
			else
				cout << cur->coe;
			if (cur->index < 0)
				cout << "x^" << "(" << cur->index << ")";
			else if (cur->index > 0)
				cout << "x^" << cur->index;
			cout << " + ";
			cur = cur->next;
		}

		if (cur->coe == 0)
			return;
		if (cur->coe < 0)
			cout << "(" << cur->coe << ")";
		else
			cout << cur->coe;
		if (cur->index < 0)
			cout << "x^" << "(" << cur->index << ")";
		else if (cur->index > 0)
			cout << "x^" << cur->index;
		cout << endl;
	}

	

};

void Add(Node* La, Node* Lb)
{
	int coe;
	int index;
	SList ls;
	while (La && Lb)
	{
		if (La->index < Lb->index)
		{
			ls.PushBack(La->coe,La->index);
			La = La->next;
		}
		else if(La->index > Lb->index)
		{
			ls.PushBack(Lb->coe, Lb->index);
			Lb = Lb->next;
		}
		else
		{
			coe = La->coe + Lb->coe;
			index = La->index;
			ls.PushBack(coe, index);

			La = La->next;
			Lb = Lb->next;
		}
	}
	while (La)
	{
		ls.PushBack(La->coe, La->index);
		La = La->next;
	}
	while (Lb)
	{
		ls.PushBack(Lb->coe, Lb->index);
		Lb = Lb->next;
	}
	ls.Traverse();

}

int main()
{

	int n, t;
	int coe;
	int index;
	cin >> t;
	while (t--)
	{
		SList ls1;
		SList ls2;
		cin >> n;
		while (n--)
		{
			cin >> coe >> index;
			ls1.PushBack(coe, index);
		}
		ls1.Traverse();
		cin >> n;
		while (n--)
		{
			cin >> coe >> index;
			ls2.PushBack(coe, index);
		}
		ls2.Traverse();
		Add(ls1.GetPointer(1), ls2.GetPointer(1));
	}
	
	return 0;
}
