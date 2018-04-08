// ���ܣ�ʵ�ֿ�������
// �㷨����������

#include "stdafx.h"
#include <iostream>

#define MAXSIZE 100

using namespace std;

int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= x)
		{
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;
	return i + 1;
}

void quick_sort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}

int main()
{
	int i, j;
	int A[MAXSIZE] = { 0 };
	cout << "����������S��" << endl;
	for (i = 1; A[i - 1] != 999; i++)  //�����1��ʼ��Ԫ�ظ���Ϊi-2,999��Ϊ����������ֹ��
	{
		cin >> A[i];
	}
	cout << "��ʼ���������Ϊ��" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl;

	quick_sort(A, 1, i - 2);

	cout << "��������������Ϊ��" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl;

    return 0;
}

