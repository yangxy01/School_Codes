//#include <regex>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    regex r("([0-9a-zA-Z]{1,19})@([0-9a-zA-Z]{1,13})(\\.[0-9a-zA-Z]+)*\\.(com|cn|net)");
//    //match: ��ĸ����1~19��@��ĸ����1~13��[.��ĸ1������].(com��cn��net)
//
//    while (true)
//    {
//        cout << "enter email: (q=quit):";
//        string str;
//
//        if (!getline(cin, str) || str == "q")      //input str
//            break;
//
//        smatch m;      //match_results
//        if (regex_match(str, m, r))     //call function, if match, return true
//        {
//            cout << " valid data." << endl;
//            cout << m.size() << endl;    //output match result
//            for (auto i = 0; i < (int)m.size(); i++)
//                cout << m[i] << endl;
//        }
//        else           //else, return false
//            cout << " Invalid data." << endl;
//    }
//    return 0;
//}
