//#include"Sorts.h"
//
//#define random(x) (rand()%x)//����[0,x]�ڵ������
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
//	for (int count = 0; count < 5; count++)//ѭ�����
//	{
//		cout << "Please give the num:" << endl;
//		cin >> num;
//		int* a = new int[num];
//		for (int n = 0; n <8; n++)//����20������
//		{
//			cout << "���ڽ��е�" << n << "�μ���"<<endl;
//			//cout << "ԭʼ��";
//			for (int i = 0; i < num; i++)
//			{
//				a[i] = random(num);//�����ɵ�������洢������a
//				//cout << a[i] << " ";
//			}
//			//cout << endl;
//
//
//
//			//ð������
//			int* a2 = copy(a, num);//����һ����������
//			bubble_time += bubbleSort(a2, num);//����ð������
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