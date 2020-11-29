#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};

//建立带头节点的链表
void Built(int a[], Node* first, int n) {
	Node* p = first;
	for (int i = 0; i < n; i++) {
		Node* s = new Node;
		s->data = a[i];
		p->next = s;
		p = s;
	}
	p->next = NULL;
}

//遍历输出表
void PrintMethod(Node* first) {
	Node* p = first->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}


/*运用的思想：
  1、首先创建一个含头结点的单链表，头节点用first指向;
  2、创建两个指针s和p，s指向p的前面，即：s->next=p;
  3、当p指向的结点元素的值为偶数时，p和s同时往后移;
  4、当p指向的结点元素的值为奇数，且s!=first的时候，s保持不变，将p指向的结点插入到first指向的结点的后面，然后再让p指向s的后面，即：p=s->next。
  5、当p指向的结点元素的值为奇数，且s==first的时候，p和s同时往后移；
  6、循环终止的条件为 p!=NULL
*/
void revise(Node* first) {
	Node* p = first->next;
	Node* s = first;
	while (p != NULL) {
		if (p->data % 2 == 1 && s != first) {
			s->next = p->next;
			p->next = first->next;
			first->next = p;
			p = s->next;
		}
		else {
			s = p;
			p = p->next;
		}
	}
}

int main() {
	int b[] = { 0,1,9,2,2,1,0,7,2 ,1 };
	Node* first = new Node;
	Built(b, first, sizeof(b) / sizeof(int));
	PrintMethod(first);
	revise(first);
	PrintMethod(first);
}

