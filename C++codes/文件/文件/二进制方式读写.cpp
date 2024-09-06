//#include <iostream>
//#include <fstream>
//
//
//class Person
//{
//public:
//	char m_Name[64];
//	int m_Age;
//};
//
//void test()
//{
//	std::ofstream ofs("person.txt", std::ios::out | std::ios::binary);
//
//	Person person_1 = { "Àî»ª", 17 };
//
//	ofs.write((const char*)&person_1, sizeof(Person));
//
//	ofs.close();
//}
//
//int main()
//{
//	test();
//	return 0;
//}


#include <iostream>
#include <fstream>


class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test()
{
	std::ifstream ifs("person.txt", std::ios::in | std::ios::binary);

	Person person_1;

	ifs.read((char*)&person_1, sizeof(Person));

	std::cout << person_1.m_Name << person_1.m_Age << std::endl;

	ifs.close();
}

int main()
{
	test();
	return 0;
}