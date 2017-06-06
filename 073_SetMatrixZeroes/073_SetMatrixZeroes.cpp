#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		const int m = matrix.size();
		const int n = matrix[0].size();
		bool cols_zeroes = false, rows_zeroes = false;
		for (int i = 0; i < m; ++i){
			if (!matrix[i][0]){
				cols_zeroes = true;
				break;
			}
		}
		for (int j = 0; j < n; ++j){
			if (!matrix[0][j]){
				rows_zeroes = true;
				break;
			}
		}
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j){
				if (!matrix[i][j]){
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j){
				if (!(matrix[i][0] && matrix[0][j])){
					matrix[i][j] = 0;
				}
			}
		}

		if (cols_zeroes){
			for (int i = 0; i < m; ++i){
				matrix[i][0] = 0;
			}
		}
		if (rows_zeroes){
			for (int j = 0; j < n; ++j){
				matrix[0][j] = 0;
			}
		}
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	system("pause");
	return 0;
}
