//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//
//void my_print(int val)
//{
//	std::cout << val << std::endl;
//}
//
//int main()
//{
//	std::vector<int> v1;
//
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	
//	//std::vector<int>::iterator it_begin = v1.begin();	// 起始迭代器，指向容器第一个元素
//	//std::vector<int>::iterator it_end = v1.end();		// 结束迭代器，指向容器最后一个元素
//
//	//while (it_begin != it_end)
//	//{
//	//	std::cout << *it_begin << std::endl;
//	//	it_begin++;
//	//}
//
//	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
//	{
//		std::cout << *it << std::endl;
//	}
//
//	for_each(v1.begin(), v1.end(), my_print);
//
//	return 0;
//}