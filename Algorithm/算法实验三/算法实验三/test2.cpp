//#include <iostream>
//#include <cstdlib>
//#include <vector>
//#include <fstream>
//
//
//#pragma GCC optimize(3, "Ofast", "inline")
//
//using namespace std;
//
//
//class solution1
//{
//private:
//    //定义节点
//    struct node
//    {
//        int num;
//        vector<int> adj_next;
//        vector<int> col_can;
//
//        node(int _num = 0, int s_num = 0) : num(_num) {}
//    };
//
//    int n;
//    vector<int> colours;
//    int map[500][500] = {};
//    int ct[500][50] = {};
//    int time[500] = {};
//    vector<vector<int>> colours_r;
//    int colour;
//    int ans_num;
//    int ali;
//    istream& is;
//    ostream& os;
//    //定义邻接表
//    vector<node> adj_nodes;
//
//    auto check(int ss, int y) -> bool
//    {
//        for (auto x : adj_nodes[ss].adj_next)
//        {
//            if (y == colours[x])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    //删除颜色
//    void update_rm(int s, int col)
//    {
//        for (auto x : adj_nodes[s].adj_next)
//        {
//            if (!colours[x] && adj_nodes[x].col_can[col])
//            {
//                adj_nodes[x].col_can[col] = 0;
//                --adj_nodes[x].col_can[0];
//            }
//            if (!colours[x])
//            {
//                ct[x][col]++;
//            }
//        }
//    }
//
//    //恢复颜色
//    void update_cv(int s, int col)
//    {
//        for (auto x : adj_nodes[s].adj_next)
//        {
//            if (!colours[x] && !adj_nodes[x].col_can[col] && ct[x][col] == 1)
//            {
//                adj_nodes[x].col_can[col] = 1;
//                ++adj_nodes[x].col_can[0];
//            }
//            if (!colours[x])
//            {
//                --ct[x][col];
//            }
//        }
//    }
//
//    //MRV找下一个变量
//    int find_next_MRV()
//    {
//        int ans_min = INT_MAX;
//        int ans = -1;
//        for (int i = 0; i < n; ++i)
//        {
//            if (!colours[i] && adj_nodes[i].col_can[0] < ans_min)
//            {
//                ans_min = adj_nodes[i].col_can[0];
//                ans = i;
//            }
//        }
//        return ans;
//    }
//
//    //DH找下一个变量
//    int find_next_MRV_DH()
//    {
//        int ans_min = INT_MAX;
//        int degree_max = INT_MIN;
//        int ans = -1;
//        for (int i = 0; i < n; ++i)
//        {
//            if (!colours[i] && adj_nodes[i].col_can[0] < ans_min)
//            {
//                ans_min = adj_nodes[i].col_can[0];
//                ans = i;
//                degree_max = adj_nodes[i].adj_next.size();
//            }
//            else if (!colours[i] && adj_nodes[i].col_can[0] == ans_min)
//            {
//                if (adj_nodes[i].adj_next.size() > degree_max)
//                {
//                    ans = i;
//                    degree_max = adj_nodes[i].adj_next.size();
//                }
//            }
//        }
//        return ans;
//    }
//
//    //前向检查找下一个变量
//    int find_next_MRV_DH_FW1()
//    {
//        int ans_min = INT_MAX;
//        int degree_max = INT_MIN;
//        int ans = -1;
//        for (int i = 0; i < n; ++i)
//        {
//            if (!colours[i] && adj_nodes[i].col_can[0] < ans_min)
//            {
//                ans_min = adj_nodes[i].col_can[0];
//                ans = i;
//                degree_max = adj_nodes[i].adj_next.size();
//            }
//            else if (!colours[i] && adj_nodes[i].col_can[0] == ans_min)
//            {
//                if (adj_nodes[i].adj_next.size() > degree_max)
//                {
//                    ans = i;
//                    degree_max = adj_nodes[i].adj_next.size();
//                }
//            }
//        }
//        if (!ans_min)
//        {
//            return -1;
//        }
//        return ans;
//    }
//
//    //边相容找下一个变量
//    tuple<int, vector<pair<int, int>>> find_next_MRV_DH_FW2(int ss)
//    {
//        int ans_min = INT_MAX;
//        int degree_max = INT_MIN;
//        int ans = -1;
//        vector<pair<int, int>> v1;
//        for (auto i : adj_nodes[ss].adj_next)
//        {
//            if (colours[i])
//            {
//                auto& nexts = adj_nodes[i].adj_next;
//                int col = colours[i];
//
//                for (auto x : nexts)
//                {
//                    if (!colours[x] && adj_nodes[x].col_can[col])
//                    {
//                        v1.push_back(make_pair(x, col));
//                        adj_nodes[x].col_can[col] = 0;
//                        adj_nodes[x].col_can[0]--;
//                    }
//                }
//            }
//        }
//
//        for (int i = 0; i < n; ++i)
//        {
//            if (!colours[i] && adj_nodes[i].col_can[0] < ans_min)
//            {
//                ans_min = adj_nodes[i].col_can[0];
//                ans = i;
//                degree_max = adj_nodes[i].adj_next.size();
//            }
//            else if (!colours[i] && adj_nodes[i].col_can[0] == ans_min)
//            {
//                if (adj_nodes[i].adj_next.size() > degree_max)
//                {
//                    ans = i;
//                    degree_max = adj_nodes[i].adj_next.size();
//                }
//            }
//        }
//        if (!ans_min)
//        {
//            return make_tuple(-1, v1);
//        }
//        return make_tuple(ans, v1);
//    }
//
//    //边相容恢复变量
//    void recover(vector<pair<int, int>>& v1)
//    {
//        for (auto x : v1)
//        {
//            auto f = x.first, s = x.second;
//            adj_nodes[f].col_can[colours[s]] = 0;
//            adj_nodes[f].col_can[0]++;
//
//        }
//    }
//
//    //重新初始化数据
//    void init()
//    {
//        for (auto& x : adj_nodes)
//        {
//            x.col_can = vector<int>(colour + 1, 1);
//            x.col_can[0] = colour;
//        }
//        for (int i = 0; i <= n; ++i)
//        {
//            for (int j = 0; j <= colour; ++j)
//            {
//                ct[i][j] = 0;
//            }
//        }
//        colours = vector<int>(n, 0);
//        ans_num = 0;
//    }
//
//    //输出解
//    void print_ans()
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            cout << colours[i] << "!";
//        }
//        cout << endl;
//    }
//
//public:
//    solution1(istream& iss, ostream& oss) : ans_num(0), is(iss), os(oss)
//    {
//        
//    }
//
//    //输入数据
//    void input()
//    {
//        int m;
//        is >> n >> m >> colour;
//        ali = colour;
//        for (int i = 0; i < n; ++i)
//        {
//            adj_nodes.push_back(node(i, n));
//            adj_nodes[i].col_can = vector<int>(colour + 1, 1);
//            adj_nodes[i].col_can[0] = n;
//        }
//        while (m--)
//        {
//            int i, j;
//            //char c;
//            //is >> c;
//            is >> i >> j;
//            --i, --j;
//            if (!map[i][j])
//            {
//                adj_nodes[i].adj_next.push_back(j);
//                adj_nodes[j].adj_next.push_back(i);
//            }
//            map[i][j] = 1;
//            map[j][i] = 1;
//        }
//        init();
//    }
//
//
//    //朴素回溯，找第一个解
//    void dfs_ori(int ss)
//    {
//        if (ss >= n || ans_num)
//        {
//            print_ans();
//            ans_num++;
//            return;
//        }
//        for (int i = 1; i <= colour; ++i)
//        {
//            if (!colours[ss] && check(ss, i))
//            {
//                colours[ss] = i;
//                dfs_ori(ss + 1);
//                colours[ss] = 0;
//
//            }
//        }
//    }
//
//    //轮转找第一个解
//    void dfs(int ss, int col)
//    {
//        if (!check(ss, col) || ans_num)
//        {
//            return;
//        }
//        if (ss >= n - 1)
//        {
//            ans_num++;
//            print_ans();
//            return;
//        }
//        //cout << ss << "-";
//        colours[ss] = col;
//        for (int i = 1; i <= colour; ++i)
//        {
//            dfs(ss + 1, i);
//            colours[ss + 1] = 0;
//        }
//    }
//
//    //MRV找第一个解
//    void dfs_MRV(int ss, int deep, int col)
//    {
//        if (deep >= n - 1 || ans_num)
//        {
//            ans_num++;
//            //print_ans();
//            return;
//        }
//        //adj_nodes[ss].col_can[col] = 0;
//        colours[ss] = col;
//        //cout << ss << " " << col;
//        update_rm(ss, col);
//        int next = find_next_MRV();
//        //cout << next << " ";
//        for (int i = 1; i <= colour; ++i)
//        {
//            if (adj_nodes[next].col_can[i])
//            {
//                dfs_MRV(next, deep + 1, i);
//                colours[next] = 0;
//                //adj_nodes[next].col_can[i] = 1;
//                update_cv(next, i);
//            }
//        }
//
//    }
//
//    //DH找第一个解
//    void dfs_MRV_DH(int ss, int deep, int col)
//    {
//        if (deep >= n - 1 || ans_num)
//        {
//            ans_num++;
//            return;
//        }
//        colours[ss] = col;
//        update_rm(ss, col);
//        int next = find_next_MRV_DH();
//        for (int i = 1; i <= colour; ++i)
//        {
//            if (adj_nodes[next].col_can[i])
//            {
//                dfs_MRV_DH(next, deep + 1, i);
//                colours[next] = 0;
//                //adj_nodes[next].col_can[i] = 1;
//                update_cv(next, i);
//            }
//        }
//    }
//
//    //一阶前向找第一个解
//    void dfs_MRV_DH_forward(int ss, int deep, int col)
//    {
//        if (deep >= n - 1 || ans_num)
//        {
//            //print_ans();
//            ans_num++;
//            return;
//        }
//        colours[ss] = col;
//        update_rm(ss, col);
//        int next = find_next_MRV_DH_FW1();
//        if (next == -1)
//        {
//            return;
//        }
//        vector<int> cols;
//        for (int i = 1; i <= colour; ++i)
//        {
//            if (adj_nodes[next].col_can[i])
//            {
//                dfs_MRV_DH_forward(next, deep + 1, i);
//                colours[next] = 0;
//                update_cv(next, i);
//            }
//        }
//    }
//
//    //边相容找第一个解
//    void dfs_MRV_DH_forward2(int ss, int deep, int col)
//    {
//        if (deep >= n - 1 || ans_num)
//        {
//            colours[ss] = col;
//            //print_ans();
//            ans_num++;
//            return;
//        }
//        colours[ss] = col;
//        update_rm(ss, col);
//        auto n = find_next_MRV_DH_FW2(ss);
//        int next = get<0>(n);
//        auto& rec = get<1>(n);
//        if (next == -1)
//        {
//            return;
//        }
//        for (int i = 1; i <= colour; ++i)
//        {
//            if (adj_nodes[next].col_can[i])
//            {
//                dfs_MRV_DH_forward2(next, deep + 1, i);
//                colours[next] = 0;
//                update_cv(next, i);
//                recover(rec);
//            }
//        }
//    }
//
//    //轮转法找第一个解
//    int dfs_1(int ss)
//    {
//        if (ss >= n || ans_num)
//        {
//            //ans_num++;
//            return 1;
//        }
//        int ret = 0, tmp = 0;
//        for (int i = 1; i <= colour; ++i)
//        {
//            if (time[i] == 0)
//            {
//                if (tmp)
//                {
//                    continue;
//                }
//                colours[ss] = i, time[i]++, tmp = ali, ali--;
//                ret += dfs_1(ss + 1) * tmp;
//                time[i]--, ali++;
//            }
//            else
//            {
//                if (time[i] == 0)
//                {
//                    continue;
//                }
//                bool flg = true;
//                auto nexts = adj_nodes[ss].adj_next;
//                for (auto x : nexts)
//                {
//                    if (i == colours[x])
//                    {
//                        flg = false;
//                    }
//                }
//                if (flg)
//                {
//                    colours[ss] = i, time[i]++, ret += dfs_1(ss + 1), time[i]--;
//                }
//            }
//            colours[ss] = 0;
//        }
//        return ret;
//    }
//
//    //利用最佳策略找第一个解，测试数据
//    void run()
//    {
//        init();
//
//        cout << "MRV+DH+FW_1:";
//        auto begin = clock();
//        dfs_MRV_DH(3, 0, 1);
//        auto end = clock();
//        os << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
//    }
//
//    //利用各种策略找第一个解，测试数据
//    void run2()
//    {
//
//        init();
//        cout << "MRV+DH+FW_2:";
//        auto begin = clock();
//        dfs_MRV_DH_forward2(3, 0, 1);
//        auto end = clock();
//        os << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
//
//        init();
//
//        cout << "MRV+DH+FW_1:";
//        begin = clock();
//        dfs_MRV_DH_forward(3, 0, 1);
//        end = clock();
//        os << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
//
//        init();
//
//        cout << "MRV+DH:";
//        begin = clock();
//        dfs_MRV_DH(3, 0, 1);
//        end = clock();
//        os << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
//
//    }
//
//};