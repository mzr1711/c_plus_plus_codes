#include <iostream>
using namespace std;

class Cube
{
private:
	double m_L;  // 长度
	double m_W;  // 宽度
	double m_H;  // 高度
public:
	void SetCube(int length, int weigth, int height) {
		m_L = length;
		m_W = weigth;
		m_H = height;
	}
	double CalcArea() {
		return 2 * ((m_L * m_W) + (m_L * m_H) + (m_W * m_H));
	}
	double CalcVulume() {
		return m_L * m_W * m_H;
	}
	bool IsSameCube(Cube& c) {
		if (m_L == c.m_L && m_W == c.m_W && m_H == c.m_H)
			return true;
		return false;
	}
};

//int main() {
//	Cube cube;
//	cube.SetCube(1, 1, 1);
//	cout << cube.CalcVulume() << endl;
//	cout << cube.CalcArea() << endl;
//	Cube cube_1;
//	cube_1.SetCube(1, 1, 1);
//	cout << cube_1.CalcVulume() << endl;
//	cout << cube_1.CalcArea() << endl;
//	if (cube.IsSameCube(cube_1))
//		cout << "Is same cubes" << endl;
//	else
//		cout << "Is not same cubes" << endl;
//
//	return 0;
//}