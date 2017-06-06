#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int res = 0;
		const int m = matrix.size();
		if (m == 0){
			return 0;
		}
		const int n = matrix[0].size();
		if (n == 0){
			return 0;
		}

		vector<int> left(n, 0), right(n, n), height(n, 0);

		for (int i = 0; i < m; ++i){
			int cur_left = 0, cur_right = n;

			for (int j = 0; j < n; ++j){
				height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0; // ==1, 则height++,否则为0
			}

			for (int j = 0; j < n; ++j){
				left[j] = matrix[i][j] == '1' ? max(left[j], cur_left) : 0; // ==1 左边界 为 最右,否则为0
				cur_left = matrix[i][j] == '1' ? cur_left : j + 1; // ==1， 左边界不变，否则无效
			}

			for (int j = n - 1; j >= 0; --j){
				right[j] = matrix[i][j] == '1' ? min(right[j], cur_right) : n;
				cur_right = matrix[i][j] == '1' ? cur_right : j;
			}

			for (int j = 0; j < n; ++j){
				res = max(res, (right[j] - left[j]) * height[j]); // 计算面积
			}

		}
		return res;
	}

	int maximalRectangleCodeOP(vector<vector<char>>& matrix) {
		int res = 0;
		const int m = matrix.size();
		if (m == 0){
			return 0;
		}
		const int n = matrix[0].size();
		if (n == 0){
			return 0;
		}

		vector<int> left(n, 0), right(n, n), height(n, 0);

		for (int i = 0; i < m; ++i){
			int cur_left = 0, cur_right = n;

			for (int j = n - 1; j >= 0; --j){
				right[j] = matrix[i][j] == '1' ? min(right[j], cur_right) : n;
				cur_right = matrix[i][j] == '1' ? cur_right : j;
			}

			for (int j = 0; j < n; ++j){
				const bool flag = matrix[i][j] == '1';
				height[j] = flag ? height[j] + 1 : 0;
				left[j] = flag ? max(left[j], cur_left) : 0;
				cur_left = flag ? cur_left : j + 1;
				res = max(res, (right[j] - left[j]) * height[j]);
			}

		}
		return res;
	}
};


int main(int argc, char *argv[]){
	Solution s;
	vector<vector<char>> matrix{ {'1', '0', '1', '0', '0'},
								{'1', '0', '1', '1', '1'},
								{'1', '1', '1', '1', '1'},
								{'1', '1', '1', '1', '1'} };
	cout << s.maximalRectangle(matrix) << endl;
	system("pause");
	return 0;
}
