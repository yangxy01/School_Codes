//#include<iostream>
//#include <algorithm>   
//#include <vector>
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
//			{
//				if(M[i][j])
//					Matrix[i][j] = M[i][j];
//				else
//					Matrix[i][j] = 9999;
//			}
//	}
//	~Graph()
//	{
//		for (int i = 0; i < Vernum; i++)
//			delete[]Matrix[i];
//		delete[]Matrix;
//		Matrix = NULL;
//	}
//
//	void ShortestPath_Dij(int v0,int no)
//	{
//		int i, j, k, StartVer, NewStart=0, min, max = 9999;
//		int* dist = new int[Vernum];
//		int* finish = new int[Vernum];
//		for (i = 0; i < Vernum; i++)
//			finish[i] = 0;
//		int** path = new int* [Vernum];
//		for (i = 0; i < Vernum; i++)
//		{
//			path[i] = new int[Vernum + 1];//path[i]��λ��ʾ��i���˶��ٸ�����
//			path[i][0] = 0;
//		}
//		int* cost = new int[Vernum];
//
//		StartVer = v0;
//		//��ʼ�㵽ÿһ����ľ������dist����
//		for (j = 0; j < Vernum; j++)
//		{
//			if (j != StartVer)
//			{
//				dist[j] = max;
//				if (Matrix[StartVer][j] < dist[j])//��ʼ�㵽j�����С������ֵ
//				{
//					dist[j] = Matrix[StartVer][j];//���µ�j��ľ���
//					path[j][0] = 1;//��j����1������
//					path[j][1] = j;//��ŵ�j���·��
//					cost[j] = Matrix[StartVer][j];//��¼�߹����Ĵ���
//				}
//			}
//		}
//		dist[StartVer] = 0;
//		finish[StartVer] = 1;//��ǿ�ʼ�㴦����
//		for (i = 0; i < Vernum; i++)
//		{
//			min = max;
//			for (j = 0; j < Vernum; j++)
//			{
//				if (finish[j] != 1)//����δ���ʵĶ���
//				{
//					//Ϊ���ҵ�������ʼ������Ķ���
//					if (dist[j] < min)
//					{
//						min = dist[j];
//						NewStart = j;//NewStartΪ���뵱ǰ�������Ķ���
//					}
//				}
//			}
//
//			//�ҵ��˵�ǰ��㵽�ڽ��������·�����յ�ΪNewStart
//			finish[NewStart] = 1;//�������㴦����
//
//			//���µ�ǰ���·��������
//			for (j = 0; j < Vernum; j++)
//			{
//				if (finish[j] != 1 && min + Matrix[NewStart][j] < dist[j])//����δ���ʵĵ�ǰ�����ڽ�����
//				{
//					dist[j] = min + Matrix[NewStart][j];//������ʼ�㵽j��ľ���
//					int num = path[NewStart][0];//�Ǽ�·��
//					for (k = 1; k <= num; k++)//�Ǽ�·��
//						path[j][k] = path[NewStart][k];
//					path[j][k] = j;
//					path[j][0] = num + 1;
//					cost[j] = cost[NewStart]+Matrix[NewStart][j];//���´���
//				}
//			}
//		}
//		vector<int> vec;
//		for (i = 0; i < Vernum; i++)
//		{
//			if (i != StartVer)
//			{
//				vec.push_back(cost[i]);
//			}
//		}
//		sort(vec.begin(), vec.end());
//		for (i = 1; i < no; i++)
//		{
//			min = vec.front();
//			int count = 0;
//			for (auto it : vec)
//			{
//				if (it == min)
//					count++;
//				else
//					break;
//			}
//			while (count--)
//				vec.erase(vec.begin());
//		}
//		min = vec.front();
//		vector<int> vec2;
//		for (i = 0; i < Vernum; i++)
//			if (cost[i] == min)
//				vec2.push_back(i);
//		for (i = 0; i < vec2.size()-1; i++)
//			cout << vec2[i] << " ";
//		cout << vec2[vec2.size() - 1] << endl;
//
//		delete[]dist, finish, cost;
//		for (i = 0; i < Vernum; i++)
//			delete[]path[i];
//		delete[]path;
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
//		int** Matrix= new int* [n];
//		for (int i = 0; i < n; i++)
//			Matrix[i] = new int[n];
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				cin >> Matrix[i][j];
//
//		Graph G(Matrix, n);
//		int v0,v;
//		cin >> v0>>v;
//		G.ShortestPath_Dij(v0,v);
//
//		for (int i = 0; i < n; i++)
//			delete[]Matrix[i];
//		delete[]Matrix;
//		Matrix = NULL;
//	}
//	return 0;
//}