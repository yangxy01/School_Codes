//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//using namespace std;
////ֻ֧���������͵ļ��������
//
//template<class T>
//T Max(T tt[], int tl) //����
//{
//	T max = tt[0];
//	for (int i = 1; i < tl; i++)
//	{
//		if (tt[i]>max){ max = tt[i]; }
//	}
//	return max;
//}
//
//template<class T>
//class Cryption {
//	T ptxt[100];//����
//	T ctxt[100];//����
//	T key;//��Կ
//	int len;//����
//public:
//	Cryption(T tk, T tt[], int tl) //�������ζ�Ӧ��Կ�����ġ�����
//	{
//		key = tk;
//		len = tl;
//		for (int i = 0; i < len; i++)
//		{
//			ptxt[i] = tt[i];
//		}
//	}
//	void Encrypt() //����
//	{
//		T max = Max(ptxt, len);
//		for (int i = 0; i < len; i++)
//		{
//			ctxt[i] = key + max - ptxt[i];
//		}
//	}
//	void Print() //��ӡ���������
//	{
//		int i;
//		for (i = 0; i<len - 1; i++)
//			cout << ctxt[i] << " ";
//		cout << ctxt[i] << endl;
//	}
//};
//
////֧���������͵�������
//
//int main()
//{	
//	int i;
//	int length; //����
//	int ik, itxt[100];
//	double dk, dtxt[100];
//	char ck, ctxt[100];
//	//��������
//	cin >> ik >> length;
//	for (i = 0; i<length; i++)
//		cin >> itxt[i];
//	Cryption<int> ic(ik, itxt, length);
//	ic.Encrypt();
//	ic.Print();
//
//	//����������
//	cin >> dk >> length;
//	for (i = 0; i<length; i++)
//		cin >> dtxt[i];
//	Cryption<double> dc(dk, dtxt, length);
//	dc.Encrypt();
//	dc.Print();
//
//	//�ַ�����
//	cin >> ck >> length;
//	for (i = 0; i<length; i++)
//		cin >> ctxt[i];
//	Cryption<char> cc(ck, ctxt, length);
//	cc.Encrypt();
//	cc.Print();
//
//	return 0;
//}