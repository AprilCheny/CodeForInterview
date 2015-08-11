#include <iostream>
#include <vector>

using namespace std;

/*
 *˵����{1,2, ... , n}���������У���ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)���ź���ʹ�ý�����һ��ֻ�ܽ���������
 *����������{10,6,9,5,2,8,4,7,1,3}������ź����{1,2,3,4,5,6,7,8,9,10}
 *ע�⣺��1����Ҫ��֤1~n��ÿ���������ڣ���2��ûʲôʵ��Ӧ�ü�ֵ����3��Ͷ����������i=1~n��ֱ�Ӹ�ֵa[i]=i+1
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

		if (vi[i] == i + 1) //�����ǰֵ����ȷ��λ�ã���������һ��λ��
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