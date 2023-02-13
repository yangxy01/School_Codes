//#include <iostream>
//#include <vector>
//#include <queue>
//#include <string.h>
//#include <cstdlib>
//#include <limits.h>
//#include <fstream>
//
//#define MAX 5000
//int N = 3;
//int M = 10;
//int A = 2;
//int B = 10;
//
//using namespace std;
//
//class EK
//{
//private:
//    int n, m;             // n：点数，m：边数
//    int a[MAX], p[MAX]; // 解
//    vector<int> G[MAX];  // 下标表示邻接表
//
//    struct edge
//    {
//        int begin, end;
//        int cap, flow;
//
//        edge(int u, int v, int c, int f) : begin(u), end(v), cap(c), flow(f) {}
//    };
//
//    vector<edge> edges;   //边集合
//
//    // 加边
//    void edge_push_back(int begin, int end, int cap)
//    {
//        edges.push_back(edge(begin, end, cap, 0));
//        edges.push_back(edge(end, begin, 0, 0));
//        m += 2;
//        //m = edges.size();
//        G[begin].push_back(m - 2);
//        G[end].push_back(m - 1);
//    }
//
//public:
//    EK(int a, int b, int _n) : n(_n), m(0)
//    {
//        for (int i = 1; i < M + 1; ++i)
//        {
//            edge_push_back(0, i, a);
//            edge_push_back(i, 0, 0);
//            for (int j = M + 1; j < N + M + 1; ++j)
//            {
//                edge_push_back(i, j, 1);
//                edge_push_back(j, i, 0);
//            }
//        }
//        for (int i = M + 1; i < N + M + 1; ++i)
//        {
//            edge_push_back(i, N + M + 1, b);
//            edge_push_back(N + M + 1, i, 0);
//        }
//    }
//
//
//    int Maxflow()
//    {
//        int ans = 0;
//        int s = 0, t = n - 1;
//        while (true)// 无增广路
//        {
//            memset(a, 0, sizeof(a));
//            queue<int> q;
//            q.push(s);
//            a[s] = INT_MAX;
//            //BFS找增广路
//            while (!q.empty() && !a[t])// 如果汇点接受到了流，就退出 BFS 或者 遍历完毕
//            {
//                int x = q.front();
//                q.pop();
//                for (int i = 0; i < G[x].size(); i++)
//                { //遍历 x 邻接的边的点
//                    edge& e = edges[G[x][i]];
//                    if (!a[e.end] && e.cap > e.flow)
//                    {
//                        a[e.end] = a[x] < (e.cap - e.flow) ? a[x] : (e.cap - e.flow);
//                        p[e.end] = G[x][i];
//                        q.push(e.end);
//                    }
//                }
//            }
//            if (!a[t])
//            {
//                break;  // 无增广路
//            }
//            //更新数据
//            for (int u = t; u != s; u = edges[p[u]].begin)
//            {
//                edges[p[u]].flow += a[t];   // 增加flow 值
//                int index = p[u] ^ 1;
//                edges[index].flow -= a[t]; // 减小flow 值
//            }
//            ans += a[t];
//        }
//        return ans;
//    }
//
//    //运行对问题进行求解
//    int run()
//    {
//        int ans = Maxflow();
//        if (ans == M * A)
//        {
//            cout << "ok" << endl;
//        }
//        else
//        {
//            cout << "error" << endl;
//        }
//        cout << ans << endl;
//    }
//
//    //测试时间
//    double test()
//    {
//        auto begin = clock();
//        int ans = Maxflow();
//        auto end = clock();
//        return double(end - begin) / CLOCKS_PER_SEC * 1000;
//    }
//
//    //析构函数
//    ~EK()
//    {
//        for (int i = 0; i < n; i++) G[i].clear();
//        edges.clear();
//    }
//};
//
//struct Dinic
//{
//private:
//    int n, m;
//    int s, t;
//    int deep[MAX], cur[MAX];
//    bool vis[MAX];
//
//    struct edge
//    {
//        int begin, end;
//        int cap, flow;
//
//        edge(int u, int v, int c, int f) : begin(u), end(v), cap(c), flow(f) {}
//    };
//
//
//    vector<edge> edges;
//    vector<int> G[MAX];
//
//    void edge_push_back(int begin, int end, int cap)
//    {
//        edges.push_back(edge(begin, end, cap, 0));
//        edges.push_back(edge(end, begin, 0, 0));
//        m += 2;
//        G[begin].push_back(m - 2);
//        G[end].push_back(m - 1);
//    }
//
//    //BFS分层
//    bool BFS()
//    {
//        //memset(vis, 0, sizeof(vis));
//        queue<int> q;
//        q.push(s);
//        deep[s] = 0;
//        vis[s] = true;
//        while (!q.empty())
//        {
//            auto x = q.front();
//            q.pop();
//            for (int i = 0; i < G[x].size(); i++)
//            {
//                edge& e = edges[G[x][i]];
//                if (!vis[e.end] && e.cap > e.flow)
//                {
//                    vis[e.end] = true;
//                    deep[e.end] = deep[x] + 1;
//                    q.push(e.end);
//                }
//            }
//        }
//        return vis[t];
//    }
//
//    //DFS找增广路径
//    int DFS(int x, int a)
//    {
//        if (x == t || a == 0)
//        {
//            return a;
//        }
//        int fol = 0;
//        for (int i = cur[x]; i < G[x].size(); i++)
//        {
//            auto& temp = edges[G[x][i]];
//            int f = DFS(temp.end, min(a, temp.cap - temp.flow));
//            if (f > 0 && deep[x] + 1 == deep[temp.end])
//            {
//                temp.flow += f;
//                int index = G[x][i] ^ 1;
//                edges[index].flow -= f;
//                if ((a -= f) == 0)
//                {
//                    break;
//                }
//                fol += f;
//            }
//        }
//        return fol;
//    }
//
//public:
//    Dinic(int a, int b, int _n) : n(_n), m(0)
//    {
//        for (int i = 1; i < M + 1; ++i)
//        {
//            edge_push_back(0, i, a);
//            edge_push_back(i, 0, 0);
//            for (int j = M + 1; j < N + M + 1; ++j)
//            {
//                edge_push_back(i, j, 1);
//                edge_push_back(j, i, 0);
//            }
//        }
//        for (int i = M + 1; i < N + M + 1; ++i)
//        {
//            edge_push_back(i, N + M + 1, b);
//            edge_push_back(N + M + 1, i, 0);
//        }
//    }
//
//    ~Dinic()
//    {
//        for (int i = 0; i < n; i++) G[i].clear();
//        edges.clear();
//    }
//
//    void run()
//    {
//        int ans = Maxflow();
//        if (ans == M * A)
//        {
//            cout << "ok" << endl;
//        }
//        else
//        {
//            cout << "error" << endl;
//        }
//        cout << ans << endl;
//    }
//
//    int Maxflow()
//    {
//        s = 0;
//        t = n - 1;
//        int flow = 0;
//        while (BFS())
//        {
//            memset(cur, 0, sizeof(cur));
//            flow += DFS(s, INT_MAX);
//        }
//        return flow;
//    }
//
//    double test()
//    {
//        auto begin = clock();
//        int ans = Maxflow();
//        auto end = clock();
//        return double(end - begin) / CLOCKS_PER_SEC * 1000;
//    }
//};
//
//int main(int argc, char* argv[])
//{
//    vector<int> data{ 10, 10, 30, 40, 50 };
//    string nums = argv[1];
//
//    int x = stoi(nums);
//    A *= x;
//    B *= x;
//    N *= x;
//    M *= x;
//
//    EK e(A, B, M + N + 2);
//    cout << e.test() << endl;
//    Dinic d(A, B, M + N + 2);
//    cout << d.test() << endl;
//
//
//}