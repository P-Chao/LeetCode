#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		vector<vector<int>> place;
		for (int i = 0; i < 9; ++i){
			for (int j = 0; j < 9; ++j){
				if (board[i][j] == '.'){
					place.push_back({i, j});
				} else{
					int num = board[i][j] - '1', k = i / 3 * 3 + j / 3;
					used1[i][num] = used2[j][num] = used3[k][num] = true;
				}
			}
		}
		dfs(board, place, place.size()-1);
	}
private:
	bool dfs(vector<vector<char>>& board, vector<vector<int>>& place, int n){
		if (n < 0){
			return true;
		}
		int i = place[n][0], j = place[n][1];
		for (int num = 0; num < 9; ++num){
			int k = i / 3 * 3 + j / 3;
			if (!(used1[i][num] || used2[j][num] || used3[k][num])){
				used1[i][num] = used2[j][num] = used3[k][num] = true;
				board[i][j] = num + '1';
				if (dfs(board, place, n - 1)){
					return true;
				}
				used1[i][num] = used2[j][num] = used3[k][num] = false;
				board[i][j] = '.';
			}
		}
		return false;
	}
	bool used1[9][9], used2[9][9], used3[9][9];
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<char>> board;
	s.solveSudoku(board);
	system("pause");
	return 0;
}