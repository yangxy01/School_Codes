//#include<iostream>
//#include <queue>
//#include <stack>
//#include <vector>
//#include <string>
//#include <iomanip>
//using namespace std;
//struct kid
//{
//	string sex;
//	int pos;
//};
//int main()
//{
//	char first, ch;
//	int count = 0;
//	stack<kid> st;
//	cin >> first;
//	kid k = { "boy" ,count };
//	st.push(k);
//	while (cin >> ch)
//	{
//		count++;
//		if (ch == first)
//		{
//			kid k = { "boy",count };
//			st.push(k);
//		}
//		else
//		{
//			if (st.top().sex == "boy")
//			{
//				cout << st.top().pos << " " << count << endl;
//				st.pop();
//			}
//			else
//			{
//				kid k = { "girl",count };
//				st.push(k);
//			}
//		}
//	}
//	return 0;
//}