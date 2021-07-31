//#define _CRT_SECURE_NO_WARNINGS 1
//
////----------A--------------
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//struct Stu
//{
//	string name;
//	int year;
//	double score;
//};
//int main()
//{
//	int t;
//	cin >> t;
//	Stu* stu = new Stu[t];
//	for_each(stu, stu + t, [](Stu& s)
//	{cin >> s.name >> s.year >> s.score; });
//	sort(stu, stu + t, [](Stu& s1, Stu& s2)
//	{
//		if (s1.score < s2.score)
//			return 1;
//		else if (s1.score == s2.score)
//		{
//			if (s1.name< s2.name)
//				return 1;
//			else if (s1.name == s2.name)
//			{
//				if (s1.year < s2.year)
//					return 1;
//			}
//		}
//		return 0;
//	});
//	for_each(stu, stu + t, [](Stu s)
//	{cout << s.name << " " << s.year << " " << s.score << endl; });
//	delete[]stu;
//}
//
//-----------------------B-----------
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<list>
//using namespace std;
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		vector<int> num(n - 1);
//		int i = 1;
//		for_each(num.begin(), num.end(), [&i](int& a) {i++; a = i; });
//
//		for_each(num.begin(), num.end(), [&](int& a)
//		{num.erase(remove_if(num.begin(), num.end(), [&](int& b) 
//			{return a != b && (b % a == 0); }), num.end()); });
//
//		for_each(num.begin(), num.end() - 1, [&i](int a) {cout << a << " "; });
//		cout << *(num.end() - 1) << endl;
//	}
//}


////------------------C--------------------
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//struct poker
//{
//	string colour;
//	int num;
//};
//
//int main()
//{
//	int t;
//	while (cin >> t)
//	{
//		vector<poker> p(t);
//		for_each(p.begin(), p.end(), [](poker& a) {cin >> a.colour >> a.num; });
//		int n;
//		cin >> n;
//		while (n--)
//		{
//			poker tt;
//			cin >> tt.colour >> tt.num;
//			auto pos = partition(p.begin(), p.end(), [tt](poker& p) {return tt.num <= p.num && tt.colour == p.colour; });
//			vector<poker> a(pos - p.begin());
//			for (auto i = 0; i < pos - p.begin(); i++)
//				a[i] = p[i];
//			sort(a.begin(), a.end(), [](poker& c, poker& b) {return c.num < b.num; });
//			for_each(a.begin(), a.end(), [](poker& a) {cout << a.colour << " " << a.num << endl; });
//			cout << a.size() << endl;
//		}
//	}
//}
//
//
//////-------------------D-----------------
//#include<iostream>
//#include<list>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	list<int> l(n);
//	for_each(l.begin(), l.end(), [](int& a){cin >> a; });
//	while (m--)
//	{
//		int t;
//		cin >> t;
//		auto pos = find(l.begin(), l.end(), t);
//		auto end = l.end();
//		if (pos == l.begin())
//		{
//			cout << *(++pos) << endl;
//		}
//		else if (pos == --end)
//		{
//			cout << *(--pos) << endl;
//		}
//		else
//		{
//			cout << *(--pos) << " ";
//			pos++;
//			cout << *(++pos) << endl;
//		}
//	}
//}
//
//
////------------------E---------------
//#include<iostream>
//#include<list>
//#include<string>
//#include<algorithm>
//using namespace std;
//void insert(list<list<int>>& a, int i, int c, int e);
//void Delete(list<list<int>>& a, int i, int c);
//void merge(list<list<int>>& a, int i, int j);
//void unique(list<list<int>>& a, int i);
//void display(list<list<int>>& a, int i);
//
//int main()
//{
//	int n;
//	cin >> n;
//	list<list<int>> l(n);
//	for_each(l.begin(), l.end(), [&](list<int>& a)
//	{
//		int m;
//		cin >> m;
//		a.resize(m);
//		for_each(a.begin(), a.end(), [&](int& b) {cin >> b; }); });
//		int t;
//		cin >> t;
//		while (t--)
//		{
//			string s;
//			cin >> s;
//			if (s == "insert")
//			{
//				int i, c, e;
//				cin >> i >> c >> e;
//				insert(l, i, c, e);
//				display(l, i);
//			}
//			else if (s == "delete")
//			{
//				int i, c, e;
//				cin >> i >> c;
//				Delete(l, i, c);
//				display(l, i);
//			}
//			else if (s == "merge")
//			{
//				int i, j;
//				cin >> i >> j;
//				merge(l, i, j);
//				display(l, i);
//			}
//			else if (s == "unique")
//			{
//				int i;
//				cin >> i;
//				unique(l, i);
//				display(l, i);
//			}
//			else if (s == "display")
//			{
//				int i;
//				cin >> i;
//				display(l, i);
//			}
//		}
//}
//void insert(list<list<int>>& l, int i, int c, int e)
//{
//	auto a = l.begin();
//	while (--i)
//		a++;
//	auto& l1 = *a;
//
//	if (c - 1 > l1.size())
//		return;
//
//	auto loc = l1.begin();
//	while (--c)
//		loc++;
//	l1.insert(loc, e);
//
//}
//void Delete(list<list<int>>& l, int i, int c)
//{
//	auto a = l.begin();
//	while (--i)
//		a++;
//	auto& l1 = *a;
//
//	if (c > l1.size())
//		return;
//
//	auto loc = l1.begin();
//	while (--c)
//		loc++;
//	l1.erase(loc);
//}
//void merge(list<list<int>>& l, int i, int j)
//{
//	auto a = l.begin();
//	while (--i)
//		a++;
//	auto& l1 = *a;
//
//	auto b = l.begin();
//	while (--j)
//		b++;
//	auto& l2 = *b;
//
//	l2.sort();
//
//	l1.sort();
//	l1.merge(l2);
//
//	l2.clear();
//}
//void unique(list<list<int>>& l, int i)
//{
//	auto a = l.begin();
//	while (--i)
//		a++;
//	auto& l1 = *a;
//
//	l1.sort([](int i, int j) {return i > j; });
//	l1.unique();
//
//	l.insert(a, l1);
//	l.erase(a);
//}
//void display(list<list<int>>& l, int i)
//{
//	auto a = l.begin();
//	while (--i)
//		a++;
//	auto& l1 = *a;
//	if (l1.size())
//	{
//		cout << l1.size() << " ";
//		for_each(l1.begin(), --l1.end(), [](int& a) {cout << a << " "; });
//		cout << *(--l1.end()) << endl;
//	}
//	else
//		cout << l1.size() << endl;
//}
//
//
//
////-----------------F----------------
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//struct polynomial
//{
//	int terms;
//	int index;
//};
//void print_index(polynomial& p);
//int getsign(polynomial& p);
//int print(polynomial& p);
//int print_head(polynomial& p);
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		vector<polynomial> p1(n);
//		for_each(p1.begin(), p1.end(), [](polynomial& a) {cin >> a.terms >> a.index; });
//
//		cin >> n;
//		vector<polynomial> p2(n);
//		for_each(p2.begin(), p2.end(), [](polynomial& a) {cin >> a.terms >> a.index; });
//
//		vector<polynomial> ans;
//		//-------------------------------------------------------------------------------------------------
//		for_each(p1.begin(), p1.end(), [&](polynomial& a)
//		{
//			bool flag = 0;
//			for_each(p2.begin(), p2.end(), [&](polynomial& b)
//			{
//				if (a.index == b.index)
//				{
//					polynomial temp = { 0, 0 };
//					temp.index = a.index;
//					temp.terms = a.terms + b.terms;
//					ans.push_back(temp);
//					flag = 1;
//				}
//			});
//			if (!flag)
//				ans.push_back(a);
//		});
//		for_each(p2.begin(), p2.end(), [&](polynomial& a)
//		{
//			bool flag = 0;
//			for_each(p1.begin(), p1.end(), [&](polynomial& b)
//			{
//				if (a.index == b.index)
//				{
//					flag = 1;
//				}
//			});
//			if (!flag)
//				ans.push_back(a);
//		});
//		sort(ans.begin(), ans.end(), [](polynomial a, polynomial b) {return a.index < b.index; });
//		auto temp1 = remove_if(ans.begin(), ans.end(), [](polynomial& a) {return a.terms == 0; });
//		ans.erase(temp1, ans.end());
//		//------------------------------------------------------------------------------------------------------
//		if (ans.size() != 0)
//		{
//			for (int i = 0; i < int(ans.size()); i++)
//			{
//				if (i != 0)
//				{
//					if (getsign(ans[i]) == 1)
//					{
//						cout << "+";
//						print(ans[i]);
//					}
//					else if (getsign(ans[i]) == -1)
//					{
//						print(ans[i]);
//					}
//				}
//				else
//				{
//					print_head(ans[i]);
//				}
//			}
//			cout << endl;
//		}
//		else
//			cout << "0\n";
//		//-------------------------------------------------------------------------------------------------
//		ans.clear();
//		for_each(p1.begin(), p1.end(), [&](polynomial& a)
//		{
//			bool flag = 0;
//			for_each(p2.begin(), p2.end(), [&](polynomial& b)
//			{
//				if (a.index == b.index)
//				{
//					polynomial temp = { 0, 0 };
//					temp.index = a.index;
//					temp.terms = a.terms - b.terms;
//					ans.push_back(temp);
//					flag = 1;
//				}
//			});
//			if (!flag)
//				ans.push_back(a);
//		});
//		for_each(p2.begin(), p2.end(), [&](polynomial& a)
//		{
//			bool flag = 0;
//			for_each(p1.begin(), p1.end(), [&](polynomial& b)
//			{
//				if (a.index == b.index)
//				{
//					flag = 1;
//				}
//			});
//			if (!flag)
//			{
//				polynomial temp = { 0, 0 };
//				temp.index = a.index;
//				temp.terms = -a.terms;
//				ans.push_back(temp);
//			}
//		});
//		sort(ans.begin(), ans.end(), [](polynomial a, polynomial b) {return a.index < b.index; });
//		auto temp2 = remove_if(ans.begin(), ans.end(), [](polynomial& a) {return a.terms == 0; });
//		ans.erase(temp2, ans.end());
//		//-----------------------------------------------------------------------------------------------------
//		if (ans.size() != 0)
//		{
//			for (int i = 0; i < int(ans.size()); i++)
//			{
//				if (i != 0)
//				{
//					if (getsign(ans[i]) == 1)
//					{
//						cout << "+";
//						print(ans[i]);
//					}
//					else if (getsign(ans[i]) == -1)
//					{
//						print(ans[i]);
//					}
//				}
//				else
//				{
//					print_head(ans[i]);
//				}
//			}
//			cout << endl;
//		}
//		else
//			cout << "0\n";
//		//---------------------------------------------------------------------------------------------------------
//		ans.clear();
//		for_each(p1.begin(), p1.end(), [&](polynomial& a)
//		{
//			bool flag = 0;
//			for_each(p2.begin(), p2.end(), [&](polynomial& b)
//			{
//				polynomial temp = { 0, 0 };
//				temp.index = a.index + b.index;
//				temp.terms = a.terms * b.terms;
//				ans.push_back(temp);
//				flag = 1;
//			});
//		});
//		sort(ans.begin(), ans.end(), [](polynomial a, polynomial b) {return a.index < b.index; });
//
//		for (int i = 0; i < ans.size(); i++)
//		{
//			for (int j = i + 1; j < ans.size(); j++)
//			{
//				if (ans[i].index == ans[j].index)
//				{
//					ans[i].terms += ans[j].terms;
//					ans[j].terms = 0;
//					ans[j].index = 0;
//				}
//				else
//					break;
//			}
//		}
//		auto temp3 = remove_if(ans.begin(), ans.end(), [](polynomial& a) {return a.terms == 0; });
//		ans.erase(temp3, ans.end());
//		//------------------------------------------------------------------------------------------------
//		if (ans.size() != 0)
//		{
//			for (int i = 0; i < int(ans.size()); i++)
//			{
//				if (i != 0)
//				{
//					if (getsign(ans[i]) == 1)
//					{
//						cout << "+";
//						print(ans[i]);
//					}
//					else if (getsign(ans[i]) == -1)
//					{
//						print(ans[i]);
//					}
//				}
//				else
//				{
//					print_head(ans[i]);
//				}
//			}
//			cout << endl;
//		}
//		else
//			cout << "0\n";
//	}
//}
//void print_index(polynomial& p)
//{
//	if (p.index != 1 && p.index != 0)
//		cout << "x^" << p.index;
//	else if (p.index == 1)
//		cout << "x";
//}
//int getsign(polynomial& p)
//{
//	if (p.terms == 0)
//	{
//		return 0;
//	}
//	if (p.terms > 0)
//	{
//		return 1;
//	}
//	if (p.terms < 0)
//	{
//		return -1;
//	}
//}
//int print(polynomial& p)
//{
//	if (p.terms == 0)
//	{
//		return 0;
//	}
//	if (p.terms > 0 && p.terms != 1)
//	{
//		cout << p.terms;
//		print_index(p);
//		return 1;
//	}
//	else if (p.terms < 0 && p.terms != -1)
//	{
//		cout << p.terms;
//		print_index(p);
//		return -1;
//	}
//	else if (p.terms == -1)
//	{
//		cout << "-";
//		print_index(p);
//		return -1;
//	}
//	else
//	{
//		print_index(p);
//		return 1;
//	}
//}
//int print_head(polynomial& p)
//{
//	if (p.terms == 0)
//	{
//		return 0;
//	}
//	if (p.terms > 0 && p.terms != 1)
//	{
//		cout << p.terms;
//		print_index(p);
//		return 1;
//	}
//	else if (p.terms < 0 && p.terms != -1)
//	{
//		cout << p.terms;
//		print_index(p);
//		return -1;
//	}
//	else if (p.terms == -1)
//	{
//		if (p.index == 0)
//			cout << "-1";
//		else
//			cout << "-";
//		print_index(p);
//		return -1;
//	}
//	else
//	{
//		if (p.index == 0)
//			cout << '1';
//		print_index(p);
//		return 1;
//	}
//}
//
//
//
////-----------------G--------------
//#include<iostream>
//#include<list>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, m;
//		cin >> n >> m;
//		list<int> l(n);
//		int i = 0;
//		for_each(l.begin(), l.end(), [&i](int& a) {; a = ++i; });
//		int k = 0;
//		for (auto i = l.begin();;)
//		{
//			if (++k == m)
//			{
//				if (l.size() != 1)
//					cout << *i << " ";
//				else
//					cout << *i << "\n";
//				auto die = i;
//				if (i != begin(l))
//					i--;
//				else
//					i = --l.end();
//				l.erase(die);
//				k = 0;
//			}
//			if (l.size() == 0)
//				break;
//			if (i == --l.end())
//			{
//				i = l.begin();
//			}
//			else
//				i++;
//		}
//	}
//}