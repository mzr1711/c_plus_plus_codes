#pragma once
#include <iostream>
#include "point.h"
using namespace std;

class Circle {
public:
	void SetCircle(Point p, double r);
	bool IsInCircle(Point p);
private:
	Point m_center;
	double m_r;
};