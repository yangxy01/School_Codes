#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


int t;
string str[21];
string cmd();
string mycopy(int N, int X, int L);
int myfind(string S, int N);
int myrefind(string S, int N);
string myinsert(string S, int N, int X);
void myprint(int N);
void myprintall();
string myreset(string S, int N);
string myadd(string S1, string S2);
//D. 字符串操作（string）
int main()
{
	int n;
	cin >> n;
	t = n;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	string command;
	while (1)
	{
		string ret=cmd();
		if (ret == "over")
			break;
	}

	return 0;
}
string cmd()
{
	string command;
	cin >> command;
	if (command == "copy")
	{
		int N = stoi(cmd());
		int X = stoi(cmd());
		int L = stoi(cmd());
		return mycopy(N, X, L);
	}
	else if (command == "find")
	{
		string S = cmd();
		int N = stoi(cmd());
		return to_string(myfind(S, N));
	}
	else if (command == "rfind")
	{
		string S = cmd();
		int N = stoi(cmd());
		return to_string(myrefind(S, N));
	}
	else if (command == "insert")
	{
		string S = cmd();
		int N = stoi(cmd());
		int X = stoi(cmd());
		return myinsert(S, N, X);
	}
	else if (command == "print")
	{
		int N = stoi(cmd());
		myprint(N);
		return "";
	}
	else if (command == "printall")
	{
		myprintall();
		return "";
	}
	else if (command == "reset")
	{
		string S = cmd();
		int N = stoi(cmd());
		return myreset(S, N);
	}
	else if (command == "add")
	{
		string S1 = cmd();
		string S2 = cmd();
		return myadd(S1, S2);
	}
	else if (command == "over")
		return "over";
	else
		return command;
}

string mycopy(int N, int X, int L)
{
	return str[N - 1].substr(X, L);
}
int myfind(string S, int N)
{
	if (str[N - 1].find(S) != string::npos)
		return str[N - 1].find(S);
	else
		return str[N - 1].length();
}
int myrefind(string S, int N)
{
	if (str[N - 1].rfind(S) != string::npos)
		return str[N - 1].rfind(S);
	else
		return str[N - 1].length();
}
string myinsert(string S, int N, int X)
{
	string sub = str[N - 1].substr(0, X);
	sub += S;
	sub += str[N - 1].substr(X);
	str[N - 1] = sub;
	return sub;
}
void myprint(int N)
{
	cout << str[N - 1] << endl;
}
void myprintall()
{
	for (int i = 0; i < t; i++)
	{
		myprint(i + 1);
	}
}
string myreset(string S, int N)
{
	str[N - 1] = S;
	return str[N - 1];
}
string myadd(string S1, string S2)
{
	if (S1.length() > 5 || S2.length() > 5)
		return S1 + S2;
	else
	{
		int flag = 1;
		for (int i = 0; i < S1.length(); i++)
		{
			if (!(S1[i] >= '0' && S1[i] <= '9'))
				flag = 0;
		}
		for (int i = 0; i < S2.length(); i++)
		{
			if (!(S2[i] >= '0' && S2[i] <= '9'))
				flag = 0;
		}
		if (flag==0)
			return S1 + S2;
		else
		{
			int sum = 0;
			sum = stoi(S1) + stoi(S2);
			return to_string(sum);
		}
	}
	
}



//void findtimes(string str, string str2)
//{
//	int start = 0,count=0,maxlen;
//	maxlen = str.length();
//	while (start<maxlen)
//	{
//		int ret=str.find(str2, start);
//		if (ret != string::npos)
//		{
//			count++;
//			start = ret;
//			start++;
//		}
//		else
//		{
//			break;
//		}
//		
//	}
//	cout << str2 << ":" << count << endl;
//}
//
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int t;
//		cin >> t;
//		while (t--)
//		{
//			string str2;
//			cin >> str2;
//			findtimes(str, str2);
//		}
//	}
//
//	return 0;
//}









////B. 字符串替换(string)
//string change(string str, string strA, string strB)
//{
//	int start = 0, lenA,posA;
//	string newstr;
//	lenA = strA.length();
//	while (1)
//	{
//		posA = str.find(strA, start);
//		//cout <<"substr="<< str.substr(start, posA-start) << endl;
//		newstr += str.substr(start, posA - start);
//		if (posA != string::npos)
//		newstr += strB;
//		start = posA + lenA;
//		if (posA == string::npos)   
//			return newstr;
//	}
//}
//
//int main()
//{
//	string str,strA,strB,newstr;
//	cin.ignore(100, '\n');
//	getline(cin, str);
//	getline(cin, strA);
//	getline(cin, strB);
//	newstr=change(str, strA, strB);
//	cout << newstr << endl;
//	return 0;
//}











////A. 串应用- 计算一个串的最长的真前后缀
//
//string matched_Prefix_Postfix(string str)
//{
//	int maxlength = str.length()-1;
//	string pre_substring;
//	string post_substring;
//	for (int len = maxlength; len > 0; len--)
//	{
//		pre_substring = str.substr(0, len);
//		post_substring = str.substr(maxlength - len+1);
//		if (pre_substring == post_substring)
//			return post_substring;
//	}
//	return "empty";
//}
//int main()
//{
//	int n;
//	cin >> n;
//	cin.ignore(100, '\n');
//		
//	while (n--)
//	{
//		string str,ret;
//		getline(cin, str);
//		ret=matched_Prefix_Postfix(str);
//		cout << ret << endl;
//	}
//	return 0;
//}