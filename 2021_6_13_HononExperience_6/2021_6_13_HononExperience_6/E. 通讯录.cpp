//#include<iostream>
//#include<map>
//using namespace std;
//int main()
//{
//	multimap<string, string> mymap;
//	int n, m,type;
//	string name, num;
//	cin >> n;
//	while (n--)
//	{
//		cin >> name >> num;
//		mymap.insert(make_pair(name, num));
//	}
//	cin >> m;
//	while (m--)
//	{
//		cin >> type >> name;
//		if (type == 1)
//		{
//			if (mymap.find(name) != mymap.end())
//			{
//				int count = 0;
//				count = mymap.count(name);
//				/*for (auto x : mymap)
//				{
//					if (x.first == name)
//						count++;
//				}*/
//				cout << count << endl;
//			}
//			else
//				cout << "0" << endl;
//		}
//		else
//		{
//			if (mymap.find(name) != mymap.end())
//			{
//				for (auto x : mymap)
//				{
//					if (x.first == name)
//						cout << x.second << endl;
//				}
//			}
//			else
//				cout << "None" << endl;
//			
//		}
//	}
//
//	return 0;
//}