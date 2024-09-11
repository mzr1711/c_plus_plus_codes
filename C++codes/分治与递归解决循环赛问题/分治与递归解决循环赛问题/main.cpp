#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int** CreateTable(int n) {
	int** table = new int* [n];
	for (int i = 0; i < n; i++) {
		table[i] = new int[n];
		for (int j = 0; j < n; j++) {
			if (j == 0)
				table[i][j] = i + 1;
			else
				table[i][j] = 0;
		}
	}
	return table;
}

void DeleteTable(int** table, int n) {
	for (int i = 0; i < n; i++)
		delete[] table[i];
	delete[] table;
}

void PrintTable(int** table, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << right << table[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void GroupingContestant(int** table, int head, int tail) {
	if (tail - head > 0) {
		int mid = (head + tail) / 2;
		GroupingContestant(table, head, mid);  // left part
		GroupingContestant(table, mid + 1, tail);  // right part
		int end = tail - head;
		int start = (tail - head) / 2 + 1;
		for (int i = tail; i >= head; i--) {
			for (int j = end; j >= start; j--) {
				if (i <= mid) {  // the first half
					table[i][j] = table[i + start][j - start];
				}
				else {  // the second half
					table[i][j] = table[i - start][j - start];
				}
			}
		}
	}
}

bool IsPowerOfTwo(int n) {
	return (n && !(n & (n - 1)));
}

int main() {
	int n = 0;  // 运动员数量
	int** table;

	do {
		cout << "please input a number which is a power of two:";
		cin >> n;
		if (IsPowerOfTwo(n))
			break;
		else
			cout << "input error, please input again" << endl;
	} while (1);

	table = CreateTable(n);
	//PrintTable(table, n);

	GroupingContestant(table, 0, n - 1);
	PrintTable(table, n);

	DeleteTable(table, n);
	table = NULL;

	return 0;
}