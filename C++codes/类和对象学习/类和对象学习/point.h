#pragma once
#include <iostream>
using namespace std;

class Point {
public:
	void SetPoint(int x, int y);
	int GetPoint_X();
	int GetPoint_Y();
private:
	int m_x;
	int m_y;
};