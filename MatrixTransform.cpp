#include <iostream>
#include <vector>

using namespace std;

/*
 *说明：方阵顺时针旋转90°
 *举例：输入方阵[[1,2,3],[4,5,6],[7,8,9]]和方阵阶3，输出方阵：[[7,4,1],[8,5,2],[9,6,3]]
 */

class Transform {
public:
	vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
		// write code here
		if (mat.empty() || (n == 0))
			return mat;

		for (int i = 0; i < n / 2; i++) //先上下翻转
			for (int j = 0; j < n; j++)
				swap(mat[i][j], mat[n - 1 - i][j]);

		for (int i = 0; i < n; i++) //再 左上<-->右下 对角线翻转
			for (int j = 0; j < i; j++)
				swap(mat[i][j], mat[j][i]);

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
			vi[j] = i * 3 + 1 + j;
			vvi.push_back(vi);
	}

	Transform transform;
	vector< vector<int> > res = transform.transformImage(vvi, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}