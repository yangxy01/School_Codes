#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(-1);
    int n,x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        while(st.size()>1&&x>st.top())
            st.pop();
        cout<<st.top()<<" ";
        st.push(x);
    }
    return 0;
}
