////input one line, find out words
//#include <iostream>
//#include <string>
//using namespace std;
//
//
//int main()
//{
//    string line;
//    string words[100];
//
//    getline(cin, line, '\n');    //input
//
//    int start = 0;
//    int end = 0;
//    while (end != string::npos)
//    {
//        start = line.find_first_not_of(" ", start);   //start of word
//        end = line.find_first_of(" ", start + 1);     //end of word
//        cout << line.substr(start, end - start) << endl;
//        start = end + 1;
//    }
//
//    system("pause");
//    return 0;
//}
//
