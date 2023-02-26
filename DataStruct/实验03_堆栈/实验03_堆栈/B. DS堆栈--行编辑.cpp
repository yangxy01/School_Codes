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
//			if (ch != '#')
//				st.push(ch);
//			else
//			{
//				if(st.size()>0)
//					st.pop();
//			}
//		}
//		if (st.empty())
//			cout << "NULL" << endl;
//		else
//		{
//			stack<char> st2;
//			while (st.size() > 0)
//			{
//				st2.push(st.top());
//				st.pop();
//			}
//			while (st2.size() > 0)
//			{
//				cout<<st2.top();
//				st2.pop();
//			}
//			cout << endl;
//		}
//	}
//
//	return 0;
//}