#include <iostream>
#include <string>

using namespace std;

/*
 *说明：字符串反转，不能使用其他存储空间
 *举例：输入"This is nowcoder"，输出"redocwon si sihT"
 */

class Reverse {
public:
	string reverseString(string iniString) {
		// write code here
		if (iniString.empty() || (iniString.length() == 1))
			return iniString;

		char ch;
		int len = iniString.length();
		for (int i = 0; i < len / 2; i++)
		{
			ch = iniString[i];
			iniString[i] = iniString[len - 1 - i];
			iniString[len - 1 - i] = ch;
		}

		return iniString;

		/*
		string res;
		string::reverse_iterator rb = iniString.rbegin();
		string::reverse_iterator re = iniString.rend();

		int len = iniString.length();
		for (; rb != iniString.rend(); rb++)
			res.push_back(*rb);

		return res;
		*/
	}
};

int main()
{
	string str1 = "This is nowcoder";
	Reverse reverse;
	string res = reverse.reverseString(str1);
	cout << res << endl;

	return 0;
}