//#this_is_main.cpp
#include<iostream>
using namespace std;
struct Node
{
	int number_int;
	Node* next;
};
void ShowNode(Node* head);	//遍历链表
void CreatList(Node*& head)	//创建链表
{
	Node* p, *s;
	s = new Node;
	p = new Node;
	cin >> s->number_int;
	while (s->number_int != 0)
	{
		if (head == NULL)
		{
			head = s;
			cout << head << endl;
		}
		else
		{
			p->next = s;
			p = s;
			s = new Node;
			cin >> s->number_int;
		}
	}
	p->next = NULL;
	delete s, p;
}

void ShowNode(Node* head)
{
	cout << "now the items of node are: \n";
	while (head)
	{
		cout << head->number_int << "\t";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node* head = NULL;
	CreatList(head);
	ShowNode(head);
	cout << head << endl;
}
