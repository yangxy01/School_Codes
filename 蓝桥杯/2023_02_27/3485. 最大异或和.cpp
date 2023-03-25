#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+10, M=N*32;
int a[N], s[N];
int son[M][2], idx=0, cou[M];

void insert(int x, int c)
{
    int cur=0;
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;
        if(son[cur][u]==0)
        {
            idx++;
            son[cur][u]=idx;
        }
        cur = son[cur][u];
        cou[cur]+=c;
    }
}

int query(int x)
{
    int cur=0, res=0;
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;
        if(cou[son[cur][!u]]>0)
        {
            res = res*2+!u;
            cur = son[cur][!u];
        }
        else
        {
            res = res*2+u;
            cur = son[cur][u];
        }
    }
    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    insert(0,1);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(i-m>0)
            insert(s[i-m-1], -1);
        int x=s[i];
        res = max(res, x^query(x));
        insert(x, 1);
    }
    cout<<res<<endl;
    return 0;
}
