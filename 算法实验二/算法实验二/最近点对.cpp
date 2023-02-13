#include"minDistance.h"

#define random(x) (rand()%x)//生成[0,x]内的随机数
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
			if (myset.find(points[i]) == myset.end())//点不重复
			{
				myset.insert(points[i]);
			}
			else//点不重复
			{
				i--;
			}
		}

		//showCoordinate(points, num);

		//蛮力法
		int min_i = 0, min_j = 1;
		double min_dist = 0, time = 0;
		clock_t begin, end;
		//begin = clock();
		//min_dist = bruteForce(points, num, min_i, min_j);
		//end = clock();
		//time = (double)(end - begin)/CLOCKS_PER_SEC;
		//cout << "--------经过计算-> (" << points[min_i].x << "," << points[min_i].y <<") 和 ("
		//	<< points[min_j].x << "," << points[min_j].y
		//	<< ") 距离最近，距离为：" << sqrt(min_dist) << endl;
		//cout << "--------规模为"<<num<<"时，蛮力法耗时：: " << time << "s" << endl;


		////调用未优化的分治，分治+快排
		min_i = 0, min_j = 1;
		min_dist = 0, time = 0;

		begin = clock();
		sort(points, points + num, cmpX);
		//showCoordinate(points, num);
		min_dist = divideMethod_A(points, 0, num-1, min_i, min_j);	
		end = clock();
		time = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << "--------经过计算-> (" << points[min_i].x << "," << points[min_i].y <<") 和 ("
			<< points[min_j].x << "," << points[min_j].y
			<< ") 距离最近，距离为：" << sqrt(min_dist) << endl;
		cout << "规模为" << num << "时，分治+快排耗时：" << time << "s" << endl;

		////调用优化的分治，分治+归并
		//Point minPoint_i;
		//Point minPoint_j;

		//begin = clock();
		//sort(points, points + num, cmpX);
		//min_dist = divideMethod_B(points, tmp_points, 0, num - 1, minPoint_i, minPoint_j);
		//end = clock();
		//time = (double)(end - begin) / CLOCKS_PER_SEC;
		//cout << "--------经过计算-> (" << minPoint_i.x << "," << minPoint_i.y << ") 和 ("
		//	<< minPoint_j.x << "," << minPoint_j.y
		//	<< ") 距离最近，距离为：" << sqrt(min_dist) << endl;
		//cout << "规模为" << num << "时，分治+归并耗时：" << time << "s" << endl;

		delete[]points;
		delete[]tmp_points;
	}
	
	return 0;
}
