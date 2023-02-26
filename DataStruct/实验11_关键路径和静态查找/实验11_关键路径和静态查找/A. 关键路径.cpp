//#include<iostream>
//#include<vector>
//#include<string>
//#include<stack>
//#include<queue>
//using namespace std;
//
//class Vertex
//{
//public:
//	int index;
//	bool hasEnterQueue;
//	int early, later, indegree;
//	Vertex(int no)
//	{
//		index = no;
//		hasEnterQueue = false;
//		early = 0;
//		later = 0x7FFF;
//		indegree = 0;
//	}
//	void updateEarly()
//	{
//
//	}
//};
//
//class Graph
//{
//public:
//	vector<Vertex> vertexs;
//	vector<vector<int>> Matrix;
//	int Vernum;
//	Graph(int n = 0) { Vernum = n; }
//	void Creaate()
//	{
//		Matrix.resize(Vernum);
//		for (int i = 0; i < Vernum; i++)
//		{
//			Vertex ver(i);
//			vertexs.push_back(ver);
//			Matrix[i].resize(Vernum);
//		}
//		int m, a, b, time;
//		cin >> m;
//		while (m--)
//		{
//			cin >> a >> b >> time;
//			Matrix[a][b] = time;
//			vertexs[b].indegree++;
//		}
//	}
//	void Show()
//	{
//		for (int i = 0; i < Vernum; i++)
//		{
//			for (int j = 0; j < Vernum; j++)
//			{
//				cout << Matrix[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//		for (int i = 0; i < Vernum; i++)
//			cout << vertexs[i].indegree << " ";
//		cout << endl;
//	}
//	void CriticalPath()
//	{
//		stack<int> st;
//		TopoOrder(st);
//		while (st.size() > 0)
//		{
//			int ver = st.top();
//			st.pop();
//			for (int i = 0; i < Vernum; i++)
//			{
//				if (ver != i && Matrix[i][ver] != 0)
//				{
//					if (vertexs[ver].later - Matrix[i][ver] < vertexs[i].later)
//						vertexs[i].later = vertexs[ver].later - Matrix[i][ver];
//				}
//			}
//		}
//		for (int i = 0; i < Vernum; i++)
//			cout << vertexs[i].early << " ";
//		cout << endl;
//		for (int i = 0; i < Vernum; i++)
//			cout << vertexs[i].later << " ";
//		cout << endl;
//	}
//	bool TopoOrder(stack<int>& st)
//	{
//		queue<int> s;
//		for (int i = 0; i < Vernum; i++)
//		{
//			if (vertexs[i].indegree == 0)
//				s.push(i);
//		}
//		int count = 0;
//		while (s.size() > 0)
//		{
//			int ver = s.front();
//			st.push(ver);
//			s.pop();
//			count++;
//			for (int j = 0; j < Vernum; j++)
//			{
//				if (ver!= j && Matrix[ver][j] != 0)
//				{
//					vertexs[j].indegree--;
//					if (vertexs[j].indegree == 0)
//						s.push(j);
//					if (vertexs[ver].early + Matrix[ver][j] > vertexs[j].early)
//						vertexs[j].early = vertexs[ver].early + Matrix[ver][j];
//				}
//			}
//			if(count==Vernum)
//				vertexs[ver].later = vertexs[ver].early;
//		}
//		if (count < Vernum)
//			return false;
//		return true;
//	}
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	Graph G(n);
//	G.Creaate();
//	G.CriticalPath();
//	
//	return 0;
//}