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
//	HuffmanTree(char* c, int w[], int n) //叶子结点值，叶子结点权值，叶子结点数量
//	{
//		num = n;	
//		int i, m, s1, s2;	
//		m = 2 * n - 1;		//霍夫曼树总结点数量
//		HT = new HTNode[m + 1];		//下标从1开始使用
//
//		//初始化过程
//		for (i = 1; i <= n; i++)	// 为Huffman树的叶子结点赋初值
//		{ 
//			if(c)
//				HT[i].ch = c[i - 1];	
//			HT[i].weight = w[i - 1];
//			HT[i].parent = 0;		//父结点默认为0
//			HT[i].lchild = HT[i].rchild = 0; //孩子结点默认为0
//		}
//		for (i = n + 1; i <= m; ++i)	// 为Huffman树的内部结点赋初值
//		{ 
//			if (c)
//				HT[i].ch = ' ';		//值为空
//			HT[i].weight = 0;	//权值为0
//			HT[i].parent = HT[i].lchild = HT[i].rchild = 0;	//父,孩子结点默认为0
//		}
//
//		//开始构建除叶子结点外的结点
//		for (i = n + 1; i <= m; ++i) 
//		{
//			Select(i - 1, s1, s2); //从树集合中，找出权值最小和次小的两棵树
//			HT[s1].parent = i; HT[s2].parent = i; // 将最小的两棵树合并成一棵树
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
//			if (HT[j].parent == 0) //改结点没有被删
//			{
//				//遍历过程完成初始化
//				if (s1 == 0) s1 = j;	
//				else if (s2 == 0) s2 = j;
//
//				//选权值最小和次小
//				if (HT[j].weight < HT[s1].weight) { s2 = s1; s1 = j; }//选最小并更新次小
//				else if (HT[j].weight < HT[s2].weight && s2 != 0) { s2 = j; }//选次小
//			}
//		}
//	}
//
//	void HuffmanCoding() // 求编码(vector版本)
//	{
//		int i, j;
//		for (i = 1; i <= num; i++)
//		{
//			j = i;
//			while (HT[j].parent)
//			{
//				if (HT[HT[j].parent].lchild == j)	//是左孩子
//					HT[i].path.push_back('0');
//				else
//					HT[i].path.push_back('1');
//				j = HT[j].parent;
//			}
//		}
//	}
//
//	//void HuffmanCoding() // 从叶子到根逆向求每个字符的编码
//	//{
//	//	int  i, j, m, c, f, start;
//	//	char cd[MAXCODELEN];			// 存放每个字符的编码序列
//	//	m = MAXCODELEN;
//	//	cd[m - 1] = '\0';
//
//	//	for (i = 1; i <= num; i++) // 对字符（叶子结点）逐个求Huffman编码
//	//	{	   
//	//		start = m - 1;	// 编码结束符位置
//
//	//		//从叶子到根逆向求每个字符的编码
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
//		for (int i = 1; i <= num; i++)//vector版本
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