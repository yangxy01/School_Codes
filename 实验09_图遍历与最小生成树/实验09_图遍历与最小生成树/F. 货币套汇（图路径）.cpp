#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<bitset>
#include<queue>
using namespace std;

class Graph
{
private:
	int* visited;
	double** Matrix;
	int flag;
	vector<string> names;
	int Vernum;
	void DFSuntil(int start,int v,int num, double cost)
	{
		for (int j = 0; j < Vernum; j++)
		{
			if (Matrix[v][j]&&num<Vernum&&flag==0)
			{
				if (j==start&&cost * Matrix[v][j] > 1)
				{
					flag = 1;
					return;
				}
				DFSuntil(start,j,++num,cost* Matrix[v][j]);
			}
		}
	}
public:
	Graph() { visited = NULL; Matrix = NULL; Vernum = 0; flag = 0; }
	Graph(int num, double** m, vector<string> names)
	{
		flag = 0;
		Vernum = num;
		Matrix = new double* [Vernum];
		visited = new int[Vernum];
		this->names = names;
		for (int i = 0; i < Vernum; i++)
		{
			Matrix[i] = new double[Vernum];
		}
		for (int i = 0; i < Vernum; i++)
		{
			visited[i] = 0;
			for (int j = 0; j < Vernum; j++)
			{
				Matrix[i][j] = m[i][j];
			}
		}
	}
	~Graph()
	{
		for (int i = 0; i < Vernum; i++)
			delete[]Matrix[i];
		delete[]Matrix;
		delete[]visited;
	}
	void DFS(int sorce = 0)
	{
		double cost = 1;
		int num = 0;
		for (int i = 0; i < Vernum&& flag == 0; i++)
			DFSuntil(i,i,num,cost);
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	void Show()
	{
		for (int i = 0; i < Vernum; i++)
		{
			int j;
			for (j = 0; j < Vernum - 1; j++)
				cout << Matrix[i][j] << " ";
			cout << Matrix[i][j] << endl;
		}
	}
	

};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, j;
		string str, str2;
		vector<string> names;
		cin >> n>>m;
		double** M = new double* [n];
		for (int i = 0; i < n; i++)
			M[i] = new double[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = 0;
		map<string, int> mymap;
		for (j = 0; j < n; j++)
		{
			cin >> str;
			names.push_back(str);
			mymap[str] = j;
		}

		double weight;
		for (int i = 0; i < m; i++)
		{
			cin >> str >> weight>> str2 ;
			M[mymap[str]][mymap[str2]] = weight;
		}

		Graph G(n, M, names);
		G.DFS();

		for (int i = 0; i < n; i++)
			delete[]M[i];
		delete[]M;
	}
	return 0;
}