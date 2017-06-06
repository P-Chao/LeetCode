#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p){
		int slen = s.size(), plen = p.size();
		vector<vector<bool>> dp(slen+1, vector<bool>(plen+1));
		dp[0][0] = true;
		for (int i = 1; i <= slen; ++i){
			dp[i][0] = false;
		}
		for (int j = 1; j <= plen; ++j){
			dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2];
		}
		for (int i = 1; i <= slen; ++i){
			for (int j = 1; j <= plen; ++j){
				if (p[j - 1] == '*'){
					dp[i][j] = dp[i][j-2] ||
						(s[i-1] == p[j-2] || '.' == p[j-2]) && dp[i-1][j];
				} else{
					dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-2] || '.' == p[j-2]);
				}
			}
		}
		return dp[slen][plen];
	}

	bool isMatchMy(string s, string p) { // BackTrack
		if (p.empty()){
			return s.empty();
		}
		if (p.size() == 1){
			if (s.size() != 1){
				return false;
			}
			if (s[0] == p[0] || '.' == p[0]){
				return true;
			} else{
				return false;
			}
		}

		if (p[1] == '*'){
			if (s.empty()){
				return isMatch(s, p.substr(2));
			}
			if (s[0] == p[0] || '.' == p[0]){
				return (isMatch(s.substr(1), p) || isMatch(s, p.substr(2)));
			} else{
				return isMatch(s, p.substr(2));
			}
		} else{
			if (s.empty()){
				return false;
			}
			if ((s[0] == p[0]) || ('.' == p[0])){
				return isMatch(s.substr(1), p.substr(1));
			} else{
				return false;
			}
		}
		return false;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.isMatch("a", "a*a") << endl;
	system("pause");
	return 0;
}