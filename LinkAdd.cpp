#include <iostream>

using namespace std;

/*
 *说明：有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位排在链表的首部。编写函数对这两个整数求和，并用链表形式返回结果。
 *举例：输入链表{1,2,3}和{3,2,1}，输出链表{4,4,4}
 */

typedef struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Plus {
public:
	ListNode* plusAB(ListNode* a, ListNode* b) {
		// write code here
		if ((a == NULL) && (b == NULL))
			return a;

		int sa = 0;
		int sb = 0;
		ListNode *pa = a;
		ListNode *pb = b;
		while (pa != NULL)
		{
			sa++;
			pa = pa->next;
		}
		while (pb != NULL)
		{
			sb++;
			pb = pb->next;
		}
		pa = a;
		pb = b;

		int res = 0;
		if (sa == sb)
		{
			int index = 0;
			while (pa != NULL)
			{
				res += (pa->val + pb->val) * (int)pow(10, index);
				pa = pa->next;
				pb = pb->next;
				index++;
			}
			pa = a;
			if (res > (int)pow(10, sa))
			{
				ListNode *last = (ListNode *)malloc(sizeof(ListNode));
				while (pa->next != NULL)
				{
					pa->val = res % 10;
					res /= 10;
					pa = pa->next;
				}
				pa->next = last;
				pa->val = res % 10;
				res /= 10;
				pa->next->val = res;
			}
			else
			{
				while (pa != NULL)
				{
					pa->val = res % 10;
					res /= 10;
					pa = pa->next;
				}
			}

			return a;
		}
		else if (sa < sb)
		{
			int index = 0;
			int diff = sa;
			while (pb != NULL)
			{
				if (diff > 0)
				{
					res += (pb->val + pa->val) * (int)pow(10, index);
					pb = pb->next;
					pa = pa->next;
					diff--;
				}
				else
				{
					res += pb->val * (int)pow(10, index);
					pb = pb->next;
				}
				index++;
			}
			pb = b;
			if (res > (int)pow(10, sb))
			{
				ListNode *last = (ListNode *)malloc(sizeof(ListNode));
				while (pb->next != NULL)
				{
					pb->val = res % 10;
					res /= 10;
					pb = pb->next;
				}
				pb->next = last;
				pb->val = res % 10;
				res /= 10;
				pb->next->val = res;
			}
			else
			{
				while (pb != NULL)
				{
					pb->val = res % 10;
					res /= 10;
					pb = pb->next;
				}
			}

			return b;
		}
		else
		{
			int index = 0;
			int diff = sb;
			while (pa != NULL)
			{
				if (diff > 0)
				{
					res += (pa->val + pb->val) * (int)pow(10, index);
					pa = pa->next;
					pb = pb->next;
					diff--;
				}
				else
				{
					res += pa->val * (int)pow(10, index);
					pa = pa->next;
				}
				index++;
			}
			pa = a;
			if (res > (int)pow(10, sa))
			{
				ListNode *last = (ListNode *)malloc(sizeof(ListNode));
				while (pa->next != NULL)
				{
					pa->val = res % 10;
					res /= 10;
					pa = pa->next;
				}
				pa->next = last;
				pa->val = res % 10;
				res /= 10;
				pa->next->val = res;
			}
			else
			{
				while (pa != NULL)
				{
					pa->val = res % 10;
					res /= 10;
					pa = pa->next;
				}
			}

			return a;
		}
	}
};

int main()
{

	ListNode *a[3] = {NULL, NULL, NULL};
	for (int i = 0; i < 3; i++)
		a[i] = (ListNode *)malloc(sizeof(ListNode));
	ListNode *b[3] = { NULL, NULL, NULL };
	for (int i = 0; i < 3; i++)
		b[i] = (ListNode *)malloc(sizeof(ListNode));
	ListNode *c[4] = { NULL, NULL, NULL, NULL };
	for (int i = 0; i < 4; i++)
		c[i] = (ListNode *)malloc(sizeof(ListNode));

	int i = 0;
	for (; i < 2; i++)
	{
		a[i]->val = (i + 1) * 2;
		a[i]->next = a[i + 1];
		b[i]->val = 3 - i;
		b[i]->next = b[i + 1];
		c[i]->val = i + 5;
		c[i]->next = c[i + 1];
	}
	a[i]->val = 1;
	a[i]->next = NULL;
	b[i]->val = 3 - i;
	b[i]->next = NULL;
	c[i]->val = i + 5;
	c[i]->next = c[i + 1];
	c[i + 1]->val = i + 6;
	c[i + 1]->next = NULL;
	
	Plus plus;
	ListNode *res = plus.plusAB(c[0], a[0]);
	for (int j = 0; j < 4; j++)
	{
		cout << res->val;
		res = res->next;
	}

	return 0;
}