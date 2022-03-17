//#include<iostream>
//#include<map>
//#include<vector>
//#include<string>
//#include<bitset>
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
//	void DFS(int source = 0)
//	{
//		int j = 0, count=0;
//		bitset<20>visits[20];
//		for (int i = 0; i < Vernum; i++)
//		{
//			for (j = 0; j < Vernum; j++)
//				visited[j] = 0;
//			DFSuntil(i);
//			if (count == 0)
//			{
//				for (int k = 0; k < Vernum; k++)
//				{
//					if (visited[k])
//						visits[count][k] = 1;
//				}
//				count++;
//			}
//			else
//			{
//				bitset<20>tmp;
//				for (int k = 0; k < Vernum; k++)
//				{
//					if (visited[k])
//						tmp[k] = 1;
//				}
//				int flag = 1;
//				for (int k = 0; k < count; k++)
//				{
//					if (visits[k] == tmp)
//					{
//						flag = 0;
//						break;
//					}
//				}
//				if (flag)
//				{
//					visits[count] = tmp;
//					count++;
//				}
//			}
//		}
//		cout <<count << endl;
//	}
//	void Show()
//	{
//		for (int i = 0; i < Vernum; i++)
//		{
//			int j;
//			for (j = 0; j < Vernum-1; j++)
//				cout << Matrix[i][j] << " ";
//			cout << Matrix[i][j] <<endl;
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
//		/*bitset<20>visits[3];
//		for (int i = 0; i < 3; i++)
//			cout << visits[i] << endl;*/
//		int n,m,j;
//		string str,str2;
//		cin >> n;
//		int** M = new int* [n];
//		for (int i = 0; i < n; i++)
//			M[i] = new int[n];
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				M[i][j]=0;
//		map<string, int> mymap;
//		for (j = 0; j < n - 1; j++)
//		{
//			cin >> str;
//			cout << str << " ";
//			mymap[str] = j;
//		}
//		cin >> str;
//		cout << str << endl;
//		mymap[str] = j;
//		cin >> m;
//		for (int i = 0; i < m; i++)
//		{
//			cin >> str >> str2;
//			M[mymap[str]][mymap[str2]] = 1;
//			M[mymap[str2]][mymap[str]] = 1;
//		}
//		
//		Graph G(n, M);
//		G.Show();
//		G.DFS();
//		cout << endl;
//
//		for (int i = 0; i < n; i++)
//			delete[]M[i];
//		delete[]M;
//	}
//	return 0;
//}