//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//struct Pos
//{
//	int xp;
//	int yp;
//};
//
//int main()
//{
//	int t, n,x;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n;
//		int** num = new int*[n];
//		for (int i = 0; i < n; i++)
//			num[i] = new int[n];
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> x;
//				num[i][j] = x;
//			}
//		}
//		
//		stack<Pos> path;
//		Pos orig = { 0,0 };
//		path.push(orig);
//		while (!path.empty())
//		{
//			while ((path.top().yp + 1 < n) && num[path.top().xp][path.top().yp + 1] != 1)
//			{
//				Pos p = { path.top().xp, path.top().yp + 1 };
//				path.push(p);
//			}
//			if ((path.top().xp + 1 < n) && num[path.top().xp + 1][path.top().yp] != 1)
//			{
//				Pos p = { path.top().xp + 1, path.top().yp };
//				path.push(p);
//				continue;
//			}
//			else if (path.top().xp == n - 1 && path.top().yp == n - 1)
//				break;
//			else
//			{
//				num[path.top().xp][path.top().yp] = 1;
//				path.pop();
//				continue;
//			}
//		}
//
//		if (!path.empty())//找到路径
//		{
//			stack<Pos> path1;
//			while (!path.empty())
//			{
//				path1.push(path.top());
//				path.pop();
//			}
//			Pos cpos;
//			int i = 0;  //以下是输出路径的代码
//			while (!path1.empty())
//			{
//				cpos = path1.top();
//				if ((++i) % 4 == 0)
//					cout << '[' << cpos.xp << ',' << cpos.yp << ']' << "--" << endl;
//				else
//					cout << '[' << cpos.xp << ',' << cpos.yp << ']' << "--";
//				path1.pop();
//			}
//			cout << "END" << endl;
//		}
//		else
//			cout << "no path" << endl; //找不到路径输出no path
//
//		for (int i = 0; i < n; i++)
//			delete[]num[i];
//		delete[]num;
//		
//	}
//
//	return 0;
//}