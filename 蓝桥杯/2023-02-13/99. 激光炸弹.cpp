#include<iostream>
using namespace std;
typedef long long LL;
const int N=5010;

int s[N][N];

int main()
{
    int n,r,x,y,w;
    int mx=0,my=0;
    cin>>n>>r;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>w;
        x++;y++;
        s[x][y]+=w;
        mx=max(mx,x);
        my=max(my,y);
    }
    int res=0;
    // for(int i=1;i<=mx;i++)
    // {
    //     for(int j=1;j<=my;j++)
    //     {
    //         s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
    //         if(i>=r&&j>=r)
    //         {
    //             int tmp=s[i][j]-s[i][j-r]-s[i-r][j]+s[i-r][j-r];
    //             res=max(res, tmp);
    //         }
    //     }
    // }
    cout<<res<<endl;
    return 0;
}
