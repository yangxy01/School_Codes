#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//A. ����(vector)
int main()
{
	int n, m;
	while (cin>>n>>m)
	{
		int count = 0;
		int i;
		vector<int> vec(2*n);
		for (i = 0; i < 2 * n; i++)//��ֵ
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




////B. �շ������Ĺ���(vector)
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
//		it = min_element(vec.begin(), vec.end());//����СԪ��
//		sum += *it;
//		vec.erase(it);
//		it = min_element(vec.begin(), vec.end());//�ҵڶ�СԪ��
//		sum += *it;
//
//		cost += sum;
//		vec.erase(it);
//		vec.push_back(sum);
//	}
//	cout << cost << endl;
//	return 0;
//}




////D. ������(vector)
//int main()
//{
//	int m, n;//��������������ʾ��Χ
//	cin >> m >> n;
//
//	vector<int> vec(n);
//	vector<int> Lucky;
//	
//	for (int i = 0; i < n; i++)
//	{
//		vec[i] = i + 1;
//	}
//	Lucky.push_back(2);//�ȼ����һ��������Ϊ2�����㴦��
//	vector<int>::iterator it;
//	vector<int>::iterator newend;
//	int count = 1;
//	while (1)
//	{
//		int i;
//		for (it = vec.begin(),i=1; it < vec.end(); it++,i++)
//		{
//			if (i % Lucky.back() == 0)
//				*it = -1;	//��Ϊ-1
//		}
//		newend = remove(vec.begin(), vec.end(), -1);
//		vec.erase(newend, vec.end());//ɾ��
//
//		Lucky.push_back(vec[count]);
//		if (vec[count] == vec.back())
//			break;
//		count++;
//	}
//
//	Lucky[0] = 1;//��һ������������Ϊ1
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






//C. �������ƴ���vector+���ͣ�
//int main()
//{
//	vector<string> vec;
//	string str;
//	while (1)//���϶���
//	{
//		getline(cin, str);
//		if (str == "00")
//			break;
//		vec.push_back(str);
//	}
//	cin >> str;
//	vector<string>::iterator ite;
//	for (ite = vec.begin(); ite < vec.end(); ite++)//��������
//	{
//		if (*ite == str)
//		{
//			cout << str << " found" << endl;
//			break;
//		}
//	}
//	if (ite == vec.end())//���û�ҵ�
//	{
//		vec.push_back(str);
//		cout << str << " not found" << endl;
//	}
//
//	int x, y;//��������λ��
//	cin >> x >> y;
//	cout << vec[x - 1] << endl;//�����x������
//
//	//������
//	sort(vec.begin(), vec.end());
//	cout << vec[y - 1] << endl;//�����y������
//
//	return 0;
//}
