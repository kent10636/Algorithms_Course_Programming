// ���ܣ����һ�������㷨����������⣺
//       ����������Ԫ�ػ�����ͬ����������������飬Ԫ�ظ����ֱ�Ϊm��n���ҿ����ڵ�λʱ���ڷ������ǵĵ�i��Ԫ�أ�
//       �����һ��ʱ�����ΪO(lgm+lgn)���㷨�ҳ���������������Ԫ���еĵ�k���Ԫ��
// NOT WORKING!δ���

#include "stdafx.h"
#include <iostream>
#include <vector>

#define MAXSIZE 100

using namespace std;

vector<int> divide(int A[], int m_low, int m_high, int B[], int n_low, int n_high)
{
	vector<int> pos;

	if (m_low < m_high&&n_low < n_high)  //A��B�������ֹһ��Ԫ��
	{
		int m_middle = (m_low + m_high + 1) / 2;
		int n_middle = (n_low + n_high + 1) / 2;
		if (A[m_middle - 1] < B[n_middle] && B[n_middle - 1] < A[m_middle])
		{
			pos.push_back(m_middle);
			pos.push_back(n_middle);
			return pos;
		}
		else if (A[m_middle - 1] > B[n_middle])
			return divide(A, m_low, m_middle - 1, B, n_middle, n_high);
		else if (B[n_middle - 1] > A[m_middle])
			return divide(A, m_middle, m_high, B, n_low, n_middle - 1);
	}

	else if (m_low == m_high)  //A����ֻʣһ��Ԫ�أ�B���鲻ֹһ��Ԫ��
	{
		int n_middle = (n_low + n_high + 1) / 2;
		if (A[m_high] < B[n_middle] && B[n_middle - 1] < A[m_high])
		{
			pos.push_back(m_high);
			pos.push_back(n_high);
			return pos;
		}
		else if (A[m_high] > B[n_middle])
			return divide(A, m_low, m_high, B, n_middle, n_high);
		else if (B[n_middle - 1] > A[m_high])
			return divide(A, m_low, m_high, B, n_low, n_middle - 1);
	}

	else if (n_low == n_high)  //A���鲻ֹһ��Ԫ�أ�B����ֻʣһ��Ԫ��
	{
		
		int m_middle = (m_low + m_high + 1) / 2;
		if (B[n_high] < A[m_middle] && A[m_middle - 1] < B[n_high])
		{
			pos.push_back(m_high);
			pos.push_back(n_high);
			return pos;
		}
		else if (B[n_high] > A[m_middle])
			return divide(A, m_middle, m_high, B, n_low, n_high);
		else if (A[m_middle - 1] > B[n_high])
			return divide(A, m_low, m_middle - 1, B, n_low, n_high);
	}

	else if (m_low == m_high&&n_low == n_high)  //A��B���鶼ֻʣһ��Ԫ��
	{
		if (A[m_high] < B[n_high])
		{
			pos.push_back(m_high + 1);
			pos.push_back(n_high);
			return pos;
		}
		else if (A[m_high] > B[n_high])
		{
			pos.push_back(m_high);
			pos.push_back(n_high + 1);
			return pos;
		}
	}
}

int find_K(int A[], int m, int B[], int n, int k)
{
	if (A[m - 1] < B[0])  //A��Ԫ��ȫ��B��Ԫ��С
	{
		if (k > n) return A[m - (k - n)];
		else return B[n - k];
	}
	if (B[n - 1] < A[0])  //B��Ԫ��ȫ��A��Ԫ��С
	{
		if (k > m) return B[n - (k - m)];
		else return A[m - k];
	}
}

int find_k(int A[], int ml, int mh, int B[], int nl, int nh, int k)
{	
	vector<int> pos = divide(A, ml, mh, B, ml, mh);
	int right_count = (mh + 1 - pos[0]) + (nh + 1 - pos[1]);

	if (k == right_count)
	{
		return A[pos[0]] < B[pos[1]] ? A[pos[0]] : B[pos[1]];
	}
	else if (k < right_count)
	{
		return find_k(A, pos[0], mh, B, pos[1], nh, k);
	}
	else
	{
		return find_k(A, ml, pos[0] - 1, B, nl, pos[1] - 1, k);
	}
}

int main()
{
	int A[MAXSIZE];
	int A_size, A_end;
	cout << "�����������������A��" << endl;
	for (int i=0;;i++)
	{
		cin >> A[i];
		if (A[i] == 999)
		{
			A_size = i;  //m
			A_end = i - 1;
			break;
		}
	}
	cout << "����A��" << endl;
	for (int j = 0; j < A_size; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;

	int B[MAXSIZE];
	int B_size, B_end;
	cout << "�����������������B��" << endl;
	for (int i=0;B[i-1];i++)
	{
		cin >> B[i];
		if (B[i] == 999)
		{
			B_size = i;  //n
			B_end = i - 1;
			break;
		}
	}
	cout << "����B��" << endl;
	for (int j = 0; j < B_size; j++)
	{
		cout << B[j] << ' ';
	}
	cout << endl << endl;

	int k;
	cout << "������kֵ��" << endl;
	cin >> k;
	
	int numK = 999;
	numK = find_K(A, A_size, B, B_size, k);
	if(numK!=999) cout << "��k���Ԫ��Ϊ��" << numK << endl;

	int num = find_k(A, 0, A_end, B, 0, B_end, k);
	cout << "��k���Ԫ��Ϊ��" << num << endl;

    return 0;
}

/*
for (i = 1;; i++) 
{
	if (cin.get() == '\n') break;
	cin >> A[i - 1];
}
*/