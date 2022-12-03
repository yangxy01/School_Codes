//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//using namespace std;
//
//void rotate(int *matrix, int *changed_matrix)
//{
//	for (int i = 0; i<2; i++)
//	{
//		for (int j = 0; j<3; j++)
//		{
//			*(changed_matrix + i*3 + j) = *(matrix + i * 3 + j);
//		}
//	}
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int matrix[2][3], changed_matrix[3][2];
//		for (int i = 0; i<2; i++)
//		for (int j = 0; j<3; j++)
//			cin >> matrix[i][j];
//		rotate(*matrix, *changed_matrix);
//		for (int i = 0; i<3; i++)
//		{
//			for (int j = 0; j<2; j++)
//				cout << *(*(changed_matrix + i) + j) << ' ';
//			cout << endl;
//		}
//	}
//	return 0;
//}
