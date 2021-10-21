//#include<iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	char* type = new char[n];
//	int* time = new int[n];
//	for (int i = 0; i < n; i++)
//		cin >> type[i];
//	for (int i = 0; i < n; i++)
//		cin >> time[i];
//	int sumA = 0, sumB = 0, sumC = 0;
//	queue<int> queA, queB, queC;
//	for (int i = 0; i < n; i++)
//	{
//		if (type[i] == 'A')
//			queA.push(time[i]);
//		else if(type[i] == 'B')
//			queB.push(time[i]);
//		else if (type[i] == 'C')
//			queC.push(time[i]);
//	}
//	int sizeA = 0, sizeB = 0, sizeC = 0;
//	sizeA = queA.size();
//	sizeB = queB.size();
//	sizeC = queC.size();
//	while (queA.size() > 0)
//	{
//		sumA += queA.front();
//		queA.pop();
//	}
//	while (queB.size() > 0)
//	{
//		sumB += queB.front();
//		queB.pop();
//	}
//	while (queC.size() > 0)
//	{
//		sumC += queC.front();
//		queC.pop();
//	}
//	cout << sumA / sizeA << endl;
//	cout << sumB / sizeB << endl;
//	cout << sumC / sizeC << endl;
//	return 0;
//}