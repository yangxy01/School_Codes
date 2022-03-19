//#include<iostream>
//#include<queue>
//using namespace std;
//
//struct Arc
//{
//	int Adjver;
//	double weight;
//	Arc* NextArc=NULL;
//};
//struct Vertex
//{
//	int data;
//	Arc* firstArc=NULL;
//};
//
//
//class Graph
//{
//private:
//	int Vernum, Arcnum;
//	Vertex* VerHead;
//public:
//	Graph() { VerHead = NULL; Vernum = 0; Arcnum = 0; }
//	Graph(int Vnum,int Anum)
//	{
//		int left, right;
//		double weight;
//		Vernum = Vnum; 
//		Arcnum = Anum;
//		VerHead = new Vertex[Vernum];
//		for (int i = 0; i < Arcnum; i++)
//		{
//			cin >> left >> right >> weight;
//			Insert(left, right, weight);
//		}
//	}
//	~Graph()
//	{
//		if (VerHead)
//		{
//			delete[]VerHead;
//		}
//	}
//	void Insert(int x, int y, double weight)
//	{
//		if (VerHead[x].firstArc == NULL || VerHead[x].firstArc->Adjver > y)
//		{
//			Arc* p = new Arc;
//			p->Adjver = y;
//			p->NextArc = VerHead[x].firstArc;
//			p->weight = weight;
//			VerHead[x].firstArc = p;
//		}
//		else
//		{
//			Arc* p = VerHead[x].firstArc;
//			Arc* newarc = new Arc;
//			newarc->Adjver = y;
//			newarc->weight = weight;
//			while (p->NextArc)
//			{
//				Arc* q = p->NextArc;
//				if (q->Adjver > y)
//				{
//					newarc->NextArc = q;
//					p->NextArc = newarc;
//					break;
//				}
//				p = p->NextArc;
//			}
//			if (p->NextArc==NULL)
//			{
//				newarc->NextArc = NULL;
//				p->NextArc = newarc;
//			}
//		}
//	}
//	void Longest()
//	{
//		
//		int visited[8] = { 0 };
//		visited[5] = 1;
//		for (int end = 0; end < 8; end++)
//		{
//			queue<int> path;
//			double sum = 0;
//			if (end != 5)
//			{
//				queue<int> p;
//				double tmp = 0;
//				p.push(5);
//				DFSutil(5, end, visited, p, path, tmp, sum);
//				if (end != 0)
//				{
//					while (path.size() > 1)
//					{
//						cout << path.front() << " ";
//						path.pop();
//					}
//					cout << path.front() << endl;
//					path.pop();
//				}
//				else
//				{
//					while (path.size() > 0)
//					{
//						cout << path.front() << " ";
//						path.pop();
//					}
//					cout << endl;
//				}
//			}
//		}
//	}
//	void DFSutil(int i,int end, int visited[8], queue<int> p, queue<int> &path, double tmp, double& sum)
//	{
//		Arc* parc = VerHead[i].firstArc;
//		while (parc)
//		{
//			if (visited[parc->Adjver] == 0)
//			{
//				if (parc->Adjver == end)
//				{
//					queue<int> pa = p;
//					tmp += parc->weight;
//					pa.push(parc->Adjver);
//					if (tmp > sum)
//					{
//						path = pa;
//						sum = tmp;
//					}
//						
//				}
//				else
//				{
//					visited[parc->Adjver] = 1;
//					queue<int> pa = p;
//					tmp += parc->weight;
//					pa.push(parc->Adjver);
//					DFSutil(parc->Adjver, end, visited, pa, path,tmp,sum);
//					visited[parc->Adjver] = 0;
//				}
//			}
//			parc = parc->NextArc;
//		}
//	}
//};
//
//
//int main()
//{
//	int Vernum, Arcnum;
//	cin >> Vernum >> Arcnum;
//	Graph G(Vernum, Arcnum);
//	G.Longest();
//	return 0;
//}