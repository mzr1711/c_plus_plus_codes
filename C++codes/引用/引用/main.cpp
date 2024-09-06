//#include <iostream>
//using namespace std;

//int main()
//{
//	//1.引用时必须初始化
//	//int& c;
//
//	//2.引用在初始化后不能改变
//
//	int a = 10;
//	int& b = a;
//
//	cout << "a的值是" << a << endl;
//	cout << "b的值是" << b << endl;
//
//	b = 100;
//
//	cout << "a的值是" << a << endl;
//	cout << "b的值是" << b << endl;
//
//	system("pause");
//	return 0;
//}

//void intSwap1(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void intSwap2(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void intSwap3(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	//intSwap1(a, b);  //不做任何处理的交换
//	//intSwap2(&a, &b);  //取出a和b的地址交换值
//	intSwap3(a, b);  //形参使用引用的交换
//
//	cout << "a的值为" << a << endl;
//	cout << "b的值为" << b << endl;
//
//	return 0;
//}


//int& test(void)
//{
//	static int a = 10;
//	return a;
//}
//
//int main()
//{
//	int& ref = test();
//
//	cout << "a的值为" << ref << endl;
//	cout << "a的值为" << ref << endl;
//
//	//函数能作为左值
//	test() = 1000;
//
//	cout << "a的值为" << ref << endl;
//
//	ref = 100;
//
//	cout << "a的值为" << ref << endl;
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main() {
//	int a = 10;
//	int& b = a;
//
//	cout << b << endl;
//
//	b = 20;
//
//	cout << a << endl;
//
//	return 0;
//}

#/*include <iostream>
using namespace std;

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 10;
	int b = 20;
	Swap(a, b);
	cout << a << "  " << b << endl;
	return 0;
}*/

//#include <iostream>
//using namespace std;

//int& test(void)
//{
//	static int a = 10;
//	return a;
//}
//
//int main()
//{
//	int& ref = test();
//
//	cout << "a的值为" << ref << endl;
//	cout << "a的值为" << ref << endl;
//
//	//函数能作为左值
//	test() = 1000;
//
//	cout << "a的值为" << ref << endl;
//
//	ref = 100;
//
//	cout << "a的值为" << ref << endl;
//
//	return 0;
//}


#include <iostream>
using namespace std;

void test(int& num) {
	num = 1000;
}

int main() {
	int a = 100;
	cout << a << endl;
	test(a);
	cout << a << endl;

	return 0;
}