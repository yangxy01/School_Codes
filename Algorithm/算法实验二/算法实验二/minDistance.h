#pragma once
#include<iostream>
#include<time.h>
#include<iomanip>
#include <vector>
#include<algorithm>
#include<cmath>
#include<float.h>
#include <unordered_set>

using namespace std;

struct Point
{
    double x;
    double y;
};

class myhash {
public:
    size_t operator()(const Point& p)const
    {
        return size_t((p.x + 1) * 3 + (p.y + 1) * 7);
    }
};


class equalPoint {
public:
    bool operator()(const Point& p1, const Point& p2)const
    {
        return p1.x == p2.x && p1.y == p2.y;
    }
};


bool cmpX(const Point& a, const Point& b)
{
    return a.x < b.x;
}
bool cmpY(const Point& a, const Point& b)
{
    return a.y < b.y;
}

void Print(int a[], int num)
{
    int i;
    for (i = 0; i < num; i++)
        cout << a[i] << " ";
    cout << endl;
}

void showCoordinate(Point* points, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        cout << "(" << points[i].x << "," << points[i].y << ") ";
        if (i && i % 10 == 0)
            cout << endl;
    }
    cout << endl;
}


double bruteForce(Point* points, int num, int& min_i, int& min_j)
{
    double dist = 0, cal_dist = 0;
    int i, j;
    dist = (points[0].x - points[1].x) * (points[0].x - points[1].x)
         + (points[0].y - points[1].y) * (points[0].y - points[1].y);
    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            cal_dist = (points[i].x - points[j].x) * (points[i].x - points[j].x)
                     + (points[i].y - points[j].y) * (points[i].y - points[j].y);
            if (cal_dist < dist)
            {
                min_i = i;
                min_j = j;
                dist = cal_dist;
            }
        }
    }
    return dist;
}

void Merge(Point points[], Point tmp_points[], int left, int mid, int right)
{
    int i = left, j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) 
    {
        if (points[i].y < points[j].y)
            tmp_points[k++] = points[i++];
        else
            tmp_points[k++] = points[j++];
    }

    while (i <= mid)
        tmp_points[k++] = points[i++];
    while (j <= right)
        tmp_points[k++] = points[j++];

    for (i = left; i <= right; i++)
        points[i] = tmp_points[i];
   
}

//未优化的分治，分治+快排
double divideMethod_A(Point points[], int low, int high, int& min_i, int& min_j)
{
    double min_dist = 0, cal_dist = 0;
    if (high == low)//只有一个点
    {
        return DBL_MAX;
    }
    else if (high - low == 1)//只有两个点
    {
        min_i = low;
        min_j = high;
        min_dist = (points[low].x - points[high].x) * (points[low].x - points[high].x)
                 + (points[low].y - points[high].y) * (points[low].y - points[high].y);
        return min_dist;
    }
    else if (high - low == 2)//有三个点
    {
        //计算最短距离
        min_i = low;
        min_j = high;
        min_dist = (points[low].x - points[high].x) * (points[low].x - points[high].x)
                 + (points[low].y - points[high].y) * (points[low].y - points[high].y);
        cal_dist = (points[low].x - points[low+1].x) * (points[low].x - points[low + 1].x)
                 + (points[low].y - points[low + 1].y) * (points[low].y - points[low + 1].y);
        if (cal_dist < min_dist)
        {
            min_dist = cal_dist;
            min_i = low;
            min_j = low + 1;
        }
        cal_dist = (points[low + 1].x - points[high].x) * (points[low + 1].x - points[high].x)
                 + (points[low + 1].y - points[high].y) * (points[low + 1].y - points[high].y);
        if (cal_dist < min_dist)
        {
            min_dist = cal_dist;
            min_i = low + 1;
            min_j = high;
        }
        return min_dist;
    }
    
    int mid, left_min_i, left_min_j, right_min_i, right_min_j;
    double left_dist = 0, right_dist = 0;
    mid = (low + high) / 2;
    left_dist = divideMethod_A(points, low, mid, left_min_i, left_min_j);
    right_dist = divideMethod_A(points, mid+1, high, right_min_i, right_min_j);
    if (left_dist < right_dist)
    {
        min_i = left_min_i;
        min_j = left_min_j;
        min_dist = left_dist;
    }
    else
    {
        min_i = right_min_i;
        min_j = right_min_j;
        min_dist = right_dist;
    }
    Point minPoint_i = points[min_i];
    Point minPoint_j = points[min_j];


    //以下处理中间的点对
    int count = 0, i, j;
    Point* midpoints = new Point[high - low + 1];
    for (i = mid; i >= low && (points[mid].x - points[i].x) < sqrt(min_dist); i--)
    {
        midpoints[count] = points[i];
        count++;
    }
    for (i = mid+1; i <= high && (points[i].x - points[mid].x) < sqrt(min_dist); i++)
    {
        midpoints[count] = points[i];
        count++;
    }
    sort(midpoints, midpoints + count, cmpY);
    
    for (i = 0; i < count; i++)//处理midpoints中的点，找出[mid-d,mid+d]中的最近点对
    {
        for (j = i + 1; j < i + 7 && j < count; j++)
        {
            if ((midpoints[j].y - midpoints[i].y) >= min_dist)
            {
                break;
            }
            else
            {
                cal_dist = (points[i].x - points[j].x) * (points[i].x - points[j].x)
                         + (points[i].y - points[j].y) * (points[i].y - points[j].y);
                if (cal_dist < min_dist)
                {
                    min_i = i;
                    min_j = j;
                    min_dist = cal_dist;
                }
            }
        }
    }
    delete[]midpoints;
    return min_dist;

}

//优化的分治，分治+归并
double divideMethod_B(Point points[], Point tmp_points[], int low, int high, Point& minPoint_i, Point& minPoint_j)
{
    double min_dist = 0, cal_dist = 0;
    int min_i, min_j;
    if (high == low)//只有一个点
    {
        return DBL_MAX;
    }
    else if (high - low == 1)//只有两个点
    {
        min_i = low;
        min_j = high;
        min_dist = (points[low].x - points[high].x) * (points[low].x - points[high].x)
            + (points[low].y - points[high].y) * (points[low].y - points[high].y);
        if (points[high].y < points[low].y)
        {
            Point tmp = points[high];
            points[high] = points[low];
            points[low] = tmp;
        }
        minPoint_i = points[min_i];
        minPoint_j = points[min_j];
        return min_dist;
    }
    else if (high - low == 2)//有三个点
    {
        //先将这三个点排序
        for (int i = low + 1; i <= high; i++)
        {
            for (int j = i; j > low; j--)
            {
                if (points[j].y < points[j - 1].y)
                {
                    Point tmp = points[j];
                    points[j] = points[j - 1];
                    points[j - 1] = tmp;
                }
            }
        }

        //计算最短距离
        min_i = low;
        min_j = high;
        min_dist = (points[low].x - points[high].x) * (points[low].x - points[high].x)
            + (points[low].y - points[high].y) * (points[low].y - points[high].y);
        cal_dist = (points[low].x - points[low + 1].x) * (points[low].x - points[low + 1].x)
            + (points[low].y - points[low + 1].y) * (points[low].y - points[low + 1].y);
        if (cal_dist < min_dist)
        {
            min_dist = cal_dist;
            min_i = low;
            min_j = low + 1;
        }
        cal_dist = (points[low + 1].x - points[high].x) * (points[low + 1].x - points[high].x)
            + (points[low + 1].y - points[high].y) * (points[low + 1].y - points[high].y);
        if (cal_dist < min_dist)
        {
            min_dist = cal_dist;
            min_i = low + 1;
            min_j = high;
        }
        minPoint_i = points[min_i];
        minPoint_j = points[min_j];
        return min_dist;
    }

    int mid;
    Point left_min_i, left_min_j;
    Point right_min_i, right_min_j;
    double left_dist = 0, right_dist = 0;
    mid = (low + high) / 2;
    left_dist = divideMethod_B(points, tmp_points, low, mid, left_min_i, left_min_j);
    right_dist = divideMethod_B(points, tmp_points, mid + 1, high, right_min_i, right_min_j);
    if (left_dist < right_dist)
    {
        minPoint_i = left_min_i;
        minPoint_j = left_min_j;
        min_dist = left_dist;
    }
    else
    {
        minPoint_i = right_min_i;
        minPoint_j = right_min_j;
        min_dist = right_dist;
    }

    Merge(points, tmp_points, low, mid, high);//Merge


    //以下处理中间的点对
    int count = 0, i, j;
    Point* midpoints = new Point[high - low + 1];
    for (i = low; i <= high; i++)
    {
        if (fabs(points[i].x - points[mid].x) <= sqrt(min_dist))
        {
            midpoints[count] = points[i];
            count++;
        }
    }

    //sort(midpoints, midpoints + count, cmpY);

    for (i = 0; i < count; i++)//处理midpoints中的点，找出[mid-d,mid+d]中的最近点对
    {
        for (j = i + 1; j < i + 7 && j < count; j++)
        {
            if ((midpoints[j].y - midpoints[i].y) >= min_dist)
            {
                break;
            }
            else
            {
                cal_dist = (points[i].x - points[j].x) * (points[i].x - points[j].x)
                    + (points[i].y - points[j].y) * (points[i].y - points[j].y);
                if (cal_dist < min_dist)
                {
                    min_i = i;
                    min_j = j;
                    min_dist = cal_dist;
                }
            }
        }
    }
    delete[]midpoints;
    return min_dist;

}
