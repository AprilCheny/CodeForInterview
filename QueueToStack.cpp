#include <iostream>
#include <queue>

using namespace std;

/*
 *说明：两个队列模拟栈
 *
 */

template<typename T>
class MyStack
{
public:
	MyStack()
	{
		isize = 0;
		flag = false;
	}
	int size()
	{
		return isize;
	}
	bool empty()
	{
		return isize == 0 ? true : false;
	}
	T& top()
	{
		if (!q1.empty())
		{
			while (q1.size() != 1)
			{
				T temp = q1.front();
				q1.pop();
				q2.push(temp);
			}
			flag = false;
			return q1.front();
		}
		else
		{
			if (q2.empty())
				throw std::exception("Empty Stack");
			else
			{
				while (q2.size() != 1)
				{
					T temp = q2.front();
					q2.pop();
					q1.push(temp);
				}
				flag = true;
				return q2.front();
			}
		}
	}
	void pop()
	{
		if (flag)
		{
			q2.pop();
			--isize;
		}
		else
		{
			if (!q1.empty())
			{
				while (q1.size() != 1)
				{
					T temp = q1.front();
					q1.pop();
					q2.push(temp);
				}
				q1.pop();
				--isize;
			}
			else
			{
				if (q2.empty())
					throw std::exception("Empty Stack");
				else
				{
					while (q2.size() != 1)
					{
						T temp = q2.front();
						q2.pop();
						q1.push(temp);
					}
					q2.pop();
					--isize;
				}
			}
		}
		/*if (!q1.empty())
		{
			while (q1.size() != 1)
			{
				T temp = q1.front();
				q1.pop();
				q2.push(temp);
			}
			q1.pop();
			--isize;
		}
		else
		{
			if (q2.empty())
				throw std::exception("Empty Stack");
			else
			{
				while (q2.size() != 1)
				{
					T temp = q2.front();
					q2.pop();
					q1.push(temp);
				}
				q2.pop();
				--isize;
			}
		}*/
	}
	void push(const T& value)
	{
		q1.push(value);
		++isize;
		flag = false;
	}

private:
	queue<T> q1;
	queue<T> q2;

	int isize;
	bool flag; //是否是对q2操作
};

int main()
{
	MyStack<int> myStack;
	for (int i = 0; i < 10; i++)
		myStack.push(i);
	while (myStack.size() != 9)
	{
		cout << myStack.top() << " ";
		myStack.pop();
	}
	myStack.push(10);
	cout << myStack.top() << " ";
	myStack.pop();
	myStack.push(11);
	myStack.push(12);
	cout << myStack.top() << " ";
	myStack.pop();
	while (!myStack.empty())
	{
		cout << myStack.top() << " ";
		myStack.pop();
	}
	cout << endl;

	return 0;
}