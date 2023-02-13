#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N=100010;
LL a[N];
LL s[N]={0};

int main()
{
    LL n, sum=0, res=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        sum+=a[i];
    }
    if(sum%3!=0||n<3)
    {
        cout<<0<<endl;
        return 0;
    }
    sum/=3;
    LL count=0, total=0;
    
    //1. 两层循环做法
    // for(int i=1;i<n;i++)
    // {
    //     if(s[i]==sum*2)
    //     {
    //         for(int j=1;j<i;j++)
    //         {
    //             if(s[j]==sum)
    //               count++; 
    //         }
    //     }
    // }
    
    //2.双指针优化
    for(int i=1;i<n;i++)
    {
        if(s[i]==sum*2)
            total+=count;
        if(s[i]==sum)
            count++;
    }
    cout<<total<<endl;
    return 0;
}
