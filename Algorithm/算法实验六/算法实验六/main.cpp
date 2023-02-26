#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<list>
#include <utility>
#include <fstream>
#include <stack>
#include<time.h>
#include<Windows.h>
using namespace std;

vector<int> fathers;

string test = "test.txt";
string onDuty1 = "onDuty1.txt";
string onDuty2 = "onDuty2.txt";
string big5 = "big5.txt";//5个医生
string big10 = "big10.txt";//10个医生
string big15 = "big15.txt";//15个医生
string mode = big5;

void initial(int num)
{
	fathers.resize(num, 0);
}

void showGraph(vector<list<pair<int, int>>>& graph, string type = "origin")
{
	int num = graph.size();
	if (type == "result")//输出流是怎么流的
	{
		cout << "final flow->" << endl;
		vector<list<pair<int, int>>> result(num);
		for (int x = 0; x < num; x++)
		{
			for (auto& y : graph[x])
				if (y.first < x)//反向边
					result[y.first].push_back(make_pair(x, y.second));
		}
		for (int i = 0; i < num; i++)
		{
			cout << i << ": ";
			for (auto& x : result[i])
				cout << i << "-" << x.first << ":" << x.second << " ";
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			cout << i << ": ";
			for (auto& x : graph[i])
				cout << i << "-" << x.first << ":" << x.second << " ";
			cout << endl;
		}
		cout << endl;
	}
}

bool EK_BFS(vector<list<pair<int, int>>>& graph)
{
	vector<int> visited(graph.size(), 0);
	queue<int> que;
	que.push(0);//将源点压入
	fathers[0] = 0;
	visited[0] = 1;
	int x;
	int tail = graph.size() - 1;
	while (!que.empty())
	{
		x = que.front();
		que.pop();
		for (auto& y : graph[x])
		{
			if (visited[y.first])
				continue;
			fathers[y.first] = x;
			visited[y.first] = 1;
			que.push(y.first);
			if (y.first == tail)
			{
				return true;
			}
		}	
	}
	return false;
}

void EK(vector<list<pair<int, int>>>& graph)
{
	while (1)
	{
		if (EK_BFS(graph) == false)
			break;
		else//更改残存网络
		{
			int minc = 9999;
			int father,son;
			stack<int> path;
			path.push(graph.size() - 1);
			while (path.top())//逆向遍历路径求最小c
			{
				son = path.top();
				father = fathers[son];
				for (auto& y : graph[father])
				{
					if (y.first == son)
					{
						minc = min(minc, y.second);
						break;
					}
				}
				path.push(father);
			}

			//正向更改路径残存值，并加反向边
			father = path.top();
			path.pop();
			while (!path.empty())
			{
				int flag = 0;//标志不存在反向边
				son = path.top();
				path.pop();
				for (auto itn = graph[father].begin(); itn!= graph[father].end(); itn++)
				{
					if (itn->first == son)
					{
						itn->second -= minc;
						if (itn->second == 0)
							graph[father].erase(itn);
						break;
					}
				}
				for (auto& y : graph[son])
				{
					if (y.first == father)
					{
						y.second += minc;
						flag = 1;
					}
				}
				if (flag == 0)
					graph[son].push_back(make_pair(father, minc));
				father = son;
			}
		}

		//showGraph(graph);//输出邻接表
	}
}

void test1()
{
	//创建邻接表
	//pair第一个分量为邻居下标，第二个分量为该边容量
	vector<list<pair<int,int>>> graph;
	fstream myFile;
	string path = "D:\\BaiduNetdiskDownload\\文件\\02学校各科资料\\03_大二下\\01_算法\\实验\\实验六\\";
	myFile.open(path + mode, ios::in);
	if (myFile.is_open())
	{
		string line;
		getline(myFile, line);
		int num = atoi(line.c_str());//节点数
		cout << "num = " << num << endl;
		initial(num);
		graph.resize(num);
		getline(myFile, line);
		int arc_num = atoi(line.c_str());//边数
		cout << "arc_num = " << arc_num << endl;
		int m, n, cap;
		int total_cap = 0;//计算输出最大容量
		while (myFile >> m >> n >>cap)
		{
			if (m == 0)
			{
				total_cap += cap;
			}
			graph[m].push_back(make_pair(n,cap));
		}
		myFile.close();
		//showGraph(graph);//输出邻接表
		//调用EK算法
		//auto begin = clock();
		LARGE_INTEGER freq_;
		QueryPerformanceFrequency(&freq_);
		LARGE_INTEGER begin_time;
		LARGE_INTEGER end_time;
		QueryPerformanceCounter(&begin_time);
		EK(graph);
		auto end = clock();
		QueryPerformanceCounter(&end_time);
		double ns_time = (end_time.QuadPart - begin_time.QuadPart) * 1.0 / freq_.QuadPart;
		cout << mode << endl;
		cout << "耗时：" << ns_time*1000 << "ms" << endl;
		//cout << "耗时：" << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
		//showGraph(graph, "result");//输出邻接表
		int total_c = 0;//总残存量
		for (auto& y : graph[0])
		{
			total_c += y.second;
		}
		cout << "最大流值 = " << total_cap - total_c << endl;
	}
}

//void test2()
//{
//	//创建邻接表
//	//pair第一个分量为邻居下标，第二个分量为该边容量
//	vector<list<pair<int, int>>> graph;
//	int doctors_num = 5;
//	int holidays_num = 7;
//	vector<int> doctors(doctors_num, holidays_num);//5个医生，每个医生可以取4个假期
//	//int dates[] = { 3,3,3,5,1,1,7 };
//	int dates[] = { 2,3 };
//	int count = 0;
//	//第一层
//	for (int i = 0; i < doctors_num; i++)
//	{
//		cout << 0 << " " << i + 1 << " " << holidays_num << endl;
//		count++;
//	}
//	//第二层
//	count++;
//	for (int i = 1; i < doctors_num+1; i++)
//	{
//		for (int j = 0; j < holidays_num; j++)
//		{
//			cout << i << " " << count << " " << 1 << endl;
//			count++;
//		}
//	}
//	//第三层
//	for (int i = 1+ doctors_num; i < doctors_num + 1+ holidays_num* doctors_num; i++)
//	{
//		for (int j = 0; j < holidays_num; j++)
//		{
//			cout << i << " " << count << " " << 1 << endl;
//			count++;
//		}
//	}
//	
//}

int main()
{
	test1();
	return 0;
}