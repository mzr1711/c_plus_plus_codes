#include "point.h"

void Point::SetPoint(int x, int y) {
	m_x = x;
	m_y = y;
}

int Point::GetPoint_X() {
	return m_x;
}

int Point::GetPoint_Y() {
	return m_y;
}