//#include<iostream>
//#include <queue>
//#include <vector>
//#include <string>
//using namespace std;
//
//int findpos(vector<vector<int>>& vec,int t,int val)
//{
//	for (int i = 0; i < t; i++)
//	{
//		for (auto it : vec[i])
//		{
//			if (it == val)
//				return i;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	vector<vector<int>> vec;
//	vector<int> ins[100];
//	vector<int> tmpvec;
//	queue<vector<int>> que;
//	queue<int> out;
//	queue<vector<int>> tmpque;
//	int num, val, pos1, pos2, flag, sum=0;
//	string command;
//	for (int i = 0; i < t; i++)
//	{
//		vector<int> v;
//		cin >> num;
//		for (int j = 0; j < num; j++)
//		{
//			cin >> val;
//			v.push_back(val);
//		}
//		vec.push_back(v);
//	}
//	while (cin >> command && command != "STOP")
//	{
//		if (command == "ENQUEUE")
//		{
//			sum++;
//			cin >> val;
//			pos1 = findpos(vec, t, val);
//			if (que.empty())//队空直接插入组
//			{
//				vector<int> v;
//				v.push_back(val);
//				que.push(v);
//			}
//			else//队不空
//			{
//				flag = 0;
//				while (!que.empty())//逐个处理组
//				{
//					vector<int> v = que.front();
//					pos2 = findpos(vec, t, v.front());//找一下队内组是什么组
//					if (pos1 == pos2)//元素与队内组相同则插入
//					{
//						v.push_back(val);
//						flag = 1;
//					}
//					que.pop();
//					tmpque.push(v);
//				}
//				if (flag == 0)//元素与队内组都不同
//				{
//					vector<int> v;
//					v.push_back(val);
//					tmpque.push(v);
//				}
//				while (!tmpque.empty())//将tmp队列的组放回主队列
//				{
//					que.push(tmpque.front());
//					tmpque.pop();
//				}
//			}
//		}
//		else if (command == "DEQUEUE")
//		{
//			sum--;
//			if(!que.empty())//处理第一组
//			{
//				vector<int> v = que.front();
//				que.pop();
//				out.push(v.front());
//				v.erase(v.begin());
//				if(v.size()>0)
//					tmpque.push(v);
//			}
//			while (!que.empty())//逐个处理剩下组
//			{
//				tmpque.push(que.front());
//				que.pop();			
//			}		
//			while (!tmpque.empty())//将tmp队列的组放回主队列
//			{
//				que.push(tmpque.front());
//				tmpque.pop();
//			}
//		}
//	}
//	
//	int count = 0;
//	while (!out.empty())//逐个处理组
//	{	
//		count++;
//		if (count < sum)
//			cout << out.front() << " ";
//		else
//			cout << out.front() << endl;
//		out.pop();
//	}
//
//	return 0;
//}