#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
 *说明：一个袋子可以装重S，一组物品重W={w1, w2, ... , wN}，找出若干件物品，使得恰好能装入袋子中
 *举例：S=16，W={2,3,4,5,6,7,8,9,10,11}，则一组解是{5,11}
 */

void clear_stack(stack<int> &s)
{
	while (!s.empty())
		s.pop();
}

void print_stack(stack<int> &s)
{
	int tmp;
	while (!s.empty())
	{
		tmp = s.top();
		cout << tmp << " ";
		s.pop();
	}
	cout << endl;
}

int main()
{
	int s = 16;
	const int n = 10;
	vector<int> wi(n, 0);

	for (int i = 0; i < n; i++)
		wi[i] = i + 2;

	sort(wi.begin(), wi.end());

	stack<int> selected;
	for (int i = n - 1; i >= 0; i--) //类似贪心策略处理
	{
		selected.push(wi[i]);
		s -= wi[i];
		if (s == 0)
		{
			print_stack(selected);
			break;
		}
		else if (s > 0)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				selected.push(wi[j]);
				s -= wi[j];
				if (s == 0)
				{
					print_stack(selected);
					break;
					break;
				}
				else if (s > 0)
				{
					selected.push(wi[j]);
				}
				else
				{
					selected.pop();
					s += wi[j];
				}
			}
		}
		else
		{
			s += wi[i];
			clear_stack(selected);
		}
	}

	if (s != 0)
		cout << "No solution" << endl;

	return 0;
}