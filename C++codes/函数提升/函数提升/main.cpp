#include <iostream>
using namespace std;

////函数可以有默认值
//int test1(int a, int b = 10, int c = 10)
//{
//	return a + b + c;
//}
//
////函数的定义和声明里，只能其中一个写默认值
//int test2(int a, int b, int c);
//
//int test2(int a = 10, int b = 10, int c = 10)
//{
//	return a + b + c;
//}
//
//int main()
//{
//	//cout << test1(10) << endl;
//	cout << test2() << endl;
//
//	return 0;
//}


//void func()
//{
//	cout << "调用func函数" << endl;
//}
//
//void func(int a = 10)
//{
//	cout << "调用func(int a)函数" << endl;
//}
//
//int main()
//{
//	int a = 1;
//	func(a);
//
//	return 0;
//}

//void test(int a = 10) {
//	cout << a << endl;
//}
//
//int main() {
//	test(20);
//	test();
//	return 0;
//}


// 函数重载

void func(int a = 10) {
	cout << a << endl;
}

void func(double a) {
	cout << "func调用" << endl;
}

void func(const int a) {
	cout << "const调用" << endl;
}

int main() {
	func(10);
	return 0;
}