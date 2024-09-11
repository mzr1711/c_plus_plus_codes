#include <iostream>
using namespace std;

int* GreedySelector(int* s, int* f, int n, int start, int end)
{
	int* time = (int*)malloc(sizeof(int) * (end - start + 1));
	for (int i = 0; i < end - start + 1; i++)
		time[i] = 0;
	int* res = (int*)malloc(sizeof(int) * n + 1);
	for (int i = 0; i < n + 1; i++)
		res[i] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = s[i] - 1; j < f[i]; j++)
		{
			if (time[j] == 1)  // 执行检测到该时间段被占用，则直接跳出该段循环
			{
				break;
			}
			if (j == f[i] - 1)
			{
				for (int k = s[i] - 1; k < f[i]; k++)
					time[j] = 1;  // 将该段时间标记为使用
				res[0]++;
				res[res[0]] = i + 1;
			}
		}
	}
	return res;
}

int main()
{
	int s[11] = { 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
	int f[11] = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

	int* res = GreedySelector(s, f, 11, 1, 14);

	for (int i = 1; i <= res[0]; i++)
	{
		cout << res[i] << endl;
	}

	return 0;
}