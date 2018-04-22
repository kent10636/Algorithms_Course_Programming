// 功能：计算最小代价矩阵链乘顺序
// 算法：动态规划DP

#include <iostream>

#define ARRAY_SIZE 10
#define MAXNUM 999
#define MATRIX_SIZE 5  /* 6 */

using namespace std;

int m[ARRAY_SIZE][ARRAY_SIZE], s[ARRAY_SIZE][ARRAY_SIZE];

int matrix_chain_order(int p[])
{
	int i, j, k, l, q;
	int n = MATRIX_SIZE - 1;
	for (i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}
	for (l = 2; l <= n; l++)
	{
		for (i = 1; i <= n - l + 1; i++)
		{
			j = i + l - 1;
			m[i][j] = MAXNUM;
			for (k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];  // 不是p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	return 0;
}

int print_optimal_parens(int i, int j)
{
	if (i == j)
	{
		printf("A");
	}
	else
	{
		printf("(");
		print_optimal_parens(i, s[i][j]);
		print_optimal_parens(s[i][j] + 1, j);
		printf(")");
	}
	return 0;
}

int main()
{
	int p[MATRIX_SIZE + 1];
	int arr[] = { 3,5,2,1,10 };  /* {2,7,3,6,10}; {10,3,15,12,7,2}; {7,2,4,15,20,5} */
	int i, j;
	for (i = 1, j = 0; i <= MATRIX_SIZE || j <= MATRIX_SIZE; i++, j++)
	{
		p[i] = arr[j];
	}
	matrix_chain_order(p);
	print_optimal_parens(1, MATRIX_SIZE-1);
	printf("\n");
    return 0;
}
