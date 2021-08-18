//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//#include <list>
//#include <stack>    //使用系统提供的stack适配器
//using namespace std;
//
//template <class T>
//class cstack       //以vector为基础容器，适配栈
//{
//	vector<T> c;
//public:
//	bool empty()
//	{
//		return c.empty();
//	}
//	void push(const T &e)
//	{
//		c.push_back(e);
//	}
//	T &top()
//	{
//		return c.back();
//	}
//	void pop()
//	{
//		c.pop_back();
//	}
//
//	int size() const { return c.size(); }
//};
//
//template <class T>
//bool operator==(const cstack<T> &x, const cstack<T> &y)
//{
//	return x.c == y.c;
//}
//
//template <class T>
//bool operator<(const cstack<T> &x, const cstack<T> &y)
//{
//	return x.c<y.c;
//}
//
//int main()
//{
//	/*cstack<int> s;
//	s.push(10);         //入栈
//	s.push(20);
//	s.push(30);
//
//	while(!s.empty())    //出栈
//	{
//	cout << s.top() << " ";
//	s.pop();
//	}
//	cout << endl;
//	*/
//
//	stack<int, list<int>> s;    //以list为基础容器
//	s.push(10);
//	s.push(20);
//	s.push(30);
//
//	while (!s.empty())
//	{
//		cout << s.top() << " ";
//		s.pop();
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//
//}
//
