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
string big5 = "big5.txt";//5��ҽ��
string big10 = "big10.txt";//10��ҽ��
string big15 = "big15.txt";//15��ҽ��
string mode = big5;

void initial(int num)
{
	fathers.resize(num, 0);
}

void showGraph(vector<list<pair<int, int>>>& graph, string type = "origin")
{
	int num = graph.size();
	if (type == "result")//���������ô����
	{
		cout << "final flow->" << endl;
		vector<list<pair<int, int>>> result(num);
		for (int x = 0; x < num; x++)
		{
			for (auto& y : graph[x])
				if (y.first < x)//�����
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
	que.push(0);//��Դ��ѹ��
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
		else//���Ĳд�����
		{
			int minc = 9999;
			int father,son;
			stack<int> path;
			path.push(graph.size() - 1);
			while (path.top())//�������·������Сc
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

			//�������·���д�ֵ�����ӷ����
			father = path.top();
			path.pop();
			while (!path.empty())
			{
				int flag = 0;//��־�����ڷ����
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

		//showGraph(graph);//����ڽӱ�
	}
}

void test1()
{
	//�����ڽӱ�
	//pair��һ������Ϊ�ھ��±꣬�ڶ�������Ϊ�ñ�����
	vector<list<pair<int,int>>> graph;
	fstream myFile;
	string path = "D:\\BaiduNetdiskDownload\\�ļ�\\02ѧУ��������\\03_�����\\01_�㷨\\ʵ��\\ʵ����\\";
	myFile.open(path + mode, ios::in);
	if (myFile.is_open())
	{
		string line;
		getline(myFile, line);
		int num = atoi(line.c_str());//�ڵ���
		cout << "num = " << num << endl;
		initial(num);
		graph.resize(num);
		getline(myFile, line);
		int arc_num = atoi(line.c_str());//����
		cout << "arc_num = " << arc_num << endl;
		int m, n, cap;
		int total_cap = 0;//��������������
		while (myFile >> m >> n >>cap)
		{
			if (m == 0)
			{
				total_cap += cap;
			}
			graph[m].push_back(make_pair(n,cap));
		}
		myFile.close();
		//showGraph(graph);//����ڽӱ�
		//����EK�㷨
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
		cout << "��ʱ��" << ns_time*1000 << "ms" << endl;
		//cout << "��ʱ��" << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
		//showGraph(graph, "result");//����ڽӱ�
		int total_c = 0;//�ܲд���
		for (auto& y : graph[0])
		{
			total_c += y.second;
		}
		cout << "�����ֵ = " << total_cap - total_c << endl;
	}
}

//void test2()
//{
//	//�����ڽӱ�
//	//pair��һ������Ϊ�ھ��±꣬�ڶ�������Ϊ�ñ�����
//	vector<list<pair<int, int>>> graph;
//	int doctors_num = 5;
//	int holidays_num = 7;
//	vector<int> doctors(doctors_num, holidays_num);//5��ҽ����ÿ��ҽ������ȡ4������
//	//int dates[] = { 3,3,3,5,1,1,7 };
//	int dates[] = { 2,3 };
//	int count = 0;
//	//��һ��
//	for (int i = 0; i < doctors_num; i++)
//	{
//		cout << 0 << " " << i + 1 << " " << holidays_num << endl;
//		count++;
//	}
//	//�ڶ���
//	count++;
//	for (int i = 1; i < doctors_num+1; i++)
//	{
//		for (int j = 0; j < holidays_num; j++)
//		{
//			cout << i << " " << count << " " << 1 << endl;
//			count++;
//		}
//	}
//	//������
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