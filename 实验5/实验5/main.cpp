#include<iostream>
#include<vector>
#include<list>
#include <fstream>
#include <string>
#include<queue>
#include<time.h>
#include<Windows.h>
using namespace std;

struct Point {
	int val;
	int edge_visited=0;//��ʾ���ǲ��Ƿ��ʹ���1��ʾvisited��0��ʾδvisited
};

vector<int> depth;
vector<int> visited;//1��ʾvisited��0��ʾδvisited
vector<int> fathers;
vector<pair<int, int>> no_tree_edge;//�����������м�¼������
vector<int> edge2node;//�����õ��ʾ

string smalls = "small.txt";
string medium = "mediumDG.txt";
string large = "largeG.txt";
string scale = large;


void initial(int num)
{
	depth.resize(num, 0);
	visited.resize(num, 0);
	fathers.resize(num, 0);
	edge2node.resize(num, 0);
	for (int i = 0; i < num; i++)
		fathers[i] = i;
	no_tree_edge.resize(0);
}

bool BFS(vector<list<int>>& graph, int m, int n)
{
	vector<int> visited(graph.size());
	queue<int> que;
	que.push(m);
	visited[m] = 1;
	int x;
	bool state = false;
	while (!que.empty())
	{
		x = que.front();
		que.pop();
		if (x == n)
		{
			state = true;
			break;
		}
		for (auto y : graph[x])
		{
			if (visited[y] == 0)
			{
				que.push(y);
				visited[y] = 1;
			}
		}
	}
	return state;
}

//�Ż��汾find
inline int Find_opt(int x, vector<int>& fathers)
{
	//�ݹ�д��
	//if (fathers[x] == x)//x�������ϵĴ���Ԫ��Ϊ����
	//	return x;
	//else
	//{
	//	fathers[x] = Find(x, fathers);
	//	return fathers[x];
	//}

	//�ǵݹ�д��
	int final = x;
	while (fathers[final] != final)
		final = fathers[final];
	int i = x, j;
	while (i != final)//·��ѹ��
	{
		j = fathers[i];
		fathers[i] = final;
		i = j;
	}
	return final;
}

//��ͨ�汾find
inline int Find(int x, vector<int>& fathers)
{
	//�ݹ�д��
	if (fathers[x] == x)//x�������ϵĴ���Ԫ��Ϊ����
		return x;
	else
	{
		fathers[x] = Find(x, fathers);
		return fathers[x];
	}
}

void Union(int x, int y, vector<int>& fathers,string type="opt")
{
	if (type == "opt")
	{
		int x_father = Find_opt(x, fathers);
		int y_father = Find_opt(y, fathers);
		fathers[x] = y_father;
	}
	else
	{
		int x_father = Find(x, fathers);
		int y_father = Find(y, fathers);
		fathers[x] = y_father;
	}
}

void UnionFindSets(vector<list<int>>& graph)
{
	int num = graph.size();

	//�������ϳ�ʼ������
	vector<int> fathers(num);
	for (int i = 0; i < num; i++)
		fathers[i] = i;

	//��������ͨ����union
	for (int i = 0; i < num; i++)
	{
		for (auto &j : graph[i])
		{
			Union(i, j, fathers);
		}
	}
}

void lca()
{
	for (auto& edge : no_tree_edge)
	{
		int x = edge.first, y = edge.second;
		//x�x��������ͬһ�߶�
		while (depth[x] > depth[y])
		{
			edge2node[x] = 1;
			x = fathers[x];
		}
		//y�y��������ͬһ�߶�
		while (depth[x] < depth[y])
		{
			edge2node[y] = 1;
			y = fathers[y];
		}
		//xyͬʱ�����������������
		while (x != y)
		{
			edge2node[x] = 1;
			x = fathers[x];
			edge2node[y] = 1;
			y = fathers[y];
		}
	}
}

void test1()
{
	//��ȡ����
	vector<list<int>> graph;
	vector<pair<int, int>> bridge;
	fstream myFile;
	string path = "D:\\BaiduNetdiskDownload\\�ļ�\\02ѧУ��������\\03_�����\\01_�㷨\\ʵ��\\ʵ����\\";
	myFile.open(path+ scale, ios::in);
	if (myFile.is_open())
	{
		string line;
		getline(myFile, line);
		int num = atoi(line.c_str());
		cout <<"num = "<< num << endl;
		graph.resize(num);
		getline(myFile, line);
		int arc_num = atoi(line.c_str());
		cout << "arc_num = " << arc_num << endl;
		int m, n;
		while (myFile >> m >> n)
		{
			//cout << m << " " << n << endl;
			if (m == n)
				continue;
			graph[m].push_back(n);
			graph[n].push_back(m);
		}
		myFile.close();

		LARGE_INTEGER freq_;
		QueryPerformanceFrequency(&freq_);
		LARGE_INTEGER begin_time;
		LARGE_INTEGER end_time;
		QueryPerformanceCounter(&begin_time);
		//auto begin = clock();
		//��׼�㷨
		for (int m = 0; m < num; m++)
		{
			int size = graph[m].size();
			if (size==0)
				continue;
			int count = 0;
			for (auto itn = graph[m].begin(); count < size; count++)
			{
				//ɾ����
				n = *itn;
				graph[m].erase(itn++);
				graph[n].erase(find(graph[n].begin(), graph[n].end(), m));
				if (!BFS(graph, m, n))//����ͨ
				{
					if(find(bridge.begin(), bridge.end(), make_pair(n, m))== bridge.end())//������
						bridge.push_back(make_pair(m, n));
				}
				//�ָ���
				graph[m].push_back(n);
				graph[n].push_back(m);
			}
		}
		Sleep(10);
		QueryPerformanceCounter(&end_time);
		double ns_time = (end_time.QuadPart - begin_time.QuadPart) * 1.0 / freq_.QuadPart;
		cout << "��׼��������ʱ��Ϊ" << ns_time << "ms" << endl;
		//auto end = clock();
		//cout <<"���ݼ�Ϊ"<< scale << "����׼�㷨��ʱ��" << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;


		//�����
		int bridge_num = bridge.size();
		if (bridge_num)
		{
			for (auto& b : bridge)
				cout << "bridge��" << b.first << " " << b.second << endl;
			cout << "�ŵĸ���Ϊ��" << bridge_num << endl;
		}
		else
			cout << "�ŵĸ���Ϊ��" << bridge_num << endl;
	}
}
void test2()
{
	//��ȡ����
	vector<list<Point>> graph;
	vector<pair<int, int>> bridge;
	fstream myFile;
	string path = "D:\\BaiduNetdiskDownload\\�ļ�\\02ѧУ��������\\03_�����\\01_�㷨\\ʵ��\\ʵ����\\";
	myFile.open(path + scale, ios::in);
	if (myFile.is_open())
	{
		string line;
		getline(myFile, line);
		int num = atoi(line.c_str());
		cout << "num = " << num << endl;

		//���ó�ʼ������
		initial(num);

		graph.resize(num);
		getline(myFile, line);
		int arc_num = atoi(line.c_str());
		cout << "arc_num = " << arc_num << endl;
		int m, n;
		while (myFile >> m >> n)
		{
			if (m == n)
				continue;
			graph[m].push_back({ n,0 });
			graph[n].push_back({ m,0 });
		}
		myFile.close();

		auto begin = clock();
		/*LARGE_INTEGER freq_;
		QueryPerformanceFrequency(&freq_);
		LARGE_INTEGER begin_time;
		LARGE_INTEGER end_time;
		QueryPerformanceCounter(&begin_time);*/
		//����
		for (int i = 0; i < num; i++)
		{
			//int cumulative_depth = 1;//���ڼ�¼��ǰ���ĸ߶�
			if (visited[i])//visited��
			{
				continue;
			}
			visited[i] = 1;
			//�����δvisited
			queue<int> que;//����Ҫ���ʵĵ�
			que.push(i);
			int x;
			while (!que.empty())
			{
				x = que.front();
				if(x==i)
					depth[x] = 1;
				//cumulative_depth++;
				que.pop();
				for (auto& y : graph[x])
				{
					if (visited[y.val] == 0)//δ����
					{
						que.push(y.val);
						visited[y.val] = 1;//���������Ϊ������
						y.edge_visited = 1;//x->y���������Ϊ������
						for(auto& z : graph[y.val])
							if(z.val==x)
								z.edge_visited = 1;//y->x���������Ϊ������
						fathers[y.val] = x;//y�ĸ��ڵ�Ϊx
						depth[y.val] = depth[x]+1;//�������Ϊ���ڵ�+1
					}
					else//�ñ�Ϊ������
					{
						if(y.edge_visited==0)//�����û�б����ʹ�
							no_tree_edge.push_back(make_pair(x,y.val));
						y.edge_visited = 1;//x->y���������Ϊ������
						for (auto& z : graph[y.val])
							if (z.val == x)
								z.edge_visited = 1;//y->x���������Ϊ������
					}
				}
			}
		}
		
		//����lca������
		lca();
		auto end = clock();
		cout <<"���ݼ�Ϊ"<<scale<< "�����鼯+lca��ʱ��" << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
		/*Sleep(10);
		QueryPerformanceCounter(&end_time);
		double ns_time = (end_time.QuadPart - begin_time.QuadPart) * 1.0 / freq_.QuadPart;
		cout << "���鼯+lca������ʱ��Ϊ" << ns_time << "ms" << endl;*/

		int count = 0;
		for (int i = 0; i < num; ++i)
		{
			if (edge2node[i] == 0 && i != fathers[i])
			{
				cout << i << " " << fathers[i] << endl;
				count++;
			}
		}
		cout << "����" << count << "����" << endl;
	}
}

int main()
{
	//test1();
	test2();
	return 0;
}