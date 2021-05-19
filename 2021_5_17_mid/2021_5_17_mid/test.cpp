#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class CStack
{
	int*a;
	int size;
	int top;
public:
	CStack();
	CStack(int s);
	CStack(CStack&r_s);
	void push(int val);
	int pop();
	~CStack();
};
CStack::CStack(){ size = 10; top = 0; }
CStack::CStack(int s)
{
	a = new int[s];
	top = 0;
	size = s;
	cout << "Constructor." << endl;
}
CStack::CStack(CStack&r_s)
{
	delete[]a;
	a = new int[r_s.size];
	top = r_s.top;
	for (int i = 0; i < top; i++)
		a[i] = r_s.a[i];
}
CStack::~CStack()
{
	cout << "Destructor." << endl;
	delete[]a;
}
void CStack::push(int val)
{
	a[top] = val;
	top++;
}
int CStack::pop()
{
	top--;
	return a[top];	
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		CStack S(n);
		int x;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			S.push(x);
		}
		for (int i = 0; i < n; i++)
		{
			if (i<n-1)
				cout << S.pop() << " ";
			else
				cout << S.pop() <<endl;
		}
	}
	return 0;
}