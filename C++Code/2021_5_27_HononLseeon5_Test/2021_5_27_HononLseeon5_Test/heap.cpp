//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	//int score[] = {99,100,78,80,85,60,50};
//	int score[] = { 62, 41, 30, 28, 16, 22, 13, 19, 17, 15 };     //�μ�22ҳ����
//	vector<int> v(score, score + 10);
//
//	make_heap(v.begin(), v.end());        //����v,ʹ�乹�ɴ󶥶ѡ������Ƕѣ����ԭ����
//	for_each(begin(v), end(v), [](int x){cout << x << " "; });
//	cout << endl;
//
//	vector<int> vbak(v);
//
//
//	//ѭ������
//	cout << "---------heap sort---------" << endl;
//	int count = 0;     //��¼�������
//	for (auto it = begin(v), itend = end(v); itend != it; itend--)
//	{
//		cout << ++count << ":";
//		pop_heap(it, itend);   //���µ����㷨
//		for_each(begin(v), end(v), [](int x){cout << x << " "; });
//		cout << endl;
//	}
//
//	cout << "---------heap sort---------" << endl;
//	sort_heap(begin(vbak), end(vbak));     //��������
//	for_each(begin(vbak), end(vbak), [](int x){cout << x << " "; });
//	cout << endl;
//
//	cout << "---------push_heap--------" << endl;
//	v.push_back(1000);   //β�˲���1000
//	push_heap(v.begin(), v.end());  //���ݵ���Ϊ��
//	for (auto x : v)       //���
//		cout << x << " ";
//	cout << endl;
//	
//
//	system("pause");
//	return 0;
//}
//
//
//
//
