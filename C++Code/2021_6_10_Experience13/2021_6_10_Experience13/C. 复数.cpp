//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//using namespace std;
//class CComplex
//{
//	int real, image;
//public:
//	CComplex(int r = 0, int i = 0) :real(r), image(i){}
//	friend istream& operator>>(istream&in, CComplex&X);
//	friend ostream& operator<<(ostream&out, CComplex&X);
//
//};
//istream& operator>>(istream&in, CComplex&X)
//{
//	in >> X.real>>X.image;
//	return in;
//}
//ostream& operator<<(ostream&out, CComplex&X)
//{
//	if (X.real != 0)
//	{
//		out << X.real ;
//		if (X.image != 0)
//		{
//			if (X.image>0)
//				out << "+";
//			out << X.image << "i" << endl;
//		}
//			
//	}
//	else
//	{
//		if (X.image != 0)
//		{
//			if (X.image>0)
//				out << "+";
//			out << X.image << "i" << endl;
//		}
//		else
//			out <<"0"<< endl;
//	}
//	return out;
//}
//
//int main()
//{
//	int n;
//	double r, i;
//	CComplex x;
//	cin >> n;
//	while (n--) 
//	{
//		cin >> x;
//		cout << x;
//	}
//	return 0;
//}