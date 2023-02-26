//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define MAXCODELEN	15	
//struct HTNode 
//{
//	char ch;			
//	int  weight;		
//	int  parent, lchild, rchild;
//	char code[MAXCODELEN];	
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
//			if(c)
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
//	//void HuffmanCoding() // ��Ҷ�ӵ���������ÿ���ַ��ı���
//	//{
//	//	int  i, j, m, c, f, start;
//	//	char cd[MAXCODELEN];			// ���ÿ���ַ��ı�������
//	//	m = MAXCODELEN;
//	//	cd[m - 1] = '\0';
//
//	//	for (i = 1; i <= num; i++) // ���ַ���Ҷ�ӽ�㣩�����Huffman����
//	//	{	   
//	//		start = m - 1;	// ���������λ��
//
//	//		//��Ҷ�ӵ���������ÿ���ַ��ı���
//	//		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) 
//	//		{
//	//			if (HT[f].lchild == c) 
//	//				cd[--start] = '0';
//	//			else                   
//	//				cd[--start] = '1';
//	//		} 			
//	//		for (j = 0; j < m - start; j++) 
//	//			HT[i].code[j] = cd[start + j];
//	//		
//	//	}
//	//}
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
//
//		/*for (int i = 1; i <= num; i++)
//		{
//			cout << HT[i].weight << "-";
//			cout << HT[i].code << endl;
//		}*/
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
//	int n,x;
//	while (t--)
//	{
//		cin >> n;
//		int* w = new int[n];
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x;
//			w[i] = x;
//		}
//		HuffmanTree HTree(NULL, w, n);
//		HTree.HuffmanCoding();
//		HTree.ShowCode();
//		delete[]w;
//	}
//	return 0;
//}