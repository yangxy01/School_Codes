//#include<iostream>
//using namespace std;
//
//struct ArcNode 
//{      
//	int AdjVex;	
//	int Weight=0;	
//	ArcNode* NextArc;	
//};
//
//struct VexNode 
//{	
//	char Data;	
//	ArcNode* firstArc;	
//};
//
//class Graph 
//{			
//	int  VertexNum;			
//	VexNode* AdjList;		
//
//public:
//	Graph(int VN = 0, int AN = 0)
//	{	
//		int  i, ArcNum;	
//		char x, y;
//		VertexNum = VN;			
//		AdjList = new VexNode[VertexNum];
//		for (i = 0; i < VertexNum; i++) 
//		{
//			cin >> AdjList[i].Data;	
//			AdjList[i].firstArc = NULL;
//		}	
//		ArcNum=AN;			
//		for (i = 0; i < ArcNum; i++) 
//		{
//			cin >> x >> y;		
//			InsertLinkList(x, y);	
//		}
//	}
//
//	void InsertLinkList(char x, char y) 
//	{
//		int i, j;	
//		ArcNode* p, * q;
//		i = GetVexNodeNo(x);		
//		j = GetVexNodeNo(y);
//		q = new ArcNode;			
//		q->AdjVex = j;			
//		q->NextArc = NULL;
//		if ((AdjList[i].firstArc == NULL) || (AdjList[i].firstArc->AdjVex > j)) 
//		{
//			q->NextArc = AdjList[i].firstArc;	
//			AdjList[i].firstArc = q;
//		}
//		else 
//		{
//			p = AdjList[i].firstArc;
//			while ((p->NextArc) && (p->NextArc->AdjVex < j))
//				p = p->NextArc;
//			q->NextArc = p->NextArc;	
//			p->NextArc = q;
//		}
//	}
//
//	int GetVexNodeNo(char c)	
//	{
//		int j;
//		for (j = 0; j < VertexNum; j++)
//			if (AdjList[j].Data == c) 
//				break;
//		return j;
//	}
//
//	void Traverse()
//	{
//		for (int i = 0; i < VertexNum; i++)
//		{
//			cout << i << " " << AdjList[i].Data;
//			ArcNode* p = AdjList[i].firstArc;
//			if (p)
//			{
//				cout << "-" << p->AdjVex;
//				while (p->NextArc)
//				{
//					p = p->NextArc;
//					cout << "-" << p->AdjVex;
//				}
//				cout << "-^" << endl;
//			}
//			else
//				cout << "-^" << endl;
//		}
//	}
//
//};
//
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int  ArcNum, VertexNum;
//		cin >> VertexNum >> ArcNum;
//		Graph G(VertexNum, ArcNum);
//		G.Traverse();
//	}
//
//}