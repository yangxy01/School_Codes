#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()//ÊµÏÖ×Ö·û´®ÄæÐòÊä³ö
{
	int n;
	cin >> n;
	char*p = new char [n];
	cin >> p;
	int len = strlen(p);
	int i;
	for (i = n - 1; i >= 0; i--)
	{
		cout << *(p + i);
	}
	cout << endl;
	delete[] p;
	p = NULL;
}