//#include <regex>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	cin.ignore(100, '\n');
//	string str;
//	while (t--)
//	{
//		getline(cin, str);
//		//regex r("(\\b\\w+)");
//		regex r("( *(\\w+)[^ ]?)+");
//		smatch m;
//		int count = 0;
//
//		regex_match(str, m, r);
//		cout << m.size() <<" ";
//		for (int i = 1; i < (int)m.size(); i++)
//			cout << m[i] << " ";
//		cout << endl;
//
//
//		//while (regex_search(str, m, r))
//		//{
//		//	/*for (int i=1;i<(int)m.size();i++) 
//		//		cout << m[i] << " ";	*/
//		//	count++;
//		//	str = m.suffix().str();
//
//		//}
//		/*cout << count<<endl;*/
//	}
//
//	return 0;
//}