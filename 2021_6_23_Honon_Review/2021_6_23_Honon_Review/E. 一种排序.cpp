//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//struct Retangle
//{
//	int no;
//	int L;
//	int W;
//	Retangle(int n,int l,int w):no(n),L(l),W(w){}
//	bool operator==(const Retangle& R)
//	{
//		if (no == R.no && L == R.L && W == R.W)
//			return true;
//		return false;
//	}
//	bool operator<(const Retangle& R2)
//	{
//		if (no == R2.no)
//		{
//			if (L == R2.L)
//			{
//				return W < R2.W;
//			}
//			return L < R2.L;
//		}
//		return no < R2.no;
//	}
//};
//
////struct cmp
////{
////	bool operator()(Retangle R1, Retangle R2)
////	{
////		
////		if (R1.no == R2.no)
////		{
////			if (R1.L == R2.L)
////			{
////				return R1.W < R2.W;
////			}
////			return R1.L < R2.L;
////		}
////		return R1.no < R2.no;
////	}
////};
//
//int main()
//{
//	vector<Retangle> vec;
//	int t;
//	int no;
//	int L;
//	int W;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		while (n--)
//		{
//			cin >> no >> L >> W;
//			if (W > L) { int tmp = W; W = L; L = tmp; }
//			Retangle R(no, L, W);
//			if (find(vec.begin(), vec.end(), R)== vec.end())
//			vec.push_back(R);
//		}	
//		//sort(vec.begin(), vec.end(), cmp());
//		cout << endl;
//		for ( auto const& x : vec)
//		{
//			cout << x.no << " " << x.L << " " << x.W << endl;
//		}
//	}
//	
//
//	return 0;
//}