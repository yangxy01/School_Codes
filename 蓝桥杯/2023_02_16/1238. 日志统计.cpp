#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+10;

struct log
{
    int ts;
    int id;
    bool operator<(const log& item)
    {
        if(ts!=item.ts)
            return ts<item.ts;
        return id<item.id;
    }
}vec[N];

// log vec[N];
int ccount[N]={0}, res[N]={0};

int main()
{
    int n,d,k;
    cin>>n>>d>>k;
    for(int i=0;i<n;i++)
        scanf("%d%d", &vec[i].ts, &vec[i].id);
    sort(vec, vec+n);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<vec[i].ts<<" "<<vec[i].id<<endl;
    // }
    // cout<<"------------"<<endl;
    for(int i=0, j=0; i<n; i++)
    {
        while(j<n && vec[j].ts-vec[i].ts<d)
        {
            ccount[vec[j].id]++;
            if(ccount[vec[j].id]>=k) 
                res[vec[j].id]=1;
            j++;
        }
        ccount[vec[i].id]--;
    }
    for(int i=0; i<N; i++)
        if(res[i])
            cout<<i<<endl;
    return 0;
}
