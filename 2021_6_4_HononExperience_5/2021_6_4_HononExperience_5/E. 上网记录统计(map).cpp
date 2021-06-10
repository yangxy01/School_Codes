#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include<algorithm>
using namespace std;

int main()
{
	int m;
	string name,web;
	while (cin >> m)
	{
		map<string, vector<string>> mapStud;
		vector<string> order;
		for (int i = 0; i < m; i++)
		{
			cin >> name >> web;
			auto reit = mapStud.find(name);
			if (reit == mapStud.end())
			{
				mapStud[name].push_back(web);
				order.push_back(name);
			}
			else
			{
				mapStud[name].push_back(web);
			}
		}

		for (auto x : order)
		{
			for (auto y : mapStud)
			{
				if (y.first == x)
				{
					auto z = y.second.begin();
					for (;z< y.second.end()-1;z++)
					{
						cout << *z << " ";
					}
					cout << *z << endl;
				}
			}
				
		}
	}

	return 0;
}




//#include<iostream>
//#include<string>
//#include<vector>
//#include<map>
//#include<algorithm>
//#include<set>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		map<string, vector<string>> ans;
//		vector<string> index;
//		for (int i = 0; i < n; i++)
//		{
//			string name;
//			cin >> name;
//			string web;
//			cin >> web;
//			ans[name].push_back(web);
//			auto pos = find(index.begin(), index.end(), name);
//			if (pos == index.end())
//				index.push_back(name);
//		}
//		for (int i = 0; i < index.size(); i++)
//		{
//			for_each(ans.begin(), ans.end(), [&](pair<string, vector<string>> p)
//				{
//					if (index[i] == p.first)
//					{
//						cout << p.first << " ";
//						for_each(p.second.begin(), p.second.end() - 1, [](string s)
//							{
//								cout << s << " ";
//							});
//						cout << *(p.second.end() - 1) << endl;
//					}
//				});
//		}
//		cout << endl;
//	}
//}