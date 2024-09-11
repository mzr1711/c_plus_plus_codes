#include <iostream>
#include <deque>


void print_deque(const std::deque<int> d)
{
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test()
{
	std::deque<int> d;

	for (int i = 0; i < 10; i++)
		d.push_back(i);

	print_deque(d);
}

int main()
{
	test();

	return 0;
}