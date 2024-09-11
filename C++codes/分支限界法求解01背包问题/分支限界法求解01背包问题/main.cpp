#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Thing {
public:
	Thing(int w, int v);
	double GetK();
	bool operator<(const Thing& s) const {
		return m_k > s.m_k;
	}

	int m_w;  // 质量
	int m_v;  // 价值
	double m_k;  // 单位价值
};

class TreeNode {
public:
	double CalcUb();

	int m_W;  // 当前重量
	int m_V;  // 当前价值
	int m_ub;  // 该结点上界
};

Thing::Thing(int w, int v) {
	m_w = w;
	m_v = v;
}

double Thing::GetK() {
	return (double)m_v / (double)m_w;
}

double TreeNode::CalcUb() {
	return 0;
}

int main() {
	int capacity;  // 容量
	int count;  // 商品的数量

	cout << "The capacity of this backpack is:";
	cin >> capacity;
	cout << "The count of goods is:";
	cin >> count;

	vector<Thing>things;

	for (int i = 0; i < count; i++) {
		int w, v;
		cout << "weight:";
		cin >> w;
		cout << "value:";
		cin >> v;
		Thing temp(w, v);
		things.push_back(temp);
	}

	sort(things.begin(), things.end());

	for (int i = 0; i < count; i++) {
		cout << "w=" << things[i].m_w << ", v=" << things[i].m_v << ", k=" << things[i].GetK() << endl;
	}

	return 0;
}