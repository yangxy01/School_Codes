///*
//ÿ�����磬�ȶ����յ��������ʵ���Ҳ����һ��Ҳû�յ�����ÿһ��
//����һ���������磬�����Ŀǰ��û��֧�����ʵ���ѡ��������
//����С�����ţ��������Ǹ��塣��û��֧�����ʵ��ᱻ��������һ�졣
//���ڱȶ��Ѿ�֪����ÿ���յ��ʵ����������������������֧����˳��
//�ȶ���֤���һ��ȫ�����塣
//*/
//#include <set>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    multiset<int> billset;
//    int t, n, e;
//
//    cin >> t;    //t��
//
//    while (t--)
//    {
//        cin >> n;     //ÿ���˵���
//
//        while (n--)
//        {
//            cin >> e;
//            billset.insert(e);     //��������˵�
//        }
//        if (t > 0)
//        {
//            cout << *billset.begin() << " " << *(--billset.end()) << endl;   //��С�������
//            billset.erase(billset.begin());
//            billset.erase(--billset.end());
//        }
//        else
//        {
//            for (auto x : billset)       //���һ�죬�����˵�
//                cout << x << " ";
//            cout << endl;
//
//        }
//    }
//    system("pause");
//    return 0;
//}
///*
//4
//3 3 6 5
//2 4 2
//3 7 1 7
//1 10
//*/
//
