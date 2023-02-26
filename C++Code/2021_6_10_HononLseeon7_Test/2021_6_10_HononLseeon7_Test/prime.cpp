//用筛选法求1到30000之间的所有素数。
//#include <bitset>
//#include <iostream>
//using namespace std;
//
//#define N 30001
//
//int main()
//{
//    bitset<N>  prime;//初始默认全为0
//    int i, j;
//
//    prime.set();
//
//    prime.flip(1);
//    prime.flip(0);
//    for (i = 2; i <= N / 2; i++)
//    {
//        if (prime[i])       //若i为素数
//        {
//            for (j = i + 1; j <= N - 1; j++)    //将所有整除i的数字去掉
//                if (!(j % i))
//                    prime.set(j, 0);
//        }
//    }
//
//    for (i = 2; i <= N - 1; i++)    //值为1的为素数
//        if (prime.test(i))
//            cout << i << " ";
//    cout << endl;
//
//    system("pause");
//    return 0;
//}
