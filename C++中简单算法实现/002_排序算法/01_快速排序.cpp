#include<iostream>
using namespace std;
int *a, n;
void QuickSort(int left, int right) //记住：第一个参数：数组第一个数的下标，第二个参数：数组最后一个数的下标
{
	if (left > right)
		return;
	int i(left), j(right), temp(a[left]), m;  //temp存储基数
	while (i != j)
	{
		while (temp <= a[j] && i < j) //一定要从右边先开始，避免 i 和 j 相等的时候，所指的数大于基数
			j--;
		while (temp >= a[i] && i < j)
			i++;
		if (i < j)  //避免出现i<j 的情况
		{
			m = a[i];
			a[i] = a[j];
			a[j] = m;
		}
	}
  //当两个下标相等的时候，将下标所指的数和基数兑换
	a[left] = a[i]; 
	a[i] = temp;
	QuickSort(i + 1, right);    //采用递归的方法
	QuickSort(left, i - 1 );
	return;
}

int main()
{
	a = new int[10];
	int arrar[] = { 1,9,2,2,1,1,0,7,1,2,2,1,7 };
	for (int i = 0; i < 10; i++)
		a[i ] = arrar[i];
	n = 10;
	QuickSort(0, n - 1 );
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
}
