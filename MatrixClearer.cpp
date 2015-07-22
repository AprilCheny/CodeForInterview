#include <iostream>
#include <vector>

using namespace std;

/*
 *说明：若NxN矩阵中某个元素为0，则将其所在的行与列清零。
 *举例：输入方阵[[1,2,3],[0,1,2],[0,0,1]]，输出方阵：[[0,0,3],[0,0,0],[0,0,0]]
 */

class Clearer {
public:
	vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
		// write code here
		if (mat.empty() || (n == 0))
			return mat;

		vector<int> vi;
		vector<int> vj;

		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 0)
			{
				vi.push_back(i);
				vj.push_back(j);
			}
		}

		int is = vi.size();
		int js = vj.size();
		for (int i = 0; i < is; i++)
		{
			for (int j = 0; j < n; j++)
				mat[vi[i]][j] = 0;
		}
		for (int j = 0; j < js; j++)
		{
			for (int i = 0; i < n; i++)
				mat[i][vj[j]] = 0;
		}

		return mat;
	}
};

int main()
{
	vector< vector<int> > vvi;
	int n = 3;
	vector<int> vi(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			vi[j] = i * 3 + j;
		vvi.push_back(vi);
	}

	Clearer clearer;
	vector< vector<int> > res = clearer.clearZero(vvi, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}