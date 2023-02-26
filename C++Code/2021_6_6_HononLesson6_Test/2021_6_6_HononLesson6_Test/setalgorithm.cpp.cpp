/*
计算集合的并、交、差、对称差。
3 10 20 30
4 10 1 2 3
*/

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

//输出multiset
void display(multiset<int> re)
{
    for (auto x : re)
        cout << x << " ";
    cout << endl;
}

//输入，并插入multiset
void input(multiset<int>& s, int n)
{
    int e;
    while (n--)
    {
        cin >> e;
        s.insert(e);
    }
}


int main()
{
    multiset<int> s1, s2, result;      //set
    vector<int> v(10);
    list<int> l;
    int n;


    //输入两个集合
    cin >> n;
    input(s1, n);
    cin >> n;
    input(s2, n);

    //求集合的并
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(result, result.begin()));
    cout << "union:";
    for (auto x : result)
        cout << x << " ";
    cout << endl;

    //求集合的交
    auto it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());
    cout << "intersection:";
    v.resize(it - begin(v));
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    //集合的差, s1-s2: 在s1中，不在s2中元素集合
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(l));
    cout << "difference:";
    for (auto it = l.begin(); it != l.end(); it++)
        cout << *it << " ";
    cout << endl;

    //集合的对称差
    result.clear();
    set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(result, end(result)));
    cout << "symmetric difference:";
    for (auto x : result)
        cout << x << " ";
    cout << endl;

    system("pause");
    return 0;


}
