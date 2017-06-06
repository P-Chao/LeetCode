#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

// 连通域方法

class SolutionMy{
public:
	int trapRainWater(vector<vector<int>>& heightMap){
		// input check
		int val = 0;
		const int cols = heightMap.size();
		if (cols < 3){
			return 0;
		}
		const int rows = heightMap[0].size();
		if (rows < 3){
			return 0;
		}
		
		// little root, pair(height, position)
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

		// boundray enquene
		for (int i = 0; i < cols; ++i){
			q.push({heightMap[i][0], i * rows});
			q.push({heightMap[i][rows-1], i * rows + rows-1});
		}
		for (int i = 1; i < rows - 1; ++i){
			q.push({heightMap[0][i], i});
			q.push({heightMap[cols-1][i], (cols-1)*rows + i});
		}

		// bfs search direction and visited label, c++ initialize
		vector<vector<int>> dir{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
		vector<vector<bool>> visited(cols, vector<bool>(rows, false));

		// bfs
		int mx = INT_MIN;
		while (!q.empty()){
			const auto t = q.top(); q.pop();
			mx = max(mx, t.first);

			const int c = t.second / rows; //xx
			const int r = t.second % rows; //yy
			for (int i = 0; i < 4/*dir.size()*/; ++i){
				const int x = c + dir[i][0];
				const int y = r + dir[i][1];
				if (x < 1 || x >= cols-1 || y < 1 || y >= rows-1 || visited[x][y]){
					continue;
				}
				visited[x][y] = true;
				if (heightMap[x][y] < mx){
					val += mx - heightMap[x][y];
				}
				q.push({heightMap[x][y], x * rows + y});
			}
		}

		return val;
	}
};

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		if (heightMap.empty())
			return 0;
		int m = heightMap.size(), n = heightMap[0].size(), res = 0, mx = INT_MIN;
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // greater 最小优先队列 less 最大优先队列
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		vector<vector<int>> dir{ { 0, -1 }, { -1, 0 }, { 0, 1 }, {1, 0} };
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (i==0 || i == m - 1 || j == 0 || j == n - 1){ // boundary
					q.push({ heightMap[i][j], i * n + j });
					visited[i][j] = true;
				}
			}
		}
		while (!q.empty()){
			auto t = q.top(); q.pop(); 
			int h = t.first, r = t.second / n, c = t.second % n;
			mx = max(mx, h);
			for (int i = 0; i < dir.size(); ++i){ // bfs, visited
				int x = r + dir[i][0], y = c + dir[i][1];
				if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]){
					continue;
				}
				visited[x][y] = true; // bfs, check end
				if (heightMap[x][y] < mx){
					res += mx - heightMap[x][y];
				}
				q.push({heightMap[x][y], x * n + y});
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]){
	vector<vector<int>> heights = {
		{12, 13, 0, 12},
		{13, 4, 13, 12},
		{13, 8, 10, 12},
		{12, 13, 12, 12},
		{13, 13, 13, 13}
	};//ans = 14

	SolutionMy s;
	cout << s.trapRainWater(heights) << endl;
	system("pause");
	return 0;
}
