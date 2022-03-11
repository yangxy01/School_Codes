//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//struct HTNode
//{
//	char ch;
//	int  weight;
//	int  parent, lchild, rchild;
//	vector<char> path;
//};
//
//class HuffmanTree
//{
//private:
//	HTNode* HT;
//	int num;
//public:
//	HuffmanTree() { num = 0; HT = NULL; }
//	HuffmanTree(char* c, int w[], int n) //Ҷ�ӽ��ֵ��Ҷ�ӽ��Ȩֵ��Ҷ�ӽ������
//	{
//		num = n;
//		int i, m, s1, s2;
//		m = 2 * n - 1;		//���������ܽ������
//		HT = new HTNode[m + 1];		//�±��1��ʼʹ��
//
//		//��ʼ������
//		for (i = 1; i <= n; i++)	// ΪHuffman����Ҷ�ӽ�㸳��ֵ
//		{
//			if (c)
//				HT[i].ch = c[i - 1];
//			HT[i].weight = w[i - 1];
//			HT[i].parent = 0;		//�����Ĭ��Ϊ0
//			HT[i].lchild = HT[i].rchild = 0; //���ӽ��Ĭ��Ϊ0
//		}
//		for (i = n + 1; i <= m; ++i)	// ΪHuffman�����ڲ���㸳��ֵ
//		{
//			if (c)
//				HT[i].ch = ' ';		//ֵΪ��
//			HT[i].weight = 0;	//ȨֵΪ0
//			HT[i].parent = HT[i].lchild = HT[i].rchild = 0;	//��,���ӽ��Ĭ��Ϊ0
//		}
//
//		//��ʼ������Ҷ�ӽ����Ľ��
//		for (i = n + 1; i <= m; ++i)
//		{
//			Select(i - 1, s1, s2); //���������У��ҳ�Ȩֵ��С�ʹ�С��������
//			HT[s1].parent = i; HT[s2].parent = i; // ����С���������ϲ���һ����
//			HT[i].lchild = s1; HT[i].rchild = s2;
//			HT[i].weight = HT[s1].weight + HT[s2].weight;
//		}
//	}
//
//	void Select(int i, int& s1, int& s2)
//	{
//		int j;
//		s1 = s2 = 0;
//		for (j = 1; j <= i; j++)
//		{
//			if (HT[j].parent == 0) //�Ľ��û�б�ɾ
//			{
//				//����������ɳ�ʼ��
//				if (s1 == 0) s1 = j;
//				else if (s2 == 0) s2 = j;
//
//				//ѡȨֵ��С�ʹ�С
//				if (HT[j].weight < HT[s1].weight) { s2 = s1; s1 = j; }//ѡ��С�����´�С
//				else if (HT[j].weight < HT[s2].weight && s2 != 0) { s2 = j; }//ѡ��С
//			}
//		}
//	}
//
//	void HuffmanCoding() // �����(vector�汾)
//	{
//		int i, j;
//		for (i = 1; i <= num; i++)
//		{
//			j = i;
//			while (HT[j].parent)
//			{
//				if (HT[HT[j].parent].lchild == j)	//������
//					HT[i].path.push_back('0');
//				else
//					HT[i].path.push_back('1');
//				j = HT[j].parent;
//			}
//		}
//	}
//
//
//	void ShowCode()
//	{
//		for (int i = 1; i <= num; i++)//vector�汾
//		{
//			cout << HT[i].weight << "-";
//			for (int j = HT[i].path.size() - 1; j >= 0; j--)
//			{
//				cout << HT[i].path[j];
//			}
//			cout << endl;
//		}
//	}
//
//	int Decode(const string codestr, char txtstr[])
//	{
//		int root = 2 * num - 1;
//		int count = 0;
//		int cur = root;
//		for (int i = 0; i < codestr.length(); i++)
//		{
//			if (codestr[i] == '0')
//			{
//				cur = HT[cur].lchild;
//			}
//			else if (codestr[i] == '1')
//			{
//				cur = HT[cur].rchild;
//			}
//			else
//				return 0;
//			if (cur <= num)
//			{
//				txtstr[count++] = HT[cur].ch;
//				txtstr[count] = '\0';
//				cur = root;
//			}
//		}
//		if (cur != root)
//			return 0;
//		return 1;
//	}
//
//	~HuffmanTree() { if (HT) delete[] HT; }
//
//};
//
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	int n, x, k;
//	char ch;
//	string codestr;
//	while (t--)
//	{
//		cin >> n;
//		int* w = new int[n];
//		char* str = new char[n];
//		char txtstr[20];
//		txtstr[0] = '\0';
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x;
//			w[i] = x;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			cin >> ch;
//			str[i] = ch;
//		}
//		HuffmanTree HTree(str, w, n);
//		cin >> k;
//		while (k--)
//		{
//			cin >> codestr;
//			int ret = HTree.Decode(codestr, txtstr);
//			if (ret)
//				cout << txtstr << endl;
//			else
//				cout << "error" << endl;
//		}
//		
//		delete[]w;
//		delete[]str;
//	}
//	return 0;
//}