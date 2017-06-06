#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		const int m = grid.size();
		const int n = grid[0].size();
		vector<vector<int>> sum(m, vector<int>(n, 0));
		for (int i = 1; i < m; ++i){
			sum[i][0] = sum[i - 1][0] + grid[i - 1][0];
		}
		for (int j = 1; j < n; ++j){
			sum[0][j] = sum[0][j - 1] + grid[0][j - 1];
		}
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j){
				sum[i][j] = min(sum[i - 1][j] + grid[i - 1][j], sum[i][j - 1] + grid[i][j - 1]);
			}
		}
		return sum[m - 1][n - 1] + grid[m - 1][n - 1];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<int>> grid{ { 1, 2, 3, 4 }, { 2, 3, 4, 5 }, { 3, 4, 5, 4 }, { 4, 5, 6, 7 } }; // 26
	cout << s.minPathSum(grid) << endl;
	system("pause");
	return 0;
}