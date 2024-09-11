#include <iostream>
#include <string>


void test()
{
	std::string s1;

	std::string s2 = "hello world";

	std::string s3(s2);

	std::string s4(10, 'a');

	const char* str = "haha";
	std::string s5(str);

	std::cout << s1 << s2 << s3 << s4 << s5 << std::endl;
}

int main()
{
	test();

	return 0;
}