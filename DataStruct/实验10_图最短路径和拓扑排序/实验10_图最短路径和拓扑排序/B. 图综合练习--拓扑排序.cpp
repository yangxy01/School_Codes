//#include<iostream>
//using namespace std;
//
//class Graph
//{
//private:
//	int** Matrix;
//	int Vernum;
//public:
//	Graph() { Matrix = NULL; Vernum = 0; }
//	Graph(int** M, int num)
//	{
//		Vernum = num;
//		Matrix = new int* [Vernum];
//		for (int i = 0; i < Vernum; i++)
//			Matrix[i] = new int[Vernum];
//		for (int i = 0; i < Vernum; i++)
//			for (int j = 0; j < Vernum; j++)
//				Matrix[i][j] = M[i][j];
//	}
//	~Graph()
//	{
//		for (int i = 0; i < Vernum; i++)
//			delete[]Matrix[i];
//		delete[]Matrix;
//		Matrix = NULL;
//	}
//	void TopologicalSorting()
//	{
//		int i, j, flag = 1, count = 0;
//		int* queue = new int[Vernum];
//		int* visited = new int[Vernum];
//		for (i = 0; i < Vernum; i++)
//			visited[i] = 0;
//		int start = 0, end = 0;
//		for (j = 0; j < Vernum; j++)
//		{
//			flag = 0;
//			for (i = 0; i < Vernum; i++)
//			{
//				if (Matrix[i][j] == 1)
//				{
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 0)
//			{
//				queue[end] = j;
//				visited[j] = 1;
//				end++;
//			}
//		}
//		while (start != end)
//		{
//			int v = queue[start];
//			start++;
//			cout << v << " ";
//			count++;
//			for (j = 0; j < Vernum; j++)
//			{
//				if (Matrix[v][j])
//					Matrix[v][j] = 0;
//			}
//			//print();
//			for (j = 0; j < Vernum; j++)
//			{
//				if (visited[j])
//					continue;
//				flag = 0;
//				for (i = 0; i < Vernum; i++)
//				{
//					if (Matrix[i][j] == 1)
//					{
//						flag = 1;
//						break;
//					}
//				}
//				if (flag == 0)
//				{
//					queue[end] = j;
//					visited[j] = 1;
//					end++;
//				}
//			}
//		}
//		cout << endl;
//		delete[]queue,visited;
//	}
//	void print()
//	{
//		for (int i = 0; i < Vernum; i++)
//		{
//			for (int j = 0; j < Vernum; j++)
//				cout << Matrix[i][j] << " ";
//			cout << endl;
//		}
//	}
//
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
//		int** Matrix = new int* [n];
//		for (int i = 0; i < n; i++)
//			Matrix[i] = new int[n];
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				cin >> Matrix[i][j];
//
//		Graph G(Matrix, n);
//		G.TopologicalSorting();
//		
//
//		for (int i = 0; i < n; i++)
//			delete[]Matrix[i];
//		delete[]Matrix;
//		Matrix = NULL;
//	}
//	return 0;
//}