//#include<iostream>
//#include<unordered_set>
//using namespace std;
//int belong(unordered_set<long>& A, unordered_set<long>& B)//判断A是否属于B
//{
//	for (auto it : A)
//	{
//		if (B.find(it) == B.end())//找不到，A必不属于B
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
//			if (belong(A, B)) { cout << "A是B的真子集" << endl; break; }
//			if (belong(B, A)) { cout << "B是A的真子集" << endl; break; }
//			if (mix(A, B))
//				cout << "A交B空集" << endl;
//			else
//				cout << "A交B非空" << endl;
//			break;
//		}
//		A.clear();
//		B.clear();
//		
//	}
//
//	return 0;
//}