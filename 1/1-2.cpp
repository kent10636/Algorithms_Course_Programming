// ���ܣ�ʵ�����ȶ��У���ӡ���Ԫ�ء�ȡ�����Ԫ�ء�����һ��Ԫ��ֵ������һ����Ԫ��
// �㷨��max_heapifyά�ִ󶥶ѵ����ʣ�build_max_heap�����󶥶ѣ�heapsort�����򣨴�С���󣩣�
//       heap_maximum��max_extract_max��heap_increase_key��max_heap_insert

#include "stdafx.h"
#include <iostream>
#include <limits>

#define MAXSIZE 100

using namespace std;

int PARENT(int i) 
{
	return i / 2;
}
int LEFT(int i) 
{
	return 2 * i;
}
int RIGHT(int i) 
{
	return 2 * i + 1;
}

void max_heapify(int A[], int i, int heapsize)
{
	int largest;
	int l = LEFT(i);
	int r = RIGHT(i);
	if (l <= heapsize&&A[l] > A[i])
	{
		largest = l;
	}
	else 
		largest = i;
	if (r <= heapsize&&A[r] > A[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		max_heapify(A, largest, heapsize);
	}
}

void build_max_heap(int A[], int heapsize)
{
	//cout << heapsize <<endl;
	for (int i = heapsize / 2; i >= 1; i--)
	{
		max_heapify(A, i, heapsize);
	}
}

void heapsort(int A[], int arraysize)  //�����򣨴�С����
{
	int heapsize = arraysize;
	build_max_heap(A, arraysize);
	for (int i = arraysize; i >= 2; i--)
	{
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		heapsize--;
		max_heapify(A, 1, heapsize);
	}
}

int heap_maximum(int A[])  //��ӡ���Ԫ��
{
	return A[1];
}

int max_extract_max(int A[], int heapsize)  //ȡ�����Ԫ��
{
	if (heapsize < 1)
	{
		cout << "heap underflow" << endl;
		return false;
	}
	int max = A[1];
	A[1] = A[heapsize];
	heapsize--;
	max_heapify(A, 1, heapsize);
	return max;
}

void heap_increase_key(int A[], int i, int key)  //����һ��Ԫ��ֵ
{
	if (key < A[i])
	{
		cout << "new key is smaller than current key" << endl;
		return;
	}
	A[i] = key;
	while (i > 1 && A[PARENT(i)] < A[i])
	{
		int temp = A[i];
		A[i] = A[PARENT(i)];
		A[PARENT(i)] = temp;
		i = PARENT(i);
	}
}

void max_heap_insert(int A[], int key, int heapsize)  //����һ����Ԫ��
{
	//int arraysize = sizeof(A) / sizeof(int);
	//int heapsize = arraysize;
	heapsize++;
	A[heapsize] = INT_MIN;  //�����ͷ�ļ�limits
	heap_increase_key(A, heapsize, key);
}

int main()
{
	int i, j;
	int A[MAXSIZE];
	cout << "����������A��" << endl;
	for (i = 1; A[i - 1] != 999; i++)  //�����1��ʼ��Ԫ�ظ���Ϊi-2��999��Ϊ����������ֹ��
	{
		cin >> A[i];
	}
	cout << endl;
	
	int arraysize = i - 2;
	//cout << arraysize << endl;

	build_max_heap(A, arraysize);  //�����󶥶�
	cout << "�����󶥶Ѻ������Ϊ��" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;
	
	/*
	heapsort(A, arraysize);  //������
	cout << "������������Ϊ��" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;
	*/

	cout << "���Ԫ��Ϊ��" << heap_maximum(A) << endl << endl;  //��ӡ���Ԫ��

	/*
	cout << "ȡ�����Ԫ��Ϊ��" << max_extract_max(A, arraysize) << endl;  //ȡ�����Ԫ��
	cout << "ȡ�����Ԫ�غ�Ĵ󶥶�����Ϊ��" << endl;
	for (j = 1; j < i - 2; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;
	*/
	
	cout << "����������󶥶��еڼ���Ԫ�ص�ֵ��";
	int position;
	cin >> position;
	cout << "������������Ԫ��ֵ��";
	int key;
	cin >> key;
	heap_increase_key(A, position, key);  //����һ��Ԫ��ֵ
	cout << "����һ��Ԫ��ֵ��Ĵ󶥶�����Ϊ��" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;
	
	cout << "������һ��Ҫ�����Ԫ�أ�";
	int insert;
	cin >> insert;
	max_heap_insert(A, insert, arraysize);  //����һ����Ԫ��
	cout << "����һ��Ԫ��ֵ��Ĵ󶥶�����Ϊ��" << endl;
	for (j = 1; j < i ; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;

    return 0;
}