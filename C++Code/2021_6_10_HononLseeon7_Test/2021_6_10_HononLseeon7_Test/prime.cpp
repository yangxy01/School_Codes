//��ɸѡ����1��30000֮�������������
//#include <bitset>
//#include <iostream>
//using namespace std;
//
//#define N 30001
//
//int main()
//{
//    bitset<N>  prime;//��ʼĬ��ȫΪ0
//    int i, j;
//
//    prime.set();
//
//    prime.flip(1);
//    prime.flip(0);
//    for (i = 2; i <= N / 2; i++)
//    {
//        if (prime[i])       //��iΪ����
//        {
//            for (j = i + 1; j <= N - 1; j++)    //����������i������ȥ��
//                if (!(j % i))
//                    prime.set(j, 0);
//        }
//    }
//
//    for (i = 2; i <= N - 1; i++)    //ֵΪ1��Ϊ����
//        if (prime.test(i))
//            cout << i << " ";
//    cout << endl;
//
//    system("pause");
//    return 0;
//}
