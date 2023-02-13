#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[1010],n;
    double avg=0;
    double D=0;   
    int i;
    cin>>n;
    for(i=0;i<n;i++)
	{
        cin>>num[i];
        avg+=num[i];
    }
    avg/=n;
 
    for(i=0;i<n;i++)
	{
        D+=((num[i]-avg)*(num[i]-avg));
    }
    D/=n;
    for(i=0;i<n;i++)
	{
        printf("%.16f\n",(num[i]-avg)/sqrt(D));
    }
    return 0;
}
