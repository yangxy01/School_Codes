#include<iostream>
using namespace std;

class Graph
{
	char type;
	int VertexNum;
	int** Matrix;
	char** Vers;
public:
	Graph(char t=' ', int num=0) :type(t), VertexNum(num)
	{
		int ArcNum;
		Matrix = new int* [VertexNum];
		for (int i = 0; i < VertexNum; i++)
			Matrix[i] = new int[VertexNum];
		for (int i = 0; i < VertexNum; i++)
			for (int j = 0; j < VertexNum; j++)
				Matrix[i][j] = 0;

		Vers = new char* [VertexNum];
		for (int i = 0; i < VertexNum; i++)
			Vers[i] = new char[100];
		for (int i = 0; i < VertexNum; i++)
			cin >> Vers[i];

		cin >> ArcNum;
		char a[100], b[100];
		int m, n;
		if (type == 'D')
		{
			for (int i = 0; i < ArcNum; i++)
			{
				cin >> a >> b;
				m = GetNo(a);
				n = GetNo(b);
				Matrix[m][n] = 1;
			}
		}
		else
		{
			for (int i = 0; i < ArcNum; i++)
			{
				cin >> a >> b;
				m = GetNo(a);
				n = GetNo(b);
				Matrix[m][n] = 1;
				Matrix[n][m] = 1;
			}
		}
	}
	~Graph()
	{
		for (int i = 0; i < VertexNum; i++)
		{
			delete[]Vers[i];
			delete[]Matrix[i];
		}
		delete[]Vers;
		delete[]Matrix;
	}

	int GetNo(char* s)
	{
		int j;
		for (j = 0; j < VertexNum; j++)
		{
			int k = 0;
			while (*(Vers[j] + k) != '\0' && *(s + k) != '\0')
			{
				if (*(Vers[j] + k) != *(s + k))
					break;
				k++;
			}
			if(*(Vers[j] + k) == '\0' && *(s + k) == '\0')
				return j;
		}
	}

	void ShowMatrix()
	{
		for (int i = 0; i < VertexNum; i++)
		{
			for (int j = 0; j < VertexNum - 1; j++)
				cout << Matrix[i][j]<<" ";
			cout << Matrix[i][VertexNum - 1] <<endl;
		}
	}

	void ShowDegree()
	{
		int* out = new int [VertexNum];
		int* in = new int[VertexNum];
		int* all = new int[VertexNum];
		for (int i = 0; i < VertexNum; i++)
		{
			out[i] = 0;
			in[i] = 0;
			all[i] = 0;
		}

		if (type == 'D')
		{
			for (int i = 0; i < VertexNum; i++)
			{
				for (int j = 0; j < VertexNum; j++)
				{
					if (Matrix[i][j] == 1)
					{
						out[i]++;
						all[i]++;
					}
					if (Matrix[j][i] == 1)
					{
						in[i]++;
						all[i]++;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < VertexNum; i++)
			{
				for (int j = 0; j < VertexNum; j++)
				{
					if (Matrix[i][j] == 1)
						all[i]++;
				}
			}
		}
		for (int i = 0; i < VertexNum; i++)
		{
			if (all[i] != 0)
			{
				if (type == 'D')
				{
					cout << Vers[i] << ":";
					cout << " " << out[i] << " " << in[i] << " " << all[i] << endl;
				}
				else
					cout << Vers[i] << ":" << " " << all[i] << endl;
			}	
		}
		for (int i = 0; i < VertexNum; i++)
			if (all[i] == 0)
				cout << Vers[i] << endl;
		delete[]out;
		delete[]in;
		delete[]all;
	}
};

int main()
{
	int t;
	cin >> t;
	char type;
	int VertexNum;
	while (t--)
	{
		cin >> type >> VertexNum;
		Graph T(type, VertexNum);
		T.ShowMatrix();
		T.ShowDegree();
	}
}