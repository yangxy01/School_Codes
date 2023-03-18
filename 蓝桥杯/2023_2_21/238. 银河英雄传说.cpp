#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

const int N=30000+100;
int p[N],d[N],nums[N];

int ffind(int x)
{
    if(p[x]!=x)
    {
        int t = p[x];
        p[x]=ffind(p[x]);
        d[x]+=d[t];
    }
    return p[x];
}

int main()
{
    for(int i=1;i<=N-10;i++)
    {
        p[i]=i;
        nums[i]=1;
    }
    int T,a,b;
    char op;
    cin>>T;
    while(T--)
    {
    	scanf("%c",&op);
        scanf("%c%d%d", &op, &a, &b);
        int pa=ffind(a);
        int pb=ffind(b);
        if(op=='M')
        {
            if(pa!=pb)
            {
                p[pa]=pb;
                d[pa]+=nums[pb];
                nums[pb]+=nums[pa];
            }
        }
        else
        {
            if(pa!=pb)
                puts("-1");
            else
            {
            	if(a==b)
            		puts("0");
            	else
            		printf("%d\n",abs(d[a]-d[b])-1);
			}
        }
    }
    return 0;
}
