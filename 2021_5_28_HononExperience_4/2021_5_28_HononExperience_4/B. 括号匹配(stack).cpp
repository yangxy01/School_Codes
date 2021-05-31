//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <stack>
//#include <vector>
//#include <string>
//using namespace std;
//int ismatch(string str)
//{
//	stack<char> st;
//	for (auto s : str)
//	{
//		if (s == '(' || s == '{' || s == '[')
//			st.push(s);
//		else
//		{
//			if (st.empty())
//				return 3;
//			else if (st.top() != '('&&s == ')')
//				return 1;
//			else if (st.top() != '{'&&s == '}')
//				return 1;
//			else if (st.top() != '['&&s == ']')
//				return 1;
//			else
//				st.pop();
//		}
//	}
//	if (st.empty())
//		return 0;
//	return 2;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	string str;
//	while (t--)
//	{
//		cin >> str;
//		int ret = ismatch(str);
//		if (ret == 0)
//			cout << "yes" << endl;
//		else if (ret == 1)
//			cout << "no 1" << endl;
//		else if (ret == 2)
//			cout << "no 2" << endl;
//		else if (ret == 3)
//			cout << "no 3" << endl;
//	}
//	return 0;
//}
