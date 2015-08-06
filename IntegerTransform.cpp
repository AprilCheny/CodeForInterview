#include <iostream>

using namespace std;

/*
 *说明：两个整数二进制表示中比特位的不同位数
 *举例：输入10和5，输出4
 */

int main()
{
	int a = 19114;
	int b = 17568;
	unsigned int tmp = (a ^ b);
	
	int count = 0;
	while (tmp > 0)
	{
		if (tmp % 2 == 1)
			count++;
		tmp >>= 1;
	}

	cout << count << endl;

	return 0;
}