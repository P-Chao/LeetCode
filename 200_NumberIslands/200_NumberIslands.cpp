#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		const int m = grid.size();
		if (m == 0){
			return 0;
		}
		const int n = grid[0].size();
		if (n == 0){
			return 0;
		}

		queue<pair<int, int>> q;
		vector<vector<int>> dir{ { -1, 0 }, { 1, 0 }, { 0, 1 }, {0, -1} };
		vector<vector<bool>> visited(m,vector<bool>(n, false));

		int cnt = 0;
		int ii = 0, jj = 0;
		while (true){
			bool seed = false;
			for (int i = ii; i < m; ++i){
				for (int j = 0; j < n; ++j){
					if (grid[i][j] && !visited[i][j]){
						ii = i;
						jj = j;
						cnt++;
						seed = true;
						break;
					}
				}
				if (seed){
					break;
				}
			}
			if (!seed){
				return cnt;
			}

			// bfs(ii, jj, visited, grid);
			q.push({ii, jj});
			visited[ii][jj] = true;
			while (!q.empty()){
				auto t = q.front();
				q.pop();
				for (int d = 0; d < 4; ++d){
					int i = t.first + dir[d][0];
					int j = t.second + dir[d][1];
					if (i < 0 || i >= m || j < 0 || j >= n){
						continue;
					}
					if (!visited[i][j] && grid[i][j]){
						visited[i][j] = true;
						q.push({ i, j });
					}
				}
			}
		}
		return cnt;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<char>> grid1 = { { 0, 1, 0 },
								{ 1, 0, 1 },
								{ 0, 1, 0 } };
	vector<vector<char>> grid2 = { { 1, 1, 0, 0, 0 },
								{ 1, 1, 0, 0, 0 },
								{ 0, 0, 1, 0, 0 },
								{ 0, 0, 0, 1, 1 } };
	vector<string> str = {"11111011111111101011", "01111111111110111110", "10111001101111111111", "11110111111111111111", "10011111111111111111", "10111111011101110111", "01111111111101101111", "11111111111101111011", "11111111110111111111", "11111111111111111111", "01111111011111111111", "11111111111111111111", "11111111111111111111", "11111011111110111111", "10111110111011110111", "11111111111101111110", "11111111111110111100", "11111111111111111111", "11111111111111111111", "11111111111111111111"};
	vector<vector<char>> grid3(str.size(), vector<char>(str[0].size(), 1));
	for (int i = 0; i < grid3.size(); ++i){
		for (int j = 0; j < grid3[0].size(); ++j){
			if (str[i][j] == '0'){
				grid3[i][j] = 0;
			}
		}
	}

	cout << s.numIslands(grid3) << endl;
	system("pause");
	return 0;
}