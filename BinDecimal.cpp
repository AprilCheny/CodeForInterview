#include <iostream>
#include <string>

using namespace std;

/*
 *说明：一个(0,1)区间的小数，转化为二进制表示
 *举例：输入0.625，输出0.101
 */

class BinDecimal {
private:
	double divideNum(double num, int &i)
	{
		i = (int)num;
		return num - i;
	}

public:
	string printBin(double num) {
		// write code here
		double inf_min = pow(2, -32);
		string res;
		res.push_back('0');
		res.push_back('.');

		int i;
		int count = 0;
		num *= 2;
		while (count <= 30)
		{
			double d = divideNum(num, i);
			if (d - inf_min > 0)
			{
				res.push_back(i + 48);
				num = d * 2;
			}
			else
			{
				res.push_back(i + 48);
				return res;
			}

			count++;
		}

		return string("Error");
	}
};

int main()
{
	double num = 0.46502;
	BinDecimal binDecimal;
	string res = binDecimal.printBin(num);
	cout << res << endl;

	return 0;
}