//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	string str,str1;
//	int t,pos;
//	cin >> t;
//	vector<string> vec;
//	cin.ignore(100, '\n');
//	while (t--)
//	{
//		getline(cin, str);
//		while (1)
//		{
//			pos = str.find_first_of(" ");
//			if (pos == string::npos)
//				break;
//			str1 = str.substr(0, pos-0);
//			vec.push_back(str1);
//			str = str.substr(pos + 1);
//		}
//		vec.push_back(str);
//		for (auto x = vec.rbegin(); x < vec.rend()-1; x++)
//			cout << *x << " ";
//		cout << vec.front() << endl;
//		vec.clear();
//	}
//	
//
//	return 0;
//}