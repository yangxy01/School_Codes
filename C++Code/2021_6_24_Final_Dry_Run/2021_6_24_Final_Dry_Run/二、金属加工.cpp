//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class Metal
//{
//protected:
//	int hardness, weight, vol;
//public:
//	Metal(int h = 0, int w = 0, int v = 0) 
//		:hardness(h), weight(w), vol(v){}
//	friend Metal operator+(Metal&m1, Metal&m2);
//	friend Metal operator*(Metal&m, int n);
//	Metal& operator++()
//	{
//		hardness++;
//		weight *= 1.1;
//		vol *= 1.1;
//		return *this;
//	}
//	Metal& operator--(int)
//	{
//		hardness--;
//		weight *= 0.9;
//		vol *= 0.9;
//		return *this;
//	}
//
//	void Display()
//	{
//		cout << "硬度" << hardness << "--重量" << weight
//			<< "--体积" << vol<< endl;
//	}
//};
//
//Metal operator+(Metal&m1, Metal&m2)
//{
//	Metal M(m1.hardness + m2.hardness, m1.weight + m2.weight, m1.vol + m2.vol);
//	return M;
//}
//Metal operator*(Metal&m, int n)
//{
//	int v = m.vol *n;
//	Metal M(m.hardness, m.weight, v);
//	return M;
//}
//
//int main()
//{
//	int hardness, weight, vol,n;
//	cin >> hardness >> weight >> vol;
//	Metal M1(hardness, weight, vol);
//	cin >> hardness >> weight >> vol;
//	Metal M2(hardness, weight, vol);
//	(M1 + M2).Display();
//	cin >> n;
//	(M1*n).Display();
//	(++M1).Display();
//	(M2--).Display();
//
//	return 0;
//}