#include <iostream>
#include <vector>

class Graph
{
public:
	std::vector<std::vector<int>> graph;
	int node_num;
	std::vector<char> node_name;

public:
	Graph(int num, std::vector<std::vector<int>> array)
	{
		node_num = num;

		graph.resize(node_num, std::vector<int>(node_num, 0));
		node_name.resize(node_num);

		for (int i = 0; i < node_num; i++)
		{
			node_name[i] = 'A' + i;
			for (int j = 0; j < node_num; j++)
			{
				graph[i][j] = array[i][j];
			}
		}
	}

	void PrintGraph()
	{
		for (int i = 0; i < node_num; i++)
			std::cout << node_name[i] << " ";
		std::cout << std::endl;
		for (int i = 0; i < node_num; i++)
		{
			for (int j = 0; j < node_num; j++)
			{
				std::cout << graph[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	void Dijkstra(int src_index, int dst_index)
	{
		std::vector<int>	distance(node_num, INT_MAX);
		std::vector<int>	previous(node_num, -1);
		std::vector<bool>	visited(node_num, false);

		distance[src_index] = 0;

		while (1)
		{
			// Find the minimum distance
			int min = INT_MAX;
			int current_index = -1;
			for (int i = 0; i < node_num; i++)
			{
				if (distance[i] < min && !visited[i])
				{
					min = distance[i];
					current_index = i;
				}
			}

			if (current_index == -1)
				break;

			visited[current_index] = true;

			if (current_index == dst_index)
			{
				for (int i = 0; i < node_num; i++)
					std::cout << distance[i] << " ";
				std::cout << std::endl;
				for (int i = 0; i < node_num; i++)
					std::cout << previous[i] << " ";
				std::cout << std::endl;
				for (int i = 0; i < node_num; i++)
					std::cout << visited[i] << " ";
				std::cout << std::endl;

				std::vector<int> path;
				int index = dst_index;
				int total_length = 0;
				while (1)
				{
					total_length += graph[index][previous[index]];
					path.push_back(index);
					index = previous[index];
					if (index == src_index)
					{
						path.push_back(src_index);
						break;
					}
				}
				for (int i = path.size() - 1; i > 0; i--)
				{
					std::cout << node_name[path[i]] << " --> " << node_name[path[i - 1]] << std::endl;
				}
				std::cout << "Total length:" << total_length << std::endl;
				std::cout << "End of search" << std::endl << std::endl;
				break;
			}

			// Update the arrays
			for (int i = 0; i < node_num; i++)
			{
				if (!visited[i] && graph[current_index][i] != 0)
				{
					int new_distance = graph[current_index][i] + distance[current_index];
					if (new_distance < distance[i])
					{
						distance[i] = new_distance;
						previous[i] = current_index;
					}
				}
			}
		}
	}
};

int main()
{
	//std::vector<std::vector<int>> array1 = {
	//	{0,5,7,0,8,0,0},
	//	{5,0,4,10,0,0,0},
	//	{7,4,0,0,0,0,7},
	//	{0,10,0,0,0,6,4},
	//	{8,0,0,0,0,10,0},
	//	{0,0,0,6,10,0,0},
	//	{0,0,7,4,0,0,0}
	//};

	//Graph g1(7, array1);

	//g1.PrintGraph();

	//g1.Dijkstra(0, 6);
	//g1.Dijkstra(0, 5);
	//g1.Dijkstra(1, 5);

	std::vector<std::vector<int>> array2 = {
		{0,30,0,11,0,	0,0,10,0,0,		0,21,0},	// A
		{30,0,0,0,2,	0,0,0,0,0,		0,0,0},		// B
		{0,0,0,0,8,		0,0,0,0,0,		23,0,19},	// C
		{11,0,0,0,10,	0,0,0,8,0,		0,0,0},		// D
		{0,2,8,10,0,	8,0,0,9,0,		17,0,0},	// E
		{0,0,0,0,8,		0,0,0,0,0,		0,0,13},	// F
		{0,0,0,0,0,		0,0,6,0,11,		15,0,0},	// G
		{10,0,0,0,0,	0,6,0,0,0,		0,0,0},		// H
		{0,0,0,8,9,		0,0,0,0,8,		0,20,0},	// I
		{0,0,0,0,0,		0,11,0,8,0,		0,0,0},		// J
		{0,0,23,0,17,	0,15,0,0,0,		0,0,18},	// K
		{21,0,0,0,0,	0,0,0,20,0,		0,0,0},		// L
		{0,0,19,0,0,	13,0,0,0,0,		18,0,0},	// M
	};

	Graph g2(13, array2);

	g2.Dijkstra(7, 2);

	return 0;
}