//#include<iostream>
//#include<unordered_set>
//using namespace std;
//int belong(unordered_set<long>& A, unordered_set<long>& B)//�ж�A�Ƿ�����B
//{
//	for (auto it : A)
//	{
//		if (B.find(it) == B.end())//�Ҳ�����A�ز�����B
//			return 0;
//	}
//	return 1;
//}
//int mix(unordered_set<long>& A, unordered_set<long>& B)
//{
//	for (auto it : A)
//	{
//		if (B.insert(it).second == false)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	unordered_set<long> A;
//	unordered_set<long> B;
//	int t,n,m,x,y;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> m;
//		while (n--)
//		{
//			cin >> x;
//			A.insert(x);
//		}
//		while (m--)
//		{
//			cin >> y;
//			B.insert(y);
//		}
//
//		while (1)
//		{
//			if (belong(A, B) && belong(B, A)) { cout << "A=B" << endl; break; }
//			if (belong(A, B)) { cout << "A��B�����Ӽ�" << endl; break; }
//			if (belong(B, A)) { cout << "B��A�����Ӽ�" << endl; break; }
//			if (mix(A, B))
//				cout << "A��B�ռ�" << endl;
//			else
//				cout << "A��B�ǿ�" << endl;
//			break;
//		}
//		A.clear();
//		B.clear();
//		
//	}
//
//	return 0;
//}