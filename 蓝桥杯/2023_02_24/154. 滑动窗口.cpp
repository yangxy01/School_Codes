#include<iostream>
#include<stdio.h>
using namespace std;

const int N=1e6+10;
int a[N],minq[N],maxq[N];

int main()
{
    int n,k;
    int l=0,r=-1;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        while(l<=r&&a[i]<=a[minq[r]])
            r--;
        r++;
        minq[r]=i;
        if(minq[l]<=i-k)
            l++;
        if(i>=k-1)
            cout<<a[minq[l]]<<" ";
    }
    cout<<endl;
    l=0,r=-1;
    for(int i=0;i<n;i++)
    {
        int val = a[i];
        while(l<=r&&val>=maxq[r])
            r--;
        r++;
        maxq[r]=i;
        if(maxq[l]<=i-k)
            l++;
        if(i>=k-1)
            cout<<a[maxq[l]]<<" ";
    }
    
    return 0;
}
