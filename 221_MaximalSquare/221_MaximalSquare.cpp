#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char> >& matrix) {
		if (matrix.size() == 0){
			return 0;
		}
		vector<vector<char> > b(matrix.size() + 1, vector<char>(matrix[0].size() + 1, 0));
		int maxx = 0;
		for (int i = 1; i <= matrix.size(); i++){
			for (int j = 1; j <= matrix[0].size(); j++){
				if (matrix[i - 1][j - 1] == '1'){
					b[i][j] = min(min(b[i - 1][j - 1], b[i - 1][j]), b[i][j - 1]) + 1;
					if (b[i][j]>maxx){
						maxx = b[i][j];
					}
				}
			}
		}
		return maxx*maxx;
	}

	int maximalSquareOld(vector<vector<char>>& matrix) {
		const int m = matrix.size();
		if (m == 0){
			return 0;
		}
		const int n = matrix[0].size();
		if (n == 0){
			return 0;
		}
		int maxarea = 0;
		vector<int> left(n, 0), right(n, n), height(n, 0);
		for (int i = 0; i < m; ++i){
			int curleft = 0, curright = n;
			for (int j = 0; j < n; ++j){
				if (matrix[i][j] == '1'){
					height[j]++;
				} else{
					height[j] = 0;
				}
			}

			for (int j = 0; j < n; ++j){
				if (matrix[i][j] == '1'){
					left[j] = max(curleft, left[j]);
				} else{
					left[j] = 0;
					curleft = j + 1;
				}
			}

			for (int j = n - 1; j >= 0; --j){
				if (matrix[i][j] == '1'){
					right[j] = min(curright, right[j]);
				} else{
					right[j] = n;
					curright = j;
				}
			}

			for (int j = 0; j < n; ++j){
				if (height[j]){
					int a = min(right[j]-left[j], height[j]);
					maxarea = max(maxarea, a * a);
				}
			}
		}

		return maxarea;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<char>> matrix{
		{ '1', '0', '1', '0', '0' },
		{ '1', '0', '1', '1', '1' },
		{ '1', '1', '1', '1', '1' },
		{ '1', '0', '0', '1', '0' } };
	vector<vector<char>> matrix2{
		{ '0', '1' } };
	cout << s.maximalSquare(matrix) << endl;
	system("pause");
	return 0;
}