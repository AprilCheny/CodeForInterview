#include <iostream>
#include <vector>

using namespace std;

/*
 *说明：找出旋转数组的最小值。旋转数组：一个有序的数组最开始的若干个元素搬到数组的末尾，例如{3,4,5,1,2}即是{1,2,3,4,5}的一个旋转
 *注意：如果有序数组确实经过了旋转，则旋转后数组的第一个元素一定大于最后一个元素
 */

int FindMin(vector<int> &vi, int low, int high)
{
	if (low > high)
		throw new std::exception("Invalid input");

	if (high - low == vi.size() && vi[0] < vi[high - 1])
		return vi[low];

	if (low == high)
		return vi[low];

	int mid = (low + high) >> 1;
	if (mid == low)
		return vi[low] < vi[high] ? vi[low] : vi[high];

	if (vi[low] < vi[mid])
		return FindMin(vi, mid + 1, high);
	else
		return FindMin(vi, low, mid - 1);
}

int MinInOrder(vector<int> &vi, int low, int high)
{
	int res = vi[low];
	for (int i = low + 1; i <= high; i++)
	{
		if (vi[i] < res)
			res = vi[i];
	}
	
	return res;
}

int FindMin(vector<int> &vi)
{
	int num = vi.size();
	
	if (num == 0)
		throw new std::exception("Invalid Input");
	if (num == 1)
		return vi[0];
	
	int low = 0;
	int high = num - 1;
	int mid = low;
	while (low < high)
	{
		if (high - low == 1)
		{
			mid = high;
			break;
		}
		int mid = (low + high) >> 1;
		
		if (vi[low] == vi[high] && vi[mid] == vi[high]) //处理三个数相同的情况，此时不能再继续使用二分查找
			return MinInOrder(vi, low, high);
		
		if (vi[low] < vi[mid])
			low = mid;
		else
			high = mid;
	}

	return vi[mid];
}

int main()
{
	const int num = 11;
	vector<int> data(num, 0);
	for (int i = 0; i < 11; i++)
		data[i] = i + 1;
	for (int i = 7; i < 11; i++)
		data[i] = i - 6;
	
	int min_num = FindMin(data);
	cout << min_num << endl;

	return 0;
}