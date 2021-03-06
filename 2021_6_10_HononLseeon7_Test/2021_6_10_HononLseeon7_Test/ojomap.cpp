///*OJ1180，组链表与通讯录
//现在使用组链表来实现通讯录，通讯录是多个联系人的信息集合，每个联系人都包含姓名和电话属性。
//每个联系人对应一个链表结点，姓名首字母相同的联系人放在同一个链表中。联系人的类定义基本写好，
//如下参考代码
//通讯录的类界面如下代码，操作包括：
//1、该类没有构造函数，使用输入函数Input实现数据的输入和通讯录的初始化
//2、打印函数Print，输出整个通讯录，输出格式参考样本
//3、插入新的联系人，重载运算符+=来实现，如果联系人姓名已经存在，则用新的电话覆盖旧电话
//注意：插入采用头插法，即新结点直接插入头结点之后
//4、查找联系人姓名，重载运算符()来实现，查找成功返回链表结点指针，失败返回NULL
//5、合并两个通讯录，重载运算符+来实现，合并结果放在第一个通讯录中，即左操作数。
//通讯录的合并实际上是两个相同首字母的链表合并。对于相同首字母的两个链表i和j合并过程如下：
//1）第二个链表j从头开始，取出联系人信息，在第一个链表i中查找。
//2）如果联系人已存在，则用第二个通讯录的电话覆盖第一个通讯录的电话
//3）如果联系人不存在，则把联系人插入到第一个链表i中
//*/
//
///*
//0(A),1(B),2(C),3(D),4(E),5(F),6(G)
//7(H),8(I),9(J),10(K),11(L),12(M),13(N),
//14(O),15(P),16(Q),17(R),18(S),19(T),
//20(U),21(V),22(W),23(X),24(Y),25(Z)
//*/
///*  cb测试桶子数7。vscode测试桶子数7。均表头插入。注意屏蔽pBook.reserve(26);
//4
//Tom 8111
//Any 1222
//Ken 2333
//Kim 2444
//*/
///*  cb测试桶子数11。vscode测试桶子数7。
//6
//Tom 8111
//Any 1222
//Ken 2333
//Kim 2444
//Bob 2223
//Peter 7899
//*/
///*cb测试桶子数23。vscode测试桶子数17。
//12
//Tom 8111
//Any 1222
//Ken 2333
//Kim 2444
//Bob 2223
//Peter 7899
//Zone 3456
//Lee 7890
//Clion 1234
//David 2345
//Xin 1230
//Hai 7312
//*/
//
///*样例输入
//4
//Tom 8111
//Any 1222
//Ken 2333
//Kim 2444
//Any
//Ben
//Tim 8222
//2
//Tom 8444
//Ann 1333
//样例输出
//Any--1222
//查找失败
//A--Ann.1333--Any.1222--
//K--Kim.2444--Ken.2333--
//T--Tim.8222--Tom.8444--
//*/
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
////哈希函数
//struct hashfun
//{
//    int operator()(const string& name) const
//    {
//        return name[0] - 'A';
//    }
//};
//
////通讯录类
//class PhoneBook
//{
//    unordered_map<string, int, hashfun> pBook;   //存储
//public:
//    PhoneBook();
//    using PhoneBookit = unordered_map<string, int, hashfun>::iterator;
//    void Input();   //初始信息输入并插入通讯录
//    void Print();   //输出
//    int operator()(string name);   //按姓名查找
//    PhoneBook operator+(const PhoneBook& rhs);   //合并通讯录 
//    PhoneBook& operator+=(const pair<string, int>& rhs);   //插入新结点
//};
//
////重置桶子数
//PhoneBook::PhoneBook()
//{
//    pBook.reserve(26);
//}
//
////初始数据输入
//void PhoneBook::Input()
//{
//    string name;
//    int phone, n;
//
//    cin >> n;
//    while (n--)
//    {
//        cin >> name >> phone;
//        pBook.insert(make_pair(name, phone));
//    }
//}
//
////输出
//void PhoneBook::Print()
//{
//    cout << "----------------" << endl;
//    cout << "bucket_count: " << pBook.bucket_count() << endl;
//    cout << "load_factor: " << pBook.load_factor() << endl;
//    cout << "max_load_factor: " << pBook.max_load_factor() << endl;
//    for (auto i = 0; i < (int)pBook.bucket_count(); i++)
//    {
//
//        //第i个桶子元素数及元素
//        if (!pBook.bucket_size(i))
//            continue;
//        cout << char('A' + i) << "--";
//        for (auto it = pBook.begin(i); it != pBook.end(i); it++)
//            cout << it->first << "." << it->second << "--";
//        cout << endl;
//    }
//}
//
////finded, return phone; else ,return -1
//int PhoneBook::operator()(string name)
//{
//    PhoneBookit it = pBook.find(name);
//    if (it != pBook.end())
//        return it->second;
//    else
//        return -1;
//}
//
////*this,rhsBook两个通讯录合并
//PhoneBook PhoneBook::operator+(const PhoneBook& rhsBook)
//{
//    PhoneBook result(*this);
//    for (auto it = rhsBook.pBook.begin(); it != rhsBook.pBook.end(); it++)
//    {
//
//        auto reit = result.pBook.find(it->first);
//        if (reit != result.pBook.end())
//        {
//            reit->second = it->second;
//        }
//        else
//            result.pBook.insert(*it);
//    }
//    return result;
//
//}
//
////rhs插入*this通讯录
//PhoneBook& PhoneBook::operator+=(const pair<string, int>& rhs)
//{
//    PhoneBookit it;
//
//    it = pBook.find(rhs.first);
//
//    if (it != pBook.end())
//        it->second = rhs.second;
//    else
//        pBook.insert(rhs);
//
//    return *this;
//}
//
//int main()
//{
//    string tname;
//    int i, tno;
//
//    PhoneBook pb;
//    pb.Input(); //接收输入数据，初始化第一个通讯录
//    pb.Print();
//    //两次姓名查找
//    for (i = 0; i < 2; i++)
//    {
//        cin >> tname;
//        tno = pb(tname); //调用()运算符，实现查找
//        if (tno != -1)
//            cout << tname << "--" << tno << endl;
//        else
//            cout << "find error查找失败" << endl; //查找失败，输出提示信息
//    }
//    //一次插入
//    cin >> tname >> tno;
//    pair<string, int> p(tname, tno);
//    pb += p; //调用+=运算符，实现插入新联系人
//    pb.Print();
//
//    //通讯录合并
//    PhoneBook pc;
//    pc.Input(); //初始化第二个通讯录
//    pc.Print();
//    pb = pb + pc; //调用+运算符，实现合并
//
//    pb.Print(); //输出所有操作后的通讯录
//
//    system("pause");
//    return 0;
//}
