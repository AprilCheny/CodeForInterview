#include <iostream>
#include <vector>

using namespace std;

/*
 *说明：不使用额外的存储空间反转单链表（可使用局部变量）（单链表原地逆序）
 *举例：输入单链表1->2->3->4->5->null，输出单链表5->4->3->2->1->null
 */

typedef struct Node
{
	int val;
	Node* next;
};

Node* reverse(Node* head)
{
	Node* node = nullptr;
	while (head)
	{
		Node* next = head->next;
		head->next = node;
		node = head;
		head = next;
	}

	return node;
}

int main()
{
	const int num = 5;
	Node* head = new Node;
	head->val = 2;
	head->next = nullptr;
	Node *temp = head;
	for (int i = 1; i < num; i++)
	{
		Node *curr = new Node;
		temp->next = curr;
		curr->val = i + 2;
		curr->next = nullptr;
		temp = temp->next;
	}

	head = reverse(head);
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}