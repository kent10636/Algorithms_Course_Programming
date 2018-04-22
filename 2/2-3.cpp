// ���ܣ�Ѱ��������Ӵ�
// �㷨����̬�滮DP

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

	int **c = new int*[length1 + 1];  //����length1+1��  
	for (i = 0; i < length1 + 1; i++)
	{
		c[i] = new int[length2 + 1];  //����length2+1��  
	}

	//����ά����c�ĵ�0�С���0��ȫ����ʼ��Ϊ0
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
			if (X[i - 1] == Y[j - 1])  //����c[][]��0��0��û��ʹ�ã�c[][]�ĵ�i��Ԫ�ض�ӦX�ĵ�i-1��Ԫ��  
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
	//���Զ�ά����c
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
	printf("������Ӵ��ĳ���Ϊ��%d\n", len);

	printf("������Ӵ�Ϊ��");
	for (int i = index - len; i < index; i++)
	{
		cout << X[i];
	}
	cout << endl;

    return 0;
}
