// ���ܣ�Ѱ�������������
// �㷨����̬�滮DP

#include <iostream>
#include <string>

#define MAXSIZE 100

using namespace std;
 
int LCS_LENGTH(char* X, char* Y, int** b)
{
	int length1 = strlen(X);
	int length2 = strlen(Y);
	
	int i, j;
	
	//����˫ָ�����붯̬��ά����  
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

	for (i = 1; i <= length1 ; i++)
	{
		for (j = 1; j <= length2 ; j++)
		{
			if (X[i - 1] == Y[j - 1])  //����c[][]��0��0��û��ʹ�ã�c[][]�ĵ�i��Ԫ�ض�ӦX�ĵ�i-1��Ԫ��  
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = '�I';  //��������Ӵ�ʱ����������  
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = '��';
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = '��';
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

	int len = c[length1][length2];
	return len;
}

void PRINT_LCS(int** b, char* X, int i, int j)
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (b[i][j] == '�I')
	{
		PRINT_LCS(b, X, i - 1, j - 1); 
		printf("%c", X[i - 1]);  //����c[][]��0��0��û��ʹ�ã�c[][]�ĵ�i��Ԫ�ض�ӦX�ĵ�i-1��Ԫ��
	}
	else if (b[i][j] == '��')
	{
		PRINT_LCS(b, X, i - 1, j);
	}
	else
	{
		PRINT_LCS(b, X, i, j - 1);
	}
}

int main(void)
{
	char X[MAXSIZE] = "xzyzzyx";
	char Y[MAXSIZE] = "zxyyzxz";
	//char X[MAXSIZE] = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFISRLLAIVAD";
	//char Y[MAXSIZE] = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG";

	int length1 = strlen(X);
	int length2 = strlen(Y);
	//cout << length1 << " " << length2 << endl;
	
	//����˫ָ�����붯̬��ά����  
	int** b = new int* [length1 + 1];
	for (int i = 0; i <= length1; i++)
	{
		b[i] = new int [length2 + 1];
	}

	int len = LCS_LENGTH(X, Y, b);
	printf("����������еĳ���Ϊ��%d\n", len);
	
	printf("�����������Ϊ��");
	PRINT_LCS(b, X, length1, length2);
	cout << endl;
	
	return 0;
}
