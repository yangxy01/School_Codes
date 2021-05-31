#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
using namespace std;

struct Person
{
	int nowrow;
	int level;
};

int FindPer(int num, int x, int y)
{
	int*flag = new int[num];
	int**matrix = new int*[num];
	for (int i = 0; i<num; i++)
	{
		flag[i] = 0;
		matrix[i] = new int[num];
		for (int j = 0; j<num; j++)
			cin >> matrix[i][j];
	}
	Person temp;
	int end=y-1;
	temp.nowrow = x-1;
	temp.level = 0;

	queue<Person> q;
	q.push(temp);
	flag[temp.nowrow] = 1;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		int nowrow = temp.nowrow;
		int level = temp.level;
		for (int i = 0; i<num; i++)
		{
			if (matrix[nowrow][i] && !flag[i])
			{
				temp.nowrow = i;
				temp.level = level + 1;
				q.push(temp);
				flag[i] = 1;
				if (i == end)
				{
					delete[]flag;
					for (int i = 0; i<num; i++)
						delete[]matrix[i];
					return level;
				}
			}
		}
	}
	delete[]flag;
	for (int i = 0; i<num; i++)
		delete[]matrix[i];
	return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, y;
		cin >> n >> x >> y;
		int ret = FindPer(n, x, y);
		if (ret == -1)
			cout << "no" << endl; 
		else
			cout << ret << endl;
		
	}
}
