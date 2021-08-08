////#include<iostream>
////#include<string>
////#include<set>
////using namespace std;
////
////struct cmp
////{
////	bool operator()(const string& s1, const string& s2)const
////	{
////		return s1 < s2;
////	}
////};
////
////int main()
////{
////	string str,str1,str2;
////	set<string, cmp>word;
////	while (cin >> str)
////	{
////		string str1;
////		for (auto x : str)
////			str1 += tolower(x);
////		str = str1;
////		if (str.find('.') != string::npos)
////		{
////			str = str.substr(0,str.find('.'));
////			word.insert(str);
////		}
////		else if (str.find(':') != string::npos)
////		{
////			str1 = str.substr(0, str.find(':'));
////			int pos = str.find('"');
////			str2 = str.substr(pos+1);
////			word.insert(str1);
////			word.insert(str2);
////		}
////		else
////			word.insert(str);
////	}
////	for (auto x : word)
////	{
////		cout << x << endl;
////	}
////	return 0;
////}
//
//
//
//#include <iostream>
//#include <string>
//#include <regex>
//#include <set>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    string str;
//    set<string> myset;
//    while (getline(cin, str)) 
//    {
//        regex r("[a-zA-Z]+");
//        smatch m;
//        while (regex_search(str, m, r)) 
//        {
//            for (auto x : m) 
//            {
//                string str2 = x;
//                for (auto& y : str2)
//                    if ('A' <= y && y <= 'Z')
//                    {
//                        y = y +'a' - 'A';
//                    }
//                myset.insert(str2);
//            }
//            str = m.suffix().str();
//        }
//    }
//    for (auto word : myset)
//        cout << word << endl;
//    return 0;
//}