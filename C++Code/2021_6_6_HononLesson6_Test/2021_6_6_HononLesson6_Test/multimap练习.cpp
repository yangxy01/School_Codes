//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
////���
//void output(multimap<int, string, greater<int>> mapv)
//{
//    cout << endl
//        << "output map:" << endl;
//    /*for(auto x:mapv)
//        cout<<x.first<<" "<<x.second<<endl;*/
//
//        //֧�ֵ�����++,--
//    for (auto it = mapv.begin(); it != mapv.end(); it++)
//        cout << it->first << " " << it->second << endl;
//
//    cout << "end output map" << "\n\n";
//}
//
////ɾ��
//void dele(multimap<int, string, greater<int>>& mapv, int no)
//{
//    if (mapv.erase(no) > 0) //ɾ���ɹ�
//    {
//        cout << "deleted success" << endl;
//        output(mapv);
//    }
//    else
//    {
//        cout << "delete error" << endl;
//    }
//}
//
//void find(multimap<int, string, greater<int>> mapv, int no)
//{
//    auto reit = mapv.equal_range(no);
//    if (reit.first == reit.second) //δ�ҵ�
//    {
//        cout << "find range error" << endl;
//        if (reit.first != mapv.end())
//        {
//            cout << reit.first->first << " " << reit.first->second << endl;
//            cout << reit.second->first << " " << reit.second->second << endl;
//        }
//        else
//            cout << "find : end" << endl;
//    }
//    else  //�ҵ� [reit.first, reit.second)
//    {
//        for (auto it = reit.first; it != reit.second; it++)
//            cout << it->first << " " << it->second << endl;
//    }
//}
//
//int main()
//{
//    //����map���󣬼�ֵ����
//    multimap<int, string, greater<int>> mapStud;
//
//    int m, n, no;
//    string name, op;
//
//    cin >> n;
//    for (auto i = 0; i < n; i++)
//    {
//        cin >> no >> name;
//        mapStud.insert(pair<int, string>(no, name)); //����(no,name)
//    }
//
//    output(mapStud); //���
//
//    //����key,����value
//    cout << endl
//        << "find by key :" << endl;
//    cin >> no;
//    auto it = mapStud.find(no);
//    if (it != mapStud.end())
//        cout << it->second << endl;
//
//    //lower_bound,upper_bound;
//    cout << endl << "lower_bound, upper_bound : " << endl;
//    it = mapStud.lower_bound(no);
//    if (it != mapStud.end())
//        cout << it->first << " " << it->second << endl;
//    else
//        cout << "lower_bound : end" << endl;
//    it = mapStud.upper_bound(no);
//    if (it != mapStud.end())
//        cout << it->first << " " << it->second << endl;
//    else
//        cout << "upper_bound : end" << endl;
//    cout << "end lower_bound, upper_bound" << endl;
//
//    cin >> m;
//    for (int i = 0; i < m; i++)
//    {
//        cin >> op;
//        if (op == "insert") //����
//        {
//            cin >> no >> name;
//            mapStud.insert(pair<int, string>(no, name));  //��ֵ�ظ���һ���ܲ���
//            output(mapStud);
//        }
//        else if (op == "delete") //ɾ��
//        {
//            cin >> no;
//            dele(mapStud, no);
//        }
//        else if (op == "find")
//        {
//            cin >> no;
//            find(mapStud, no);
//        }
//    }
//
//    system("pause");
//    return 0;
//}
//
///*
//3
//3 liming
//3 wangwu
//2 zhaoliu
//2
//5
//insert 2 qianliu
//insert 1 lisi
//delete 1
//find 2
//*/
