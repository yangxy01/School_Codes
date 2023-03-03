#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
char g[6][6], handle[6][6];
int dx[5]={0, 0, 0, -1, 1}, dy[5]={0, -1, 1, 0, 0};

void turn(int x, int y)
{
    for(int i=0;i<5;i++)
    {
        int a=x+dx[i];
        int b=y+dy[i];
        if(a>=0&&a<5&&b>=0&&b<5)
        {
            if(handle[a][b]=='1') handle[a][b]='0';
            else handle[a][b]='1';
        }
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int res=100;
        for(int i=0;i<5;i++) scanf("%s",g[i]);
        for(int i=0;i<32;i++)//此时i表示棋盘第一行哪些灯要按，如i=5，此时灯为00101，1为要按的位置
        {
            memcpy(handle, g, sizeof(g));
            int times=0;//记录开关次数
            for(int k=0;k<5;k++)
                if(i>>k&1)
                {
                    turn(0, k);
                    times++;
                }
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<5;j++)
                {
                    if(handle[i][j]=='0')
                    {
                        turn(i+1, j);
                        times++;
                    }
                }
            }
            bool success=true;
            for(int j=0;j<5;j++)
                if(handle[4][j]=='0')
                    success=false;
            if(success&&times<=6)
            {
                res=min(times, res);
            }
        }
        if(res>6)
            cout<<-1<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}
