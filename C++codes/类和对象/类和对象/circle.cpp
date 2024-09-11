#include "circle.h"

//设置圆的中心位置，半径
void Circle::setCircle(Point p1, double r)
{
	cirPoint = p1;
	R = r;
}

//判断点在圆的哪个位置,在圆内返回-1，在圆上返回0，在圆外返回1
int Circle::PointPosition(Point p)
{
	if (R > p.getLength(cirPoint))
	{
		return -1;
	}
	else if (R == p.getLength(cirPoint))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}