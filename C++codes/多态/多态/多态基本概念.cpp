//#include <iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "animal is speaking" << endl;
//	}
//};
//
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "cat is speaking" << endl;
//	}
//};
//
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "dog is speaking" << endl;
//	}
//};
//
//// do speak functioin
//void doSpeak(Animal &animal)
//{
//	animal.speak();
//}
//
//void test()
//{
//	Cat cat;
//	doSpeak(cat);
//
//	Dog dog;
//	doSpeak(dog);
//}
//
//int main()
//{
//	test();
//	return 0;
//}