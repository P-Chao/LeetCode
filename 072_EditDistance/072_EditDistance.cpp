#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		const int n1 = word1.size();
		const int n2 = word2.size();
		if (n1 == 0 || n2 == 0){
			return n1 + n2;
		}

		vector<vector<int>> dp(n1, vector<int>(n2, 0));
		if (word1[0] == word2[0]){
			dp[0][0] = 0;
		} else{
			dp[0][0] = 1;
		}
		bool flag = (word1[0] == word2[0]);
		for (int i = 1; i < n1; ++i){
			if (!flag && word1[i] == word2[0]){
				flag = true;
				dp[i][0] = dp[i - 1][0];
			}
			else{
				dp[i][0] = dp[i - 1][0] + 1;
			}
			
		}
		flag = (word1[0] == word2[0]);
		for (int j = 1; j < n2; ++j){
			if (!flag && word1[0] == word2[j]){
				flag = true;
				dp[0][j] = dp[0][j - 1];
			}
			else{
				dp[0][j] = dp[0][j - 1] + 1;
			}
			
		}
		for (int i = 1; i < n1; ++i){
			for (int j = 1; j < n2; ++j){
				int val = min(dp[i - 1][j], dp[i][j - 1]) + 1;
				dp[i][j] = min(val, dp[i-1][j-1] + ((word1[i] == word2[j]) ? 0 : 1));
			}
		}
		return dp[n1-1][n2-1];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.minDistance("sea", "eat") << endl;
	system("pause");
	return 0;
}