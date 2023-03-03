#include<iostream>
#include<string>
#include<vector>
using namespace std;

int a[210], b[210];

int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='W')
            {
                a[i]=1;
                b[i]=1;
            }
            else
            {
                a[i]=-1;
                b[i]=-1;
            }
        }
        vector<int> res;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]!=1)
            {
                a[i]*=-1;
                a[i+1]*=-1;
                res.push_back(i+1);
            }
        }
        if(a[n-1]==1)
        {
            cout<<res.size()<<endl;
            if(res.size()==0)
                continue;
            for(auto x: res)
                cout<<x<<" ";
            cout<<endl;
        }
        else
        {
            for(int i=0;i<n-1;i++)
        {
            if(a[i]!=1)
            {
                a[i]*=-1;
                a[i+1]*=-1;
                res.push_back(i+1);
            }
        }
        if(a[n-1]==1)
        {
            cout<<res.size()<<endl;
            if(res.size()==0)
                continue;
            for(auto x: res)
                cout<<x<<" ";
            cout<<endl;
        }
            cout<<-1<<endl;
        }
        // cout<<"------------"<<endl;
    }
    return 0;
}
