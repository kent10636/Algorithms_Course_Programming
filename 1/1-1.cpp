// 功能：实现一个时间代价为nlgn的算法，给定数组S和整数x，判断数组中是否存在两个元素之和等于x
// 算法：归并排序（递归），二分查找

#include <iostream>

#define MAXSIZE 100

using namespace std;

void merge(int A[], int p, int q, int r)  //时间代价为n^2
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[MAXSIZE], R[MAXSIZE];
	for (int i = 1; i <= n1; i++)
	{
		L[i] = A[p + i - 1];
	}
	for (int j = 1; j <= n2; j++)
	{
		R[j] = A[q + j];
	}
	L[n1 + 1] = 999;
	R[n2 + 1] = 999;
	int m = 1, n = 1;
	for (int k = p; k <= r; k++)
	{
		if (L[m] <= R[n])
		{
			A[k] = L[m];
			m++;
		}
		else
		{
			A[k] = R[n];
			n++;
		}
	}
}

void merge_sort(int A[], int p, int r)  //时间代价为nlgn
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

bool find_twosum(int S[],int size,int x)
{
	int i, j;
	for (i = 1, j = size; i < j;)
	{
		if (S[i] + S[j] == x)
		{
			cout << "数组中存在两数之和等于x：" << S[i] << "+" << S[j] << "=" << x << endl;
			return true;
		}
		else if (S[i] + S[j] < x)
		{
			i++;
		}
		else
			j--;
	}
	cout << "数组中不存在两数之和等于x" << endl;
	return false;
}

int main()
{
	int i, j;
	int A[MAXSIZE] = {0};
	cout << "请输入数组S：" << endl;
	for (i = 1; A[i-1] != 999; i++)  //数组从1开始，元素个数为i-2，999作为数组输入终止符
	{
		cin >> A[i];
	}
	cout << "初始输入的数组为：" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl;

	merge_sort(A, 1, i-2);

	cout << "归并排序后的数组为：" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl;

	int x;
	cout << "请输入要查找的x值：" << endl;
	cin >> x;
	
	find_twosum(A, i - 2, x);

    return 0;
}
