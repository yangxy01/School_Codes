//#include"Sorts.h"
//
//#define random(x) (rand()%x)//生成[0,x]内的随机数
//
//int* copy(int* sou, int num)
//{
//	int* dst = new int[num];
//	for (int i = 0; i < num; i++)
//		dst[i] = sou[i];
//	return dst;
//}
//
//int main()
//{
//	srand((unsigned)time(nullptr));
//	int num;
//	double selection_time = 0, bubble_time = 0, merge_time = 0, quick_time = 0, insert_time = 0;
//	for (int count = 0; count < 5; count++)//循环五次
//	{
//		cout << "Please give the num:" << endl;
//		cin >> num;
//		int* a = new int[num];
//		for (int n = 0; n <8; n++)//生成20组数据
//		{
//			cout << "正在进行第" << n << "次计算"<<endl;
//			//cout << "原始：";
//			for (int i = 0; i < num; i++)
//			{
//				a[i] = random(num);//将生成的随机数存储于数组a
//				//cout << a[i] << " ";
//			}
//			//cout << endl;
//
//
//
//			//冒泡排序
//			int* a2 = copy(a, num);//拷贝一份排序数组
//			bubble_time += bubbleSort(a2, num);//调用冒泡排序
//			delete[]a2;
//
//		}
//		delete[]a;
//		bubble_time /= 8;
//
//		cout << "With the num of : " << num << endl;
//		cout << "bubbleSort needs: " << bubble_time << "ms" << endl;
//
//	}
//	return 0;
//}