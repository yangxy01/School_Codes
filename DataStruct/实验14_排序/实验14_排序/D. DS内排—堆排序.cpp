#include<iostream>
using namespace std;

class HeapSort
{
	int* arr;
	int len;
	int savelen;
public:
	HeapSort(int l) :len(l), savelen(l)
	{
		arr = new int[len];
		for (int i = 0; i < len; i++)
			cin >> arr[i];
	}
	~HeapSort() { delete[]arr; }

	void Swap(int i, int j)
	{
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	void MakeHeap()
	{
		for (int i = len / 2 - 1; i >= 0; i--)
		{
			int min_index;
			min_index = 2 * i + 1;
			if (2 * i + 2 < len - 1 && arr[2 * i + 1] > arr[2 * i + 2])
			{
				min_index = 2 * i + 2;
			}
			if (arr[min_index] < arr[i])
			{
				Swap(i, min_index);
				TopToBottom(min_index);
			}
		}
		Show();
	}

	void heapSort()
	{
		for (int i=len-1;i>=1;i--)
		{
			len--;
			Swap(i, 0);
			TopToBottom(0);
			Show();
		}
	}

	void TopToBottom(int root)
	{
		if (root > len / 2 - 1)
			return;
		int i = root;
		int min_index = 2 * i + 1;
		if (2 * i + 2 < len  && arr[2 * i + 1] > arr[2 * i + 2])
		{
			min_index = 2 * i + 2;
		}
		if (arr[min_index] < arr[i])
		{
			Swap(i, min_index);
			TopToBottom(min_index);
		}
	}

	void Show()
	{
		cout << savelen << " ";
		for (int i = 0; i < savelen - 1; i++)
			cout << arr[i] << " ";
		cout << arr[savelen - 1] << endl;
	}
};

int main()
{
	int n;
	cin >> n;
	HeapSort HS(n);
	HS.MakeHeap();
	HS.heapSort();
	return 0;
}