#include<iostream>
#include<string>
#include <string.h>  
using namespace std;

int main()
{
	string str ="aaa,,,bbb,ccc,,ddd";//��Ŀ����string 
	char s[str.length()+1]={'\0'};//ת��Ϊchar 
	for(int i=0;i<str.length();i++)
		s[i]=str[i];
	char* ret= NULL;
	//��һ�ε���Ҫ����s 
	ret=strtok(s ,",");
	cout<<ret<<endl;
	//�������ô���NULL������Ĭ��ʹ���и�ʣ�µĴ���ַ 
	while(ret=strtok(NULL ,","))
	{
		cout<<ret<<endl;
	}
	return 0;
 } 
