#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	int used1[9][9], used2[9][9], used3[9][9];

public:
	void solveSudoku(vector<vector<char> > &board) {
		vector<vector<int>> place;
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[i].size(); ++j) {
				if (board[i][j] == '.')
					place.push_back({ i, j });
				else {
					int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
					used1[i][num] = used2[j][num] = used3[k][num] = 1;
				}
			}

		DFS(board, place, place.size() - 1);
	}

private:
	bool DFS(vector<vector<char>> &board, vector<vector<int>> &place, int n)
	{
		if (n < 0)
			return true;

		int i = place[n][0], j = place[n][1];

		for (int num = 0; num < 9; ++num)
		{
			int k = i / 3 * 3 + j / 3;
			if (!used1[i][num] && !used2[j][num] && !used3[k][num])
			{
				used1[i][num] = used2[j][num] = used3[k][num] = 1;
				board[i][j] = num + '0' + 1;

				if (DFS(board, place, n - 1))
					return true;

				used1[i][num] = used2[j][num] = used3[k][num] = 0;
				board[i][j] = '.';
			}
		}

		return false;
	}
};