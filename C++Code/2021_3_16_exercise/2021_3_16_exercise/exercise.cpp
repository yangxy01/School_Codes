#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//void my_strcpy(const char*arr1, char*arr2)
//{
//	while (*arr1)
//	{
//		*arr2 = *arr1;
//		arr1++;
//		arr2++;
//	}
//	*arr2 = *arr1;
//}
//
//int main()//×Ö·û´®¸´ÖÆ
//{
//	char arr1[20] = "abcdefg";
//	char arr2[20];
//	my_strcpy(arr1, arr2);
//	cout << arr2 << endl;
//	return 0;
//}


int main()//ÊµÏÖ×Ö·û´®ÄæÐòÊä³ö
{
	int n;
	cin >> n;
	char*p = new char [n];
	cin >> p;
	int len = strlen(p);
	int i;
	for (i = n - 1; i >= 0; i--)
	{
		cout << *(p + i);
	}
	cout << endl;
	delete[] p;
	p = NULL;
}