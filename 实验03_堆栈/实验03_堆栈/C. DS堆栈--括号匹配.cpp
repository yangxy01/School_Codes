//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	getchar();
//	char ch;
//	while (t--)
//	{
//		stack<char> st;
//		while ((ch = getchar()) != '\n')
//		{
//			if (ch == '(' || ch == '{' || ch == '[')
//				st.push(ch);
//			else if (ch == ')' && st.top() == '(')
//				st.pop();
//			else if (ch == '}' && st.top() == '{')
//				st.pop();
//			else if (ch == ']' && st.top() == '[')
//				st.pop();
//			else
//				continue;
//		}
//		if (st.empty())
//			cout << "ok" << endl;
//		else
//		{
//			cout << "error" << endl;
//		}
//	}
//
//	return 0;
//}