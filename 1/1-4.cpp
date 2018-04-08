// 功能：提出一个分治算法解决以下问题：
//       有两个所有元素互不相同的已排序的整数数组，元素个数分别为m和n，且可以在单位时间内访问它们的第i个元素，
//       请给出一个时间代价为O(lgm+lgn)的算法找出这两个数组所有元素中的第k大的元素
//NOT WORKING!未完成

#include <iostream>
#include <vector>

#define MAXSIZE 100

using namespace std;

vector<int> divide(int m[], int m_head, int m_tail, int n[], int n_head, int n_tail)
{
	vector<int> position;

	if (m_head < m_tail&&n_head < n_tail)  //m、n数组均不止一个元素
	{
		int m_middle = (m_head + m_tail) / 2;
		int n_middle = (n_head + n_tail) / 2;
		if (m[m_middle] < n[n_middle + 1] && n[n_middle] < m[m_middle + 1])
		{
			position.push_back(m_middle);
			position.push_back(n_middle);
			return position;
		}
		else if (m[m_middle] > n[n_middle + 1])
			return divide(m, m_head, m_middle, n, n_middle + 1, n_tail);
		else if (n[n_middle] > m[m_middle + 1])
			return divide(m, m_middle + 1, m_tail, n, n_head, n_middle);
	}

	else if (m_head == m_tail)  //m数组只剩一个元素，n数组不止一个元素
	{
		int n_middle = (n_head + n_tail) / 2;
		if (m[m_tail] < n[n_middle + 1] && n[n_middle] < m[m_tail])
		{
			position.push_back(m_tail);
			position.push_back(n_tail);
			return position;
		}
		else if (m[m_tail] > n[n_middle + 1])
			return divide(m, m_head, m_tail, n, n_middle + 1, n_tail);
		else if (n[n_middle] > m[m_tail])
			return divide(m, m_head, m_tail, n, n_head, n_middle);
	}

	else if (n_head == n_tail)  //m数组不止一个元素，n数组只剩一个元素
	{
		
		int m_middle = (m_head + m_tail) / 2;
		if (n[n_tail] < m[m_middle + 1] && m[m_middle] < n[n_tail])
		{
			position.push_back(m_tail);
			position.push_back(n_tail);
			return position;
		}
		else if (n[n_tail] > m[m_middle + 1])
			return divide(m, m_middle + 1, m_tail, n, n_head, n_tail);
		else if (m[m_middle] > n[n_tail])
			return divide(m, m_head, m_middle, n, n_head, n_tail);
	}

	else if (m_head == m_tail&&n_head == n_tail)  //m、n数组都只剩一个元素
	{
		if (m[m_tail] < n[n_tail])
		{
			position.push_back(m_tail);
			position.push_back(n_tail - 1);
			return position;
		}
		else if (m[m_tail] > n[n_tail])
		{
			position.push_back(m_tail - 1);
			position.push_back(n_tail);
			return position;
		}
	}
}

int find_k(int m[], int ml, int mh, int n[], int nl, int nh, int k)
{	
	vector<int> position = divide(m, ml, mh, n, nl, nh);
	
	if (position[0] == 0)  //A[mh - 1] < B[0]，A中元素全比B中元素小
	{
		if (k > nh) return m[mh - (k - nh) + 1];
		else return n[nh - k + 1];
	}
	if (position[1] == 0)  //B[n - 1] < A[0]，B中元素全比A中元素小
	{
		if (k > mh) return n[nh - (k - mh) + 1];
		else return m[mh - k + 1];
	}
	
	int right_count = (mh - position[0]) + (nh - position[1]);

	if (k == right_count)
	{
		return m[position[0] + 1] < n[position[1] + 1] ? m[position[0] + 1] : n[position[1] + 1];
	}
	else if (k < right_count)
	{
		return find_k(m, position[0] + 1, mh, n, position[1] + 1, nh, k);
	}
	else
	{
		return find_k(m, ml, position[0], n, nl, position[1], k - right_count);
	}
}

int main()
{
	int A[MAXSIZE] = {0};
	int A_size, A_end;
	cout << "输入有序的整数数组A：" << endl;
	for (int i=1;;i++)
	{
		cin >> A[i];
		if (A[i] == 999)
		{
			A_size = i - 1;  //m
			A_end = i - 1;  //mh
			break;
		}
	}
	cout << "数组A：" << endl;
	for (int j = 1; j <= A_size; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;

	int B[MAXSIZE] = {0};
	int B_size, B_end;
	cout << "输入有序的整数数组B：" << endl;
	for (int i=1;;i++)
	{
		cin >> B[i];
		if (B[i] == 999)
		{
			B_size = i - 1;  //n
			B_end = i - 1;  //nh
			break;
		}
	}
	cout << "数组B：" << endl;
	for (int j = 1; j <= B_size; j++)
	{
		cout << B[j] << ' ';
	}
	cout << endl << endl;

	int k;
	cout << "请输入k值：" << endl;
	cin >> k;

	int num = find_k(A, 1, A_end, B, 1, B_end, k);
	cout << "第k大的元素为：" << num << endl;

    return 0;
}

/*
for (i = 1;; i++) 
{
	if (cin.get() == '\n') break;
	cin >> A[i - 1];
}
*/
