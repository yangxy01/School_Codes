#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

#define endl '\n'

const int N=1010;
const int M=1e6;
int record[N];
int h[N], idx=0, e[M], ne[M];
int n,l,m,u;

void add(int a, int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}

int bfs(int u)
{
    int res=0;
    memset(record, 0, sizeof(record));
    queue<int> que;
    que.push(u);
    record[u]=1;
    bool state =false;
    while(que.size())
    {
        int cur = que.front();
        que.pop();
        int p=h[cur];
        while(p!=-1)
        {
            int v=e[p];
            if(record[v]!=0)
            {
            	p=ne[p];
            	continue;
			}
            record[v]=record[cur]+1;
            if(record[v]<=l+1)
            {
                res++;
            }
            que.push(v);
            p=ne[p];
        }
        if(state)
            return res;
    }
    return res;
}

int main()
{
	memset(h, -1, sizeof(h));
	cin>>n>>l;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>u;
            add(u, i);
        }
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>u;
        cout<<bfs(u)<<endl;;
    }
    return 0;
}
