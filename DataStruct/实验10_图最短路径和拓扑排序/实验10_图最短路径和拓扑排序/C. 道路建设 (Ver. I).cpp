#include<iostream>
using namespace std;

class Graph
{
private:
	int** Matrix;
	int Vernum;
public:
	Graph() { Matrix = NULL; Vernum = 0; }
	Graph(int** M, int num)
	{
		Vernum = num;
		Matrix = new int* [Vernum];
		for (int i = 0; i < Vernum; i++)
			Matrix[i] = new int[Vernum];
		for (int i = 0; i < Vernum; i++)
			for (int j = 0; j < Vernum; j++)
			{
				Matrix[i][j] = M[i][j];
			}
	}
	~Graph()
	{
		for (int i = 0; i < Vernum; i++)
			delete[]Matrix[i];
		delete[]Matrix;
		Matrix = NULL;
	}
	void Prim(int start)
	{
		int* visited = new int[Vernum];
		int j, count = 1,total=0;
		for (j = 0; j < Vernum; j++)
			visited[j] = 0;
		struct Closedge
		{
			int lowcost;
			int adj;
		};
		Closedge* closedge = new Closedge[Vernum];
		for (int i = 0; i < Vernum; i++)
		{
			closedge[i].adj = -1;
			closedge[i].lowcost = 9999;
		}
		visited[start] = 1;
		for (int i = 0; i < Vernum; i++)
		{
			if (i!=start)
			{
				closedge[i].lowcost = Matrix[start][i];
				closedge[i].adj = start;
			}
		}
		while (count < Vernum)
		{
			int low = 9999;
			int lowindex = 0;
			for (int i = 0; i < Vernum; i++)
			{
				if (closedge[i].lowcost < low && visited[i] != 1)
				{
					low = closedge[i].lowcost;
					lowindex = i;
				}
			}
			total += low;
			count++;
			visited[lowindex] = 1;
			for (int i = 0; i < Vernum; i++)
			{
				if (lowindex!=i && visited[i] != 1 && Matrix[lowindex][i] < closedge[i].lowcost)
				{
					closedge[i].lowcost = Matrix[lowindex][i];
					closedge[i].adj = lowindex;
				}
			}

		}
		cout << total << endl;
		delete[]closedge,visited;
	}
	void show()
	{
		for (int i = 0; i < Vernum; i++)
		{
			for (int j = 0; j < Vernum; j++)
				cout << Matrix[i][j] << " ";
			cout << endl;
		}
	}
	
};

int main()
{
	int n;
	while (cin >> n)
	{
		int** Matrix = new int* [n];
		for (int i = 0; i < n; i++)
			Matrix[i] = new int[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> Matrix[i][j];
		int Q,x,y;
		cin >> Q;
		while (Q--)
		{
			cin >> x >> y;
			Matrix[x-1][y-1] = 0;
			Matrix[y-1][x-1] = 0;
		}
		Graph G(Matrix, n);
		G.show();
		G.Prim(x-1);

		for (int i = 0; i < n; i++)
			delete[]Matrix[i];
		delete[]Matrix;
		Matrix = nullptr;
	}
	return 0;
}