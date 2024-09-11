//#include <iostream>
//using namespace std;
//
//
//template<class T>
//void my_sort(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		T min_index = i;
//		for (int j = i; j < len; j++)
//		{
//			if (arr[j] < arr[min_index])
//			{
//				min_index = j;
//			}
//		}
//		T temp = arr[i];
//		arr[i] = arr[min_index];
//		arr[min_index] = temp;
//	}
//}
//
//void test()
//{
//	char char_arr[] = "badcfe";
//
//	my_sort<char>(char_arr, sizeof(char_arr));
//
//	cout << char_arr;
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}