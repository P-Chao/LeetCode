#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		const int n = triangle.size();
		if (n == 0){
			return 0;
		}
		for (int i = n - 2; i >= 0; --i){
			for (int j = 0; j <= i; ++j){
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.minimumTotal(vector<vector<int>>{{2}, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 }}) << endl; // 11
	system("pause");
	return 0;
}