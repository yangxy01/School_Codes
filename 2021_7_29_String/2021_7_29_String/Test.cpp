#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
	bool IsEqual(char ch1, char ch2)
	{
		if (ch1 >= 'a'&&ch1 <= 'z')
			ch1 = 'A' - 'a' + ch1;
		if (ch2 >= 'a'&&ch2 <= 'z')
			ch2 = 'A' - 'a' + ch2;
		if (ch1 == ch2)
			return true;
		return false;
	}

	bool isPalindrome(string s)
	{
		int begin = 0;
		int end = s.size() - 1;
		while (begin<end)
		{
			while (begin<end)
			{
				if ((s[begin] >= 'a'&&s[begin] <= 'z') || (s[begin] >= '0'&&s[begin] <= '9') ||
					(s[begin] >= 'A'&&s[begin] <= 'Z'))
					break;
				begin++;
			}
			while (begin<end)
			{
				if ((s[end] >= 'a'&&s[end] <= 'z') || (s[end] >= '0'&&s[end] <= '9') ||
					(s[end] >= 'A'&&s[end] <= 'Z'))
					break;
				end--;
			}
			if (IsEqual(s[begin], s[end]))
			{
				begin++;
				end--;
				continue;
			}
			else
			{
				cout << "false" << endl;
				return false;
			}
		}
		return true;
	}
};

int main()
{
	string s;
	getline(cin,s);
	Solution sol;
	if (sol.isPalindrome(s))
		cout << 1 << endl;
	else
		cout << 2 << endl;
	return 0;
}