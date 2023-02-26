#include"Sorts.h"

#define random(x) (rand()%x)//����[0,x]�ڵ������

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

	//���������㷨Ч�ʲ���
	for (int count = 0; count < 8; count++)//ѭ��8��
	{
		double selection_time = 0, bubble_time = 0, merge_time = 0, Remerge_time = 0, quick_time = 0, insert_time = 0;
		cout << "Please input the scale:" << endl;
		cout << "from: [10000]  [20000]  [30000]  [40000]  [50000]  [100000]  [200000]  [300000]  " << endl;
		cin >> num;
		int* a = new int[num];
		cout << "calculating..., please wait" << endl;
		int times = 20;
		for (int n = 0; n < times; n++)//����20������
		{
			for (int i = 0; i < num; i++)
			{
				a[i] = random(num);//�����ɵ�������洢������a
			}

			//ѡ������
			int* a1 = copy(a, num);//����һ����������
			selection_time += selectionSort(a1, num);//����ѡ������
			delete[]a1;

			//ð������
			int* a2 = copy(a, num);//����һ����������
			bubble_time += bubbleSort(a2, num);//����ð������
			delete[]a2;

			//�ǵݹ�汾�鲢����
			int* a3 = copy(a, num);//����һ����������
			merge_time += mergeSort(a3, num);//���ù鲢����
			delete[]a3;

			//��������
			int* a4 = copy(a, num);//����һ����������
			clock_t begin, end;
			begin = clock();
			quickSort(a4, 0, num - 1);//���ÿ�������
			end = clock();
			quick_time += (double)(end - begin);
			//cout << "quickSort: " << (double)(end - begin) << "ms" << endl;
			delete[]a4;

			//��������
			int* a5 = copy(a, num);//����һ����������
			insert_time += insertSort(a5, num);//���ò�������
			delete[]a5;

			//�ݹ�汾�鲢����
			int* a6 = copy(a, num);//����һ����������
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
		cout << "�ǵݹ�汾��mergeSort needs: " << setprecision(3) << merge_time << "ms" << endl;
		cout << "�ݹ�汾��Re-mergeSort needs: " << setprecision(3) << Remerge_time << "ms" << endl;
		cout << "quickSort needs: " << setprecision(3) << quick_time << "ms" << endl;
		cout << "insertSort needs: " << setprecision(3) << insert_time << "s" << endl << endl;
	}


	////topK���ֺ���
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






