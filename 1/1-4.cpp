// ���ܣ����һ�������㷨����������⣺
//       ����������Ԫ�ػ�����ͬ����������������飬Ԫ�ظ����ֱ�Ϊm��n���ҿ����ڵ�λʱ���ڷ������ǵĵ�i��Ԫ�أ�
//       �����һ��ʱ�����ΪO(lgm+lgn)���㷨�ҳ���������������Ԫ���еĵ�k���Ԫ��
// NOT WORKING!δ���

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
	vector<int> pos = divide(A, ml, mh, B, nl, nh);
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
	for (int i = 0;; i++)
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
	for (int i = 0; B[i - 1]; i++)
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

	//int numK = 999;
	//numK = find_K(A, A_size, B, B_size, k);
	//if(numK!=999) cout << "��k���Ԫ��Ϊ��" << numK << endl;

	int num = find_k(A, 0, A_end, B, 0, B_end, k);
	cout << "��k���Ԫ��Ϊ��" << num << endl;

	return 0;
}

/*
for (i = 1;; i++)
{
cin >> A[i - 1];
if (cin.get() == '\n') break;
}
*/

/*
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
else //if (n[n_middle] > m[m_middle + 1])
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
else //if (n[n_middle] > m[m_tail])
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
else //if (m[m_middle] > n[n_tail])
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
else //if (m[m_tail] > n[n_tail])
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

if (position[0] == 0)  //n[nh] < m[1]��B��Ԫ��ȫ��A��Ԫ��С
{
if (k > mh) return n[nh - (k - mh) + 1];
else return m[mh - k + 1];
}
if (position[1] == 0)  //m[mh] < n[1]��A��Ԫ��ȫ��B��Ԫ��С
{
if (k > nh) return m[mh - (k - nh) + 1];
else return n[nh - k + 1];
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
int A[MAXSIZE] = { 0 };
int A_size, A_end;
cout << "�����������������A��" << endl;
for (int i = 1;; i++)
{
cin >> A[i];
if (cin.get() == '\n')
{
A_size = i;  //m
A_end = i;  //m_tail
break;
}
}
cout << "����A��" << endl;
for (int j = 1; j <= A_size; j++)
{
cout << A[j] << ' ';
}
cout << endl << endl;

int B[MAXSIZE] = { 0 };
int B_size, B_end;
cout << "�����������������B��" << endl;
for (int i = 1;; i++)
{
cin >> B[i];
if (cin.get() == '\n')
{
B_size = i;  //n
B_end = i;  //n_tail
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
cout << "��" << k << "���Ԫ��Ϊ��" << num << endl;

return 0;
}
*/
