//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <stack>
//#include <vector>
//#include <string>
//using namespace std;
//
//
//int main() 
//{
//	int t,len;
//	string IN, OUT;
//	cin >> t;
//	while (t--) 
//	{
//		vector<string> record; 
//		stack<char> st;
//		cin >> len >> IN >> OUT;	
//		int in = 0, out = 0;
//		while (out <len)
//		{
//			while (in<len && IN[in] != OUT[out])
//			{  
//				st.push(IN[in]);
//				in++;
//				record.push_back("in");
//			}
//			if (in == len) 
//				break;
//
//			if (IN[in] == OUT[out])
//			{  
//				record.push_back("in");
//				record.push_back("out");
//				in++; 
//				out++;			
//			}
//			
//			while (!st.empty()&&st.top() == OUT[out])
//			{
//				record.push_back("out");
//				st.pop();
//				out++;
//			}
//		}
//		if (st.empty() && out == len)
//		{
//			cout << "Yes" << endl;
//			for (auto x : record)
//			{
//				cout << x << endl;
//			}
//
//		}
//		else
//		{
//			cout << "No" << endl;
//		}
//		cout << "FINISH" << endl;
//	}
//	return 0;
//}
//
