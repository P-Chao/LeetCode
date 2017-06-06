#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size() - 1;
		const int nh1 = matrix.size() / 2;
		int nh2 = nh1;
		if (!(n % 2)){
			nh2++;
		}
		for (int i = 0; i < nh1; ++i){
			for (int j = 0; j < nh2; ++j){
				swap(matrix[j][i], matrix[i][n-j]);
				swap(matrix[j][i], matrix[n-j][n-i]);
				swap(matrix[j][i], matrix[n-i][j]);
			}
		}
		return;
	}

	void rotate_opt(vector<vector<int>>& matrix) {
		const int n = matrix.size() - 1;
		const int nh1 = matrix.size() / 2;
		int nh2 = nh1;
		if (!(n % 2)){
			nh2++;
		}
		int tmp = 0;
		int ni = 0, nj = 0;
		for (int i = 0; i < nh1; ++i){
			for (int j = 0; j < nh2; ++j){
				ni = n - i;
				nj = n - j;
				tmp = matrix[j][i];
				matrix[j][i] = matrix[ni][j];
				matrix[ni][j] = matrix[nj][ni];
				matrix[nj][ni] = matrix[i][nj];
				matrix[i][nj] = tmp;
			}
		}
		return;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<int>> matrix{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	s.rotate(matrix);
	for (int i = 0; i < matrix.size(); ++i){
		for (int j = 0; j < matrix.size(); ++j){
			cout << matrix[i][j] << ", ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}