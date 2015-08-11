#include <iostream>
#include <stack>

using namespace std;

/*
 *说明：两个栈模拟队列
 *
 */

template<typename T>
class MyQueue
{
public:
	MyQueue()
	{
		isize = 0;
	}

	int size()
	{
		return isize;
	}
	bool empty()
	{
		return isize == 0 ? true : false;
	}

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> s1;
	stack<T> s2;

	int isize;
};

template<typename T>
void MyQueue<T>::appendTail(const T& node)
{
	s1.push(node);
	++isize;
}

template<typename T>
T MyQueue<T>::deleteHead()
{
	if (s2.empty())
	{
		while (!s1.empty())
		{
			T temp = s1.top();
			s1.pop();
			s2.push(temp);
		}
	}
	if (s2.empty())
		throw std::exception("Empty Queue");
	
	T temp = s2.top();
	s2.pop();
	--isize;
	
	return temp;
}

int main()
{
	MyQueue<int> myQueue;
	int i = 0;
	while (i++ < 10)
		myQueue.appendTail(i);

	while (!myQueue.empty())
	{
		int res = myQueue.deleteHead();
		cout << res << " ";
	}
	cout << endl;

	return 0;
}