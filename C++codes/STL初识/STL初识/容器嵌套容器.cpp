//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//
//void test()
//{
//	std::vector<std::vector<int>> v;
//
//	//std::vector<int> v1;
//	//std::vector<int> v2;
//	//std::vector<int> v3;
//	//std::vector<int> v4;
//
//	//for (int i = 0; i < 4; i++)
//	//{
//	//	v1.push_back(i + 0);
//	//	v2.push_back(i + 1);
//	//	v3.push_back(i + 2);
//	//	v4.push_back(i + 3);
//	//}
//
//	//v.push_back(v1);
//	//v.push_back(v2);
//	//v.push_back(v3);
//	//v.push_back(v4);
//
//	v.resize(4);
//	for (int i = 0; i < 4; i++)
//	{
//		v[i].resize(4);
//		for (int j = 0; j < 4; j++)
//		{
//			v[i][j] = i * 4 + j;
//		}
//	}
//
//	for (std::vector<std::vector<int>>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		for (std::vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
//		{
//			std::cout << (*vit) << " ";
//		}
//		std::cout << std::endl;
//	}
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}