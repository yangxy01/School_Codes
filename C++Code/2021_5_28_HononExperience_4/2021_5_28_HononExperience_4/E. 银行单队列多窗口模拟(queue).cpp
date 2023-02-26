//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <iomanip>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <string>
//using namespace std;
//struct Per
//{
//	int arrive;
//	int consume;
//	Per(int a, int c) :arrive(a), consume(c){}
//};
//
//struct window 
//{
//	int is_busy;
//	int finish;
//	window():is_busy(0), finish(0) {}
//};
//
//int main()
//{
//	int time = 0,arrive,consume;
//	int wait_all = 0, now_wait = 0, finish = 0, maxwait = 0;
//	int n,k,num;
//	cin >> n;
//	num = n;
//	queue<Per> que;
//	while (n--)
//	{
//		cin >> arrive >> consume;
//		/*if (consume > 60)
//			consume = 60;*/
//		que.push(Per(arrive, consume));
//	}
//	cin >> k;
//	vector<window> win(k);
//	while (!que.empty())
//	{
//		if (time >= que.front().arrive)
//		{
//			for (int i = 0; i < k; i++)
//			{
//				if (win[i].finish<= time) 
//				{
//					win[i].is_busy = 0;
//				}
//			}
//
//			for (int i = 0; i < k; i++)
//			{
//				if (que.empty())
//					break;
//				if (!win[i].is_busy&&time >= que.front().arrive)//不忙
//				{
//					win[i].is_busy = 1;
//					win[i].finish = time + que.front().consume;
//					now_wait = time - que.front().arrive;
//					wait_all += now_wait;
//					if (now_wait > maxwait){maxwait = now_wait;}
//					if (win[i].finish > finish){finish = win[i].finish;}
//					que.pop();
//				}		
//			}
//			
//		}
//		time++;
//	}
//	cout << fixed << setprecision(1) << 1.0*wait_all / num << " " << maxwait
//		<< " " << finish << endl;
//	return 0;
//}
//
////#include <iostream>
////#include <queue>
////#include <iomanip>
////#include <string>
////using namespace std;
////
////class quetomer {
////public:
////	int arrive, consume;
////	quetomer(int c_t, int u_t) {
////		arrive = c_t;
////		consume = u_t;
////	}
////
////};
////class window {
////public:
////	bool is_busy;
////	int finish;
////	window() :is_busy(0), finish(0) {}
////};
////
////int main() {
////	int n, arrive, consume, k;
////	int wait_all = 0, now_wait = 0, finish = 0, maxwait = 0;
////	queue<quetomer> que;
////	cin >> n; //顾客人数
////	int n1 = n;
////	while (n1--) 
////	{
////		cin >> arrive >> consume;
////		que.push(quetomer(arrive, consume));
////	}
////	cin >> k;
////	window *win = new window[k];
////	int time = 0;
////	while (!que.empty()) 
////	{
////		if (time >= que.front().arrive) 
////		{
////			for (int i = 0; i < k; i++) 
////			{
////				if (win[i].finish <= time) 
////				{
////					win[i].is_busy = 0;
////				}
////			}
////			for (int i = 0; i < k; i++) 
////			{
////				if (!win[i].is_busy && (!que.empty()) 
////					&& (time >= que.front().arrive)) 
////				{
////					win[i].is_busy = 1;
////					win[i].finish = time + que.front().consume;
////					now_wait = time - que.front().arrive;
////					wait_all += now_wait;
////					if (now_wait > maxwait) 
////					{
////						maxwait = now_wait;
////					}
////					if (win[i].finish > finish) 
////					{
////						finish = win[i].finish;
////					}
////					que.pop();
////				}
////
////			}
////		}
////
////		time++;
////	}
////	cout << fixed << setprecision(1) << (double)wait_all / n << " " << maxwait << " " << finish << endl;
////	delete[]win;
////	return 0;
////}
//
