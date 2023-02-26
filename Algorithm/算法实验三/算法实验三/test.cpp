//#include <iostream>
//#include "vector"
//#include "queue"
//#include "fstream"
//#include "unordered_set"
//#include "set"
//#include "union_find.h"
//
//
//using namespace std;
//
//class solution
//{
//private:
//    int node;
//    int edge;
//    vector<vector<int>> adj_list;
//    istream& is;
//    ostream& os;
//    int ans_count = 0;
//public:
//    solution(int _node = 0, int _edge = 0, istream& _fin = cin, ostream& _fout = cout) :adj_list(vector<vector<int>>(_node)),
//        is(_fin), os(_fout), node(_node), edge(_edge)
//    {
//        while (_edge--)
//        {
//            int a, b;
//            is >> a >> b;
//            adj_list[a].push_back(b);
//            adj_list[b].push_back(a);
//        }
//    }
//
//    auto count() -> int
//    {
//        queue<int> q;
//        int ans = 0;
//        unordered_set<int> visited;
//        for (int i = 0; i < node; ++i)
//        {
//            if (visited.find(i) != visited.end())
//            {
//                continue;
//            }
//            else
//            {
//                ++ans;
//                q.push(i);
//                visited.insert(i);
//                while (!q.empty())
//                {
//                    auto temp = q.front();
//                    q.pop();
//                    for (auto x : adj_list[temp])
//                    {
//                        if (visited.find(x) == visited.end() && x != -1)
//                        {
//                            q.push(x);
//                            visited.insert(temp);
//                        }
//                    }
//                }
//            }
//        }
//        return ans;
//    }
//
//    auto count_run()
//    {
//        for (int i = 0; i < node; ++i)
//        {
//            for (auto& x : adj_list[i])
//            {
//                int temp = x;
//                unsigned b = count();
//                auto pos1 = find(adj_list[x].begin(), adj_list[x].end(), i);
//                *pos1 = -1;
//                x = -1;
//                unsigned e = count();
//                x = temp;
//                auto pos2 = find(adj_list[x].begin(), adj_list[x].end(), -1);
//                *pos2 = i;
//                if (b != e)
//                {
//                    ++ans_count;
//                }
//            }
//        }
//        return ans_count / 2;
//    }
//
//};
//
//class solution_1
//{
//private:
//    int node;
//    int edge;
//    int ans_cir = 0;
//    int ans_tree = 0;
//    vector<vector<pair<int, int>>> adj_list;
//    vector<pair<int, int>> edges;
//    vector<pair<int, int>> rm;
//    queue<pair<int, int>> rm1;
//    istream& is;
//    ostream& os;
//    UnionFind uf;
//    vector<int> depth;
//    vector<int> father;
//    vector<int> edge_by_node;
//
//    void rm_edge_lca(int a, int b)
//    {
//        //把他们搞到深度相同
//        while (depth[a] > depth[b])
//        {
//            edge_by_node[a] = 1;
//            a = father[a];
//
//        }
//        while (depth[a] < depth[b])
//        {
//            edge_by_node[b] = 1;
//            b = father[b];
//        }
//        //同时上升找祖先
//        while (a != b)
//        {
//            edge_by_node[a] = 1;
//            a = father[a];
//
//            edge_by_node[b] = 1;
//            b = father[b];
//        }
//    }
//
//    void bfs_tree()
//    {
//        queue<pair<int, int>> q;
//        vector<int> visited(node, 0);
//        for (int i = 0; i < node; ++i)
//        {
//            if (visited[i])
//            {
//                continue;
//            }
//            else
//            {
//                q.push(make_pair(i, 0));
//                visited[i] = 1;
//                while (!q.empty())
//                {
//                    auto temp = q.front();
//                    q.pop();
//                    for (auto& x : adj_list[temp.first])
//                    {
//                        if (!visited[x.first] && x.second == 0)
//                        {
//                            q.push(make_pair(x.first, temp.second + 1));
//                            visited[x.first] = 1;
//                            depth[x.first] = temp.second + 1;
//                            father[x.first] = temp.first;
//
//                            int b = uf.Find(x.first);
//                            int a = uf.Find(temp.first);
//                            if (a != b)
//                            {
//                                uf.Union(temp.first, x.first);
//                                x.second = 1;
//                                auto pos1 = find_if(adj_list[x.first].begin(), adj_list[x.first].end(), [temp](pair<int, int>& item) {return item.first == temp.first; });
//                                if (pos1 != adj_list[x.first].end())
//                                {
//                                    pos1->second = 2;
//                                }
//                            }
//                        }
//                        else if (x.second == 0)
//                        {
//                            int b = uf.Find(x.first);
//                            int a = uf.Find(temp.first);
//                            if (a == b)
//                            {
//                                rm_edge_lca(temp.first, x.first);
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//public:
//    solution_1(int _node = 0, int _edge = 0, istream& _fin = cin, ostream& _fout = cout) :
//        adj_list(vector<vector<pair<int, int>>>(_node)), is(_fin), os(_fout), node(_node), edge(_edge),
//        uf(_node), depth(vector<int>(_node)), father(vector<int>(_node, -1)), edge_by_node(vector<int>(node, 0))
//    {
//        while (_edge--)
//        {
//            int a, b;
//            is >> a >> b;
//            if (a == b)
//            {
//                continue;
//            }
//            if (find_if(adj_list[a].begin(), adj_list[a].end(), [b](auto& x) { return x.first == b; }) != adj_list[a].end())
//            {
//                continue;
//            }
//            adj_list[a].push_back(make_pair(b, 0));
//            adj_list[b].push_back(make_pair(a, 0));
//        }
//    }
//
//
//
//    /*auto build() -> int
//    {
//        for (auto x:edges)
//        {
//            uf.Union(x.first,x.second);
//        }
//        return uf.part;
//    }*/
//
//    auto count_run()
//    {
//        for (int i = 0; i < node; ++i)
//        {
//            for (auto x : adj_list[i])
//            {
//                if (x.second == 1 && !(edge_by_node[x.first]))
//                {
//                    cout << i << " " << x.first << endl;
//                }
//            }
//        }
//    }
//
//    void run()
//    {
//        bfs_tree();
//        //count_run();
//    }
//};
//
//
//int main()
//{
//    ifstream fin("D:\\005腾讯与学习\\WeChat Files\\WeChat Files\\wxid_ngqbvl22umtn22\\FileStorage\\File\\2022-05\\largeG.txt");
//    int n, e;
//    fin >> n >> e;
//    solution_1 s(n, e, fin);
//    auto begin = clock();
//    s.run();
//    auto end = clock();
//    cout << double(end - begin) / CLOCKS_PER_SEC * 1000 << endl;
//    return 0;
//}
