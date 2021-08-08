#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

int main()
{
	int n,m;
	cin >> n;
    bitset<101> mysetA[101];
    bitset<101> mysetB[101];
    bitset<101> result;
    mysetA->reset();
    mysetB->reset();
	for(int i=0;i<n;i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> num;
            mysetA[i][num] = 1;
		}
	}
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        mysetB[i][num] = 1;
        cin >> num;
        mysetB[i][num] = 1;
    }
    
    for (int i = 0; i < t; i++)//t×éÂÖÑ¯Êý¾Ý
    {
        int numof = 0;
        vector<int> vec;
        for (int j = 0; j < n; j++)
        {
            result = mysetB[i] & mysetA[j];
            int count = result.count();
            if (count == 2)
            {
                numof++;
                vec.push_back(j);
            }
        }
        if (numof == 0)
            cout << "no" << endl;
        else
        {
            int k;
            for (k = 0; k < numof - 1; k++)
            {
                cout << vec[k]+1 << " ";
            }
            cout << vec[k]+1 <<endl;
        }
    }

	return 0;
}

