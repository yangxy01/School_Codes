///*OJ1180����������ͨѶ¼
//����ʹ����������ʵ��ͨѶ¼��ͨѶ¼�Ƕ����ϵ�˵���Ϣ���ϣ�ÿ����ϵ�˶����������͵绰���ԡ�
//ÿ����ϵ�˶�Ӧһ�������㣬��������ĸ��ͬ����ϵ�˷���ͬһ�������С���ϵ�˵��ඨ�����д�ã�
//���²ο�����
//ͨѶ¼����������´��룬����������
//1������û�й��캯����ʹ�����뺯��Inputʵ�����ݵ������ͨѶ¼�ĳ�ʼ��
//2����ӡ����Print���������ͨѶ¼�������ʽ�ο�����
//3�������µ���ϵ�ˣ����������+=��ʵ�֣������ϵ�������Ѿ����ڣ������µĵ绰���Ǿɵ绰
//ע�⣺�������ͷ�巨�����½��ֱ�Ӳ���ͷ���֮��
//4��������ϵ�����������������()��ʵ�֣����ҳɹ�����������ָ�룬ʧ�ܷ���NULL
//5���ϲ�����ͨѶ¼�����������+��ʵ�֣��ϲ�������ڵ�һ��ͨѶ¼�У������������
//ͨѶ¼�ĺϲ�ʵ������������ͬ����ĸ������ϲ���������ͬ����ĸ����������i��j�ϲ��������£�
//1���ڶ�������j��ͷ��ʼ��ȡ����ϵ����Ϣ���ڵ�һ������i�в��ҡ�
//2�������ϵ���Ѵ��ڣ����õڶ���ͨѶ¼�ĵ绰���ǵ�һ��ͨѶ¼�ĵ绰
//3�������ϵ�˲����ڣ������ϵ�˲��뵽��һ������i��
//*/
//
///*
//0(A),1(B),2(C),3(D),4(E),5(F),6(G)
//7(H),8(I),9(J),10(K),11(L),12(M),13(N),
//14(O),15(P),16(Q),17(R),18(S),19(T),
//20(U),21(V),22(W),23(X),24(Y),25(Z)
//*/
///*  cb����Ͱ����7��vscode����Ͱ����7������ͷ���롣ע������pBook.reserve(26);
//4
//Tom 8111
//Any 1222
//Ken 2333
//Kim 2444
//*/
///*  cb����Ͱ����11��vscode����Ͱ����7��
//6
//Tom 8111
//Any 1222
//Ken 2333
//Kim 2444
//Bob 2223
//Peter 7899
//*/
///*cb����Ͱ����23��vscode����Ͱ����17��
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
///*��������
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
//�������
//Any--1222
//����ʧ��
//A--Ann.1333--Any.1222--
//K--Kim.2444--Ken.2333--
//T--Tim.8222--Tom.8444--
//*/
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
////��ϣ����
//struct hashfun
//{
//    int operator()(const string& name) const
//    {
//        return name[0] - 'A';
//    }
//};
//
////ͨѶ¼��
//class PhoneBook
//{
//    unordered_map<string, int, hashfun> pBook;   //�洢
//public:
//    PhoneBook();
//    using PhoneBookit = unordered_map<string, int, hashfun>::iterator;
//    void Input();   //��ʼ��Ϣ���벢����ͨѶ¼
//    void Print();   //���
//    int operator()(string name);   //����������
//    PhoneBook operator+(const PhoneBook& rhs);   //�ϲ�ͨѶ¼ 
//    PhoneBook& operator+=(const pair<string, int>& rhs);   //�����½��
//};
//
////����Ͱ����
//PhoneBook::PhoneBook()
//{
//    pBook.reserve(26);
//}
//
////��ʼ��������
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
////���
//void PhoneBook::Print()
//{
//    cout << "----------------" << endl;
//    cout << "bucket_count: " << pBook.bucket_count() << endl;
//    cout << "load_factor: " << pBook.load_factor() << endl;
//    cout << "max_load_factor: " << pBook.max_load_factor() << endl;
//    for (auto i = 0; i < (int)pBook.bucket_count(); i++)
//    {
//
//        //��i��Ͱ��Ԫ������Ԫ��
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
////*this,rhsBook����ͨѶ¼�ϲ�
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
////rhs����*thisͨѶ¼
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
//    pb.Input(); //�����������ݣ���ʼ����һ��ͨѶ¼
//    pb.Print();
//    //������������
//    for (i = 0; i < 2; i++)
//    {
//        cin >> tname;
//        tno = pb(tname); //����()�������ʵ�ֲ���
//        if (tno != -1)
//            cout << tname << "--" << tno << endl;
//        else
//            cout << "find error����ʧ��" << endl; //����ʧ�ܣ������ʾ��Ϣ
//    }
//    //һ�β���
//    cin >> tname >> tno;
//    pair<string, int> p(tname, tno);
//    pb += p; //����+=�������ʵ�ֲ�������ϵ��
//    pb.Print();
//
//    //ͨѶ¼�ϲ�
//    PhoneBook pc;
//    pc.Input(); //��ʼ���ڶ���ͨѶ¼
//    pc.Print();
//    pb = pb + pc; //����+�������ʵ�ֺϲ�
//
//    pb.Print(); //������в������ͨѶ¼
//
//    system("pause");
//    return 0;
//}
