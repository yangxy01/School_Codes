//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class CBigInteger
//{
//	char *p;
//public:
//	CBigInteger(){ p = new char[1001]; }
//	CBigInteger(char *num)
//	{
//		p = new char[1001];
//		strcpy(p, num);
//	}
//	CBigInteger(const CBigInteger &b)
//	{
//		p = new char[1001];
//		strcpy(p, b.p);
//	}
//
//	friend istream& operator>>(istream &in, CBigInteger &r);
//	friend ostream& operator<<(ostream &out, CBigInteger r);
//
//	~CBigInteger(){ if (p)delete[]p; }
//};
//
//
//istream &operator>>(istream &in, CBigInteger &r) 
//{
//	char str[1001];
//	in >> str;
//	int i = 0;
//	if (str[0] == '0' && str[1] != '\0')
//	for (i = 0; str[i] == '0'; i++);
//	strcpy(r.p, str + i);
//	return in;
//}
//
//ostream &operator<<(ostream &out, CBigInteger r) {
//	if (r.p[0] == '-')
//		out << '(' << r.p << ')';
//	else
//		out << r.p;
//	return out;
//}
//
//
//
//
//int main()
//{
//	int t;
//	char op;
//	CBigInteger bigNum1;
//	CBigInteger bigNum2;
//
//	cin >> t;
//	while (t--)
//	{
//		cin >> bigNum1 >> op >> bigNum2;
//		cout << bigNum1 << " " << op << " " << bigNum2 << " = ";
//		if (op == '+')
//			cout << bigNum1 + bigNum2 << endl;
//		else if (op == '-')
//			cout << bigNum1 - bigNum2 << endl;
//		else if (op == '*')
//			cout << bigNum1*bigNum2 << endl;
//	}
//	return 0;
//}
