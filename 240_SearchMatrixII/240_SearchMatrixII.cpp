#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (!m){
			return false;
		}
		int n = matrix[0].size();
		if (!n){
			return false;
		}
		int i = 0, j = n - 1;
		while (i < m && j >= 0) {
			if (matrix[i][j] == target){
				return true;
			} else if (matrix[i][j] > target){
				--j;
			} else{
				++i;
			}
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<int>> matrix{ 
		{ 1, 4, 7, 11, 15 },
		{ 2, 5, 8, 12, 19 },
		{ 3, 6, 9, 16, 22 },
		{ 10, 13, 14, 17, 24 },
		{ 18, 21, 23, 26, 30 } };
	cout << s.searchMatrix(matrix, 5) << endl;
	system("pause");
	return 0;
}