#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		m = matrix.size();
		if (m <= 0){
			return 0;
		}
		n = matrix[0].size();
		if (n <= 0){
			return 0;
		}
		int ret = 0;
		dir = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				ret = max(ret, dfs(i, j, matrix, dp));
			}
		}
		return ret;
	}
private:
	int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
		if (dp[i][j]){
			return dp[i][j];
		}
		int maxlen = 0;
		
		for (int d = 0; d < 4; ++d){
			int x = i + dir[d][0];
			int y = j + dir[d][1];
			if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]){
				maxlen = max(maxlen, dfs(x, y, matrix, dp));
			}
		}
		dp[i][j] = maxlen + 1;
		return dp[i][j];
	}

	int m, n;
	vector<vector<int>> dir;
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<int>> matrix2{ 
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 
		{ 19, 18, 17, 16, 15, 14, 13, 12, 11, 10 }, 
		{ 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 }, 
		{ 39, 38, 37, 36, 35, 34, 33, 32, 31, 30 }, 
		{ 40, 41, 42, 43, 44, 45, 46, 47, 48, 49 }, 
		{ 59, 58, 57, 56, 55, 54, 53, 52, 51, 50 }, 
		{ 60, 61, 62, 63, 64, 65, 66, 67, 68, 69 }, 
		{ 79, 78, 77, 76, 75, 74, 73, 72, 71, 70 }, 
		{ 80, 81, 82, 83, 84, 85, 86, 87, 88, 89 }, 
		{ 99, 98, 97, 96, 95, 94, 93, 92, 91, 90 }, 
		{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 }, 
		{ 119, 118, 117, 116, 115, 114, 113, 112, 111, 110 }, 
		{ 120, 121, 122, 123, 124, 125, 126, 127, 128, 129 }, 
		{ 139, 138, 137, 136, 135, 134, 133, 132, 131, 130 }, 
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	vector<vector<int>> matrix{ { 9, 9, 4 }, { 6, 6, 8 }, { 2, 1, 1 } };
	cout << s.longestIncreasingPath(matrix2) << endl;
	system("pause");
	return 0;
}