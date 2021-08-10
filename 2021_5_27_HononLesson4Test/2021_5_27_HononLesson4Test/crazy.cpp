#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

//计算疯狂队列，返回身高差的总和
int maxcrazy(vector<int> v, deque<int> q);

int main()
{
	vector<int> vec;
	deque<int> que;
	int n, e;


	cin >> n;
	while (n--)
	{
		cin >> e;
		vec.push_back(e);
	}
	sort(begin(vec), end(vec));   //身高按升序排序

	cout << maxcrazy(vec, que) << endl;

	system("pause");
	return 0;
}

//计算疯狂队列，返回身高差的总和
int maxcrazy(vector<int> v, deque<int> &q)
{
	int sum = 0, maxvalue;
	q.push_back(v.back());   //最高者入队列
	v.erase(v.end() - 1);

	while (!v.empty())
	{
		//计算v的头尾与队列头尾最高差
		maxvalue = max(abs(v.front() - q.front()), abs(v.front() - q.back()));
		maxvalue = max(maxvalue, abs(v.back() - q.back()));
		maxvalue = max(maxvalue, abs(v.back() - q.front()));

		//根据计算结果入q的队尾或队头
		if (maxvalue == abs(v.front() - q.back()))
		{
			q.push_back(v.front());
			v.erase(begin(v));
		}
		else if (maxvalue == abs(v.front() - q.front()))
		{
			q.push_front(v.front());
			v.erase(begin(v));
		}
		else if (maxvalue == abs(v.back() - q.front()))
		{
			q.push_front(v.back());
			v.erase(end(v) - 1);
		}
		else
		{
			q.push_back(v.back());
			v.erase(end(v) - 1);
		}
		sum += maxvalue;
	}
	return sum;
}
