#pragma once
#include<iostream>
#include<time.h>
#include<iomanip>
#include <vector>

using namespace std;

void Print(int a[], int num)
{
    int i;
    for (i = 0; i < num; i++)
        cout << a[i] << " ";
    cout << endl;
}

//1.选择排序
double selectionSort(int a[], int num)
{
    clock_t begin, end;
    int i, j, k, tmp;
    begin = clock();//记录开始时间
    for (i = 0; i < num; i++)
    {
        k = i;//记录最小值下标
        for (j = i + 1; j < num; j++)//遍历寻找最小值
        {
            if (a[j] < a[k])//更新最小值下标
                k = j;
        }
        //swap(a[i], a[k]);
        tmp = a[i];
        a[i] = a[k];
        a[k] = tmp;
    }
    end = clock();//记录结束时间
    return (double)(end - begin) / CLOCKS_PER_SEC;
    //cout <<"selectionSort: " << (double)(end - begin) << "ms" << endl;
}

//2.冒泡排序
double bubbleSort(int a[], int num)
{
    clock_t begin, end;
    int i, j, tmp;
    begin = clock();
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num - i - 1; j++)//找出当前行最大值沉底
        {
            if (a[j] > a[j + 1])//把大的只放到后面
            {
                //swap(a[j], a[j+1]);
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    end = clock();
    return (double)(end - begin) / CLOCKS_PER_SEC;
    //cout << "bubbleSort: " << (double)(end - begin) << "ms" << endl;
}

//3.合并排序
void merge(int a[], int* tmp, int left, int mid, int right)
{
    int i = left, j = mid + 1;
    int k = i;
    while (i <= mid && j <= right)//没到序列末尾则继续
    {
        //将左右两边序列小的放入tmp数组存储
        if (a[i] <= a[j])
        {
            tmp[k] = a[i]; i++; k++;
        }
        else
        {
            tmp[k] = a[j]; j++; k++;
        }
    }
    while (i <= mid) //左边序列剩余并入
    { 
        tmp[k] = a[i]; i++; k++;
    }
    while (j <= right) //右边序列剩余并入
    { 
        tmp[k] = a[j]; j++; k++;
    }
}
double mergeSort(int a[], int num)
{
    clock_t begin, end;
    begin = clock();
    int* tmp = new int[num];
    int left, mid, right;
    for (int gap = 1; gap <= num / 2 + 1; gap *= 2)
    {
        int i = 0;
        while(i<num)
        {
            left = i;
            mid = left + gap - 1;
            if (mid >= num - 1)
                break;
            right = left + 2*gap - 1;
            if (right >= num)
                right = num - 1;
            merge(a, tmp, left, mid, right);
            i = right + 1;
        }
        for (int j = 0; j < num; j++)//更改回原数组
            a[j] = tmp[j];
    }
    delete[]tmp;
    end = clock();
    return (double)(end - begin);
    //cout << "mergeSort: " << (double)(end - begin) << "ms" << endl;
}

void recursionMergeSort(int a[], int* tmp, int left, int right)
{
    if (left == right)//一个元素不用排序
        return; 
    //else if (left + 1 == right)//两个元素不用排序
    //{
    //    if (a[left] > a[right])
    //    {
    //        int save = a[left];
    //        a[left] = a[right];
    //        a[right] = save;
    //    }
    //    return;
    //}
    int mid = (left + right) / 2;
    recursionMergeSort(a, tmp, left, mid);
    recursionMergeSort(a, tmp, mid + 1, right);
    merge(a, tmp, left, mid, right);
    
    for (int j = left; j <= right; j++)//更改回原数组
        a[j] = tmp[j];
    //Print(a, 7);
}



//4.快速排序
void quickSort(int a[], int left, int right)
{
    int i = left, j = right;
    int pivotkey = a[left];

    while (right > left)
    {
        while (right > left && a[right] >= pivotkey)
            right--;
        if (a[right] < pivotkey)
        {
            a[left] = a[right];
            left++;
        }

        while (right > left && a[left] <= pivotkey)
            left++;
        if (a[left] > pivotkey)
        {
            a[right] = a[left];
            right--;
        }
    }  
    a[left] = pivotkey;
    if (i < left - 1) { quickSort(a, i, left - 1); }
    if (j > right + 1) { quickSort(a, right + 1, j); }
}

//5.插入排序
double insertSort(int a[], int num)
{
    clock_t begin, end;
    int i, j, key;
    begin = clock();
    for (i = 1; i < num; i++)//从下标为1的元素开始插入排序
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    end = clock();
    return (double)(end - begin) / CLOCKS_PER_SEC;
    //cout << "insertSort: " << (double)(end - begin) << "ms" << endl;
}



void adjustHeap(vector<int>& vec, int root, int len)
{
    int left = 2 * root + 1;//左结点
    int right = left + 1;//右结点
    int minindex = root;//记录最大的结点下标

    if (left<len && vec[left]<vec[minindex])//将当前最小结点和左结点做比较
        minindex = left;

    if (right<len && vec[right]<vec[minindex])//将当前最小结点和右结点做比较
        minindex = right;
    
    if (minindex != root)//最大结点不是根结点，即要交换
    {
        int tmp = vec[minindex];
        vec[minindex] = vec[root];
        vec[root] = tmp;
        adjustHeap(vec, minindex, len);//对交换后的结点继续调整
    }
    return;
}
void heapSort(vector<int>& vec, int len)
{
    int tmp;
    for (int i = 10 / 2 - 1; i >= 0; i--)//用前十个元素初始化堆
    {
        adjustHeap(vec, i, len);
    }
    for (int i = 10; i < len; i++)//堆排序
    {
        if (vec[i] > vec[0])//大于堆中最小值
        {
            tmp = vec[i];
            vec[i] = vec[0];
            vec[0] = tmp;
            adjustHeap(vec, 0, 10);//交换后调整堆顶
        }
    }

    return;

}


