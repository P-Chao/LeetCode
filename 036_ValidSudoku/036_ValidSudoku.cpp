#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool maskb[9][9] = {false}; //i % 3 + j /3
		bool maskr[9][9] = {false}; //i
		bool maskc[9][9] = {false}; //j
		for (int i = 0; i < 9; ++i){
			int tp = i / 3;
			for (int j = 0; j < 9; ++j){
				int t = tp * 3 + j / 3;
				if (board[i][j] == '.'){
					continue;
				}
				auto& m1 = maskb[t][board[i][j]-'1'];
				auto& m2 = maskc[i][board[i][j]-'1'];
				auto& m3 = maskr[j][board[i][j]-'1'];
				if (m1 || m2 || m3){
					return false;
				}
				m1 = true;
				m2 = true;
				m3 = true;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<char>> board = {};
	cout << s.isValidSudoku(board) << endl;
	system("pause");
	return 0;
}