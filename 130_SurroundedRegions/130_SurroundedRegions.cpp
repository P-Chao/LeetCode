#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		const int m = board.size();
		if (m == 0){
			return;
		}
		const int n = board[0].size();
		if (n == 0){
			return;
		}

		queue<pair<int, int>> q;
		vector<vector<int>> dir{ { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		for (int i = 0; i < m; ++i){
			if (board[i][0] == 'O'){
				board[i][0] = 'V';
				q.push({i, 0});
			}
			if (board[i][n-1] == 'O'){
				board[i][n-1] = 'V';
				q.push({i, n-1});
			}
		}
		for (int j = 1; j < n-1; ++j){
			if (board[0][j] == 'O'){
				board[0][j] = 'V';
				q.push({0, j});
			}
			if (board[m-1][j] == 'O'){
				board[m-1][j] = 'V';
				q.push({m-1, j});
			}
		}

		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			for (int d = 0; d < 4; ++d){
				int i = t.first + dir[d][0];
				int j = t.second + dir[d][1];
				if (i < 0 || i > m - 1 || j < 0 || j > n - 1){
					continue;
				}
				if (board[i][j] == 'O'){
					board[i][j] = 'V';
					q.push({i, j});
				}
			}
		}

		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				switch (board[i][j]){
				case 'V':
					board[i][j] = 'O';
					break;
				case 'O':
					board[i][j] = 'X';
					break;
				case 'X':
					break;
				default:
					// throw a exp
					abort();
					break;
				}
			}
		}
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<string> grid{"XXXX","XOOX","XXOX","XOXX"};
	vector<vector<char>> board(grid.size(), vector<char>(grid[0].size(), 1));
	for (int i = 0; i < board.size(); ++i){
		for (int j = 0; j < board[0].size(); ++j){
			board[i][j] = grid[i][j];
		}
	}
	s.solve(board);
	for (auto bd : board){
		for (auto v: bd){
			cout << v;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}