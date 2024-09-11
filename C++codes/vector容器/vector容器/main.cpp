#include <iostream>
#include <vector>


void print_vector(std::vector<int> v)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test()
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	print_vector(v);

	v.pop_back();
	print_vector(v);

	v.insert(v.begin(), 100);
	print_vector(v);

	v.insert(v.begin() + 3, 2, 1);
	print_vector(v);

	v.erase(v.begin() + 2, v.end() - 2);
	print_vector(v);

	v.clear();
	print_vector(v);
}

void test2()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	print_vector(v);

	std::vector<int> v2;
	for (int i = 10; i > 0; i--)
		v2.push_back(i);

	print_vector(v2);

	v.swap(v2);
	print_vector(v);
	print_vector(v2);
}

void test3()
{
	std::vector<int> v;

	for (int i = 0; i < 10000; i++)
		v.push_back(i);

	std::cout << v.capacity() << std::endl;
	std::cout << v.size() << std::endl;

	v.resize(5);

	std::cout << v.capacity() << std::endl;
	std::cout << v.size() << std::endl;

	std::vector<int>(v).swap(v);

	std::cout << v.capacity() << std::endl;
	std::cout << v.size() << std::endl;
}

void test4()
{
	int capacity = 0;
	int num = 0;

	std::vector<int> v;
	v.reserve(9999);

	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		if (capacity != v.capacity())
		{
			capacity = v.capacity();
			num++;
		}
	}

	std::cout << num << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << v.size() << std::endl;
}

int main()
{
	//test();
	//test2();
	//test3();
	test4();

	return 0;
}