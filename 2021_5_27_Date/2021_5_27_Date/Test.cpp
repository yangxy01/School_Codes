#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
void Test1()
{
	Date d1(1999, 1, 1);
	d1.print();
	Date d2(2010, 2, 29);
	d2.print();
	Date d3(2021, 5, 60);
	d3.print();
}
void Test2()
{
	Date d1(2021, 5, 30);
	d1 += 5;
	d1.print();
	(d1 + 5).print();
	d1 += -5;
	d1.print();

	/*d1 -= 5;
	d1.print();
	(d1 - 5).print();

	Date d2(2021, 12, 30);
	d2 += 5;
	d2.print();
	d2 -= 5;
	d2.print();*/
}
void Test3()
{
	Date d1(2021, 5, 30);
	d1++;
	d1.print();
	(++d1).print();
}
void Test4()
{
	Date d1(2021, 5, 30);
	Date d2 = d1++;
	d2++;
	if (d1 < d2)
		cout << "<" << endl;
	else if (d1 > d2)
		cout << ">" << endl;
	else if (d1 == d2)
		cout << "==" << endl;
	if (d1 != d2)
		cout << "!=" << endl;
}
void Test5()
{
	Date d1(2021, 5, 30);
	Date d2(2021, 6, 2);
	cout << d2 - d1 << endl;
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();
	return 0;
}