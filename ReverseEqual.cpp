#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *说明：检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数
 *举例：输入字符串"Hello world"和"worldhello "，输出false；输入字符串"waterbottle"和"erbottlewat"，输出true
 */

bool Find(const string &ts, const string &ps, int &pos, const vector<int> &dis_table)
{
	int ts_size = ts.size();
	int ps_size = ps.size();
	int limit = ts_size - ps_size + 1;

	bool result = false;

	for (int i = 0; i < limit;)
	{
		if (ts[i] == ps[0])
		{
			int j = 1;
			while (j < ps_size)
			{
				if (ts[i + j] != ps[j])
					break;

				j++;
			}

			if (j == ps_size)
			{
				result = true;
				pos = i + j - ps_size;
				break;
			}
		}

		i += dis_table[ts[i + ps_size]];
	}

	return result;
}

bool SundayAlgorithm(const string &ts, const string &ps, int &pos)
{
	int ts_size = ts.size();
	int ps_size = ps.size();
	if (ts_size <= 0 || ps_size <= 0)
		return false;

	vector<int> dis_table(256, ps_size + 1);
	for (int i = 0; i < ps_size; i++)
	{
		int index = (unsigned char)ps[i];
		dis_table[index] = ps_size - i;
	}

	bool result = Find(ts, ps, pos, dis_table);

	return result;
}

class ReverseEqual {
public:
	bool checkReverseEqual(string s1, string s2) {
		// write code here
		if (s1.empty() && s2.empty())
			return true;
		if (s1.length() != s2.length())
			return false;

		char *pch1 = const_cast<char *>(s1.c_str());
		int ss1 = strlen(pch1);
		char *pch2 = const_cast<char *>(s2.c_str());
		char *pch3 = (char *)malloc(2 * ss1 + 1);
		memcpy(pch3, pch1, ss1);
		memcpy(pch3 + ss1, pch1, ss1);
		pch3[2 * ss1] = '\0';

		bool res = false;
		int pos;
		if (SundayAlgorithm(string(pch3), string(pch2), pos)) //strstr(pch3, pch2)
			res = true;

		return res;
	}
};

int main()
{
	string s1 = "Hello world";
	string s2 = "worldhello ";
	string s3 = "waterbottle";
	string s4 = "erbottlewat";

	ReverseEqual reverseEqual;
	bool res1 = reverseEqual.checkReverseEqual(s1, s2);
	bool res2 = reverseEqual.checkReverseEqual(s3, s4);

	cout << "res1: " << res1 << endl;
	cout << "res2: " << res2 << endl;

	return 0;
}