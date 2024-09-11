#include "circle.h"
#include <cmath>

void Circle::SetCircle(Point p, double r) {
	m_center = p;
	m_r = r;
}

bool Circle::IsInCircle(Point p) {
	int x = p.GetPoint_X() - m_center.GetPoint_X();
	int y = p.GetPoint_Y() - m_center.GetPoint_Y();
	if (pow(x, 2) + pow(y, 2) <= pow(m_r, 2))
		return true;
	return false;
}