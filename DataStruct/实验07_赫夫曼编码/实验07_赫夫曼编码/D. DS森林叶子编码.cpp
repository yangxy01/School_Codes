#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct ForestNode
{
	char data = '0';
	vector<ForestNode*> nodes;
	ForestNode* parent = NULL;
	ForestNode* child = NULL;
	ForestNode* bro = NULL;
};

struct BiNode
{
	char data = '0';
	BiNode* child;
	BiNode* bro;
};

class Forest
{
private:
	vector<ForestNode*> roots;
	int N,M;
	ForestNode* Biroot;
	ForestNode* Create(ForestNode* node, string str,int &pos)
	{
		if (str[pos] == '0')
		{
			pos++;
			return NULL;
		}
		if (pos < str.length())
		{
			ForestNode* newnode = new ForestNode;
			newnode->data = str[pos];
			pos++;
			newnode->parent = node;
			for (int i = 0; i < M; i++)
				newnode->nodes.push_back(Create(newnode, str, pos));
			return newnode;
		}
		else
			return NULL;
	}
	void Convert(ForestNode* Fnode)
	{
		if (Fnode == NULL)
			return;
		if(Fnode->nodes.size() > 0)
			Fnode->child = Fnode->nodes[0];
		if ((Fnode->parent) && (Fnode->parent->nodes.size() > 0))
		{
			for (int k = 0; k < Fnode->parent->nodes.size()-1; k++)
			{
				if(Fnode->parent->nodes[k]==Fnode)
					Fnode->bro = Fnode->parent->nodes[k+1];
			}		
		}
		for (int i = 0; i < Fnode->nodes.size(); i++)
			Convert(Fnode->nodes[i]);
	}

	void ShowCode(ForestNode* node, string path)
	{
		if (node == NULL)
			return;
		if (node->child == NULL && node->bro == NULL)
		{
			cout << path << endl;
			return;
		}
		
		ShowCode(node->child, path + "0");
		ShowCode(node->bro, path + "1");
	}

	void Destory(ForestNode* node)
	{
		if (node == NULL)
			return;
		for (int i = 0; i < M; i++)
			Destory(node->nodes[i]);
		delete node;
	}

public:
	Forest(int n = 0, int m = 0) { N = n; M = m; Biroot = NULL; }
	~Forest()
	{
		for (int i = 0; i < N; i++)
			Destory(roots[i]);
	}
	void Create()
	{
		char ch;
		string str;
		for (int i = 0; i < N; i++)
		{
			while ((ch = getchar()) != '\n')
				if (ch != ' ')
					str += ch;
			int pos = 0;
			roots.push_back(Create(NULL,str,pos));
			str = "";
		}
		
	}
	void Convert()
	{
		int i;
		for (i = 0; i < N-1; i++)
		{
			Convert(roots[i]);
			roots[i]->bro = roots[i + 1];
		}
		Convert(roots[i]);
		Biroot = roots[0];
	}
	void ShowCode()
	{
		string path;
		ShowCode(Biroot, path);
	}
	
};

int main()
{
	int n, m;
	cin >> n >> m;
	getchar();
	Forest Trees(n,m);
	Trees.Create();
	Trees.Convert();
	Trees.ShowCode();
	return 0;
}