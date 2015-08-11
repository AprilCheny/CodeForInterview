#include <iostream>
#include <vector>

using namespace std;

/*
 *说明：{1,2, ... , n}的乱序排列，在时间复杂度O(n)，空间复杂度O(1)内排好序。使用交换，一次只能交换两个数
 *举例：输入{10,6,9,5,2,8,4,7,1,3}，输出排好序后{1,2,3,4,5,6,7,8,9,10}
 *注意：（1）需要保证1~n中每个数都存在；（2）没什么实际应用价值；（3）投机方法：对i=1~n，直接赋值a[i]=i+1
 */

void SkipSort(vector<int> &vi)
{
	int vis = vi.size();

	if (vis <= 1)
		return;

	int i = 0;
	while (i < vis)
	{
		int temp = vi[vi[i] - 1];
		vi[vi[i] - 1] = vi[i];
		vi[i] = temp;

		if (vi[i] == i + 1) //如果当前值在正确的位置，则排序下一个位置
			++i;
	}
}

int main()
{
	const int num = 10;
	int d[] = { 10, 6, 9, 5, 2, 8, 4, 7, 1, 3 };
	vector<int> vi(d, d + 10);

	SkipSort(vi);
	for (int i = 0; i < 10; i++)
		cout << vi[i] << " ";
	cout << endl;

	return 0;
}