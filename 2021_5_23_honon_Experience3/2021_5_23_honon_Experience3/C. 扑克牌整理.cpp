//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//#include<string>
//#include <algorithm>
//using namespace std;
//struct poker
//{
//	string col;
//	int num;
//};
//
//int main()
//{
//	int t;
//	while (cin >> t)
//	{
//		vector<poker> pu(t);
//		for_each(pu.begin(), pu.end(), [](poker& p) {cin >> p.col >> p.num; });
//		int n;
//		cin >> n;
//		while (n--)
//		{
//			poker pok;
//			vector<poker>::iterator ite;
//			cin >> pok.col >> pok.num;
//			ite = partition(pu.begin(), pu.end(), [pok](poker& po)
//			{
//				return pok.col == po.col && pok.num <= po.num;
//
//			});
//			vector<poker> p2(pu.begin(),ite);
//			
//			sort(p2.begin(), p2.end(), [](poker& pa, poker& pb) {return pa.num < pb.num; });
//			for_each(p2.begin(), p2.end(), [](poker& p) {cout << p.col << " " << p.num << endl; });
//			cout << p2.size() << endl;
//		}
//	}
//}