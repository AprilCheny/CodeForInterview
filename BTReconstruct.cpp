#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*
 *说明：输入二叉树的前序遍历和中序遍历，重建二叉树
 *举例：输入前序序列{1,2,4,7,3,5,6,8}和中序序列{4,7,2,1,5,3,8,6}，输出重建的二叉树
 */

struct BinaryTreeNode
{
	BinaryTreeNode(int v = 0) : value(v), left(nullptr), right(nullptr){}
	
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

BinaryTreeNode* ConstructRecursion(int* pre_start, int* pre_end, int* in_start, int* in_end) //递归重建二叉树
{
	int root_value = pre_start[0]; //根据前序序列获得根节点
	BinaryTreeNode* root = new BinaryTreeNode;
	root->value = root_value;

	if (pre_start == pre_end) //如果子序列中只有一个节点了
	{
		if (in_start == in_end && *pre_start == *in_start)
		{
			root->left = nullptr;
			root->right = nullptr;
			return root;
		}
		else
			throw std::exception("Invalid input");
	}

	int *root_in_inOrder = in_start; //找到根节点在中序序列中的位置
	while (root_in_inOrder <= in_end && *root_in_inOrder != root_value)
		++root_in_inOrder;
	if (root_in_inOrder == in_end && *root_in_inOrder != root_value)
		throw std::exception("Invalid input");

	int left_len = root_in_inOrder - in_start; //根节点的左子树节点数目
	if (left_len > 0)
	{
		root->left = ConstructRecursion(pre_start + 1, pre_start + left_len, in_start, root_in_inOrder - 1);
	}
	if (left_len < in_end - in_start)
	{
		root->right = ConstructRecursion(pre_start + left_len + 1, pre_end, root_in_inOrder + 1, in_end);
	}

	return root;
}

BinaryTreeNode* BTReconstruct(int* preOrder, int* inOrder, const int len)
{
	if (preOrder == nullptr || inOrder == nullptr || len <= 0)
		return nullptr;

	return ConstructRecursion(preOrder, preOrder + len - 1, inOrder, inOrder + len - 1);
}

void BTPreOrderPrintRecursion(BinaryTreeNode* root) //递归前序遍历
{
	if (root == nullptr)
		return;

	cout << root->value << " ";
	BTPreOrderPrintRecursion(root->left);
	BTPreOrderPrintRecursion(root->right);
}

void BTInOrderPrintRecursion(BinaryTreeNode* root) //递归中序遍历
{
	if (root == nullptr)
		return;

	BTInOrderPrintRecursion(root->left);
	cout << root->value << " ";
	BTInOrderPrintRecursion(root->right);
}

void BTPostOrderPrintRecursion(BinaryTreeNode* root) //递归后序遍历
{
	if (root == nullptr)
		return;

	BTPostOrderPrintRecursion(root->left);
	BTPostOrderPrintRecursion(root->right);
	cout << root->value << " ";
}

void push_stack(stack<BinaryTreeNode*> &btn, BinaryTreeNode* root)
{
	if (root != nullptr)
	{
		if (root->right != nullptr)
			push_stack(btn, root->right);
		if (root->left != nullptr)
			push_stack(btn, root->left);
		btn.push(root);
	}
}

void BTPreOrderPrintCirculation(BinaryTreeNode* root) //非递归前序遍历
{
	stack<BinaryTreeNode*> btn_s;
	BinaryTreeNode* curr = root;

	while (curr != nullptr || !btn_s.empty())
	{
		if (curr != nullptr)
		{
			cout << curr->value << " ";
			btn_s.push(curr);
			curr = curr->left;
		}
		else
		{
			curr = btn_s.top();
			btn_s.pop();
			curr = curr->right;

		}
	}

	/*
	push_stack(btn_s, root);

	while (!btn_s.empty())
	{
		BinaryTreeNode *curr = btn_s.top();
		cout << curr->value << " ";
		btn_s.pop();
	}
	*/
}

void BTInOrderPrintCirculation(BinaryTreeNode* root) //非递归中序遍历
{
	stack<BinaryTreeNode*> btn_s;
	BinaryTreeNode* curr = root;

	while (curr != nullptr || !btn_s.empty())
	{
		if (curr != nullptr)
		{
			btn_s.push(curr);
			curr = curr->left;
		}
		else
		{
			curr = btn_s.top();
			cout << curr->value << " ";
			btn_s.pop();
			curr = curr->right;

		}
	}
}

void BTPostOrderPrintCirculation(BinaryTreeNode* root) //非递归后序遍历
{
	stack<BinaryTreeNode*> btn_s;
	BinaryTreeNode* curr = root;
	BinaryTreeNode* prev = nullptr;

	btn_s.push(curr);
	while (!btn_s.empty())
	{
		curr = btn_s.top();
		if ((curr->left == nullptr && curr->right == nullptr) || (prev != nullptr && (prev == curr->left || prev == curr->right))) //如果当前节点是叶节点或者其左右孩子都已经遍历过
		{
			cout << curr->value << " ";
			btn_s.pop();
			prev = curr;
		}
		else
		{
			if (curr->right != nullptr)
				btn_s.push(curr->right);
			if (curr->left != nullptr)
				btn_s.push(curr->left);
		}
	}
}

void BroadFirstTraversal(BinaryTreeNode* root) //二叉树的层序遍历
{
	queue<BinaryTreeNode*> btn_q;
	if (root != nullptr)
	{
		btn_q.push(root);
	    while (!btn_q.empty())
		{
			BinaryTreeNode* curr = btn_q.front();
			cout << curr->value << " ";
			if (curr->left != nullptr)
				btn_q.push(curr->left);
			if (curr->right != nullptr)
				btn_q.push(curr->right);
			btn_q.pop();
		}
	}
}

int main()
{
	const int len = 8;
	int preOrder[len] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inOrder[len] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	BinaryTreeNode* root = BTReconstruct(preOrder, inOrder, len);
	BTPreOrderPrintRecursion(root);
	cout << endl;
	BTInOrderPrintRecursion(root);
	cout << endl;
	BTPostOrderPrintRecursion(root);
	cout << endl;

	BTPreOrderPrintCirculation(root);
	cout << endl;
	BTInOrderPrintCirculation(root);
	cout << endl;
	BTPostOrderPrintCirculation(root);
	cout << endl;

	BroadFirstTraversal(root);
	cout << endl;

	return 0;
}