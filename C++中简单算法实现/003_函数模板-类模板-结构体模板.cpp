#include<iostream>
using namespace std;

//结构体模板
template <class T>
struct Node
{
	T date;
	Node* next;
};

//模板函数
template <typename T>
void methodBuilt(Node<T>* first, T a[], int n)//创建一个链表，包含元素为a[]数组
{
	//first = new Node<T>;这是错误的写法，函数接受first这个指针的时候，指针已经指向了一个结点，不可以再为这个指针创立新的结点。
	Node<T>* p = first;
	for (int i = 0; i < n; i++)
	{
		Node<T>* s = new Node<T>;
		s->date = a[i];
		p->next = s;
		p = s;
	}
	p->next = NULL;
}

//模板函数
template <typename T>	//对链表的打印输出
void methodPrint(Node<T>* first)
{
	Node<T>* p = first->next;
	while (p != NULL)
	{
		cout << p->date << " ";
		p = p->next;
	}
}

//模板类
template <class T>
class ListNode
{
private:
	Node<T>* first;
public:
	ListNode(T a[], int n);
	void Print();
};

template <class T>ListNode<T>::ListNode(T a[],int n)
{
	first = new Node<T>;
	Node<T>* p = first;
	for (int i = 0; i < n; i++)
	{
		Node<T>* s = new Node<T>;
		s->date = a[i];
		p->next = s;
		p = s;
	}
	p->next = NULL;
}

template <class T>void ListNode<T>::Print()
{
	Node<T>* p = first->next;
	while (p!=NULL)
	{
		cout << p->date << " ";
		p = p->next;
	}
}

int main()
{
//再main函数中，对模板函数-模板类-结构体模板使用前，一定要进行实例化！！实例化的操作就是<实例化类型（int、char等）>
	int a[] = { 6,7,6,4,3,1,7,8,9 };
	ListNode<int> li(a, 9);
	li.Print();
	cout << endl;
	char b[] = { 'a','b','d','h','q','m' };
	ListNode<char> li2(b, 6);
	li2.Print();
	cout << endl;
	Node<int>* test = new Node<int>;  //要进行初始化后才可以传递给函数！
	methodBuilt(test, a, 9);
	methodPrint(test);
	cout << endl;
	Node<char>* test2 = new Node<char>;
	methodBuilt(test2, b, 6);
	methodPrint(test2);
}
