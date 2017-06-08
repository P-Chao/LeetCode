#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		const int m = dungeon.size();
		const int n = dungeon[0].size();
		vector<vector<int>> minHP(m, vector<int>(n, 0));
		minHP[m - 1][n - 1] = max(1, 1-dungeon[m-1][n-1]);
		for (int i = m - 2; i >= 0; --i){
			minHP[i][n-1] = max(1, minHP[i+1][n-1] - dungeon[i][n-1]);
		}

		for (int j = n - 2; j >= 0; --j){
			minHP[m-1][j] = max(1, minHP[m-1][j+1] - dungeon[m-1][j]);
		}

		for (int i = m - 2; i >= 0; --i){
			for (int j = n - 2; j >= 0; --j){
				minHP[i][j] = max(1, min(minHP[i+1][j], minHP[i][j+1]) - dungeon[i][j]);
			}
		}
		return minHP[0][0];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.calculateMinimumHP(vector<vector<int>>{{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}}) << endl;
	system("pause");
	return 0;
}