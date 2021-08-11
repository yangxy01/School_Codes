//�����������������ģ3�˻������%3����
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

/*
%3 = 0,1,2
A: A1+A2
B: B1+B2
C = A1B1+A2B1+A1B2+A2B2
*/

/*
3
1 2 3
4 5 6
7 8 9

10 25 12
12 2 2
13 43 4
*/
/*
1 2 1
1 2 1
1 2 1
*/

/*˼·��������Ԫ��%3�Ľ��תΪ��������͡�A = A1+A2  %3�õ��Ĳ���0����1
1 2 3
4 5 6
7 8 9
=
1 1 0
1 1 0
1 1 0
+
0 1 0
0 1 0
0 1 0
*/


void multi(bitset<100> A[100], bitset<100> B[100], int n, vector<vector<int>>& res)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            res[i][j] = res[i][j] + (A[i] & B[j]).count() % 3;
        }
}
int main()
{
    bitset<100>  A1[100], A2[100];
    bitset<100>  B1[100], B2[100];
    vector<vector<int>>  result(100, vector<int>(100, 0));

    int i, j, n, e;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        A1[i].reset();
        A2[i].reset();
        B1[i].reset();
        B2[i].reset();
        for (j = 0; j < n; j++)
        {
            cin >> e;
            if (e % 3 >= 1)
                A1[i][j] = 1;
            if (e % 3 == 2)
                A2[i][j] = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> e;
            if (e % 3 >= 1)              //�ڶ�������ת��
                B1[j][i] = 1;
            if (e % 3 == 2)
                B2[j][i] = 1;
        }
    }

    multi(A1, B1, n, result);
    multi(A1, B2, n, result);
    multi(A2, B1, n, result);
    multi(A2, B2, n, result);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << result[i][j] % 3 << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}

