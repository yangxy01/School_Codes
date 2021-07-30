#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<functional>
using namespace std;
/*
5
10 23 54 23 546 67 3 65 9 434 56
5 1 2 3 4 5
3 10 20 30
4 1 2 3 -10
2 7 8
7
insert 2 0 10
merge 4 2
unique 4
display 2
insert 2 1 10
delete 3 4
merge 3 4
*/
/*
5
10 23 54 23 546 67 3 65 9 434 56
5 1 2 3 4 5
3 10 20 30
4 1 2 3 -10
2 7 8
7
insert 2 0 10
merge 4 2
unique 4
display 2
insert 2 1 10
delete 3 4
merge 3 4

*/
int main()
{
	int m,n,x,i,j;
	cin >> m;
	list<int> ls[10];
	for (i = 0; i < m;i++)
	{
		cin >> n;
		while (n--)
		{
			cin >> x;
			ls[i].push_back(x);
		}
	}
	int t,pos,e;
	string str;
	cin >> t;
	while (t--)
	{
		cin >> str;
		if (str == "insert")
		{
			cin >> i >> pos >> e;
			if (pos > 0 && pos <= ls[i].size() + 1)
			{
				auto it = ls[i-1].begin();
				pos--;
				while (pos--)
				it++;
				ls[i - 1].insert(it, e);
			}
			cout << ls[i - 1].size();
			if (!ls[i - 1].empty())
			{
				for (auto x : ls[i - 1])
					cout << " " << x;
				
			}
			cout << endl;
		}
		else if (str == "delete")
		{
			cin >> i >> pos; 
			auto it = ls[i-1].begin();
			if (pos > 0 && pos < ls[i-1].size() + 1)
			{
				pos--;
				while (pos--)
					it++;
				ls[i - 1].erase(it);
			}
			cout << ls[i - 1].size();
			if (!ls[i - 1].empty())
			{
				for (auto x : ls[i - 1])
					cout << " " << x;
				
			}
			cout << endl;
		}
		else if (str == "merge")
		{
			cin >> i >> j;
			ls[i - 1].sort();
			ls[j - 1].sort();
			ls[i - 1].merge(ls[j - 1]);
			cout << ls[i - 1].size();
			if (!ls[i - 1].empty())
			{
				for (auto x : ls[i - 1])
					cout << " " << x;
				
			}
			cout << endl;
		}
		else if (str == "unique")
		{
			cin >> i ;
			if (!ls[i - 1].empty())
			{
				ls[i - 1].sort(greater<int>());
				ls[i - 1].unique();
			}
			cout << ls[i - 1].size();
			if (!ls[i - 1].empty())
			{
				for (auto x : ls[i - 1])
					cout << " " << x;
				
			}
			cout << endl;
		}
		else if (str == "display")
		{
			cin >> i;
			cout << ls[i - 1].size();
			if (!ls[i - 1].empty())
			{
				for (auto x : ls[i - 1])
					cout << " " << x;
			}
			cout << endl;
		}
	}

}