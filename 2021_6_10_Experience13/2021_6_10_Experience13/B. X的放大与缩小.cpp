//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//class CXGraph
//{
//	int n;
//public:
//	CXGraph(){ n = 0; }
//	CXGraph(int n_v){ n = n_v; }
//	CXGraph(CXGraph&obj){ n = obj.n; }
//	friend ostream& operator<<(ostream&out, const CXGraph&obj);
//	CXGraph&operator++();
//	CXGraph operator++(int);
//	CXGraph&operator--();
//	CXGraph operator--(int);
//
//};
//ostream& operator<<(ostream&out, const CXGraph&obj)
//{
//	int n = obj.n / 2, m = obj.n / 2+1;
//	int i,j;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < i ; j++)
//			out << " ";
//		for (j = 0; j < obj.n - i * 2; j++)
//			out << "X";
//		out << endl;
//	}
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < m-1-i; j++)
//			out << " ";
//		for (j = 0; j < 1+i*2; j++)
//			out << "X";
//		out << endl;
//	}
//	out << endl;
//	return out;
//}
//CXGraph&CXGraph::operator++()
//{
//	if (n<21)
//	n+=2;
//	return *this;
//}
//CXGraph CXGraph::operator++(int)
//{
//	CXGraph tmp(*this);
//	if (n<21)
//		n += 2;
//	return tmp;
//}
//CXGraph&CXGraph::operator--()
//{
//	if (n>1)
//		n -= 2;
//	return *this;
//}
//CXGraph CXGraph::operator--(int)
//{
//	CXGraph tmp(*this);
//	if (n>1)
//		n -= 2;
//	return tmp;
//}
//
//int main()
//{
//	int t, n;
//	string command;
//	cin >> n;
//	CXGraph xGraph(n);
//
//	cin >> t;
//	while (t--)
//	{
//		cin >> command;
//		
//		if (command == "show++")
//			cout << xGraph++ << endl;
//		else if (command == "++show")
//			cout << ++xGraph << endl;
//		else if (command == "show--")
//			cout << xGraph-- << endl;
//		else if (command == "--show")
//			cout << --xGraph << endl;
//		else if (command == "show")
//			cout << xGraph << endl;
//	}
//	return 0;
//}