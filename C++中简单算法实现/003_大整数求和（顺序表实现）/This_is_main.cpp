//大数值求和顺序表实现
#include<iostream>
#include"SeqList.h"
using namespace std;


int main()
{
	int a[] = { 1,2,3,4,5,6,7,8 };
	int b[] = { 1,2,3,4,5,6,7,8 };
	SeqList A(a, 8), B(b, 8), C;
	C = Add(A, B);
	A.PrintList(); cout << " + ";
	B.PrintList(); cout << " = ";
	C.PrintList();
}
