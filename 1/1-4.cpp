// ���ܣ����һ�������㷨����������⣺
//       ����������Ԫ�ػ�����ͬ����������������飬Ԫ�ظ����ֱ�Ϊm��n���ҿ����ڵ�λʱ���ڷ������ǵĵ�i��Ԫ�أ�
//       �����һ��ʱ�����ΪO(lgm+lgn)���㷨�ҳ���������������Ԫ���еĵ�k���Ԫ��
//NOT WORKING!δ���

#include <iostream>
#include <vector>

#define MAXSIZE 100

using namespace std;

vector<int> divide(int m[], int m_head, int m_tail, int n[], int n_head, int n_tail)
{
	vector<int> position;

	if (m_head < m_tail&&n_head < n_tail)  //m��n�������ֹһ��Ԫ��
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

	else if (m_head == m_tail)  //m����ֻʣһ��Ԫ�أ�n���鲻ֹһ��Ԫ��
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

	else if (n_head == n_tail)  //m���鲻ֹһ��Ԫ�أ�n����ֻʣһ��Ԫ��
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

	else if (m_head == m_tail&&n_head == n_tail)  //m��n���鶼ֻʣһ��Ԫ��
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
	
	if (position[0] == 0)  //A[mh - 1] < B[0]��A��Ԫ��ȫ��B��Ԫ��С
	{
		if (k > nh) return m[mh - (k - nh) + 1];
		else return n[nh - k + 1];
	}
	if (position[1] == 0)  //B[n - 1] < A[0]��B��Ԫ��ȫ��A��Ԫ��С
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
	cout << "�����������������A��" << endl;
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
	cout << "����A��" << endl;
	for (int j = 1; j <= A_size; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;

	int B[MAXSIZE] = {0};
	int B_size, B_end;
	cout << "�����������������B��" << endl;
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
	cout << "����B��" << endl;
	for (int j = 1; j <= B_size; j++)
	{
		cout << B[j] << ' ';
	}
	cout << endl << endl;

	int k;
	cout << "������kֵ��" << endl;
	cin >> k;

	int num = find_k(A, 1, A_end, B, 1, B_end, k);
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
