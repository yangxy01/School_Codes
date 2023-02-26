#include<bits/stdc++.h>
#define N 1001
using namespace std;
 
struct node
{
	int x;
	int y;
}a[N];
 
int b[51][51];
int temp[N][N];      
 
int n,l,s;
 
int main()
{
	cin>>n>>l>>s;
	
	
	for(int i=0;i<n;i++) cin>>a[i].x>>a[i].y;
	for(int i=s;i>=0;i--)     //´¢´æ²Ø±¦Í¼
	{
		for(int j=0;j<=s;j++) 
		{
			cin>>b[i][j];
		}
	}
 
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].x+s>l || a[i].y+s>l) continue;
		memset(temp,0,sizeof(temp));
 
		for(int j=0;j<n;j++)
		{
			if(a[j].x-a[i].x<0 || a[j].y -a[i].y<0 || a[j].x-a[i].x>s || a[j].y-a[i].y>s) continue;
			temp[a[j].x-a[i].x][a[j].y-a[i].y]=1;
		}
		bool flag=true;
		for(int k=0;k<=s;k++)
		{
			for(int j=0;j<=s;j++)
			{
				if(temp[k][j]!=b[k][j])
				{
					flag=false;
					continue;
				}
			}
		}
		if(flag) count++;
	}
	cout<<count;
	return 0;
}
 
