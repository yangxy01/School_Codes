#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct polynomial
{
	int terms;
	int index;
};
void print_index(polynomial& p);
int getsign(polynomial& p);
int print(polynomial& p);
int print_head(polynomial& p);
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<polynomial> p1(n);
		for_each(p1.begin(), p1.end(), [](polynomial& a) {cin >> a.terms >> a.index; });

		cin >> n;
		vector<polynomial> p2(n);
		for_each(p2.begin(), p2.end(), [](polynomial& a) {cin >> a.terms >> a.index; });

		vector<polynomial> ans;
		//-------------------------------------------------------------------------------------------------
		for_each(p1.begin(), p1.end(), [&](polynomial& a)
		{
			bool flag = 0;
			for_each(p2.begin(), p2.end(), [&](polynomial& b)
			{
				if (a.index == b.index)
				{
					polynomial temp = { 0, 0 };
					temp.index = a.index;
					temp.terms = a.terms + b.terms;
					ans.push_back(temp);
					flag = 1;
				}
			});
			if (!flag)
				ans.push_back(a);
		});
		for_each(p2.begin(), p2.end(), [&](polynomial& a)
		{
			bool flag = 0;
			for_each(p1.begin(), p1.end(), [&](polynomial& b)
			{
				if (a.index == b.index)
				{
					flag = 1;
				}
			});
			if (!flag)
				ans.push_back(a);
		});
		sort(ans.begin(), ans.end(), [](polynomial a, polynomial b) {return a.index < b.index; });
		auto temp1 = remove_if(ans.begin(), ans.end(), [](polynomial& a) {return a.terms == 0; });
		ans.erase(temp1, ans.end());
		//------------------------------------------------------------------------------------------------------
		if (ans.size() != 0)
		{
			for (int i = 0; i < int(ans.size()); i++)
			{
				if (i != 0)
				{
					if (getsign(ans[i]) == 1)
					{
						cout << "+";
						print(ans[i]);
					}
					else if (getsign(ans[i]) == -1)
					{
						print(ans[i]);
					}
				}
				else
				{
					print_head(ans[i]);
				}
			}
			cout << endl;
		}
		else
			cout << "0\n";
		//-------------------------------------------------------------------------------------------------
		ans.clear();
		for_each(p1.begin(), p1.end(), [&](polynomial& a)
		{
			bool flag = 0;
			for_each(p2.begin(), p2.end(), [&](polynomial& b)
			{
				if (a.index == b.index)
				{
					polynomial temp = { 0, 0 };
					temp.index = a.index;
					temp.terms = a.terms - b.terms;
					ans.push_back(temp);
					flag = 1;
				}
			});
			if (!flag)
				ans.push_back(a);
		});
		for_each(p2.begin(), p2.end(), [&](polynomial& a)
		{
			bool flag = 0;
			for_each(p1.begin(), p1.end(), [&](polynomial& b)
			{
				if (a.index == b.index)
				{
					flag = 1;
				}
			});
			if (!flag)
			{
				polynomial temp = { 0, 0 };
				temp.index = a.index;
				temp.terms = -a.terms;
				ans.push_back(temp);
			}
		});
		sort(ans.begin(), ans.end(), [](polynomial a, polynomial b) {return a.index < b.index; });
		auto temp2 = remove_if(ans.begin(), ans.end(), [](polynomial& a) {return a.terms == 0; });
		ans.erase(temp2, ans.end());
		//-----------------------------------------------------------------------------------------------------
		if (ans.size() != 0)
		{
			for (int i = 0; i < int(ans.size()); i++)
			{
				if (i != 0)
				{
					if (getsign(ans[i]) == 1)
					{
						cout << "+";
						print(ans[i]);
					}
					else if (getsign(ans[i]) == -1)
					{
						print(ans[i]);
					}
				}
				else
				{
					print_head(ans[i]);
				}
			}
			cout << endl;
		}
		else
			cout << "0\n";
		//---------------------------------------------------------------------------------------------------------
		ans.clear();
		for_each(p1.begin(), p1.end(), [&](polynomial& a)
		{
			bool flag = 0;
			for_each(p2.begin(), p2.end(), [&](polynomial& b)
			{
				polynomial temp = { 0, 0 };
				temp.index = a.index + b.index;
				temp.terms = a.terms * b.terms;
				ans.push_back(temp);
				flag = 1;
			});
		});
		sort(ans.begin(), ans.end(), [](polynomial a, polynomial b) {return a.index < b.index; });

		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = i + 1; j < ans.size(); j++)
			{
				if (ans[i].index == ans[j].index)
				{
					ans[i].terms += ans[j].terms;
					ans[j].terms = 0;
					ans[j].index = 0;
				}
				else
					break;
			}
		}
		auto temp3 = remove_if(ans.begin(), ans.end(), [](polynomial& a) {return a.terms == 0; });
		ans.erase(temp3, ans.end());
		//------------------------------------------------------------------------------------------------
		if (ans.size() != 0)
		{
			for (int i = 0; i < int(ans.size()); i++)
			{
				if (i != 0)
				{
					if (getsign(ans[i]) == 1)
					{
						cout << "+";
						print(ans[i]);
					}
					else if (getsign(ans[i]) == -1)
					{
						print(ans[i]);
					}
				}
				else
				{
					print_head(ans[i]);
				}
			}
			cout << endl;
		}
		else
			cout << "0\n";
	}
}
void print_index(polynomial& p)
{
	if (p.index != 1 && p.index != 0)
		cout << "x^" << p.index;
	else if (p.index == 1)
		cout << "x";
}
int getsign(polynomial& p)
{
	if (p.terms == 0)
	{
		return 0;
	}
	if (p.terms > 0)
	{
		return 1;
	}
	if (p.terms < 0)
	{
		return -1;
	}
}
int print(polynomial& p)
{
	if (p.terms == 0)
	{
		return 0;
	}
	if (p.terms > 0 && p.terms != 1)
	{
		cout << p.terms;
		print_index(p);
		return 1;
	}
	else if (p.terms < 0 && p.terms != -1)
	{
		cout << p.terms;
		print_index(p);
		return -1;
	}
	else if (p.terms == -1)
	{
		cout << "-";
		print_index(p);
		return -1;
	}
	else
	{
		print_index(p);
		return 1;
	}
}
int print_head(polynomial& p)
{
	if (p.terms == 0)
	{
		return 0;
	}
	if (p.terms > 0 && p.terms != 1)
	{
		cout << p.terms;
		print_index(p);
		return 1;
	}
	else if (p.terms < 0 && p.terms != -1)
	{
		cout << p.terms;
		print_index(p);
		return -1;
	}
	else if (p.terms == -1)
	{
		if (p.index == 0)
			cout << "-1";
		else
			cout << "-";
		print_index(p);
		return -1;
	}
	else
	{
		if (p.index == 0)
			cout << '1';
		print_index(p);
		return 1;
	}
}