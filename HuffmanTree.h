#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

class Node
{
public:
	unsigned char value;
	unsigned int weight;
	std::string hufCode;
	Node *lchild;
	Node *rchild;

	bool operator <(Node &n)
	{
		return weight < n.weight;
	}
	bool operator >(Node &n)
	{
		return n.weight < weight;
	}
	void Reset()
	{
		value = 0;
		weight = 0;
		hufCode = "";
		lchild = NULL;
		rchild = NULL;
	}
};

static inline bool pair_compare(const std::pair<char, int> &p1, const std::pair<char, int> &p2)
{
	return p1.second < p2.second;
}

static inline bool node_compare(const Node *n1, const Node *n2)
{
	return n1->weight < n2->weight;
}

//仅仅第一个元素出于无序状态的数组排序
template<typename T>
void SingleSort(std::vector<T> &vt, int begin, bool nc(const Node *n1, const Node *n2))
{
	int len = vt.size();
	for (int i = begin; i < len - 1; i++)
	{
		if (nc(vt[i + 1], vt[i]))
			swap(vt[i], vt[i + 1]);
		else
			break;
	}
}

class HuffmanTree
{
public:
	HuffmanTree()
	{
		root = NULL;
	}
	HuffmanTree(std::vector< std::pair<char, int> > &vp)
	{
		int leaf_num = vp.size();
		sort(vp.begin(), vp.end(), pair_compare);

		std::vector<Node*> vn(leaf_num);
		int index = 0;
		while (index != leaf_num) //创建所有叶子节点
		{
			Node *node = new Node;
			node->Reset();
			node->value = vp[index].first;
			node->weight = vp[index].second;

			vn[index] = node;

			index++;
		}

		combine(vn, 0, leaf_num - 1);
	}

	void PreErgodic(Node *root) //前序遍历Huffman树
	{
		if (root == NULL)
			return;

		if (root->lchild == NULL && root->rchild == NULL) //只打印叶子节点
			std::cout << root->value << std::endl;

		PreErgodic(root->lchild);
		PreErgodic(root->rchild);
	}

	void Encoding(Node *root) //根据建好的Huffman树进行Huffman编码
	{
		if (root == NULL)
			return;

		if (root->lchild == NULL && root->rchild == NULL)
			std::cout << root->value << "   " << root->hufCode << std::endl;

		if (root->lchild != NULL)
			root->lchild->hufCode = root->hufCode + '0';
		if (root->rchild != NULL)
			root->rchild->hufCode = root->hufCode + '1';

		Encoding(root->lchild);
		Encoding(root->rchild);
	}

	void Decoding(const std::string &binStr, const int begin, const int str_size) //根据对应的Huffman树解码二进制串
	{
		int dec_len = 0; //已解码二进制串长度
		if (begin >= str_size)
			return;

		Node *curr = root;
		while (curr != NULL)
		{
			if (curr->lchild == NULL && curr->rchild == NULL)
			{
				std::cout << curr->value;// << std::endl;
				break;
			}

			if (begin + dec_len == str_size) //二进制串已经扫描到末尾但是不是一个完整的Huffman码
				return;

			if (binStr[begin + dec_len] == '0')
				curr = curr->lchild;
			else if (binStr[begin + dec_len] == '1')
				curr = curr->rchild;

			dec_len++;
		}

		Decoding(binStr, begin + dec_len, str_size);
	}

	Node* GetRoot() //获取根节点
	{
		return root;
	}

private:
	Node *root;

	void combine(std::vector<Node*> &vn, int left, int right) //递归构建Huffman树
	{
		if (left == right)
			return;

		//构建内部节点
		Node *node = new Node;
		node->weight = vn[left]->weight + vn[left + 1]->weight;
		node->lchild = vn[left];
		node->rchild = vn[left + 1];
		vn[left + 1] = node;
		root = node;

		SingleSort(vn, left + 1, node_compare); //排序新构建的节点
		combine(vn, left + 1, right);
	}
};