#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

//------------------------------ ¶þ·Ö ------------------------------
const int N=5e6+10;

struct Sum{
    int t=0;
    int c=0;
    int d=0;
    
    bool operator<(const Sum& s)const
    {
        if(s.t!=t) return t<s.t;
        if(s.c!=c) return c<s.c;
        if(s.d!=d) return d<s.d;
        return true;
    }
};

Sum s[N*2];

int main()
{
    int n, count=0;
    cin>>n;
    for(int c=0;c*c<=n;c++)
    {
        for(int d=c;c*c+d*d<=n;d++)
        {
            int res=c*c+d*d;
            s[count++]={res, c, d};
        }
    }
    sort(s, s+count);
    for(int a=0;a*a<=n;a++)
    {
        for(int b=a;a*a+b*b<=n;b++)
        {
            int t=n-a*a-b*b;
            int l=0, r=count-1;
            while(l<r)
            {
                int mid=l+r>>1;
                if(s[mid].t>=t) r=mid;
                else l=mid+1;
            }
            if(s[l].t==t)
            {
                printf("%d %d %d %d\n", a, b, s[l].c, s[l].d);
                return 0;
            }
        }
    }
    return 0;
}

//------------------------------ Ä£Äâ¹þÏ£ ------------------------------
// const int N=5e6;
// int rem[2*N+10];

// int main()
// {
//     int n;
//     cin>>n;
//     memset(&rem, -1, sizeof(rem));
//     for(int c=0;c*c<=n;c++)
//     {
//         for(int d=c;c*c+d*d<=n;d++)
//         {
//             int res=c*c+d*d;
//             if(rem[res]==-1)
//                 rem[res]=c;
                
//         }
//     }
//     for(int a=0;a*a<=n;a++)
//     {
//         for(int b=a;a*a+b*b<=n;b++)
//         {
//             int t=n-a*a-b*b;
//             int c=rem[t];
//             if(c!=-1)
//             {
//                 int d=sqrt(t-c*c);
//                 if(d*d+c*c==t)
//                 {
//                     printf("%d %d %d %d\n", a, b, c, d);
//                     return 0;
//                 }
//             }
//         }
//     }
//     return 0;
// }
