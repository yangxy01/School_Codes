//#include<iostream>
//#include<string>
//using namespace std;
//
//class myString
//{
//	string mainstr;
//	int size;
//	
//public:
//	myString()
//	{
//		mainstr = "";
//		size = 0;
//	}
//	~myString()
//	{
//		mainstr = "";
//		size = 0;
//	}
//	void SetVal(string sp)
//	{
//		mainstr = sp;
//		size = sp.length();
//	}
//	void GetNext(string p, int* next)
//	{
//		int len = p.length();
//		int i=0, j=-1;
//		next[0] = -1;
//		while (i < len - 1)
//		{
//			if (j == -1 || p[i] == p[j])
//			{
//				i++;
//				j++;
//				next[i] = j;
//			}
//			else
//				j = next[j];
//		}
//		for (i = 0; i < len; i++)
//		{
//			cout << next[i] << " ";
//		}
//		cout << endl;
//	}
//	int KMPFind(string p, int pos, int* next)
//	{
//		int i = pos;
//		int j = 0;
//		while (i < mainstr.length() && j < (int)p.length())
//		{
//			if (j==-1 || mainstr[i] == p[j])
//			{
//				i++;
//				j++;
//			}
//			else
//			{
//				j = next[j];
//			}
//		}
//		if (j == p.length())
//			return i - p.length() +1;
//		return 0;
//	}
//
//};
//int main()
//{
//	int t;
//	string mainstr, substr;
//	cin >> t;
//	while (t--)
//	{
//		myString mystr;
//		cin >> mainstr >> substr;
//		mystr.SetVal(mainstr);
//		int* next = new int[substr.length()];
//		mystr.GetNext(substr, next);
//		int ret = mystr.KMPFind(substr, 0, next);
//		cout << ret << endl;
//		delete []next;
//		next = NULL;
//	}
//	return 0;
//}