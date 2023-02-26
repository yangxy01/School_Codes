#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='x') continue;
        int count=1, j=0;
        for(j=i+1;j<s.length();j++)
        {
            if(s[j]=='x') count++;
            else break;
        }
        if(count>=3)
            res=res+count-2;
        i=j-1;
    }
    cout<<res<<endl;
    return 0;
}
