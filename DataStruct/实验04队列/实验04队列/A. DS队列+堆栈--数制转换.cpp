//#include<iostream>
//#include<stack>
//#include<queue>
//#include<iomanip>
//using namespace std;
//
//int main()
//{
//	int t, k,integer;
//	double n, decimal;
//	cin >> t;
//	while (t--)
//	{
//		stack<char>st;
//		queue<char>que;
//		cin >> n>>k;
//		integer = int(n);
//		decimal = n - integer;
//		//cout << integer <<" "<< decimal << endl;
//		while (integer)
//		{
//			if(integer % k<=9)
//				st.push(integer % k+'0');
//			else
//				st.push(integer % k -10 + 'A');
//			integer /= k;
//		}
//		while (st.size() > 0)
//		{
//			cout << st.top();
//			st.pop();
//		}
//		cout << ".";
//
//		while (1)
//		{
//			decimal *= k;
//			if (decimal < 1)
//				que.push('0');
//			if (decimal - int(decimal) == 0)
//			{
//				if (decimal - int(decimal) <= 9)
//					que.push(int(decimal) + '0');
//				else
//					que.push(int(decimal) -10 + 'A');
//				break;
//			}
//			else if (decimal > 1)
//			{
//				que.push('1');
//				decimal = decimal - int(decimal);
//			}
//			
//		}
//		while (que.size() < 3)
//		{
//			que.push('0');
//		}
//		while (que.size() > 0)
//		{
//			cout << que.front();
//			que.pop();
//		}
//		cout << endl;
//	}
//
//	return 0;
//}