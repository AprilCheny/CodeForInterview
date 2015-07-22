#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *说明：确定其中一个字符串的字符重新排列后，能否变成另一个字符串
 *举例：输入字符串"This is nowcoder"和"is This nowcoder"，输出true；输入字符串"Here you are"和"Are you here"，输出false
 */

class Same {
public:
	bool checkSam(string stringA, string stringB) {
		// write code here
		if (stringA.empty() && stringB.empty())
			return true;
		if (stringA.empty() && !stringB.empty())
			return false;
		if (!stringA.empty() && stringB.empty())
			return false;
		if (stringA.length() != stringB.length())
			return false;

		vector<string> vsa;
		vector<string> vsb;
		char *pch = NULL;
		char *psa = const_cast<char *>(stringA.c_str());
		char *psb = const_cast<char *>(stringB.c_str());
		char *context = new char[1000];

		char *space = " ";
		bool res = true;

		while ((pch = strtok_s(psa, space, &context)) != NULL)
		{
			vsa.push_back(string(pch));
			psa = NULL;
		}
		pch = NULL;
		while ((pch = strtok_s(psb, space, &context)) != NULL)
		{
			vsb.push_back(string(pch));
			psb = NULL;
		}

		if (vsa.size() != vsb.size())
			return false;
		vector<string>::iterator iter = vsb.begin();
		vector<string>::iterator vsi;
		for (; iter != vsb.end(); iter++)
		{
			if ((vsi = find(vsa.begin(), vsa.end(), *iter)) == vsa.end())
			{
				res = false;
				break;
			}
		}

		return res;
	}
};

int main()
{
	string str1 = "This is nowcoder";
	string str2 = "is This nowcoder";
	string str3 = "Here you are";
	string str4 = "Are you here";
	string str5 = "Chen";
	string str6 = "Yong";

	Same same;

	bool res1 = same.checkSam(str1, str2);
	bool res2 = same.checkSam(str3, str4);
	bool res3 = same.checkSam(str5, str6);

	cout << "res1: " << res1 << endl;
	cout << "res2: " << res2 << endl;
	cout << "res3: " << res3 << endl;

	return 0;
}