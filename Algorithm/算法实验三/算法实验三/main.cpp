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
	struct node//һ������
	{
		vector<int> neighbor;
		vector<int> available_col;
	};
	
	vector<node> adjlist;//�ڽӱ�
	int ver_num;//�ڵ�����
	vector<int> colors;//���ڴ洢һ����
	int **adj_matrix;//�ڽӾ���
	int color_num;//color������
	int sol_num;//�����Ŀ

	//�������ƣ�ɾ����ɫ
	void Modify(int i, int color)
	{
		for (int index : adjlist[i].neighbor)
		{
			if (colors[index] == 0)//δ��ɫ
			{
				adjlist[index].available_col[color]--;
				if (adjlist[index].available_col[color] == 0)
				{
					adjlist[index].available_col[0]--;
				}
			}
		}
	}

	//������ƣ��ָ���ɫ
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

	//MRV����һ���ڵ���չ
	int MRV_for_next()
	{
		int min = 9999, ret = -1;
		for (int i = 0; i < ver_num; i++)
		{
			if (colors[i])//����ɫ����
				continue;
			if (adjlist[i].available_col[0] < min)
			{
				min = adjlist[i].available_col[0];
				ret = i;
			}
		}
		return ret;
	}

	//MDF����һ���ڵ���չ
	int MRV_MDF_for_next()
	{
		int min_color = 9999, max_degree = -9999;
		int ret = -1;
		for (int i = 0; i < ver_num; i++)
		{
			if (colors[i])//����ɫ����
				continue;
			if (adjlist[i].available_col[0] < min_color)//С����Сʣ��ֵ
			{
				min_color = adjlist[i].available_col[0];
				max_degree = adjlist[i].neighbor.size();
				ret = i;
			}
			else if (adjlist[i].available_col[0] == min_color)//������Сʣ��ֵ
			{
				if (adjlist[i].neighbor.size() > max_degree)
				{
					max_degree = adjlist[i].neighbor.size();//��������
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

	//��Ϳɫ�ļ�¼ȫ��ճ�ʼ��
	void initColor()
	{
		//��ÿ���ڵ�������ɫ��Ϊ1
		for (auto& node : adjlist)
		{
			node.available_col = vector<int>(color_num + 1, 1);
			node.available_col[0] = color_num;//��ѡ��ɫ����
		}
		colors = vector<int>(ver_num, 0);
		sol_num = 0;
	}

	void createGraph(string scale, int arc_num = 0)
	{
		//��ʼ���ڽӾ���
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
			string add = "D:\\BaiduNetdiskDownload\\�ļ�\\02ѧУ��������\\03_�����\\01_�㷨\\ʵ��\\ʵ����\\��ͼ����\\" + scale + ".col";
			ifstream mapfile(add, ios::in);
			string str;
			if (!mapfile.is_open())
			{
				cout << "δ�ɹ����ļ�" << endl;
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
		
		//��ʼ���ڽӱ�
		for (int i = 0; i < ver_num; i++)
		{
			adjlist.push_back(node());
			adjlist[i].available_col = vector<int>(color_num + 1, 1);
			adjlist[i].available_col[0] = color_num;
			//���ھ�
			for (int j = 0; j < ver_num; j++)
			{
				if (adj_matrix[i][j])
				{
					adjlist[i].neighbor.push_back(j);
				}
			}
		}
		//��ʼ����ɫ����
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

	//MRV�����ҽ�
	void MRV(int i, int num)//�������±꣬�Ѵ���ڵ���
	{
		if (num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//������ɫ
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

	//MRV_MDF�����ҽ�
	void MRV_MDF(int i, int num)//�������±꣬�Ѵ���ڵ���
	{
		if (num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//������ɫ
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

	//���ݷ���һ����
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

	//MRV������һ����
	void MRV_one(int i, int num)//�������±꣬�Ѵ���ڵ���
	{
		if (sol_num >= 1 || num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//������ɫ
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

	//MRV_MDF������һ����
	void MRV_MDF_one(int i, int num)//�������±꣬�Ѵ���ڵ���
	{
		if (sol_num >= 1 || num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//������ɫ
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

	//MRV+�Գ��ҽ�
	void MRV_symmetric(int i, int num)//�������±꣬�Ѵ���ڵ���
	{
		if (num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//������ɫ
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

	//MRV_MDF+�Գ��ҽ�
	void MRV_MDF_symmetric(int i, int num)//�������±꣬�Ѵ���ڵ���
	{
		if (num > ver_num - 1)
		{
			sol_num++;
			return;
		}
		for (int j = 1; j <= color_num; j++)//������ɫ
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

	int Get_sol_num()//��ĸ���
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

	int ver_num = 9;//������
	int color_num = 4;//��ɫ��

	Graph G(ver_num, color_num);
	G.createGraph("small");
	G.showGraph();

	//��ͨ����
	G.initColor();
	begin = clock();
	G.Backtrack(0);
	end = clock();
	time = (double)(end - begin);
	count = G.Get_sol_num();
	if (count)
	{
		cout <<"��ͨ���ݷ�����"<<count<<"����н�"<< endl;
		cout << "��ʱ��" << time << "ms" << endl;
	}
	else
		cout << "��ͨ���ݷ������ڽ�" << endl;

	//MRV
	G.initColor();
	begin = clock();
	G.MRV(0, 0);
	end = clock();
	time = (double)(end - begin);
	count = G.Get_sol_num();
	if (count)
	{
		cout << "MRV����" << count << "����н�" << endl;
		cout << "��ʱ��" << time << "ms" << endl;
	}
	else
		cout << "MRV�����ڽ�" << endl;

	//MRV+MDF
	G.initColor();
	begin = clock();
	G.MRV_MDF(0, 0);
	end = clock();
	time = (double)(end - begin);
	count = G.Get_sol_num();
	if (count)
	{
		cout << "MRV+MDF����" << count << "����н�" << endl;
		cout << "��ʱ��" << time << "ms" << endl;
	}
	else
		cout << "MRV+MDF�����ڽ�" << endl;
}

//���ģ
void bigScale()
{
	srand((unsigned)time(nullptr));
	clock_t begin, end;
	double time = 0;
	int count = 0;

	int ver_num = 450;//������
	int color_num = 5;//��ɫ��

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
		cout << "MRV����" << count << "����н�" << endl;
		cout << "��ʱ��" << time << "s" << endl;
	}
	else
		cout << "MRV�����ڽ�" << endl;

	//MRV+MDF
	G.initColor();
	begin = clock();
	G.MRV_MDF(0, 0);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	count = G.Get_sol_num();
	if (count)
	{
		cout << "MRV+MDF����" << count << "����н�" << endl;
		cout << "��ʱ��" << time << "s" << endl;
	}
	else
		cout << "MRV+MDF�����ڽ�" << endl;

}

//���ģ��ֻ��һ����
void bigScaleOne()
{
	srand((unsigned)time(nullptr));
	clock_t begin, end;
	double time = 0;
	int count = 0;

	int ver_num = 450;//������
	int color_num = 25;//��ɫ��

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
		cout << "�� MRV 1����н�" << endl;
		cout << "��ʱ��" << time << "s" << endl;
	}
	else
		cout << "MRV�����ڽ�" << endl;

	//MRV+MDF
	G.initColor();
	begin = clock();
	G.MRV_MDF_one(2, 0);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	count = G.Get_sol_num();
	if (count)
	{
		cout << "�� MRV+MDF 1����н�" << endl;
		cout << "��ʱ��" << time << "s" << endl;
	}
	else
		cout << "MRV+MDF�����ڽ�" << endl;

}

//���ģ���öԳƷ���
void bigScaleSymmetric()
{
	srand((unsigned)time(nullptr));
	clock_t begin, end;
	double time = 0;
	int count = 0;

	int ver_num = 450;//������
	int color_num = 5;//��ɫ��

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
		cout << "MRV+MDF����" << count << "����н�" << endl;
		cout << "��ʱ��" << time << "s" << endl;
	}
	else
		cout << "MRV�����ڽ�" << endl;

	//MRV+MDF
	G.initColor();
	begin = clock();
	G.MRV_MDF_symmetric(0, 0);
	end = clock();
	time = (double)(end - begin) / CLOCKS_PER_SEC;
	count = G.Get_sol_num()* color_num;
	if (count)
	{
		cout << "MRV+MDF����" << count << "����н�" << endl;
		cout << "��ʱ��" << time << "s" << endl;
	}
	else
		cout << "MRV+MDF�����ڽ�" << endl;

}

//���������ͬ��ģ��ͼ�������㷨Ч����ͼ��ģ�Ĺ�ϵ
void RandomTest()
{
	srand((unsigned)time(nullptr));
	clock_t begin, end;
	double time = 0;
	int count = 0;
	for (int ver_num = 10; ver_num < 21; ver_num += 2)
	{
		int color_num = 4;//��ɫ��
		double density = 0.08;
		int arc_num = int(ver_num * (ver_num - 1) / 2 * density);//����
		cout << "ver_num=" << ver_num << " arc_num=" << arc_num << endl;

		Graph G(ver_num, color_num);
		G.createGraph("random", arc_num);
		//G.showGraph();

		////��ͨ����
		//G.initColor();
		//begin = clock();
		//G.Backtrack(0);
		//end = clock();
		//time = (double)(end - begin);
		//count = G.Get_sol_num();
		//if (count)
		//{
		//	cout << "���ݷ��� 1 ����н�" << endl;
		//	cout << "��ʱ��" << time << "ms" << endl;
		//}
		//else
		//	cout << "��ͨ���ݷ������ڽ�" << endl;

		//MRV
		G.initColor();
		begin = clock();
		G.MRV(0, 0);
		end = clock();
		time = (double)(end - begin) / CLOCKS_PER_SEC;
		count = G.Get_sol_num();
		if (count)
		{
			cout << "MRV ���н�" << endl;
			cout << "��ʱ��" << time << "s" << endl;
		}
		else
			cout << "MRV�����ڽ�" << endl;

		//MRV+MDF
		G.initColor();
		begin = clock();
		G.MRV_MDF(0, 0);
		end = clock();
		time = (double)(end - begin) / CLOCKS_PER_SEC;
		count = G.Get_sol_num();
		if (count)
		{
			cout << "MRV+MDF ���н�" << endl;
			cout << "��ʱ��" << time << "s" << endl;
		}
		else
			cout << "MRV+MDF�����ڽ�" << endl << endl;
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