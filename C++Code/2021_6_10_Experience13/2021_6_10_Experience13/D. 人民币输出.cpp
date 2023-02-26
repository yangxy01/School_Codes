//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class RMB
//{
//	int yuan, jiao, fen;
//public:
//	RMB(){ yuan = jiao = fen = 0; }
//	friend istream& operator>>(istream& in, RMB& money);
//	friend ostream& operator<<(ostream& out, RMB& money);
//};
//istream& operator>>(istream& in, RMB& money)
//{
//	double m;
//	in >> m;
//	m += 0.005;
//	m *= 100;
//	money.yuan = (int)m / 100;
//	money.jiao = (int)m / 10%10;
//	money.fen = (int)m %10;
//	return in;
//}
//ostream& operator<<(ostream& out, RMB& money)
//{
//	out << "yuan=" << money.yuan << " " << "jiao=" << money.jiao 
//		<< " " << "fen=" << money.fen << endl;
//	return out;
//}
//
//
//int main()
//{
//	int t;
//	RMB R;
//	cin >> t;
//	while (t--)
//	{
//		cin >> R;
//		cout << R;
//	}
//	return 0;
//}