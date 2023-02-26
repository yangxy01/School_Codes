//#include<iostream>
//#include<queue>
//using namespace std;
//
//class Graph
//{
//private:
//	int* visited;
//	int** Matrix;
//	int Vernum;
//	void DFSuntil(int v)
//	{
//		visited[v] = 1;
//		cout << v << " ";
//		for (int j = 0; j < Vernum; j++)
//		{
//			if (Matrix[v][j] && visited[j] == 0)
//				DFSuntil(j);
//		}
//	}
//public:
//	Graph() { visited = NULL; Matrix = NULL; Vernum = 0; }
//	Graph(int num, int** m)
//	{
//		Vernum = num;
//		Matrix = new int* [Vernum];
//		visited = new int[Vernum];
//		for (int i = 0; i < Vernum; i++)
//			Matrix[i] = new int[Vernum];
//		for (int i = 0; i < Vernum; i++)
//		{
//			visited[i] = 0;
//			for (int j = 0; j < Vernum; j++)
//				Matrix[i][j] = m[i][j];
//		}
//	}
//	~Graph()
//	{
//		for (int i = 0; i < Vernum; i++)
//			delete[]Matrix[i];
//		delete[]Matrix;
//		delete[]visited;
//	}
//	void DFSTraverse(int sorce = 0)
//	{
//		for (int i = 0; i < Vernum; i++)
//			if (visited[i] == 0)
//				DFSuntil(i);
//		cout << endl;
//	}
//	void BFSTraverse(int sorce = 0)
//	{
//		int v;
//		queue<int> que;
//		for (int i = 0; i < Vernum; i++)
//		{
//			if (visited[i] == 0)
//			{
//				que.push(i);
//				visited[i] = 1;
//				while (!que.empty())
//				{
//					v = que.front();
//					cout << v << " ";
//					que.pop();
//					for (int j = 0; j < Vernum; j++)
//					{
//						if (Matrix[v][j] && visited[j] == 0)
//						{
//							que.push(j);
//							visited[j] = 1;
//						}
//					}
//				}
//			}
//		}
//		cout << endl;
//	}
//
//	void Show()
//	{
//		for (int i = 0; i < Vernum; i++)
//		{
//			for (int j = 0; j < Vernum; j++)
//				cout << Matrix[i][j] << " ";
//			cout << endl;
//		}
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int** M = new int* [n];
//		for (int i = 0; i < n; i++)
//			M[i] = new int[n];
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				cin >> M[i][j];
//		Graph G(n, M);
//		//G.DFSTraverse(0);
//		G.BFSTraverse();
//
//		for (int i = 0; i < n; i++)
//			delete[]M[i];
//		delete[]M;
//	}
//	return 0;
//}