#include <iostream>
using namespace std;

class Circle
{
private:
	double PI = 3.14159265;

public:
	double m_r;

	double CalcCircumference()
	{
		return 2 * PI * m_r * m_r;
	}
};

//int main()
//{
//	Circle circle;
//	circle.m_r = 4;
//	cout << "圆的半径为" << circle.m_r << endl;
//	cout << "圆的周长为" << circle.CalcCircumference() << endl;
//
//	return 0;
//}