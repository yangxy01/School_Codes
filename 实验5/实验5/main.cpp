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
	int edge_visited=0;//表示边是不是访问过，1表示visited，0表示未visited
};

vector<int> depth;
vector<int> visited;//1表示visited，0表示未visited
vector<int> fathers;
vector<pair<int, int>> no_tree_edge;//生成树过程中记录非树边
vector<int> edge2node;//树边用点表示

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

//优化版本find
inline int Find_opt(int x, vector<int>& fathers)
{
	//递归写法
	//if (fathers[x] == x)//x所属集合的代表元素为自身
	//	return x;
	//else
	//{
	//	fathers[x] = Find(x, fathers);
	//	return fathers[x];
	//}

	//非递归写法
	int final = x;
	while (fathers[final] != final)
		final = fathers[final];
	int i = x, j;
	while (i != final)//路径压缩
	{
		j = fathers[i];
		fathers[i] = final;
		i = j;
	}
	return final;
}

//普通版本find
inline int Find(int x, vector<int>& fathers)
{
	//递归写法
	if (fathers[x] == x)//x所属集合的代表元素为自身
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

	//各个集合初始化部分
	vector<int> fathers(num);
	for (int i = 0; i < num; i++)
		fathers[i] = i;

	//将各个联通分量union
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
		//x深，x先上升至同一高度
		while (depth[x] > depth[y])
		{
			edge2node[x] = 1;
			x = fathers[x];
		}
		//y深，y先上升至同一高度
		while (depth[x] < depth[y])
		{
			edge2node[y] = 1;
			y = fathers[y];
		}
		//xy同时上升找最近公共祖先
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
	//读取数据
	vector<list<int>> graph;
	vector<pair<int, int>> bridge;
	fstream myFile;
	string path = "D:\\BaiduNetdiskDownload\\文件\\02学校各科资料\\03_大二下\\01_算法\\实验\\实验五\\";
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
		//基准算法
		for (int m = 0; m < num; m++)
		{
			int size = graph[m].size();
			if (size==0)
				continue;
			int count = 0;
			for (auto itn = graph[m].begin(); count < size; count++)
			{
				//删除边
				n = *itn;
				graph[m].erase(itn++);
				graph[n].erase(find(graph[n].begin(), graph[n].end(), m));
				if (!BFS(graph, m, n))//不联通
				{
					if(find(bridge.begin(), bridge.end(), make_pair(n, m))== bridge.end())//不存在
						bridge.push_back(make_pair(m, n));
				}
				//恢复边
				graph[m].push_back(n);
				graph[n].push_back(m);
			}
		}
		Sleep(10);
		QueryPerformanceCounter(&end_time);
		double ns_time = (end_time.QuadPart - begin_time.QuadPart) * 1.0 / freq_.QuadPart;
		cout << "基准法所花的时间为" << ns_time << "ms" << endl;
		//auto end = clock();
		//cout <<"数据集为"<< scale << "，基准算法耗时：" << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;


		//输出桥
		int bridge_num = bridge.size();
		if (bridge_num)
		{
			for (auto& b : bridge)
				cout << "bridge：" << b.first << " " << b.second << endl;
			cout << "桥的个数为：" << bridge_num << endl;
		}
		else
			cout << "桥的个数为：" << bridge_num << endl;
	}
}
void test2()
{
	//读取数据
	vector<list<Point>> graph;
	vector<pair<int, int>> bridge;
	fstream myFile;
	string path = "D:\\BaiduNetdiskDownload\\文件\\02学校各科资料\\03_大二下\\01_算法\\实验\\实验五\\";
	myFile.open(path + scale, ios::in);
	if (myFile.is_open())
	{
		string line;
		getline(myFile, line);
		int num = atoi(line.c_str());
		cout << "num = " << num << endl;

		//调用初始化函数
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
		//建树
		for (int i = 0; i < num; i++)
		{
			//int cumulative_depth = 1;//用于记录当前树的高度
			if (visited[i])//visited了
			{
				continue;
			}
			visited[i] = 1;
			//这个点未visited
			queue<int> que;//保存要访问的点
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
					if (visited[y.val] == 0)//未访问
					{
						que.push(y.val);
						visited[y.val] = 1;//这个点设置为访问了
						y.edge_visited = 1;//x->y这个边设置为访问了
						for(auto& z : graph[y.val])
							if(z.val==x)
								z.edge_visited = 1;//y->x这个边设置为访问了
						fathers[y.val] = x;//y的父节点为x
						depth[y.val] = depth[x]+1;//设置深度为父节点+1
					}
					else//该边为非树边
					{
						if(y.edge_visited==0)//这个边没有被访问过
							no_tree_edge.push_back(make_pair(x,y.val));
						y.edge_visited = 1;//x->y这个边设置为访问了
						for (auto& z : graph[y.val])
							if (z.val == x)
								z.edge_visited = 1;//y->x这个边设置为访问了
					}
				}
			}
		}
		
		//调用lca处理环边
		lca();
		auto end = clock();
		cout <<"数据集为"<<scale<< "，并查集+lca耗时：" << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
		/*Sleep(10);
		QueryPerformanceCounter(&end_time);
		double ns_time = (end_time.QuadPart - begin_time.QuadPart) * 1.0 / freq_.QuadPart;
		cout << "并查集+lca所花的时间为" << ns_time << "ms" << endl;*/

		int count = 0;
		for (int i = 0; i < num; ++i)
		{
			if (edge2node[i] == 0 && i != fathers[i])
			{
				cout << i << " " << fathers[i] << endl;
				count++;
			}
		}
		cout << "共有" << count << "个桥" << endl;
	}
}

int main()
{
	//test1();
	test2();
	return 0;
}