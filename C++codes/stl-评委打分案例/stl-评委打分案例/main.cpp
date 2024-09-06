#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>


class Person
{
public:
	Person(std::string _name)
	{
		name = _name;
	}

	void push_back(int val)
	{
		scores.push_back(val);
	}

	void print_scores()
	{
		for (std::deque<int>::const_iterator it = scores.begin(); it != scores.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	void sort_scores()
	{
		sort(scores.begin(), scores.end());
	}

	void scores_pop_back()
	{
		scores.pop_back();
	}

	void scores_pop_front()
	{
		scores.pop_front();
	}

	double get_average()
	{
		double sum = 0;
		for (std::deque<int>::const_iterator it = scores.begin(); it != scores.end(); it++)
			sum += *it;
		return sum / scores.size();
	}

private:
	std::string name;
	std::deque<int> scores;
};


int main()
{
	int scores[5][10] = {
		{100, 90, 95, 98, 80, 85, 89, 100, 88, 92},
		{100, 90, 95, 98, 80, 85, 89, 100, 88, 92},
		{100, 90, 95, 98, 80, 85, 89, 100, 88, 92},
		{100, 90, 95, 98, 80, 85, 89, 100, 88, 92},
		{100, 90, 95, 98, 80, 85, 89, 100, 88, 92},
	};

	std::vector<Person> vector_person;

	Person p1("张三");
	Person p2("李四");
	Person p3("王五");
	Person p4("孙悟空");
	Person p5("猪八戒");

	vector_person.push_back(p1);
	vector_person.push_back(p2);
	vector_person.push_back(p3);
	vector_person.push_back(p4);
	vector_person.push_back(p5);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			vector_person[i].push_back(scores[i][j]);
		}
		vector_person[i].sort_scores();
		vector_person[i].scores_pop_back();
		vector_person[i].scores_pop_front();
		vector_person[i].print_scores();
		std::cout << vector_person[i].get_average() << std::endl;
	}

	return 0;
}