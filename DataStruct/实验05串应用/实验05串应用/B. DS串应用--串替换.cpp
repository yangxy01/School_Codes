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
//		int i = 0, j = -1;
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
//	}
//	int KMPFind(string p, int pos, int* next)
//	{
//		int i = pos;
//		int j = 0;
//		while (i < mainstr.length() && j < (int)p.length())
//		{
//			if (j == -1 || mainstr[i] == p[j])
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
//			return i - p.length() + 1;
//		return 0;
//	}
//	string Replace(string p, int pos,int len)
//	{
//		string s = mainstr.substr(0, pos);
//		s += p;
//		s += mainstr.substr(pos+len);
//		return s;
//	}
//};
//int main()
//{
//	int t;
//	string mainstr, substr, replacestr;
//	cin >> t;
//	while (t--)
//	{
//		myString mystr;
//		cin >> mainstr >> substr >>replacestr;
//		cout << mainstr << endl;
//		mystr.SetVal(mainstr);
//		int* next = new int[substr.length()];
//		mystr.GetNext(substr, next);
//		int ret = mystr.KMPFind(substr, 0, next);
//		if (ret)
//		{
//			string s = mystr.Replace(replacestr, ret - 1, substr.length());
//			cout << s << endl;
//		}
//		else
//		{
//			cout << mainstr << endl;
//		}
//		delete[]next;
//		next = NULL;
//	}
//	return 0;
//}