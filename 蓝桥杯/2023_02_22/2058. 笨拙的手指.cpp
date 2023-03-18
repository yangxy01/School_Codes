#include<iostream>
#include<string>
#include <unordered_set>
using namespace std;

int get(int n, string s)
{
    int res=0;
    for(int i=0;i<s.size();i++)
    {
        res=res*n+s[i]-'0';
    }
    return res;
    cout<<res<<endl;
}

int main()
{
    string a,b;
    cin>>a>>b;
    unordered_set<int> set;
    for(int i=0;i<a.size();i++)
    {
        string s=a;
        if(i==0&&s[i]==1)
        {
            int num = get(2, s);
            set.insert(num);
            continue;
        }
        int num = get(2, s);
        set.insert(num);
        s[i]^=1;
        num = get(2, s);
        set.insert(num);
    }
    for(int i=0;i<b.size();i++)
    {
        string s=b;
        if(i==0&&s[i]==1)
        {
            int num = get(3, s);
            if(set.count(num))
            {
                cout<<num<<endl;
                return 0;
            }
            continue;
        }
        int num = get(3, s);
        if(set.count(num))
        {
            cout<<num<<endl;
            return 0;
        }
        s[i]^=1;
        if(set.count(num))
        {
            cout<<num<<endl;
            return 0;
        }
    }
    return 0;
}
