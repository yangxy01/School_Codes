#include<iostream>
#include<string>
#include<cmath>
using namespace std;
#define endl '\n'
typedef unsigned long long ULL;
const int N=1e5+10, p=131;
ULL h[N],P[N];

inline ULL cal(int l, int r)
{
    l--;
    r--;
    cout<<h[r]-h[l]*P[r-l+1]<<endl;
    return h[r]-h[l]*P[r-l+1];
}

int main()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int l1,r1,l2,r2;
    h[0]=s[0];
    P[0]=1;
    for(int i=1;i<n;i++)
    {
        P[i]=P[i-1]*p;
        h[i]=h[i-1]*p+s[i];
    }
    while(m--)
    {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(cal(l1,r1)==cal(l2,r2))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
