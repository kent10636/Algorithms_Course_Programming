// 功能：寻找最长公共子串
// 算法：动态规划DP

#include <iostream>
#include <string>

#define MAXSIZE 100

using namespace std;

int index;

int LCS_LENGTH(char* X, char* Y, int** b)
{
	int length1 = strlen(X);
	int length2 = strlen(Y);

	int i, j;

	int **c = new int*[length1 + 1];  //共有length1+1行  
	for (i = 0; i < length1 + 1; i++)
	{
		c[i] = new int[length2 + 1];  //共有length2+1列  
	}

	//将二维数组c的第0列、第0行全部初始化为0
	for (i = 0; i <= length1; i++)
	{
		c[i][0] = 0;
	}
	for (j = 0; j <= length2; j++)
	{
		c[0][j] = 0;
	}

	int len = 0;
	for (i = 1; i <= length1; i++)
	{
		for (j = 1; j <= length2; j++)
		{
			if (X[i - 1] == Y[j - 1])  //由于c[][]的0行0列没有使用，c[][]的第i行元素对应X的第i-1个元素  
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				if (c[i][j] > len)
				{
					len = c[i][j];
					index = i;
					//cout << len << " " << index << endl;
				}
			}
			else
			{
				c[i][j] = 0;
			}
		}
	}

	/*
	//测试二维数组c
	for(i= 0; i <= length1; i++)
	{
		for(j = 0; j <= length2; j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	*/

	return len;
}

int main()
{
	char X[MAXSIZE] = "xzyzzyx";
	char Y[MAXSIZE] = "zxyyzxz";
	//char X[MAXSIZE] = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFISRLLAIVAD";
	//char Y[MAXSIZE] = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG";

	int length1 = strlen(X);
	int length2 = strlen(Y);
	//cout << length1 << " " << length2 << endl;

	int** b = new int*[length1 + 1];
	for (int i = 0; i <= length1; i++)
	{
		b[i] = new int[length2 + 1];
	}

	int len = LCS_LENGTH(X, Y, b);
	printf("最长公共子串的长度为：%d\n", len);

	printf("最长公共子串为：");
	for (int i = index - len; i < index; i++)
	{
		cout << X[i];
	}
	cout << endl;

    return 0;
}
