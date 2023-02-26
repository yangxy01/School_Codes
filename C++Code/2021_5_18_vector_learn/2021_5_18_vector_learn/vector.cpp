#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

void STLDefine()
{
	struct STU
	{
		int age;
	};

	vector<int> vec;
}
void STLConstructor()
{
	vector<int> vec;
	vector<int> vec1(5);
	vector<int> vec2(5, 34);
	vector<int> vec3(vec1);
	//定义迭代器
	vector<int>::iterator ite = vec2.begin();//现在本质为int*的指针
	vector<int>::iterator ite1 = vec2.end();
	vector<int> vec4(ite, ite1);


	//测试输出
	for (int i = 0; i < 5; i++)
		cout << vec4[i] << " ";
	cout << endl;
	
}

int main()
{
	//STLDefine();
	STLConstructor();
	return 0;
}