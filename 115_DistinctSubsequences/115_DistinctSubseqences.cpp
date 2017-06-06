#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		const int m = s.size();
		const int n = t.size();

		vector<vector<int>> dp(m+1, vector<int>(n+1));
		dp[0][0] = 1;
		for (int i = 1; i <= m; ++i){
			dp[i][0] = 1;
		}
		for (int i = 1; i <= m; ++i){
			int bd = min(i, n);
			for (int j = 1; j <= bd; ++j){
				if (s[i - 1] == t[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				} else{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[m][n];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.numDistinct("a", "a") << endl;
	system("pause");
	return 0;
}