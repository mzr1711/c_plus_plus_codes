//#include <iostream>
//using namespace std;
//
//// common writing
//class Calculator
//{
//public:
//	int getResult(string oper)
//	{
//		if (oper == "+")
//		{
//			return m_Num1 + m_Num2;
//		}
//		else if (oper == "-")
//		{
//			return m_Num1 - m_Num2;
//		}
//		else if (oper == "*")
//		{
//			return m_Num1 * m_Num2;
//		}
//		else if (oper == "/")
//		{
//			return m_Num1 / m_Num2;
//		}
//	}
//
//	int m_Num1;
//	int m_Num2;
//};
//
//void test01()
//{
//	Calculator calc;
//	calc.m_Num1 = 10;
//	calc.m_Num2 = 10;
//	cout << calc.m_Num1 << "+" << calc.m_Num2 << "=" << calc.getResult("+") << endl;
//	cout << calc.m_Num1 << "-" << calc.m_Num2 << "=" << calc.getResult("-") << endl;
//	cout << calc.m_Num1 << "*" << calc.m_Num2 << "=" << calc.getResult("*") << endl;
//	cout << calc.m_Num1 << "/" << calc.m_Num2 << "=" << calc.getResult("/") << endl;
//}
//
//// use polymorphism implementation calculator
//class AbstractCalculator
//{
//public:
//	virtual int getResult()
//	{
//		return 0;
//	}
//
//	int m_Num1;
//	int m_Num2;
//};
//
//class AddCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//
//class SubCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
//class MulCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//
//void test02()
//{
//	// the parent class pointer points to child class object
//	AbstractCalculator* calc = new AddCalculator;
//	calc->m_Num1 = 10;
//	calc->m_Num2 = 10;
//	cout << calc->m_Num1 << " + " << calc->m_Num2 << " = " << calc->getResult() << endl;
//
//	delete calc;
//
//	calc = new SubCalculator;
//	calc->m_Num1 = 10;
//	calc->m_Num2 = 10;
//	cout << calc->m_Num1 << " - " << calc->m_Num2 << " = " << calc->getResult() << endl;
//
//	delete calc;
//	calc = NULL;
//}
//
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}