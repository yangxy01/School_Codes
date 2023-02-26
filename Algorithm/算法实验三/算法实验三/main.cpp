#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;

class Graph
{
private:
	struct node//一个顶点
	{
		vector<int> neighbor;
		vector<int> available_col;
	};
	
	vector<node> adjlist;//邻接表
	int ver_num;//节点总数
	vector<int> colors;//用于存储一个解
	int **adj_matrix;//邻接矩阵
	int color_num;//color的总数
	int sol_num;//解的数目

	//加入限制，删除颜色
	void Modify(int i, int color)
	{
		for (int index : adjlist[i].neighbor)
		{
			if (colors[index] == 0)//未填色
			{
				adjlist[index].available_col[color]--;
				if (adjlist[index].available_col[color] == 0)
				{
					adjlist[index].available_col[0]--;
				}
			}
		}
	}

	//解除限制，恢复颜色
	void Recovery(int i, int color)
	{
		for (int index : adjlist[i].neighbor)
		{
			if (colors[index] == 0)
			{
				adjlist[index].available_col[color]++;
				if (adjlist[index].available_col[color] == 1)
				{
					adjlist[index].available_col[0]++;
				}
			}
		}
	}

	//MRV找下一个节点拓展
	int MRV_for_next()
	{
		int min = 9999, ret = -1;
		for (int i = 0; i < ver_num; i++)
		{
			if (colors[i])//已填色忽略
				continue;
			if (adjlist[i].available_col[0] < min)
			{
				min = adjlist[i].available_col[0];
				ret = i;
			}
		}
		return ret;
	}

	//MDF找下一个节点拓展
	int MRV_MDF_for_next()
	{
		int min_color = 9999, max_degree = -9999;
		int ret = -1;
		for (int i = 0; i < ver_num; i++)
		{
			if (colors[i])//已填色忽略
				continue;
			if (adjlist[i].available_col[0] < min_color)//小于最小剩余值
			{
				min_color = adjlist[i].available_col[0];
				max_degree = adjlist[i].neighbor.size();
				ret = i;
			}
			else if (adjlist[i].available_col[0] == min_color)//等于最小剩余值
			{
				if (adjlist[i].neighbor.size() > max_degree)
				{
					max_degree = adjlist[i].neighbor.size();//更新最大度
					ret = i;
				}
			}
		}
		return ret;
	}


public:
	Graph(int n, int color)
	{
		ver_num = n;
		color_num = color;
		sol_num = 0;
		adj_matrix = new int* [500];
		for (int i = 0; i < 500; i++)
		{
			adj_matrix[i] = new int[500];
		}
		for (int i = 0; i < 500; i++)
		{
			for (int j = 0; j < 500; j++)
				adj_matrix[i][j] = 0;
		}
	}
	~Graph()
	{
		for (int i = 0; i < 500; i++)
		{
			delete[]adj_matrix[i];
		}
		delete[]adj_matrix;
	}

	//把涂色的记录全清空初始化
	void initColor()
	{
		//将每个节点所有颜色置为1
		for (auto& node : adjlist)
		{
			node.available_col = vector<int>(color_num + 1, 1);
			node.available_col[0] = color_num;//可选颜色总数
		}
		colors = vector<int>(ver_num, 0);
		sol_num = 0;
	}

	void createGraph(string scale, int arc_num = 0)
	{
		//初始化邻接矩阵
		if (scale == "small")
		{
			adj_matrix[0][1] = 1;
			adj_matrix[0][2] = 1;
			adj_matrix[0][5] = 1;
			adj_matrix[1][2] = 1;
			adj_matrix[1][3] = 1;
			adj_matrix[1][5] = 1;
			adj_matrix[2][5] = 1;
			adj_matrix[3][5] = 1;
			adj_matrix[3][4] = 1;
			adj_matrix[3][6] = 1;
			adj_matrix[4][6] = 1;
			adj_matrix[4][8] = 1;
			adj_matrix[5][6] = 1;
			adj_matrix[5][7] = 1;
			adj_matrix[6][7] = 1;
			adj_matrix[6][8] = 1;
			adj_matrix[7][8] = 1;
			for (int i = 0; i < ver_num; i++)
			{
				for (int j = 0; j < ver_num; j++)
				{
					if (adj_matrix[i][j])
					{
						adj_matrix[j][i] = 1;
					}
				}
			}
		}
		else if (scale == "random")
		{
			int a = 0, b = 0;
			for (int i = 0; i < arc_num; i++)
			{
				a = rand()% ver_num;
				b = rand() % ver_num;
				if (a != b&& adj_matrix[a][b]==0)
				{
					adj_matrix[a][b] = 1;
					adj_matrix[b][a] = 1;
				}
				else
				{
					i--;
				}
			}
		}
		else
		{
			string add = "D:\\BaiduNetdiskDownload\\文件\\02学校各科资料\\03_大二下\\01_算法\\实验\\实验三\\地图数据\\" + scale + ".col";
			ifstream mapfile(add, ios::in);
			string str;
			if (!mapfile.is_open())
			{
				cout << "未成功打开文件" << endl;
			}
			while (getline(mapfile, str))
			{
				if (str[0] == 'e')
				{
					stringstream ss;
					ss << str;
					string p;
					vector<string> strs;
					while (ss >> p)
					{
						strs.push_back(p);
					}
					int m = stoi(strs[1]);
					int n = stoi(strs[2]);
					adj_matrix[m - 1][n - 1] = 1;
					adj_matrix[n - 1][m - 1] = 1;
				}
			}
			mapfile.close();
		}
		
		//初始化邻接表
		for (int i = 0; i < ver_num; i++)
		{
			adjlist.push_back(node());
			adjlist[i].available_col = vector<int>(color_num + 1, 1);
			adjlist[i].available_col[0] = color_num;
			//找邻居
			for (int j = 0; j < ver_num; j++)
			{
				if (adj_matrix[i][j])
				{
					adjlist[i].neighbor.push_back(j);
				}
			}
		}
		//初始化颜色数据
		initColor();
	}


	void Backtrack(int i)
	{
		if (i >= ver_num)
		{
			sol_num++;
			return;
		}
		for (int color = 1; color <= color_num; color++)
		{
			int flag = 1;
			for (int j = 0; j < i; j++)
			{
				if (adj_matrix[i][j] && colors[j] == color)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				colors[i] = color;
				Backtrack(i + 1);
				colors[i] = 0;
			}
		}
		return;
	}

	//MRV方法找解
	void MRV(int i, int num)//参数：下标，已处理节点数
	{
		if (num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//遍历颜色
		{
			if (adjlist[i].available_col[j]==1)
			{
				colors[i] = j;
				Modify(i, j);
				int newi = MRV_for_next();
				//cout << newi << endl;
				MRV(newi, num + 1);
				if(newi>=0)
					colors[newi] = 0;
				Recovery(i, j);
			}
		}
	}

	//MRV_MDF方法找解
	void MRV_MDF(int i, int num)//参数：下标，已处理节点数
	{
		if (num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//遍历颜色
		{
			if (adjlist[i].available_col[j] == 1)
			{
				colors[i] = j;
				Modify(i, j);
				int newi = MRV_MDF_for_next();
				MRV_MDF(newi, num + 1);
				if (newi >= 0)
					colors[newi] = 0;
				Recovery(i, j);
			}
		}
	}

	//回溯法找一个解
	void Backtrack_one(int i)
	{
		if (i >= ver_num)
		{
			sol_num++;
			return;
		}
		for (int color = 1; color <= color_num; color++)
		{
			int flag = 1;
			for (int j = 0; j < i; j++)
			{
				if (adj_matrix[i][j] && colors[j] == color)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				colors[i] = color;
				Backtrack(i + 1);
				colors[i] = 0;
			}
			if (i == 0)
				break;
		}
		return;
	}

	//MRV方法找一个解
	void MRV_one(int i, int num)//参数：下标，已处理节点数
	{
		if (sol_num >= 1 || num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//遍历颜色
		{
			if (adjlist[i].available_col[j] == 1)
			{
				colors[i] = j;
				Modify(i, j);
				int newi = MRV_for_next();
				//cout << newi << endl;
				MRV_one(newi, num + 1);
				if (newi >= 0)
					colors[newi] = 0;
				Recovery(i, j);
			}
		}
	}

	//MRV_MDF方法找一个解
	void MRV_MDF_one(int i, int num)//参数：下标，已处理节点数
	{
		if (sol_num >= 1 || num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//遍历颜色
		{
			if (adjlist[i].available_col[j] == 1)
			{
				colors[i] = j;
				Modify(i, j);
				int newi = MRV_MDF_for_next();
				MRV_MDF_one(newi, num + 1);
				if (newi >= 0)
					colors[newi] = 0;
				Recovery(i, j);
			}
		}
	}

	//MRV+对称找解
	void MRV_symmetric(int i, int num)//参数：下标，已处理节点数
	{
		if (num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//遍历颜色
		{
			if (adjlist[i].available_col[j] == 1)
			{
				colors[i] = j;
				Modify(i, j);
				int newi = MRV_for_next();
				//cout << newi << endl;
				MRV_symmetric(newi, num + 1);
				if (newi >= 0)
					colors[newi] = 0;
				Recovery(i, j);
			}
			if (i == 0)
				break;
		}
	}

	//MRV_MDF+对称找解
	void MRV_MDF_symmetric(int i, int num)//参数：下标，已处理节点数
	{
		if (num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//遍历颜色
		{
			if (adjlist[i].available_col[j] == 1)
			{
				colors[i] = j;
				Modify(i, j);
				int newi = MRV_MDF_for_next();
				MRV_MDF_symmetric(newi, num + 1);
				if (newi >= 0)
					colors[newi] = 0;
				Recovery(i, j);
			}
			if (i == 0)
				break;
		}
	}

	int Get_sol_num()//解的个数
	{
		return sol_num;
	}


	void showGraph()
	{
		for (int i = 0; i < ver_num; i++)
		{
			for (int j = 0; j < ver_num; j++)
			{
				cout << adj_matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

void smallScale()
{
	srand((unsigned)time(nullptr));
	clock_t begin, end;
	double time = 0;
	int count = 0;

	int ver_num = 9;//顶点数
	int color_num = 4;//颜色数

	Graph G(ver_num, color_num);
	G.createGraph("small");
	G.showGraph();

	//普通回溯
	G.initColor();
	begin = clock();
	G.Backtrack(0);
	end = clock();
	time = (double)(end - begin);
	count = G.Get_sol_num();
	if (count)
	{
		cout <<"普通回溯法共有"<<count<<"组可行解"<< endl;
		cout << "耗时：" << time << "ms" << endl;
	}
	else
		cout << "普通回溯法不存在解" << endl;

	//MRV
	G.initColor();
	begin = clock();
	G.MRV(0, 0);
	end = clock();
	time = (double)(end - begin);
	count = G.Get_sol_num();
	if (count)
	{
		cout << "MRV共有" << count << "组可行解" << endl;
		cout << "耗时：" << time << "ms" << endl;
	}
	else
		cout << "MRV不存在解" << endl;

	//MRV+MDF
	G.initColor();
	begin = clock();
	G.MRV_MDF(0, 0);
	end = clock();
	time = (double)(end - begin);
	count = G.Get_sol_num();
	if (count)
	{
		cout << "MRV+MDF共有" << count << "组可行解" << endl;
		cout << "耗时：" << time << "ms" << endl;
	}
	else
		cout << "MRV+MDF不存在解" << endl;
}

//大规模
void bigScale()
{
	srand((unsigned)time(nullptr));
	clock_t begin, end;
	double time = 0;
	int count = 0;

	int ver_num = 450;//顶点数
	int color_num = 5;//颜色数

	Graph G(ver_num, color_num);
	G.createGraph("le450_5a");
	//G.showGraph();

	//MRV
	G.initColor();
	begin = clock();
	G.MRV(0, 0);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	count = G.Get_sol_num() ;
	if (count)
	{
		cout << "MRV共有" << count << "组可行解" << endl;
		cout << "耗时：" << time << "s" << endl;
	}
	else
		cout << "MRV不存在解" << endl;

	//MRV+MDF
	G.initColor();
	begin = clock();
	G.MRV_MDF(0, 0);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	count = G.Get_sol_num();
	if (count)
	{
		cout << "MRV+MDF共有" << count << "组可行解" << endl;
		cout << "耗时：" << time << "s" << endl;
	}
	else
		cout << "MRV+MDF不存在解" << endl;

}

//大规模下只求一个解
void bigScaleOne()
{
	srand((unsigned)time(nullptr));
	clock_t begin, end;
	double time = 0;
	int count = 0;

	int ver_num = 450;//顶点数
	int color_num = 25;//颜色数

	Graph G(ver_num, color_num);
	//string name = "le450_5a";
	string name = "le450_15b";
	//string name = "le450_25a";
	cout << "------- " << name << " ---------" << endl;
	G.createGraph(name);
	
	//G.showGraph();

	//MRV
	G.initColor();
	begin = clock();
	G.MRV_one(2, 0);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	count = G.Get_sol_num() ;
	if (count)
	{
		cout << "求 MRV 1组可行解" << endl;
		cout << "耗时：" << time << "s" << endl;
	}
	else
		cout << "MRV不存在解" << endl;

	//MRV+MDF
	G.initColor();
	begin = clock();
	G.MRV_MDF_one(2, 0);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	count = G.Get_sol_num();
	if (count)
	{
		cout << "求 MRV+MDF 1组可行解" << endl;
		cout << "耗时：" << time << "s" << endl;
	}
	else
		cout << "MRV+MDF不存在解" << endl;

}

//大规模下用对称方法
void bigScaleSymmetric()
{
	srand((unsigned)time(nullptr));
	clock_t begin, end;
	double time = 0;
	int count = 0;

	int ver_num = 450;//顶点数
	int color_num = 5;//颜色数

	Graph G(ver_num, color_num);
	G.createGraph("le450_5a");
	//G.createGraph("le450_15b");
	//G.createGraph("le450_25a");
	//G.showGraph();

	//MRV
	G.initColor();
	begin = clock();
	G.MRV_symmetric(0, 0);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	count = G.Get_sol_num() * color_num;
	if (count)
	{
		cout << "MRV+MDF共有" << count << "组可行解" << endl;
		cout << "耗时：" << time << "s" << endl;
	}
	else
		cout << "MRV不存在解" << endl;

	//MRV+MDF
	G.initColor();
	begin = clock();
	G.MRV_MDF_symmetric(0, 0);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	count = G.Get_sol_num()* color_num;
	if (count)
	{
		cout << "MRV+MDF共有" << count << "组可行解" << endl;
		cout << "耗时：" << time << "s" << endl;
	}
	else
		cout << "MRV+MDF不存在解" << endl;

}

//随机产生不同规模的图，分析算法效率与图规模的关系
void RandomTest()
{
	srand((unsigned)time(nullptr));
	clock_t begin, end;
	double time = 0;
	int count = 0;
	for (int ver_num = 10; ver_num < 21; ver_num += 2)
	{
		int color_num = 4;//颜色数
		double density = 0.08;
		int arc_num = int(ver_num * (ver_num - 1) / 2 * density);//边数
		cout << "ver_num=" << ver_num << " arc_num=" << arc_num << endl;

		Graph G(ver_num, color_num);
		G.createGraph("random", arc_num);
		//G.showGraph();

		////普通回溯
		//G.initColor();
		//begin = clock();
		//G.Backtrack(0);
		//end = clock();
		//time = (double)(end - begin);
		//count = G.Get_sol_num();
		//if (count)
		//{
		//	cout << "回溯法求 1 组可行解" << endl;
		//	cout << "耗时：" << time << "ms" << endl;
		//}
		//else
		//	cout << "普通回溯法不存在解" << endl;

		//MRV
		G.initColor();
		begin = clock();
		G.MRV(0, 0);
		end = clock();
		time = (double)(end - begin) / CLOCKS_PER_SEC;
		count = G.Get_sol_num();
		if (count)
		{
			cout << "MRV 可行解" << endl;
			cout << "耗时：" << time << "s" << endl;
		}
		else
			cout << "MRV不存在解" << endl;

		//MRV+MDF
		G.initColor();
		begin = clock();
		G.MRV_MDF(0, 0);
		end = clock();
		time = (double)(end - begin) / CLOCKS_PER_SEC;
		count = G.Get_sol_num();
		if (count)
		{
			cout << "MRV+MDF 可行解" << endl;
			cout << "耗时：" << time << "s" << endl;
		}
		else
			cout << "MRV+MDF不存在解" << endl << endl;
	}
	

}

int main()
{
	//smallScale();
	bigScale();//3840
	//bigScaleOne();
	//bigScaleSymmetric();//3840
	//RandomTest();
	return 0;
}