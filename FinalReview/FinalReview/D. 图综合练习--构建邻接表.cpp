////#include<iostream>
////#include<string>
////#include<list>
////#include<vector>
////using namespace std;
////
////struct ArcNode
////{
////	int AdjVex;
////	int weight=0;
////};
////
////struct VerNode
////{
////	char data;
////	list<ArcNode> ls;
////};
////
////class Graph
////{
////	vector<VerNode> AdjList;
////	int VertexNum;
////public:
////	Graph(int VN = 0, int AN = 0)
////	{
////		AdjList.resize(VN);
////		int  i, ArcNum;
////		char x, y;
////		VertexNum = VN;
////		for (i = 0; i < VertexNum; i++)
////		{
////			cin >> AdjList[i].data;
////		}
////		ArcNum = AN;
////		for (i = 0; i < ArcNum; i++)
////		{
////			cin >> x >> y;
////			InsertLinkList(x, y);
////		}
////	}
////	void InsertLinkList(char x, char y)
////	{
////		int i, j;
////		ArcNode* p, * q;
////		i = GetVexNodeNo(x);
////		j = GetVexNodeNo(y);
////		ArcNode node = { j,0 };
////		list<ArcNode>& ls = AdjList[i].ls;
////		auto it = ls.begin();
////		if (ls.size() == 0)
////			ls.push_back(node);
////		else
////		{
////			for (it = ls.begin(); it != ls.end(); it++)
////			{
////				if (j < it->AdjVex)
////					break;
////			}
////			ls.insert(it, node);
////		}
////	}
////
////	int GetVexNodeNo(char c)
////	{
////		int j;
////		for (j = 0; j < VertexNum; j++)
////			if (AdjList[j].data == c)
////				break;
////		return j;
////	}
////
////	void Traverse()
////	{
////		for (int i = 0; i < VertexNum; i++)
////		{
////			cout << i << " " << AdjList[i].data;
////			list<ArcNode> ls = AdjList[i].ls;
////			for (auto it = ls.begin(); it != ls.end(); it++)
////			{
////				cout << "-" << it->AdjVex;
////				
////			}
////			cout << "-^" << endl;
////		}
////	}
////};
////
////int main()
////{
////	int t;
////	cin >> t;
////	while (t--)
////	{
////		int  ArcNum, VertexNum;
////		cin >> VertexNum >> ArcNum;
////		Graph G(VertexNum, ArcNum);
////		G.Traverse();
////	}
////
////}
//
//
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<string>
//using namespace std;
//class ljb
//{
//private:
//    vector<string> name;
//    unordered_map<string, vector<int>> ans;
//    unordered_map<string, int> pos;
//    int size;
//public:
//    ljb(int n) :size(n) {}
//    void build()
//    {
//        int t;
//        cin >> t;
//        for (int i = 0; i < size; i++)
//        {
//            string name;
//            cin >> name;
//            ljb::name.push_back(name);
//            pos[name] = i;
//        }
//        while (t--)
//        {
//            string name1, name2;
//            cin >> name1 >> name2;
//            ans[name1].push_back(pos[name2]);
//        }
//    }
//    void print()
//    {
//        for (auto& x : name)
//        {
//            cout << pos[x] << " " << x << "-";
//            for (auto& y : ans[x])
//            {
//                cout << y << "-";
//            }
//            cout << "^" << endl;
//        }
//    }
//};
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        int n;
//        cin >> n;
//        ljb l(n);
//        l.build();
//        l.print();
//    }
//}