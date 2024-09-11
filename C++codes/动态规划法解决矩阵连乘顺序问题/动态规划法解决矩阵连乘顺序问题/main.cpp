#include<iostream>
using namespace std;
#define N 7

//计算最优值 
void MatrixChain(int* p, int n, int m[][N], int s[][N]) {
	for (int i = 1; i <= n; i++) {  //矩阵链中只有一个矩阵时，次数为0
		m[i][i] = 0;
	}
	for (int r = 2; r <= n; r++) {
		for (int i = 1; i <= n - r + 1; i++) {
			int j = i + r - 1; //矩阵链的末尾矩阵，注意r-1，因为矩阵链为2时，实际是往右+1
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;

			for (int k = i + 1; k < j; k++) {  //这里面将断链点从i+1开始，可以断链的点直到j-1为止
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}

	}

}

//构造最优解 
void Traceback(int i, int j, int s[][N]) {
	if (i == j)       //回归条件
	{
		cout << "A" << i;
	}
	else       //按照最佳断点一分为二，接着继续递归
	{
		cout << "(";
		Traceback(i, s[i][j], s);
		Traceback(s[i][j] + 1, j, s);
		cout << ")";
	}
}
int main() {
	int p[N] = { 30,35,15,5,10,20,25 };
	int m[N][N], s[N][N];

	MatrixChain(p, N - 1, m, s); //N-1因为只有六个矩阵
	cout << "矩阵的最佳乘积方式为: ";
	Traceback(1, 6, s);
	return 0;
}
