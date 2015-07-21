#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *说明：判断字符串中的字符是否互异，不能使用额外的存储空间
 *举例：输入字符串"aeiou"，输出true；输入字符串"BarackObama"，输出false
 */

class Different {
public:
	bool checkDifferent(string iniString) {
		// write code here
		if (iniString.empty() || (iniString.size() == 1))
			return true;

		bool res = true;
		sort(iniString.begin(), iniString.end());
		for (int i = 0; i < iniString.length() - 1; i++)
		{
			if (iniString[i] == iniString[i + 1])
				res = false;
		}
		return res;
		
		/*使用一个定长数组的快速解法
		bool res = true;

		vector<int> vi(256, 0);
		for (int i = 0; i < iniString.length(); i++)
		{
			if (vi[iniString[i]]++ > 1)
				res = false;
		}

		return res;
		*/
	}
};

int main()
{
	string str1 = "aeiou";
	string str2 = "BarackObama";

	Different different;
	bool res1 = different.checkDifferent(str1);
	bool res2 = different.checkDifferent(str2);
	cout << "res1: " << res1 << endl;
	cout << "res2: " << res2 << endl;

	return 0;
}