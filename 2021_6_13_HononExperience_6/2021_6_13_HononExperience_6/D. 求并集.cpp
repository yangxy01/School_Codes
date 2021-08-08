//#include<iostream>
//#include<set>
//#include<list>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	set<int> A;
//	set<int> B;
//	list<int> C;
//	int m, n, e;
//	while (cin >> n >> m)
//	{
//		while (n--)
//		{
//			cin >> e;
//			A.insert(e);
//		}
//		while (m--)
//		{
//			cin >> e;
//			B.insert(e);
//		}
//		set_union(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));
//
//		while (C.size() > 1)
//		{
//			cout << C.front() << " ";
//			C.pop_front();
//		}
//		cout << C.front() <<endl;
//		C.pop_front();
//		A.clear();
//		B.clear();
//	}
//	
//	
//	return 0;
//}