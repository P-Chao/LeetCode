#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		const int n = s.size();
		vector<bool> dp(n+1, false);
		dp[0] = true;
		for (int i = 1; i <= n; ++i){
			for (int j = i - 1; j >= 0; --j){
				if (dp[j] && (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())){
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n];
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.wordBreak("leetcode", vector<string>{"leet" , "code"}) << endl;
	system("pause");
	return 0;
}