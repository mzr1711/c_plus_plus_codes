//#include <iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal构造函数的调用" << endl;
//	}
//	virtual ~Animal()
//	{
//		cout << "Animal析构函数的调用" << endl;
//	}
//	virtual void Speak() = 0;
//public:
//	string* m_Name;
//};
//
//class Cat :public Animal
//{
//public:
//	Cat(string name)
//	{
//		m_Name = new string(name);
//		cout << "Cat构造函数的调用" << endl;
//	}
//	~Cat()
//	{
//		if (m_Name != NULL)
//		{
//			delete m_Name;
//			m_Name = NULL;
//			cout << "Cat析构函数的调用" << endl;
//		}
//	}
//	void Speak()
//	{
//		cout << *m_Name << "在说话" << endl;
//	}
//};
//
//void test()
//{
//	Animal* animal = new Cat("Tom");
//	animal->Speak();
//	delete animal;
//	animal = NULL;
//}
//
//int main()
//{
//	test();
//	return 0;
//}