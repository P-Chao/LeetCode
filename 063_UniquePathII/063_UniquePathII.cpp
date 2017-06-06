#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		vector<vector<int>> path(m, vector<int>(n, 0));
		bool flag = false;
		path[0][0] = 1 - obstacleGrid[0][0];
		for (int i = 0; i < m; ++i){
			if (obstacleGrid[i][0] || flag){
				flag = true;
				path[i][0] = 0;
			} else{
				path[i][0] = 1;
			}
		}
		flag = false;
		for (int j = 0; j < n; ++j){
			if (obstacleGrid[0][j] || flag){
				flag = true;
				path[0][j] = 0;
			} else{
				path[0][j] = 1;
			}
		}

		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j){
				if (!obstacleGrid[i][j]){
					path[i][j] = path[i - 1][j] + path[i][j - 1];
				}
			}
		}
		return path[m - 1][n - 1];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<int>> obstacleGrid{ { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
	cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
	system("pause");
	return 0;
}