#include <iostream>
#include <string>


void test()
{
	std::string str = "abcdefgf";
	
	int pos = str.find("f");
	int pos_r = str.rfind("f");

	std::cout << pos << std::endl;
	std::cout << pos_r << std::endl;

	str.replace(1, 3, "11111");

	std::cout << str << std::endl;

	for (int i = 0; i < str.size(); i++)
		std::cout << str[i] << " ";

	for (int i = 0; i < str.size(); i++)
		std::cout << str.at(i) << " ";

	str[0] = 'x';
	str.at(1) = '2';
	std::cout << std::endl << str << std::endl;

	str.insert(1, "hello");
	std::cout << str << std::endl;

	str.erase(0, 5);
	std::cout << str << std::endl;

	std::string sub_str = str.substr(0, 5);
	std::cout << sub_str << std::endl;
}

void test2()
{
	std::string email = "zhangsan@sina.com";

	int pos = email.find('@');
	std::cout << pos << std::endl;

	std::string user_name = email.substr(0, pos);
	std::cout << user_name << std::endl;
}

int main()
{
	//test();
	test2();

	return 0;
}