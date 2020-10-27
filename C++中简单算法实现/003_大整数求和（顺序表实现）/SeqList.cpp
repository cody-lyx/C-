#include"SeqList.h"
#include<iostream>
using namespace std;

SeqList::SeqList(int a[], int n)
{
	if (n > MaxSize)throw"参数非法";
	for (int i = 0; i < n; i++)
		date[i] = a[i];
	length = n;
}

int SeqList::Get(int i)
{
	if (i<1 || i>length)throw"查找位置非法";
	else return date[i - 1];
}

//顺序表查找方法
int SeqList::Locate(int x)
{
	for (int i = 0; i < length; i++)
		if (date[i] == x)return i + 1;
	return 0;
}

//顺序表插入方法
void SeqList::Insert(int i, int x)
{
	if (length >= MaxSize)throw"上溢";
	if (i<1 || i>length + 1)throw"位置";
	for (int j = length; j >= i; j--)
		date[j] = date[j - 1];
	date[i - 1] = x;
	length++;
}

//顺序表删除方法
int SeqList::Delete(int i)
{
	if (length == 0)throw"下溢";
	if (i<1 || i>length)throw"位置";
	int x = date[i - 1];
	for (int j = i; j < length; j++)
		date[j - 1] = date[j];
	length--;
	return x;
}

//顺序表遍历方法
void SeqList::PrintList()
{
	for (int i = length - 1; i >= 0; i--)
		cout << date[i];
}

//两个大整数相加
SeqList Add(SeqList A, SeqList B)
{
	int flag(0), i(0);
	SeqList C;
	int n = A.Length(), m = B.Length();
	while (i < n && i < m)
	{
		C.date[i] = (A.date[i] + B.date[i] + flag) % 10;
		flag = (A.date[i] + B.date[i] + flag) / 10;
		i++;
	}
	for (; i < n; i++)
	{
		C.date[i] = (A.date[i] + flag) % 10;
		flag = (A.date[i] + flag) / 10;
	}
	for (; i < m; i++)
	{
		C.date[i] = (B.date[i] + flag) % 10;
		flag = (B.date[i] + flag) / 10;
	}
	C.length = max(m, n) + flag;
	if (flag == 1)
		C.date[C.length - 1] = 1;
	return C;
}
