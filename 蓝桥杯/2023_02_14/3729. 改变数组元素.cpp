#include<iostream>
using namespace std;

const int N=200010;
int a[N]={0};

void insert(int l, int r, int x=1)
{
    a[l]+=x;
    a[r+1]-=x;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, num;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>num;
            if(num!=0)
            {
                if(num>i)
                    insert(1, i);
                else
                    insert(i-num+1, i);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            // cout<<a[i]<<" ";
            ans+=a[i];
            if(ans!=0)
                cout<<1<<" ";
            else
                cout<<"0 ";
            a[i]=0;
        }
        a[n+1]=0;
        cout<<endl;
    }
    return 0;
}
