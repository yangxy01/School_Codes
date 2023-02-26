//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//class List
//{
//	int* mylist;
//	int len;
//public:
//	List(int l) :len(l)
//	{
//		mylist = new int[len];
//	}
//	~List()
//	{
//		if (mylist)
//			delete[]mylist;
//	}
//	void Createmylist()
//	{
//		int x;
//		for (int i = 0; i < len; i++)
//		{
//			cin >> x;
//			mylist[i] = x;
//		}
//	}
//	void InsertSort()
//	{
//		int start = 1;
//		while (start < len)
//		{
//			int cur = start;
//			while (cur >= 1)
//			{
//				if (mylist[cur] < mylist[cur - 1])
//				{
//					swap(mylist[cur], mylist[cur - 1]);
//					/*int tmp = mylist[cur];
//					mylist[cur] = mylist[cur - 1];
//					mylist[cur - 1] = tmp;*/
//				}
//				else
//					break;
//				cur--;
//			}
//			Show();
//			start++;
//		}
//	}
//	void Show()
//	{
//		for (int i = 0; i < len - 1; i++)
//			cout << mylist[i] << " ";
//		cout << mylist[len - 1] << endl;
//	}
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	List ls(n);
//	ls.Createmylist();
//	ls.InsertSort();
//	return 0;
//}





#include "iostream"
#include "vector"
#include "queue"
#include "map"
#include "limits.h"
#include "limits.h"

using namespace std;

class graph
{
private:
    vector<vector<int>> mat;
    int size;
    vector<int> dis;
public:
    graph(int n) : mat(vector<vector<int>>(n, vector<int>(n))), size(n), dis(vector<int>(n,INT_MAX / 2))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> mat[i][j];
            }
        }
    }

    void dj()
    {
        int begin = 0;
        cin >> begin;
        priority_queue<pair<int, int>> q;
        q.push(make_pair(0, begin));
        while (!q.empty())
        {
            auto temp = q.top();
            q.pop();
            int dis_to_begin = temp.first;
            if (dis[temp.second] < temp.first)
            {
                continue;
            }
            for (int i = 0; i < size; ++i)
            {
                if (mat[temp.second][i] && mat[temp.second][i] + dis_to_begin < dis[i])
                {
                    dis[i] = mat[temp.second][i] + dis_to_begin;
                    q.push(make_pair(dis[i], i));
                }
            }
        }
    }

    void print()
    {
        int k;
        cin >> k;
        map<int, vector<int>> m;
        for (int i = 0; i < size; ++i)
        {
            m[dis[i]].push_back(i);
        }
        int count = 0;
        for (auto &x: m)
        {
            count++;
            if (count == k)
            {
                for (int i = 0; i < x.second.size() - 1; ++i)
                {
                    cout << x.second[i] << " ";
                }
                cout << x.second.back() << endl;
            }
        }
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        graph g(n);
        g.dj();
        g.print();
    }
}