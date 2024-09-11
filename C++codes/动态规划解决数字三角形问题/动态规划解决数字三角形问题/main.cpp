#include <iostream>
#include <iomanip>
using namespace std;

#define NUM_MAX  10

int FindMaxSum(int (*arr)[NUM_MAX], int (*max_sum)[NUM_MAX], int i, int j, int n)
{
	if (max_sum[i][j] != -1)
		return max_sum[i][j];
	if (i >= n - 1)
		max_sum[i][j] = arr[i][j];
	else
	{
		int x = FindMaxSum(arr, max_sum, i + 1, j, n);
		int y = FindMaxSum(arr, max_sum, i + 1, j + 1, n);
		max_sum[i][j] = (x > y ? x : y) + arr[i][j];
	}
	return max_sum[i][j];
}

int main()
{
	int triangle[NUM_MAX][NUM_MAX];
	int max_sum[NUM_MAX][NUM_MAX];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> triangle[i][j];
			max_sum[i][j] = -1;
		}
	}

	//cout << FindMaxSum(triangle, max_sum, 0, 0, n);

	// 递归转化为递推
	for (int i = 0; i < n; i++)
		max_sum[n - 1][i] = triangle[n - 1][i];
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			max_sum[i][j] = 
				(max_sum[i + 1][j] > max_sum[i + 1][j + 1] ? max_sum[i + 1][j] : max_sum[i + 1][j + 1])
				+ triangle[i][j];
			cout << max_sum[i][j] << '\t';
		}
		cout << '\n';
	}

	cout << max_sum[0][0] << endl;

	return 0;
}