#include <iostream>
using namespace std;

class Class {
public:
	string m_name;
protected:
	string m_car;
private:
	int m_password;

public:
	void func() {
		cout << m_name << endl;
		cout << m_car << endl;
		cout << m_password << endl;
	}
};

//int main() {
//	Class c1;
//	c1.func();
//
//	return 0;
//}