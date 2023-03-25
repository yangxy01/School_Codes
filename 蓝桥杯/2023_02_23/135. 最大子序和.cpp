#include<iostream>
#include<stdio.h>
using namespace std;

typedef long long LL;
const int N=300010;
LL a[N],s[N], que[N];

LL sum(int l, int r)
{
    return s[r]-s[l-1];
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    LL res=a[1];
    int l=0,r=0;
    que[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(que[l]<i-m)
            l++; 
        res=max(res, s[i]-s[que[l]]);
        LL val = s[i];
        while(l<=r&&val<=s[que[r]])
            r--;
        r++;
        que[r]=i;
    }
    printf("%lld", res);
    return 0;
}
