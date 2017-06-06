#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		const int m = matrix.size();
		if (m == 0){
			return false;
		}
		const int n = matrix[0].size();
		if (n == 0){
			return false;
		}
		int row_s = 0, row_e = m - 1;
		int col_s = 0, col_e = n - 1;
		int r = 0;
		while (row_s <= row_e){
			int mid = (row_s + row_e) / 2;
			int miv = matrix[mid][0];
			if (miv < target){
				row_s = mid + 1;
				r = mid;
			} else if (miv > target){
				row_e = mid - 1;
			} else{
				return true;
			}
		}
		while (col_s <= col_e){
			int mid = (col_s + col_e) / 2;
			int miv = matrix[r][mid];
			if (miv == target){
				return true;
			} else if (miv < target){
				col_s = mid + 1;
			} else{
				col_e = mid - 1;
			}
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<int>> matrix{ { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
	cout << s.searchMatrix(matrix, 51) << endl;
	system("pause");
	return 0;
}