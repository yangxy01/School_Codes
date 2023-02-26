#include<iostream>
#include<string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str,sub;
		cin >> str;
		int len = str.length();
		int max = -1;
		int i, j;
		for (i = 0; i < len - 1; i++)
		{
			for (j = 1; j < len -1-i; j++)
			{
				//cout << "i=" << i << " j=" << j << endl;
				sub = str.substr(i, j);
				if (str.find(sub, i + j) != string::npos)
				{
					if (j > max)
						max = j;
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}