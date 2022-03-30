#include<iostream>
using namespace std;
struct Block
{
	int max;
	int index;
};

class SeqList
{
	int len;
	int* arr;
	int Blocknum;
	Block* Blockarr;
public:
	SeqList(int n = 0)
	{
		Blockarr = nullptr;
		Blocknum = 0;
		arr = new int[n];
		len = n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
	}
	void SetBlock(int m)
	{
		Blockarr = new Block[m];
		Blocknum = m;
		for (int i = 0; i < Blocknum; i++)
			cin >> Blockarr[i].max;
		Blockarr[0].index = 0;
		for (int i = 1,j=0; i < len; i++)
			if (arr[i] > Blockarr[j].max)
			{
				Blockarr[j+1].index = i;
				j++;
			}
	}
	int Search(int num)
	{
		int count = 0;
		int start = 0;
		int end = len;
		for (int i = 0; i < Blocknum; i++)
		{
			count++;
			if (num <= Blockarr[i].max)
			{
				start = Blockarr[i].index;
				if (i + 1 < Blocknum)
					end = Blockarr[i + 1].index;
				break;
			}
		}
		int i = 0;
		for (i = start; i < end; i++)
		{
			count++;
			if (arr[i] == num)
				break;
		}
		if (i == end)
			cout << "error" << endl;
		else
			cout << i+1<<"-"<<count << endl;
		
		return 0;
	}
	~SeqList()
	{
		delete[]arr,Blockarr;
		arr = nullptr;
		Blockarr = nullptr;
		len = 0;
	}
};

int main()
{
	int n;
	cin >> n;
	SeqList seq(n);
	int k,m;
	cin >> k;
	seq.SetBlock(k);
	cin >> m;
	while (m--)
	{
		int num;
		cin >> num;
		seq.Search(num);

	}
	return 0;
}