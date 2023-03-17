#include<iostream>
using namespace std;

const int N=1e5+10;
int pa[N];
int n,m;

int find(int x)
{
    while(pa[x]!=x)
        pa[x]=find(pa[x]);
    return pa[x];
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        pa[i]=i;
    char op;
    int a,b;
    while(m--)
    {
        cin>>op>>a>>b;
        int x = pa[a];
        int y = pa[b];
        if(op=='M')
        {
            if(x==y)
                continue;
            pa[x] = y;
        }
        else
        {
            if(x==y)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
