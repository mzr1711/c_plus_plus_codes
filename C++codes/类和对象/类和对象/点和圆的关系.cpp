#include <iostream>
using namespace std;
#include "point.h"
#include "circle.h"

//class Point
//{
//public:
//	//设置点的坐标
//	void setPoint(int x, int y)
//	{
//		m_X = x;
//		m_Y = y;
//	}
//
//	//返回点的水平坐标
//	int getX()
//	{
//		return m_X;
//	}
//	//返回点的竖直坐标
//	int getY()
//	{
//		return m_Y;
//	}
//
//	//计算两点之间的长度
//	double getLength(Point p)
//	{
//		return sqrt(pow(abs(p.getX() - m_X), 2) + pow(abs(p.getY() - m_Y), 2));
//	}
//
//private:
//	int m_X;
//	int m_Y;
//};

//class Circle
//{
//public:
//	//设置圆的中心位置，半径
//	void setCircle(Point p1, double r)
//	{
//		cirPoint = p1;
//		R = r;
//	}
//
//	//判断点在圆的哪个位置,在圆内返回-1，在圆上返回0，在圆外返回1
//	int PointPosition(Point p)
//	{
//		if (R > p.getLength(cirPoint))
//		{
//			return -1;
//		}
//		else if (R == p.getLength(cirPoint))
//		{
//			return 0;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//
//private:
//	Point cirPoint;
//	double R;
//};

int main()
{
	Point p1;
	Point pCir1;
	Circle c1;
	
	p1.setPoint(1, 1);
	pCir1.setPoint(4, 5);

	c1.setCircle(pCir1, 5);

	int ret = c1.PointPosition(p1);
	if (ret == 1)
	{
		cout << "点在圆外" << endl;
	}
	else if (ret == 0)
	{
		cout << "点在圆上" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}

	return 0;
}