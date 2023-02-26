#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct Node
{
	char ch;
	Node* arr[26];
};

class Trie
{
	Node* root;
	int count;
public:
	Trie()
	{
		count = 0;
		root = new Node;
		root->ch = ' ';
		for (int i = 0; i < 26; i++)
			root->arr[i] = NULL;
	}
	void Create(string word)
	{
		Node* p = root;
		for (int k = 0; k < word.length(); k++)
		{
			if (p->arr[word[k] - 'a'] == NULL)
			{
				Node* q = new Node;
				q->ch = word[k];
				for (int i = 0; i < 26; i++)
					q->arr[i] = NULL;
				p->arr[word[k] - 'a'] = q;
				p = q;
			}
			else
			{
				p = p->arr[word[k] - 'a'];
			}
		}
	}
	void Traverse()
	{
		queue<Node*>open;
		for (int i = 0; i < 26; i++)
		{
			open.push(root->arr[i]);
		}
		while (open.size() > 0)
		{
			Node* cur = open.front();
			open.pop();
			if (cur != NULL)
			{
				cout << cur->ch;
				for (int i = 0; i < 26; i++)
					open.push(cur->arr[i]);
			}
		}
		cout << endl;
	}
	void DFS(Node* p)
	{
		int flag = 1;
		for (int i = 0; i < 26; i++)
		{
			if (p->arr[i])
			{
				flag = 0;
				DFS(p->arr[i]);
			}
		}
		if(flag)
			count++;
		return;
	}
	int GetNum(string word)
	{
		count = 0;
		Node* p = root;
		for (int k = 0; k < word.length() && p; k++)
			p = p->arr[word[k] - 'a'];
		if (p == NULL)
			return 0;
		for (int i = 0; i < 26; i++)
			if (p->arr[i])
				DFS(p->arr[i]);
		return count;
	}
};

int main()
{
	string sentence,word;
	getline(cin, sentence);
	int start = 0;
	Trie T;
	while (sentence.find(" ", start) != string::npos)
	{
		word = sentence.substr(start, sentence.find( " ", start) - start);
		start = sentence.find(" ", start) + 1;
		T.Create(word);
	}
	word = sentence.substr(start, sentence.find(" ", start) - start);
	T.Create(word);
	T.Traverse();
	int t;
	string prefix;
	cin >> t;
	while (t--)
	{
		cin >> prefix;
		cout << T.GetNum(prefix) << endl;
	}
	return 0;
}