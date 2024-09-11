#include "point.h"

//设置点的坐标
void Point::setPoint(int x, int y)
{
	m_X = x;
	m_Y = y;
}

//返回点的水平坐标
int Point::getX()
{
	return m_X;
}
//返回点的竖直坐标
int Point::getY()
{
	return m_Y;
}

//计算两点之间的长度
double Point::getLength(Point p)
{
	return sqrt(pow(abs(p.getX() - m_X), 2) + pow(abs(p.getY() - m_Y), 2));
}