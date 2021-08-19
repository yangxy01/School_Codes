//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
////输出
//void output(multimap<int, string, greater<int>> mapv)
//{
//    cout << endl
//        << "output map:" << endl;
//    /*for(auto x:mapv)
//        cout<<x.first<<" "<<x.second<<endl;*/
//
//        //支持迭代器++,--
//    for (auto it = mapv.begin(); it != mapv.end(); it++)
//        cout << it->first << " " << it->second << endl;
//
//    cout << "end output map" << "\n\n";
//}
//
////删除
//void dele(multimap<int, string, greater<int>>& mapv, int no)
//{
//    if (mapv.erase(no) > 0) //删除成功
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
//    if (reit.first == reit.second) //未找到
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
//    else  //找到 [reit.first, reit.second)
//    {
//        for (auto it = reit.first; it != reit.second; it++)
//            cout << it->first << " " << it->second << endl;
//    }
//}
//
//int main()
//{
//    //定义map对象，键值降序
//    multimap<int, string, greater<int>> mapStud;
//
//    int m, n, no;
//    string name, op;
//
//    cin >> n;
//    for (auto i = 0; i < n; i++)
//    {
//        cin >> no >> name;
//        mapStud.insert(pair<int, string>(no, name)); //插入(no,name)
//    }
//
//    output(mapStud); //输出
//
//    //根据key,访问value
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
//        if (op == "insert") //插入
//        {
//            cin >> no >> name;
//            mapStud.insert(pair<int, string>(no, name));  //键值重复，一定能插入
//            output(mapStud);
//        }
//        else if (op == "delete") //删除
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
