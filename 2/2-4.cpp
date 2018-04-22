// 功能：计算最大子数组和
// 算法：动态规划DP

#include <iostream>

using namespace std;

int DPMaximumSubarray(int n, int* a, int* b, int& besti, int& bestj)
{
	int sum = a[1];
	b[1] = a[1];
	for (int j=2; j <= n; ++j)
	{
		if (b[j - 1] > 0)
		{
			b[j] = b[j - 1] + a[j];
		}
		else
		{
			b[j] = a[j];
			besti = j;
		}
		if (b[j] > sum)
		{
			sum = b[j];
			bestj = j;
		}
	}
	return sum;
}

int main()
{
	int a[] = { 0,-2,11,-4,13,-5,-2 };  //a[0]存放的是数字0，原数组从a[1]开始，“-2,11,-4,13,-5,-2”
	int len = sizeof(a) / sizeof(int) - 1;
	//cout << len << endl;
	
	cout << "输入的数组为：";
	for (int i=1;i<=len;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	
	int* b = new int[len];

	int besti = 0, bestj = 0;
	int max_sum = DPMaximumSubarray(len, a, b, besti, bestj);
	cout << "最大子数组和为：" << max_sum << endl;
	cout << "子数组下界：" << besti << "    子数组上界：" << bestj << endl;

    return 0;
}
