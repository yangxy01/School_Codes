//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//int main()
//{
//	int n,i;
//	cin >> n;
//	map<string, int>mymap;
//	string name1, name2;
//	string animal[12] = { "��","ţ","��","��","��","��","��","��","��","��","��","��" };
//	for (i = 0; i < 12; i++)
//		mymap.insert(make_pair(animal[i], i));
//	while (n--)
//	{
//		
//		cin >> name1;
//		if (mymap.count(name1)==0)
//			mymap.insert(make_pair(name1, i++));		
//		auto it = mymap.find(name1);
//		cout << name1 << "--" << it->second << endl;
//
//		cin >> name1 >> name2;
//		if (mymap.count(name1) == 0)
//			mymap.insert(make_pair(name1, i++));
//		if (mymap.count(name2) == 0)
//			mymap.insert(make_pair(name2, i++));
//
//		auto it1 = mymap.find(name1);
//		auto it2 = mymap.find(name2);
//		if (it1->second > it2->second)
//		{
//			cout << name1 << "��" << name2 << "֮��" << endl;
//		}
//		else
//		{
//			cout << name1 << "��" << name2 << "֮ǰ" << endl;
//		}
//		//mymap.clear();
//	}
//
//	return 0;
//}