#include <iostream>
#include <vector>
using namespace std;

#define GRAPH_MAX  5
#define COLOR_MAX  3

class MyGraph
{
public:
	MyGraph(vector<vector<int>>& graph, int vexs);
	void PrintGraph();
	void PrinColorFilled();
	bool Check(int pos);
	void FillColor();
	int GetCount();

private:
	vector<int>m_vexs;
	vector<vector<int>>m_arcs;
	int m_vex_num;
	int m_arc_num;
	int m_count;  // 所有颜色的填充方法
};

MyGraph::MyGraph(vector<vector<int>>&graph, int vex_num)
{
	m_vex_num = vex_num;
	m_arc_num = 0;
	m_vexs.resize(m_vex_num);
	m_arcs.resize(m_vex_num, vector<int>(m_vex_num));
	for (int i = 0; i < m_vex_num; i++)
	{
		m_vexs[i] = -1;
		for (int j = 0; j < m_vex_num; j++)
		{
			m_arcs[i][j] = graph[i][j];
			if (m_arcs[i][j] != 0)
				m_arc_num++;
		}
	}
	m_arc_num /= 2;
}

void MyGraph::PrintGraph()
{
	cout << "m_vexs:" << endl;
	for (int i = 0; i < m_vex_num; i++)
		cout << m_vexs[i] << " ";
	cout << endl << "m_arcs:" << endl;
	for (int i = 0; i < m_vex_num; i++)
	{
		for (int j = 0; j < m_vex_num; j++)
		{
			cout << m_arcs[i][j] << " ";
		}
		cout << endl;
	}
	cout << "m_vex_num = " << m_vex_num << endl;
	cout << "m_arc_num = " << m_arc_num << endl;
	cout << "m_count = " << m_count << endl;
}

void MyGraph::PrinColorFilled()
{
	cout << "color filled " << m_count << ": ";
	for (int i = 0; i < m_vex_num; i++)
		cout << m_vexs[i] << " ";
	cout << endl;
}

bool MyGraph::Check(int pos)
{
	for (int i = 0; i < pos; i++)
	{
		if (m_arcs[pos][i] != 0 &&
			m_vexs[i] == m_vexs[pos])
			return false;
	}
	return true;
}

void MyGraph::FillColor()
{
	static int vex_index = 0;
	if (vex_index >= m_vex_num)  // 所有元素颜色填充结束结束
	{
		m_count++;
		PrinColorFilled();
		return;
	}
	else
	{
		for (int i = 0; i < COLOR_MAX; i++)
		{
			m_vexs[vex_index] = i;
			if (Check(vex_index))
			{
				vex_index++;
				FillColor();
				vex_index--;
			}
		}
	}
}

int MyGraph::GetCount()
{
	return m_count;
}

int main()
{
	vector<vector<int>>graph = {
		{0, 1, 1, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 1, 0, 1, 0},
		{0, 0, 1, 0, 1},
		{1, 1, 0, 1, 0}
	};

	MyGraph g1(graph, 5);
	g1.PrintGraph();
	g1.FillColor();
	if (!g1.GetCount())
		cout << "失败，无法全部填充" << endl;
	else
		cout << "所有填充可能种类数为" << g1.GetCount() << endl;

	graph.clear();

	return 0;
}