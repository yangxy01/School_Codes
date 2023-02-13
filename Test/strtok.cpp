#include<iostream>
#include<string>
#include <string.h>  
using namespace std;

int main()
{
	string str ="aaa,,,bbb,ccc,,ddd";//题目给定string 
	char s[str.length()+1]={'\0'};//转化为char 
	for(int i=0;i<str.length();i++)
		s[i]=str[i];
	char* ret= NULL;
	//第一次调用要传入s 
	ret=strtok(s ,",");
	cout<<ret<<endl;
	//后续调用传入NULL，则函数默认使用切割剩下的串地址 
	while(ret=strtok(NULL ,","))
	{
		cout<<ret<<endl;
	}
	return 0;
 } 
