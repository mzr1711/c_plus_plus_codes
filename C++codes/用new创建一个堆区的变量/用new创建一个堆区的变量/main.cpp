#include <iostream>
using namespace std;

//int* func(void)
//{
//	//用new能在堆区开辟一块空间
//	int* pa = new int(10);
//	return pa;
//}
//
//int main()
//{
//	int* p = func();
//
//	cout << *p << endl;
//
//	return 0;
//}


int* func(void)
{
	int* p = new int(10);
	return p;
}

void test1(void)
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	delete p;

	//cout << *p << endl;
}

void test2(void)
{
	int* parr = new int[10];

	for (int i = 0; i < 10; i++)
	{
		parr[i] = 100 + i;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << parr[i] << endl;
	}

	//删除堆区开辟的数组时，delete后需要加入[]
	delete[] parr;
}

int main()
{
	//test1();
	test2();

	return 0;
}