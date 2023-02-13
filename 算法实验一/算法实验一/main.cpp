#include"Sorts.h"

#define random(x) (rand()%x)//生成[0,x]内的随机数

int* copy(int* sou, int num)
{
	int* dst = new int[num];
	for (int i = 0; i < num; i++)
		dst[i] = sou[i];
	return dst;
}

int main()
{
	srand((unsigned)time(nullptr));
	int num;

	//测试排序算法效率部分
	for (int count = 0; count < 8; count++)//循环8次
	{
		double selection_time = 0, bubble_time = 0, merge_time = 0, Remerge_time = 0, quick_time = 0, insert_time = 0;
		cout << "Please input the scale:" << endl;
		cout << "from: [10000]  [20000]  [30000]  [40000]  [50000]  [100000]  [200000]  [300000]  " << endl;
		cin >> num;
		int* a = new int[num];
		cout << "calculating..., please wait" << endl;
		int times = 20;
		for (int n = 0; n < times; n++)//生成20组数据
		{
			for (int i = 0; i < num; i++)
			{
				a[i] = random(num);//将生成的随机数存储于数组a
			}

			//选择排序
			int* a1 = copy(a, num);//拷贝一份排序数组
			selection_time += selectionSort(a1, num);//调用选择排序
			delete[]a1;

			//冒泡排序
			int* a2 = copy(a, num);//拷贝一份排序数组
			bubble_time += bubbleSort(a2, num);//调用冒泡排序
			delete[]a2;

			//非递归版本归并排序
			int* a3 = copy(a, num);//拷贝一份排序数组
			merge_time += mergeSort(a3, num);//调用归并排序
			delete[]a3;

			//快速排序
			int* a4 = copy(a, num);//拷贝一份排序数组
			clock_t begin, end;
			begin = clock();
			quickSort(a4, 0, num - 1);//调用快速排序
			end = clock();
			quick_time += (double)(end - begin);
			//cout << "quickSort: " << (double)(end - begin) << "ms" << endl;
			delete[]a4;

			//插入排序
			int* a5 = copy(a, num);//拷贝一份排序数组
			insert_time += insertSort(a5, num);//调用插入排序
			delete[]a5;

			//递归版本归并排序
			int* a6 = copy(a, num);//拷贝一份排序数组
			int* tmp = new int[num];
			begin = clock();
			recursionMergeSort(a6, tmp, 0, num - 1);
			end = clock();
			Remerge_time += (double)(end - begin);
			delete[]tmp;
			delete[]a6;
		}
		delete[]a;
		selection_time /= times;
		bubble_time /= times;
		merge_time /= times;
		Remerge_time /= times;
		quick_time /= times;
		insert_time /= times;
		cout << endl << "With the scale of : " << num << endl;
		cout << "selectionSort needs: " << setprecision(3) << selection_time << "s" << endl;
		cout << "bubbleSort needs: " << setprecision(3) << bubble_time << "s" << endl;
		cout << "非递归版本：mergeSort needs: " << setprecision(3) << merge_time << "ms" << endl;
		cout << "递归版本：Re-mergeSort needs: " << setprecision(3) << Remerge_time << "ms" << endl;
		cout << "quickSort needs: " << setprecision(3) << quick_time << "ms" << endl;
		cout << "insertSort needs: " << setprecision(3) << insert_time << "s" << endl << endl;
	}


	////topK部分函数
	//cout << "topK -> Please input the scale:" << endl;
	//cin >> num;
	//vector<int>vec(num, 0);
	//for (int i = 0; i < num; i++)
	//{
	//	vec[i] = random(num);
	//}
	//clock_t begin, end;
	//begin = clock();
	//heapSort(vec, num);
	//end = clock();
	//cout << "heapSort needs: " << setprecision(3) << double(end - begin) / CLOCKS_PER_SEC << "s" << endl;
	
	return 0;
}






