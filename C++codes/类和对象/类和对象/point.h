#pragma once
#include <iostream>
using namespace std;

class Point
{
public:
	//设置点的坐标
	void setPoint(int x, int y);

	//返回点的水平坐标
	int getX();
	//返回点的竖直坐标
	int getY();

	//计算两点之间的长度
	double getLength(Point p);

private:
	int m_X;
	int m_Y;
};
