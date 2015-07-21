#include <iostream>
#include <string>

using namespace std;

/*
 *说明：将字符串中的空格全部替换为“%20”
 *举例：输入字符串“Mr John Smith”，输出字符串“Mr%20John%20Smith”
 */

class Replacement {
public:
	string replaceSpace(string iniString, int length) {
		// write code here
		int len = length;
		int space = 0;
		if (iniString.empty() || length <= 0)
			return string("");

		for (int i = 0; i < length; i++)
		{
			if (iniString[i] == ' ')
				space++;
		}
		len += space * 2;
		iniString.resize(len);
		len--;
		for (int j = length - 1; j >= 0; j--)
		{
			if (iniString[j] != ' ')
				iniString[len--] = iniString[j];
			else
			{
				iniString[len--] = '0';
				iniString[len--] = '2';
				iniString[len--] = '%';
				--space;
				if (space == 0)
					break;
			}
		}

		return iniString;
	}
};

int main()
{
	Replacement replace;
	string str1 = "Mr John Smith";
	string str2 = "Hello   World";
	string str3 = "";

	string restr1 = replace.replaceSpace(str1, str1.length());
	cout << restr1 << endl;
	string restr2 = replace.replaceSpace(str2, str2.length());
	cout << restr2 << endl;
	string restr3 = replace.replaceSpace(str3, 10);
	cout << restr3 << endl;

	return 0;
}