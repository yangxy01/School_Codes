//#include <set>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct stringcmp//�ŵĹ�����Ҫ�����Ҫ��
//{
//    //set�������
//    bool operator()(const string& lhs, const string& rhs)
//    {
//        int count1, count2;
//        if (lhs.size() != rhs.size())    //��������
//            return lhs.size() < rhs.size();
//        else     //�������
//        {
//            count1 = count(lhs.begin(), lhs.end(), '1');    //ͳ��1�ĸ���
//            count2 = count(rhs.begin(), rhs.end(), '1');
//            if (count1 != count2)
//                return count1 < count2;      //1�ĸ�������
//            else
//                return lhs < rhs;            //1�����ȣ���ֵ����
//        }
//    }
//};
//
//
//int main()
//{
//    set<string, stringcmp>  s;
//    int n;
//    string str;
//
//    cin >> n;
//    while (n--)
//    {
//        cin >> str;
//        s.insert(str);
//    }
//
//    for (auto x : s)
//        cout << x << endl;
//
//    system("pause");
//    return 0;
//}
//
///*
//6
//10011111
//00001101
//1010101
//1
//0
//1100
//*/
//
///*
//0
//1
//1100
//1010101
//00001101
//10011111
//*/
//