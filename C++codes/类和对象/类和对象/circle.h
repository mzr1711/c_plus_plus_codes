#pragma once
#include <iostream>
using namespace std;
#include "point.h"

class Circle
{
public:
	//设置圆的中心位置，半径
	void setCircle(Point p1, double r);

	//判断点在圆的哪个位置,在圆内返回-1，在圆上返回0，在圆外返回1
	int PointPosition(Point p);

private:
	Point cirPoint;
	double R;
};