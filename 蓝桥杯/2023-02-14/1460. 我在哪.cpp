#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

typedef unsigned long long ULL;
const int N=102, P=131;
ULL h[N],p[N];

ULL trans(int l, int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    p[0]=1;
    unordered_set<ULL> myset;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+s[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        int flag=1;
        for(int j=1;i+j-1<=n;j++)
        {
            ULL tmp = trans(j, j+i-1);
            if(myset.count(tmp)>0)
            {
                flag=0;
                break;
            }
            myset.insert(tmp);
        }
        if(flag)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
