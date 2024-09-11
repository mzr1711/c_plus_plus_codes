#include <iostream>
#include <list>


void print_list(std::list<int> list)
{
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

bool my_compare(int a, int b)
{
	return a < b;
}

void test()
{
	std::list<int> list;
	for (int i = 0; i < 5; i++)
	{
		int num = rand() % 5;
		list.push_back(num);
	}
	print_list(list);

	list.reverse();
	print_list(list);

	list.sort(my_compare);
	print_list(list);
}

int main()
{
	test();

	return 0;
}