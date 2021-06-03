#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//A. 好人(vector)
int main()
{
	int n, m;
	while (cin>>n>>m)
	{
		int count = 0;
		int i;
		vector<int> vec(2*n);
		for (i = 0; i < 2 * n; i++)//赋值
			vec[i] = i+1;
		
		for (i = 1; count != n; i++)
		{
			if (i%m != 0)
			{
				vec.push_back(vec.front());
				vec.erase(vec.begin());			
			}
			else
			{
				vec.erase(vec.begin());
				count++;
			}
		}

		vector<int>::iterator it;
		for (i = 1; i <= 2 * n; i++)
		{
			int flag = 0;
			for (it = vec.begin(); it < vec.end(); it++)
			{
				if (i == *it)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				cout << "G";
			else
				cout << "B";
		}
		//int k = 0;
		//sort(vec.begin(), vec.end());
		//for (i = 1; i <= 2 * n; i++)
		//{
		//	if (vec[k] == i)
		//	{
		//		cout<<"G";
		//		k++;
		//	}
		//	else
		//		cout << "B";
		//	/*if (i % 50 == 0)
		//		cout << endl;*/
		//}
		//vec.clear();
		cout << endl;
	}
	return 0;
}




////B. 赫夫曼树的构建(vector)
//int main()
//{
//	int n,num;
//	cin >> n;
//	vector<int> vec(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num;
//		vec[i] = num;
//	}
//	int cost = 0, sum;
//	vector<int>::iterator it;
//	while (vec.size() != 1)
//	{
//		sum = 0;
//		it = min_element(vec.begin(), vec.end());//找最小元素
//		sum += *it;
//		vec.erase(it);
//		it = min_element(vec.begin(), vec.end());//找第二小元素
//		sum += *it;
//
//		cost += sum;
//		vec.erase(it);
//		vec.push_back(sum);
//	}
//	cout << cost << endl;
//	return 0;
//}




////D. 幸运数(vector)
//int main()
//{
//	int m, n;//定义两个数，表示范围
//	cin >> m >> n;
//
//	vector<int> vec(n);
//	vector<int> Lucky;
//	
//	for (int i = 0; i < n; i++)
//	{
//		vec[i] = i + 1;
//	}
//	Lucky.push_back(2);//先假设第一个幸运数为2，方便处理
//	vector<int>::iterator it;
//	vector<int>::iterator newend;
//	int count = 1;
//	while (1)
//	{
//		int i;
//		for (it = vec.begin(),i=1; it < vec.end(); it++,i++)
//		{
//			if (i % Lucky.back() == 0)
//				*it = -1;	//置为-1
//		}
//		newend = remove(vec.begin(), vec.end(), -1);
//		vec.erase(newend, vec.end());//删除
//
//		Lucky.push_back(vec[count]);
//		if (vec[count] == vec.back())
//			break;
//		count++;
//	}
//
//	Lucky[0] = 1;//第一个幸运数设置为1
//	int num = 0;
//	for (it = Lucky.begin(); it < Lucky.end(); it++)
//	{
//		if (*it > m&&*it < n)
//		{
//			num++;
//		}
//	}
//	cout << num << endl;
//	return 0;
//}






//C. 城市名称处理（vector+泛型）
//int main()
//{
//	vector<string> vec;
//	string str;
//	while (1)//不断读入
//	{
//		getline(cin, str);
//		if (str == "00")
//			break;
//		vec.push_back(str);
//	}
//	cin >> str;
//	vector<string>::iterator ite;
//	for (ite = vec.begin(); ite < vec.end(); ite++)//遍历查找
//	{
//		if (*ite == str)
//		{
//			cout << str << " found" << endl;
//			break;
//		}
//	}
//	if (ite == vec.end())//如果没找到
//	{
//		vec.push_back(str);
//		cout << str << " not found" << endl;
//	}
//
//	int x, y;//定义两个位置
//	cin >> x >> y;
//	cout << vec[x - 1] << endl;//输出第x个城市
//
//	//排序函数
//	sort(vec.begin(), vec.end());
//	cout << vec[y - 1] << endl;//输出第y个城市
//
//	return 0;
//}
