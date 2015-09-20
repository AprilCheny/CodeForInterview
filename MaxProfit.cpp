#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 *˵������һ�������ʾ��Ʊÿ��ļ۸�����ĵ�i������ʾ��Ʊ�ڵ�i��ļ۸� ���ֻ�������һ�Σ����Ρ����޴Σ����ף�Ҳ����˵ֻ������һ֧��Ʊ�����������������档
 *����������{1,2,5,9,4,3,7,8,5}�������Ϊ8��13��13��
 *�㷨��ʹ�ö�̬�滮��̰�ġ���̬�滮�㷨���
 */

inline int minOfTwo(const int a, const int b)
{
	return a > b ? b : a;
}

inline int maxOfTwo(const int a, const int b)
{
	return a > b ? a : b;
}

int maxProfitOnce(const vector<int>& price) //ֻ�������һ�ν��ף���̬�滮�㷨
{
	int ps = price.size();
	int curMin = price[0];
	int maxProfit = 0;

	for (int i = 1; i < ps; i++)
	{
		curMin = minOfTwo(curMin, price[i]); //���µ�ǰ��͹�Ʊ�۸�
		maxProfit = maxOfTwo(maxProfit, price[i] - curMin); //�����������
	}

	return maxProfit;
}

/*ֻ����������ν��ף�ʹ�ö�̬�滮�㷨��
 *(1)�Ե�i��Ϊ�ֽ��ߣ������i��֮ǰ����һ�ν��׵��������preProfit[i]���͵�i��֮�����һ�ν��׵��������postProfit[i]��
 *(2)������һ�飬max{preProfit[i] + postProfit[i]} (0��i��n-1)����������档
 */
int maxProfitTwice(const vector<int>& price) //ֻ����������ν��ף���̬�滮�㷨
{
	int ps = price.size();
	vector<int> maxProfit(ps - 3, 0);

	for (int i = 1; i < ps - 2; i++) //ȷ���ָ��ÿ���ֶ�����������Ԫ��
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

int maxProfitTimes(const vector<int>& price) //�����������ν��ף�̰���㷨
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