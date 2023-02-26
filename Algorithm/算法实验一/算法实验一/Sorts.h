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

//1.ѡ������
double selectionSort(int a[], int num)
{
    clock_t begin, end;
    int i, j, k, tmp;
    begin = clock();//��¼��ʼʱ��
    for (i = 0; i < num; i++)
    {
        k = i;//��¼��Сֵ�±�
        for (j = i + 1; j < num; j++)//����Ѱ����Сֵ
        {
            if (a[j] < a[k])//������Сֵ�±�
                k = j;
        }
        //swap(a[i], a[k]);
        tmp = a[i];
        a[i] = a[k];
        a[k] = tmp;
    }
    end = clock();//��¼����ʱ��
    return (double)(end - begin) / CLOCKS_PER_SEC;
    //cout <<"selectionSort: " << (double)(end - begin) << "ms" << endl;
}

//2.ð������
double bubbleSort(int a[], int num)
{
    clock_t begin, end;
    int i, j, tmp;
    begin = clock();
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num - i - 1; j++)//�ҳ���ǰ�����ֵ����
        {
            if (a[j] > a[j + 1])//�Ѵ��ֻ�ŵ�����
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

//3.�ϲ�����
void merge(int a[], int* tmp, int left, int mid, int right)
{
    int i = left, j = mid + 1;
    int k = i;
    while (i <= mid && j <= right)//û������ĩβ�����
    {
        //��������������С�ķ���tmp����洢
        if (a[i] <= a[j])
        {
            tmp[k] = a[i]; i++; k++;
        }
        else
        {
            tmp[k] = a[j]; j++; k++;
        }
    }
    while (i <= mid) //�������ʣ�ಢ��
    { 
        tmp[k] = a[i]; i++; k++;
    }
    while (j <= right) //�ұ�����ʣ�ಢ��
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
        for (int j = 0; j < num; j++)//���Ļ�ԭ����
            a[j] = tmp[j];
    }
    delete[]tmp;
    end = clock();
    return (double)(end - begin);
    //cout << "mergeSort: " << (double)(end - begin) << "ms" << endl;
}

void recursionMergeSort(int a[], int* tmp, int left, int right)
{
    if (left == right)//һ��Ԫ�ز�������
        return; 
    //else if (left + 1 == right)//����Ԫ�ز�������
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
    
    for (int j = left; j <= right; j++)//���Ļ�ԭ����
        a[j] = tmp[j];
    //Print(a, 7);
}



//4.��������
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

//5.��������
double insertSort(int a[], int num)
{
    clock_t begin, end;
    int i, j, key;
    begin = clock();
    for (i = 1; i < num; i++)//���±�Ϊ1��Ԫ�ؿ�ʼ��������
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
    int left = 2 * root + 1;//����
    int right = left + 1;//�ҽ��
    int minindex = root;//��¼���Ľ���±�

    if (left<len && vec[left]<vec[minindex])//����ǰ��С�����������Ƚ�
        minindex = left;

    if (right<len && vec[right]<vec[minindex])//����ǰ��С�����ҽ�����Ƚ�
        minindex = right;
    
    if (minindex != root)//����㲻�Ǹ���㣬��Ҫ����
    {
        int tmp = vec[minindex];
        vec[minindex] = vec[root];
        vec[root] = tmp;
        adjustHeap(vec, minindex, len);//�Խ�����Ľ���������
    }
    return;
}
void heapSort(vector<int>& vec, int len)
{
    int tmp;
    for (int i = 10 / 2 - 1; i >= 0; i--)//��ǰʮ��Ԫ�س�ʼ����
    {
        adjustHeap(vec, i, len);
    }
    for (int i = 10; i < len; i++)//������
    {
        if (vec[i] > vec[0])//���ڶ�����Сֵ
        {
            tmp = vec[i];
            vec[i] = vec[0];
            vec[0] = tmp;
            adjustHeap(vec, 0, 10);//����������Ѷ�
        }
    }

    return;

}


