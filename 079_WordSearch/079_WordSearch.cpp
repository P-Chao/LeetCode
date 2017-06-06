#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		m = board.size();
		if (m == 0){
			return false;
		}
		n = board[0].size();
		vector<vector<bool>> mask(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (dfs(board, word, i, j, 0, mask)){
					return true;
				}
			}
		}
		return false;
	}
private:
	bool dfs(vector<vector<char>>& board, string word, int i, int j, int pos, vector<vector<bool>>& mask){
		m = board.size();
		n = board[0].size();
		if (board[i][j] != word.at(pos)){
			return false;
		}
		if (pos == word.size() - 1){
			return true;
		}
		mask[i][j] = true;
		int curpos = pos + 1;

		// go right
		if (j + 1 < n && mask[i][j + 1] == false
			&& dfs(board, word, i, j + 1, curpos, mask)){
			return true;
		}
		// go down
		if (i + 1 < m && mask[i + 1][j] == false
			&& dfs(board, word, i + 1, j, curpos, mask)){
			return true;
		}
		// go left
		if (i - 1 >= 0 && mask[i - 1][j] == false
			&& dfs(board, word, i - 1, j, curpos, mask)){
			return true;
		}
		// go up
		if (j - 1 >= 0 && mask[i][j - 1] == false
			&& dfs(board, word, i, j - 1, curpos, mask)){
			return true;
		}

		mask[i][j] = false;
		return false;
	}
	int m, n;
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<char>> board{ { 'A', 'B', 'C', 'E' }, 
								{ 'S', 'F', 'C', 'S' }, 
								{ 'A', 'D', 'E', 'E' } };
	cout << s.exist(board, string("ABCCED")) << endl;
	system("pause");
	return 0;
}