//#include <iostream>
//using namespace std;
//
//class Cube
//{
//public:
//	//设置长方体的长宽高
//	void setCube(double L, double W, double H)
//	{
//		m_L = L;
//		m_W = W;
//		m_H = H;
//	}
//
//	//获取长
//	double getLength()
//	{
//		return m_L;
//	}
//	//获取宽
//	double getWidth()
//	{
//		return m_W;
//	}
//	double getHight()
//	{
//		return m_H;
//	}
//
//	//计算长方体的表面积
//	double calcSurfaceArea()
//	{
//		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
//	}
//
//	//计算长方体的体积
//	double calcVolume()
//	{
//		return m_L * m_W * m_H;
//	}
//
//	//比较两个立方体是否相等
//	bool isSame(Cube c2)
//	{
//		if (m_L == c2.m_L && m_W == c2.m_W && m_H == c2.m_H)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//private:
//	double m_L;
//	double m_W;
//	double m_H;
//};
//
//bool isSameCube(Cube& c1, Cube& c2)
//{
//	if (c1.getLength() == c2.getLength() &&
//		c1.getWidth() == c2.getWidth() &&
//		c1.getHight() == c2.getHight())
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	Cube c1, c2;
//
//	c1.setCube(3, 4, 5);
//	c2.setCube(3, 4, 5);
//
//	cout << "c1的表面积为：" << c1.calcSurfaceArea() << endl;
//	cout << "c1的体积为：" << c1.calcVolume() << endl;
//	cout << "c1和c2相等吗？" << c1.isSame(c2) << endl;
//	cout << "c1和c2相等吗？" << isSameCube(c1, c2) << endl;
//
//	return 0;
//}