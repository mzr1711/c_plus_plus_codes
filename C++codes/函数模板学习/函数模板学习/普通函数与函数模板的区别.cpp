//#include <iostream>
//using namespace std;
//
//// 普通函数与函数模板调用规则
//// 1.如果普通函数可以调用，优先调用普通函数
//// 2.可以通过空模板参数列表 强制调用 函数模板
//
//
//void my_print(int a)
//{
//	cout << "普通函数调用\n" << endl;
//}
//
//template<typename T>
//void my_print(T a)
//{
//	cout << "函数模板调用\n" << endl;
//}
//
//template<typename T>
//void my_print(T a, T b)
//{
//	cout << "函数模板重载调用\n" << endl;
//}
//
//void test()
//{
//	int a = 10;
//
//	//my_print(a);
//
//	// 通过空模板参数列表强制调用函数模板
//	my_print<>(a);
//
//	my_print(a, 1);
//
//	char c = 'c';
//
//	my_print(c);
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}