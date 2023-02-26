#include<iostream>
using namespace std;

const int N=1e5+10;
int a[N], count[N];

int main()
{
    int n, res=0, j=0;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(int i=0;i<n;i++)
    {
        while(j<n)
        {
            if(count[a[j]]==1)
                break;
            count[a[j]]++;
            j++;
        }
        res=max(res, j-i);
        count[a[i]]--;
        if(j==n) break;
    }
    cout<<res<<endl;
    return 0;
}
