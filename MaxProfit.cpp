#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 *说明：用一个数组表示股票每天的价格，数组的第i个数表示股票在第i天的价格。 如果只允许进行一次（两次、无限次）交易，也就是说只允许买一支股票并卖掉，求最大的收益。
 *举例：输入{1,2,5,9,4,3,7,8,5}，则输出为8（13、13）
 *算法：使用动态规划、贪心、动态规划算法解决
 */

inline int minOfTwo(const int a, const int b)
{
	return a > b ? b : a;
}

inline int maxOfTwo(const int a, const int b)
{
	return a > b ? a : b;
}

int maxProfitOnce(const vector<int>& price) //只允许进行一次交易，动态规划算法
{
	int ps = price.size();
	int curMin = price[0];
	int maxProfit = 0;

	for (int i = 1; i < ps; i++)
	{
		curMin = minOfTwo(curMin, price[i]); //存下当前最低股票价格
		maxProfit = maxOfTwo(maxProfit, price[i] - curMin); //计算最大收益
	}

	return maxProfit;
}

/*只允许进行两次交易，使用动态规划算法：
 *(1)以第i天为分界线，计算第i天之前进行一次交易的最大收益preProfit[i]，和第i天之后进行一次交易的最大收益postProfit[i]；
 *(2)最后遍历一遍，max{preProfit[i] + postProfit[i]} (0≤i≤n-1)就是最大收益。
 */
int maxProfitTwice(const vector<int>& price) //只允许进行两次交易，动态规划算法
{
	int ps = price.size();
	vector<int> maxProfit(ps - 3, 0);

	for (int i = 1; i < ps - 2; i++) //确保分割后每部分都至少有两个元素
	{
		int preProfit = maxProfitOnce(vector<int>(price.begin(), price.begin() + i));
		int postProfit = maxProfitOnce(vector<int>(price.begin() + i + 1, price.end()--));
		maxProfit[i - 1] = preProfit + postProfit;
	}

	int res = 0;
	for (int i = 0; i < ps - 3; i++)
		res = maxOfTwo(res, maxProfit[i]);

	return res;
}

int maxProfitTimes(const vector<int>& price) //允许进行任意次交易，贪心算法
{
	int ps = price.size();
	int maxProfit = 0;

	for (int i = 1; i < ps; i++)
	{
		int profit = price[i] - price[i - 1];
		if (profit > 0)
			maxProfit += profit;
	}

	return maxProfit;
}

int main()
{
	int num;
	cin >> num;
	vector<int> price(num, 0);
	for (int i = 0; i < num; i++)
		cin >> price[i];

	int res = maxProfitTwice(price);

	cout << res << endl;

	return 0;
}