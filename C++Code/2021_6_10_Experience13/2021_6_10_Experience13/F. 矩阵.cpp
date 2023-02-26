//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class CArray
//{
//	int n, m;
//	int**data;
//public:
//	CArray(){ n = 0; m = 0; data = NULL; }
//	CArray(int nValue, int mValue) :n(nValue), m(mValue)
//	{
//		data = new int*[n];
//		for (int i = 0; i < n; i++)
//		{
//			data[i] = new int[m];
//		}
//	}
//	CArray(CArray&obj)
//	{
//		int i, j;
//		n = obj.n;
//		m = obj.m;
//		data = new int*[n];
//		for (i = 0; i < n; i++)
//		{
//			data[i] = new int[m];
//		}
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < m; j++)
//			{
//				data[i][j]=obj.data[i][j];
//			}
//		}
//	}
//	CArray&operator=(CArray&obj)
//	{
//		if (data)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				delete[]data[i];
//			}
//			delete[]data;
//		}
//		else
//		{
//			int i, j;
//			n = obj.n;
//			m = obj.m;
//			data = new int*[n];
//			for (i = 0; i < n; i++)
//			{
//				data[i] = new int[m];
//			}
//			for (i = 0; i < n; i++)
//			{
//				for (j = 0; j < m; j++)
//				{
//					data[i][j] = obj.data[i][j];
//				}
//			}
//		}
//
//		return *this;
//
//	}//重载赋值
//
//	//重载[]
//	int* operator[](int row)
//	{
//		return data[row];
//	}
//
//	//重载()
//	int operator()(int i, int j)
//	{
//		return data[i][j];
//	}
//
//
//	~CArray()
//	{
//		for (int i = 0; i < n; i++)
//		{
//			delete []data[i];
//		}
//		delete []data;
//	}
//
//};
//
//int main()
//{
//	int t;
//	int n, m;
//	int i, j;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> m;
//		CArray matrixA(n, m);
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < m; j++)
//				cin >> matrixA[i][j];//理解为get函数
//			
//		}
//		cout << "matrixA:" << endl;
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < m-1; j++)
//				cout<< matrixA(i,j)<<" ";
//			cout << matrixA(i, j)<<endl;
//		}
//
//		cout << "matrixB:" << endl;
//		CArray matrixB;
//		matrixB = matrixA;
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < m-1; j++)
//				cout << matrixB[i][j]<<" ";
//			cout << matrixB[i][j]<< endl;
//		}
//	}
//
//	return 0;
//}
