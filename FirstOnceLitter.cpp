#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 *说明：字符串中第一个只出现一次的字符，时间复杂度O(n)，可以使用额外定长数组
 *举例：输入"abcdaefcbefg"，输出'd'
 */

int main()
{
	string str = "abcdaefcbefg";
	vector<int> vi(256, 0);

	for (int i = 0; i < str.size(); i++)
		vi[str[i]]++;

	char res;
	for (int i = 0; i < str.size(); i++)
	{
		if (vi[str[i]] == 1)
		{
			res = str[i];
			break;
		}
	}

	cout << "result: " << res << endl;

	return 0;
}