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

/*
 *递归版本
 *举例：假设输入1->2->3->4->5->null，则首次调整为4->5->3->1->2->null，然后再递归调整4->5和1->2
 */

Node* reverse2(Node* head, int num)
{
	int loop_count = num >> 1;
	if (num <= 1)
		return head;
	if (num == 2)
	{
		swap(head->val, head->next->val);
		return head;
	}

	Node* n1 = head;
	Node* n2 = head;
	int count1 = (num % 2 == 0 ? loop_count - 1 : loop_count);
	while (count1 >= 0)
	{
		n2 = n2->next;
		count1--;
	}

	Node* n3 = n2;
	int count2 = loop_count;
	while (count2 > 0)
	{
		swap(n1->val, n3->val);
		n1 = n1->next;
		n3 = n3->next;
		count2--;
	}

	reverse2(head, num >> 1);
	reverse2(n2, num >> 1);

	return head;
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