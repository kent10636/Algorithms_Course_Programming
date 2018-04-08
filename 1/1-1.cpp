// ���ܣ�ʵ��һ��ʱ�����Ϊnlgn���㷨����������S������x���ж��������Ƿ��������Ԫ��֮�͵���x
// �㷨���鲢���򣨵ݹ飩�����ֲ���

#include "stdafx.h"
#include <iostream>

#define MAXSIZE 100

using namespace std;

void merge(int A[], int p, int q, int r)  //ʱ�����Ϊn^2
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

void merge_sort(int A[], int p, int r)  //ʱ�����Ϊnlgn
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
			cout << "�����д�������֮�͵���x��" << S[i] << "+" << S[j] << "=" << x << endl;
			return true;
		}
		else if (S[i] + S[j] < x)
		{
			i++;
		}
		else
			j--;
	}
	cout << "�����в���������֮�͵���x" << endl;
	return false;
}

int main()
{
	int i, j;
	int A[MAXSIZE] = {0};
	cout << "����������S��" << endl;
	for (i = 1; A[i-1] != 999; i++)  //�����1��ʼ��Ԫ�ظ���Ϊi-2��999��Ϊ����������ֹ��
	{
		cin >> A[i];
	}
	cout << "��ʼ���������Ϊ��" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl;

	merge_sort(A, 1, i-2);

	cout << "�鲢����������Ϊ��" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl;

	int x;
	cout << "������Ҫ���ҵ�xֵ��" << endl;
	cin >> x;
	
	find_twosum(A, i - 2, x);

    return 0;
}