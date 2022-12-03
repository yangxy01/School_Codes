//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//char* Lock(char*p, char*q)
//{
//	char* s = new char[strlen(p) + 1];
//	int len = strlen(q),i=0,j=0;
//	while (*(p+i) != '\0')
//	{
//		int num = 0;
//		if (*(q + j) == '\0')
//		{
//			j -= len;
//		}
//		num = *(q + j) - '0';
//		
//		*(s + i) = *(p + i) + num;
//		if ((*(s + i) > 'Z'&&*(s + i) < 'a') || (*(s + i)>'z'))
//			*(s + i) = *(s + i) - 26;
//	/*	if (*p>'Z')
//			*p = *p - 26;*/
//
//		i++;
//		j++;
//		*(s + i) = '\0';
//	}
//	return s;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		char p[30], q[30];
//		cin >> p >> q;
//		char*s = Lock(p,q);
//		cout << s << endl;
//		delete s;
//	}
//	return 0;
//}