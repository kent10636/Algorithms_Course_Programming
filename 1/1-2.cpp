// 功能：实现优先队列，打印最大元素、取出最大元素、增大一个元素值、插入一个新元素
// 算法：max_heapify维持大顶堆的性质，build_max_heap建立大顶堆，heapsort堆排序（从小到大），
//       heap_maximum，max_extract_max，heap_increase_key，max_heap_insert

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

void heapsort(int A[], int arraysize)  //堆排序（从小到大）
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

int heap_maximum(int A[])  //打印最大元素
{
	return A[1];
}

int max_extract_max(int A[], int heapsize)  //取出最大元素
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

void heap_increase_key(int A[], int i, int key)  //增大一个元素值
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

void max_heap_insert(int A[], int key, int heapsize)  //插入一个新元素
{
	//int arraysize = sizeof(A) / sizeof(int);
	//int heapsize = arraysize;
	heapsize++;
	A[heapsize] = INT_MIN;  //负无穷，头文件limits
	heap_increase_key(A, heapsize, key);
}

int main()
{
	int i, j;
	int A[MAXSIZE];
	cout << "请输入数组A：" << endl;
	for (i = 1; A[i - 1] != 999; i++)  //数组从1开始，元素个数为i-2，999作为数组输入终止符
	{
		cin >> A[i];
	}
	cout << endl;
	
	int arraysize = i - 2;
	//cout << arraysize << endl;

	build_max_heap(A, arraysize);  //建立大顶堆
	cout << "建立大顶堆后的数组为：" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;
	
	/*
	heapsort(A, arraysize);  //堆排序
	cout << "堆排序后的数组为：" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;
	*/

	cout << "最大元素为：" << heap_maximum(A) << endl << endl;  //打印最大元素

	/*
	cout << "取出最大元素为：" << max_extract_max(A, arraysize) << endl;  //取出最大元素
	cout << "取出最大元素后的大顶堆数组为：" << endl;
	for (j = 1; j < i - 2; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;
	*/
	
	cout << "请输入增大大顶堆中第几个元素的值：";
	int position;
	cin >> position;
	cout << "请输入增大后的元素值：";
	int key;
	cin >> key;
	heap_increase_key(A, position, key);  //增大一个元素值
	cout << "增大一个元素值后的大顶堆数组为：" << endl;
	for (j = 1; j < i - 1; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;
	
	cout << "请输入一个要插入的元素：";
	int insert;
	cin >> insert;
	max_heap_insert(A, insert, arraysize);  //插入一个新元素
	cout << "增大一个元素值后的大顶堆数组为：" << endl;
	for (j = 1; j < i ; j++)
	{
		cout << A[j] << ' ';
	}
	cout << endl << endl;

    return 0;
}
