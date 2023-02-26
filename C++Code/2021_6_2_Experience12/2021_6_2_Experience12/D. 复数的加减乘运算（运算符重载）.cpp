//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Complex
//{
//	float Real, Image;
//public:
//	Complex(float r, float i) :Real(r), Image(i){}
//	friend Complex operator+ (Complex&C1, Complex&C2);
//	friend Complex operator- (Complex&C1, Complex&C2);
//	friend Complex operator* (Complex&C1, Complex&C2);
//	void show()
//	{
//		cout << "Real=" << Real << " Image=" << Image << endl;
//	}
//};
//Complex operator+ (Complex&C1, Complex&C2)
//{
//	Complex C3(C1.Real + C2.Real, C1.Image + C2.Image);
//	return C3;
//}
//Complex operator- (Complex&C1, Complex&C2)
//{
//	Complex C3(C1.Real - C2.Real, C1.Image - C2.Image);
//	return C3;
//}
//Complex operator* (Complex&C1, Complex&C2)
//{
//	float r = C1.Real * C2.Real - C1.Image * C2.Image;
//	float i = C1.Real * C2.Image + C1.Image * C2.Real;
//	Complex C3(r, i);
//	return C3;
//}
//
//int main()
//{
//	float Real, Image;
//	cin >> Real>> Image;
//	Complex C1(Real, Image);
//	cin >> Real >> Image;
//	Complex C2(Real, Image);
//	(C1 + C2).show();
//	(C1 - C2).show();
//	(C1 * C2).show();
//	return 0;
//}