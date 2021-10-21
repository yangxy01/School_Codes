#include<iostream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct Custom
{
	int arrive;
	int need;
	int actual=0;
};

int main()
{
	int N,n, T, P, k;
	int sum_time=0, max_time=0, final_time=0, cur_time = -1, wait_time;
	int flag = 1;
	queue<Custom> cus;
	cin >> N;
	n = N;
	while (N--)
	{
		cin >> T >> P;
		Custom C = { T,P };
		cus.push(C);
	}
	cin >> k;
	queue<Custom>* win = new queue<Custom>[k];
	while (1)
	{
		flag = 0;
		cur_time += 1;
		for (int i = 0; i < k; i++)
		{
			if (!win[i].empty())//非空
			{
				win[i].front().actual++;
				if (win[i].front().actual == win[i].front().need)
					win[i].pop();
			}
			if (win[i].empty())//空队列
			{
				if (!cus.empty()&&(cus.front().arrive <= cur_time))
				{
					wait_time = cur_time - cus.front().arrive;
					sum_time += wait_time;
					if (wait_time > max_time)
						max_time = wait_time;
					win[i].push(cus.front());
					cus.pop();
				}
			}
		}
		for (int i = 0; i < k; i++)
		{
			if (!win[i].empty())//非空
				flag = 1;
		}
		if (flag == 0&&cus.empty())
			break;
	}
	cout << fixed << setprecision(1)<<(float)sum_time / n << " " << max_time << " ";
	cout << cur_time << endl;
	delete[]win;
	return 0;
}
