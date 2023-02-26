#include"minDistance.h"

#define random(x) (rand()%x)//����[0,x]�ڵ������
int main()
{
	srand((unsigned)time(nullptr));
	int start = 1000, end = 1000000;
	/*for (int num = start; num <= end; num *= 10)*/
	while(1)
	{
		int num;
		cout << "input scale:" << endl;
		cin >> num;
		Point* points = new Point[num];
		Point* tmp_points = new Point[num];
		unordered_set<Point, myhash, equalPoint> myset;
		for (int i = 0; i < num; i++)
		{
			points[i].x = random(num);
			points[i].y = random(num);
			if (myset.find(points[i]) == myset.end())//�㲻�ظ�
			{
				myset.insert(points[i]);
			}
			else//�㲻�ظ�
			{
				i--;
			}
		}

		//showCoordinate(points, num);

		//������
		int min_i = 0, min_j = 1;
		double min_dist = 0, time = 0;
		clock_t begin, end;
		//begin = clock();
		//min_dist = bruteForce(points, num, min_i, min_j);
		//end = clock();
		//time = (double)(end - begin)/CLOCKS_PER_SEC;
		//cout << "--------��������-> (" << points[min_i].x << "," << points[min_i].y <<") �� ("
		//	<< points[min_j].x << "," << points[min_j].y
		//	<< ") �������������Ϊ��" << sqrt(min_dist) << endl;
		//cout << "--------��ģΪ"<<num<<"ʱ����������ʱ��: " << time << "s" << endl;


		////����δ�Ż��ķ��Σ�����+����
		min_i = 0, min_j = 1;
		min_dist = 0, time = 0;

		begin = clock();
		sort(points, points + num, cmpX);
		//showCoordinate(points, num);
		min_dist = divideMethod_A(points, 0, num-1, min_i, min_j);	
		end = clock();
		time = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << "--------��������-> (" << points[min_i].x << "," << points[min_i].y <<") �� ("
			<< points[min_j].x << "," << points[min_j].y
			<< ") �������������Ϊ��" << sqrt(min_dist) << endl;
		cout << "��ģΪ" << num << "ʱ������+���ź�ʱ��" << time << "s" << endl;

		////�����Ż��ķ��Σ�����+�鲢
		//Point minPoint_i;
		//Point minPoint_j;

		//begin = clock();
		//sort(points, points + num, cmpX);
		//min_dist = divideMethod_B(points, tmp_points, 0, num - 1, minPoint_i, minPoint_j);
		//end = clock();
		//time = (double)(end - begin) / CLOCKS_PER_SEC;
		//cout << "--------��������-> (" << minPoint_i.x << "," << minPoint_i.y << ") �� ("
		//	<< minPoint_j.x << "," << minPoint_j.y
		//	<< ") �������������Ϊ��" << sqrt(min_dist) << endl;
		//cout << "��ģΪ" << num << "ʱ������+�鲢��ʱ��" << time << "s" << endl;

		delete[]points;
		delete[]tmp_points;
	}
	
	return 0;
}
