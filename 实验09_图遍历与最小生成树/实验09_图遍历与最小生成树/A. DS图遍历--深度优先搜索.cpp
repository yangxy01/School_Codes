//#include<iostream>
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
//	Graph(int num,int** m)
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
//	void DFS(int sorce = 0)
//	{
//		for (int i = 0; i < Vernum; i++)
//			if(visited[i]==0)
//				DFSuntil(i);
//		cout << endl; 
//	}
//	void Show()
//	{
//		for (int i = 0; i < Vernum; i++)
//		{
//			for (int j = 0; j < Vernum; j++)
//				cout<< Matrix[i][j]<<" ";
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
//		G.DFS(0);
//
//
//		for (int i = 0; i < n; i++)
//			delete[]M[i];
//		delete[]M;
//	}
//	return 0;
//}