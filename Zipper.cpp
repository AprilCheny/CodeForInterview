#include <iostream>
#include <string>
#include <vector>
#include <cstring>

/*
 *说明：实现基本的字符串压缩功能
 *举例：输入字符串"aabcccccaaa"，输出字符串"a2b1c5a3"
 */

class Zipper {
public:
	std::string zipString(std::string iniString) {
		// write code here
		if (iniString.empty())
			return std::string("");

		std::string res;
		int num = 1, i;
		for (i = 1; i < iniString.length(); i++)
		{
			if (iniString[i - 1] == iniString[i])
				num++;
			else
			{
				res.push_back(iniString[i - 1]);
				res.push_back(num);
				num = 1;
			}
		}
		res.push_back(iniString[i - 1]);
		res.push_back(num);

		int flag = true;
		for (int j = 0; j < res.length(); j++)
		{
			if (res[j] - 'A' < 0)
			{
				if (res[j] > 1)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		{
			for (int k = 2; k < res.length() - 1; k += 2)
				res[k / 2] = res[k];
			res.resize(res.length() / 2);
		}

		return res;

		/*
		std::vector<int> vec(52, 0);
		int len = iniString.length();
		for (int i = 0; i < len; i++)
		{
			int index = iniString[i] - 'A';
			if (index > 25)
				index -= 6;
			vec[index]++;
		}

		std::string res;
		for (int i = 0; i < 52; i++)
		{
			if (vec[i] != 0)
			{
				char ch = (i <= 25 ? (char)('A' + i) : (char)('A' + i + 6));
				res.push_back(ch);
				res.push_back(vec[i]);
			}
		}

		return res;
		*/
	}
};

int main()
{
	std::string str1 = "aabcccccaaa";
	std::string str2 = "welcometonowcoderrrrr";
	std::string str3 = "jjjjjjxxxxxxxooZLLLLLLLLQQQQQQQQQLLLLLLLLECXXXXXXXIIIIIIIIIhjjyyySSooooooooommmuuEEEEEEEEEnnnnnnnffffffAAAAAllllllllbbbbkkkkkkkkkkkkKKKKKKhhhhhhhhhooooooooooYCCCCCCOOOOOOOOOMMMMMMMMMMiiiiiivvvvvvvWWWWkkkkkkwwwwwwwMmmmmmmmmLLLwwwwwwwkkkjjjjjjttttQQQQQQQQQaaaaaaaFFFFFFFlllllllllggggggggggPPPPPPuuuuuuuuaYYYYYYwQQQFFFFFFFFFFaaaaapXXXXXXXxxxxxxQQQQQQQQQsssssGGGGfffffffddddddpppQQQQQQHHHTTTaaaaaaGGGGGGddyyyyyMhhllllllllllNNNNNNNNUUUWWWWWWLLLLLLLLLYYYYYYYYYYTTKKKKKKKKiiiiiiitttttttXXXXXXXXXLLLHZZZZZZZssssjjJJJEEEEEOOOOOttttttttttBBttttttTTTTTTTTTTrrrrttttRRRRRyyooooooaaaaaaaaarrrrrrrPPPPPPPjjPPPPddddddddddHHHHnnnnnnnnnnSSSSSSSSSSzzHHHHHHHHHddddddDDDzzzhhhhhfffffffffftttttteeeeeeeeEEEEEEEEEaaaaaaccccccccccFFFFFFFF";

	Zipper zipper;
	std::string res1 = zipper.zipString(str1);
	for (int i = 0; i < res1.length(); i++)
	{
		if (res1[i] - 'A' < 0)
		{
			int num = (int)res1[i];
			std::cout << num;
		}
		else
			std::cout << res1[i];
	}
	std::cout << std::endl;
	std::string res2 = zipper.zipString(str2);
	for (int i = 0; i < res2.length(); i++)
	{
		if (res2[i] - 'A' < 0)
		{
			int num = (int)res2[i];
			std::cout << num;
		}
		else
			std::cout << res2[i];
	}
	std::cout << std::endl;
	std::string res3 = zipper.zipString(str3);
	for (int i = 0; i < res3.length(); i++)
	{
		if (res3[i] - 'A' < 0)
		{
			int num = (int)res3[i];
			std::cout << num;
		}
		else
			std::cout << res3[i];
	}
	std::string str4 = "j6x7o2Z1L8Q9L8E1C1X7I9h1j2y3S2o9m3u2E9n7f6A5l8b4k12K6h9o10Y1C6O9M10i6v7W4k6w7M1m8L3w7k3j6t4Q9a7F7l9g10P6u8a1Y6w1Q3F10a5p1X7x6Q9s5G4f7d6p3Q6H3T3a6G6d2y5M1h2l10N8U3W6L9Y10T2K8i7t7X9L3H1Z7s4j2J3E5O5t10B2t6T10r4t4R5y2o6a9r7P7j2P4d10H4n10S10z2H9d6D3z3h5f10t6e8E9a6c10F8";
	bool equ = strcmp(res3.c_str(), str4.c_str());
	if (equ)
		std::cout << "euqal result" << std::endl;

	return 0;
}