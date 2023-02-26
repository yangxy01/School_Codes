//#include<iostream>
//#include<map>
//#include<vector>
//#include<string>
//#include<bitset>
//#include<queue>
//using namespace std;
//
//struct edge
//{
//	int left;
//	int right;
//	int weight;
//};
//bool operator<(const edge& a, const edge& b)
//{
//	return a.weight > b.weight;
//}
//
//class Graph
//{
//private:
//	int* visited;
//	int** Matrix;
//	int** TestMatrix;
//	vector<string> names;
//	int Vernum;
//	void DFSuntil(int v)
//	{
//		visited[v] = 1;
//		for (int j = 0; j < Vernum; j++)
//		{
//			if (TestMatrix[v][j] && visited[j] == 0)
//				DFSuntil(j);
//		}
//	}
//public:
//	Graph() { visited = NULL; Matrix = NULL; Vernum = 0; TestMatrix = NULL; }
//	Graph(int num, int** m, vector<string> names)
//	{
//		Vernum = num;
//		Matrix = new int* [Vernum];
//		TestMatrix = new int* [Vernum];
//		visited = new int[Vernum];
//		this->names = names;
//		for (int i = 0; i < Vernum; i++)
//		{
//			Matrix[i] = new int[Vernum];
//			TestMatrix[i] = new int[Vernum];
//		}
//		for (int i = 0; i < Vernum; i++)
//		{
//			visited[i] = 0;
//			for (int j = 0; j < Vernum; j++)
//			{
//				Matrix[i][j] = m[i][j];
//				TestMatrix[i][j] = 0;
//			}
//		}
//	}
//	~Graph()
//	{
//		for (int i = 0; i < Vernum; i++)
//			delete[]Matrix[i];
//		delete[]Matrix;
//		delete[]visited;
//	}
//	int GetConnectivity(int source = 0)
//	{
//		int j = 0, count = 0;
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
//		return count;
//	}
//	void Show()
//	{
//		for (int i = 0; i < Vernum; i++)
//		{
//			int j;
//			for (j = 0; j < Vernum - 1; j++)
//				cout << Matrix[i][j] << " ";
//			cout << Matrix[i][j] << endl;
//		}
//	}
//	void Kruskal(priority_queue<edge>&pq)
//	{
//		cout << "kruskal:" << endl;
//		int count = 0;
//		while (count < Vernum - 1)
//		{
//			edge e = pq.top();
//			pq.pop();
//			int oldC = GetConnectivity();
//			TestMatrix[e.left][e.right] = 1;
//			TestMatrix[e.right][e.left] = 1;
//			int newC = GetConnectivity();
//			if (newC == oldC)
//			{
//				TestMatrix[e.left][e.right] = 0;
//				TestMatrix[e.right][e.left] = 0;
//			}
//			else
//			{
//				if (e.right < e.left)
//				{
//					int tmp = e.right;
//					e.right = e.left;
//					e.left = tmp;
//				}
//				cout << names[e.left] << " " << names[e.right] << " " << e.weight << endl;
//				count++;
//			}
//			
//		}
//	}
//	void Prim(int start)
//	{
//		cout << "prim:" << endl;
//		int j,count=1;
//		for (j = 0; j < Vernum; j++)
//			visited[j] = 0;
//		struct Closedge
//		{
//			int lowcost;
//			int adj;
//		};
//		Closedge* closedge = new Closedge[Vernum];
//		for (int i = 0; i < Vernum; i++)
//		{
//			closedge[i].adj = -1;
//			closedge[i].lowcost = 9999;
//		}
//		visited[start] = 1;
//		for (int i = 0; i < Vernum; i++)
//		{
//			if (Matrix[start][i])
//			{
//				closedge[i].lowcost = Matrix[start][i];
//				closedge[i].adj = start;
//			}
//		}
//		while (count < Vernum)
//		{
//			int low = 9999;
//			int lowindex = 0;
//			for (int i = 0; i < Vernum; i++)
//			{
//				if (closedge[i].lowcost < low && visited[i] != 1)
//				{
//					low = closedge[i].lowcost;
//					lowindex = i;
//				}
//			}
//			cout << names[closedge[lowindex].adj] << " " << names[lowindex] <<" "<< low << endl;
//			count++;
//			visited[lowindex] = 1;
//			for (int i = 0; i < Vernum; i++)
//			{
//				if (Matrix[lowindex][i] && visited[i] != 1 && Matrix[lowindex][i] < closedge[i].lowcost)
//				{
//					closedge[i].lowcost = Matrix[lowindex][i];
//					closedge[i].adj = lowindex;
//				}
//			}
//			/*
//7
//0 1 2 3 4 5 6 
//9
//0 1 28
//0 5 10
//1 2 16
//1 6 14
//3 2 12
//3 6 18
//4 6 24
//4 5 25
//3 4 22
//6
//			*/
//		}
//		delete[]closedge;
//	}
//	void Cost(int start)
//	{
//		int cost = 0;
//		int j, count = 1;
//		for (j = 0; j < Vernum; j++)
//			visited[j] = 0;
//		struct Closedge
//		{
//			int lowcost;
//			int adj;
//		};
//		Closedge* closedge = new Closedge[Vernum];
//		for (int i = 0; i < Vernum; i++)
//		{
//			closedge[i].adj = -1;
//			closedge[i].lowcost = 9999;
//		}
//		visited[start] = 1;
//		for (int i = 0; i < Vernum; i++)
//		{
//			if (Matrix[start][i])
//			{
//				closedge[i].lowcost = Matrix[start][i];
//				closedge[i].adj = start;
//			}
//		}
//		while (count < Vernum)
//		{
//			int low = 9999;
//			int lowindex = 0;
//			for (int i = 0; i < Vernum; i++)
//			{
//				if (closedge[i].lowcost < low && visited[i] != 1)
//				{
//					low = closedge[i].lowcost;
//					lowindex = i;
//				}
//			}
//			cost += low;
//			count++;
//			visited[lowindex] = 1;
//			for (int i = 0; i < Vernum; i++)
//			{
//				if (Matrix[lowindex][i] && visited[i] != 1 && Matrix[lowindex][i] < closedge[i].lowcost)
//				{
//					closedge[i].lowcost = Matrix[lowindex][i];
//					closedge[i].adj = lowindex;
//				}
//			}
//			
//		}
//		cout << cost << endl;
//		delete[]closedge;
//	}
//};
//
//int main()
//{
//	int n, m, j;
//	string str, str2;
//	priority_queue<edge>pq;
//	vector<string> names;
//	cin >> n;
//	int** M = new int* [n];
//	for (int i = 0; i < n; i++)
//		M[i] = new int[n];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			M[i][j] = 0;
//	map<string, int> mymap;
//	for (j = 0; j < n ; j++)
//	{
//		cin >> str;
//		names.push_back(str);
//		mymap[str] = j;
//	}
//	
//	cin >> m;
//	int weight;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> str >> str2>>weight;
//		M[mymap[str]][mymap[str2]] = weight;
//		M[mymap[str2]][mymap[str]] = weight;
//		edge e;
//		e.left = mymap[str];
//		e.right = mymap[str2];
//		e.weight = weight;
//		pq.push(e);
//	}
//
//	Graph G(n, M, names);
//	cin >> str;
//	int start = mymap[str];
//	G.Cost(start);
//	G.Prim(start);
//	G.Kruskal(pq);
//
//	for (int i = 0; i < n; i++)
//		delete[]M[i];
//	delete[]M;
//	return 0;
//}