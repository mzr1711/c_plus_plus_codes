#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu
{
	string name;
	int score;
};

int main()
{
	vector<int>arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	//arr.pop_back();
	//arr.pop_back();
	//arr.pop_back();

	arr[0] = 100;

	cout << arr.size() << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;

	// vector<int>().swap(arr);  // 清除所有数据且释放内存

	cout << arr.empty() << endl;

	vector<int>vec1;
	vector<int>vec2;
	vec1.push_back(1);
	vec1.push_back(2);
	vec2 = vec1;
	for (int i = 0; i < vec2.size(); i++)
		cout << vec2[i] << " ";
	cout << endl;

	sort(arr.begin(), arr.begin() + 2);  // 排序前两个数

	//sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;

	vector<Stu>students;  // 可以创建自定义类型的数组
	Stu s1;
	s1.name = "张三";
	s1.score = 100;
	students.push_back(s1);
	students.push_back({ "Jack", 90 });

	for (int i = 0; i < students.size(); i++)
		cout << "name: " << students[i].name << " score: " << students[i].score << endl;

	vector<int>vast_arr(100, 0);  // 创建一个100个元素且所有数为0的数组

	return 0;
}