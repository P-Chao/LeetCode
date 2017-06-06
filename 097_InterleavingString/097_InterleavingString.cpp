#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3){
		const int m = s1.size();
		const int n = s2.size();
		if (m + n != s3.size()){
			return false;
		}
		if (m == 0 || n == 0){
			return (s1 + s2 == s3);
		}

		vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
		dp[0][0] = true;
		for (int i = 0; i < m; ++i){
			if (dp[i][0] && s1[i] == s3[i]){
				dp[i + 1][0] = true;
			} else{
				break;
			}
		}
		for (int j = 0; j < n; ++j){
			if (dp[0][j] && s2[j] == s3[j]){
				dp[0][j + 1] = true;
			} else{
				break;
			}
		}
		for (int i = 1; i <= m; ++i){
			for (int j = 1; j <= n; ++j){
				if (dp[i][j - 1] && s2[j-1] == s3[i + j - 1]){
					dp[i][j] = true;
				} else if (dp[i - 1][j] && s1[i-1] == s3[i + j - 1]){
					dp[i][j] = true;
				}
			}
		}
		return dp[m][n];
	}

	bool isInterleaveMy(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()){
			return false;
		}
		if (s1.empty()){
			return s2 == s3;
		}
		if (s2.empty()){
			return s1 == s3;
		}
		if (s1 + s2 == s3 || s2 + s1 == s3){
			return true;
		}
		if (s1[0] == s3[0] && isInterleaveMy(s1.substr(1), s2, s3.substr(1))){
			return true;
		}
		if (s2[0] == s3[0] && isInterleaveMy(s1, s2.substr(1), s3.substr(1))){
			return true;
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isInterleave("accccaabbccabccabbcaabaabccccbbcabcabaccccabcaccbbccaaaccab",
			"cbaccbcaaaaacabbbbaaaccbabbcbcbbbbbbabcbbabaababaa",
			"cbaccbcaaccaaccaabbcacacaabbbbbaccaaacbcbabbbcbccaabbaabbbbcccbbcabbbcbcababbcaabaabcabacaccabcaccbbccaaaccab") << endl;
	system("pause");
	return 0;
}