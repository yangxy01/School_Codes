//#include<iostream>
//#include<queue>
//#include<map>
//#include<utility>
//#include<bitset>
//using namespace std;
//int main()
//{
//	int t,m,n;
//	cin >> t;
//	while (t--)
//	{
//		int i, j,num;
//		cin >> m >> n;
//		bitset<100> myset[100];
//		for (i = 0; i < m; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				cin >> num;
//				myset[i][j] = num;
//			}
//		}	
//		queue<pair<int, int>> que;
//		map<int, pair<int, int>> dir;
//		dir[0] = make_pair(0, 1);
//		dir[1] = make_pair(0, -1);
//		dir[2] = make_pair(1,0);
//		dir[3] = make_pair(-1, 0);
//		for (int p = 0; p < m; p++)
//		{
//			if (p == 0 || p == m - 1)
//			{
//				for (int q = 0; q < n; q++)
//				{
//					if (myset[p][q] != 1)
//					{
//						que.push(make_pair(0, q));
//						while (!que.empty())
//						{
//							for (i = 0; i < 4; i++)
//							{
//								if ((que.front().first + dir[i].first < m) && (que.front().first + dir[i].first >= 0)
//									&& (que.front().second + dir[i].second < n) && (que.front().second + dir[i].second >= 0)
//									&& (myset[que.front().first + dir[i].first][que.front().second + dir[i].second] == 0))
//								{
//									myset[que.front().first + dir[i].first][que.front().second + dir[i].second] = 1;
//									que.push(make_pair(que.front().first + dir[i].first, que.front().second + dir[i].second));
//								}
//							}
//							que.pop();
//						}
//						myset[0][q] = 1;
//					}
//				}
//			}
//			else
//			{
//				if (myset[p][0] != 1)
//				{
//					que.push(make_pair(p, 0));
//					while (!que.empty())
//					{
//						for (i = 0; i < 4; i++)
//						{
//							if ((que.front().first + dir[i].first < m) && (que.front().first + dir[i].first >= 0)
//								&& (que.front().second + dir[i].second < n) && (que.front().second + dir[i].second >= 0)
//								&& (myset[que.front().first + dir[i].first][que.front().second + dir[i].second] == 0))
//							{
//								myset[que.front().first + dir[i].first][que.front().second + dir[i].second] = 1;
//								que.push(make_pair(que.front().first + dir[i].first, que.front().second + dir[i].second));
//							}
//						}
//						que.pop();
//					}
//					myset[p][0] = 1;
//				}
//				if (myset[p][n-1] != 1)
//				{
//					que.push(make_pair(p, n - 1));
//					while (!que.empty())
//					{
//						for (i = 0; i < 4; i++)
//						{
//							if ((que.front().first + dir[i].first < n) && (que.front().first + dir[i].first >= 0)
//								&& (que.front().second + dir[i].second < m) && (que.front().second + dir[i].second >= 0)
//								&& (myset[que.front().first + dir[i].first][que.front().second + dir[i].second] == 0))
//							{
//								myset[que.front().first + dir[i].first][que.front().second + dir[i].second] = 1;
//								que.push(make_pair(que.front().first + dir[i].first, que.front().second + dir[i].second));
//							}
//						}
//						que.pop();
//					}
//					myset[p][n-1] = 1;
//				}
//			}
//		}
//		
//		int sum = 0;
//		for (i = 0; i < m; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (myset[i][j]==0)
//					sum++;
//			}
//		}
//		cout << sum << endl;
//		
//	}
//
//	return 0;
//}