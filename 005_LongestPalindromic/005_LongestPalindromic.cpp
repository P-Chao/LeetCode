#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2) return s;
		int start = 0, len = 1;
		for (int i = 0; i < s.size();) {
			int j = i, k = i;
			while (k < s.size() - 1 && s[k] == s[k + 1]){ // 找相等
				k++;
			}
			i = k + 1;  // 避免重复
			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) {  // 从相等开始找对称
				j--;
				k++;
			}
			int newLen = k - j + 1;
			if (len < newLen) {  // 记录结果
				len = newLen;
				start = j;
			}
		}
		return s.substr(start, len);
	}

	string longestPalindromeMyDP(string s) {
		const int n = s.size();
		if (n < 2){
			return s;
		}
		int maxlen = 1;
		pair<int, int> v{0, 0};
		vector<vector<bool>> valid(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i){
			valid[i][i] = true;
		}
		
		for (int i = 0; i < n - 1; ++i){
			int j = i + 1;
			if (s[i] == s[j]){
				valid[i][j] = true;
				maxlen = 2;
				v = { i, j };
			}
		}
		for (int len = 2; len < n; len++){
			for (int i = 0; i < n - len; ++i){
				int j = i + len;
				if (s[i] == s[j] && valid[i+1][j-1]){
					valid[i][j] = true;
					maxlen = len + 1;
					v = { i, j };
				}
			}
		}
		return s.substr(v.first, v.second - v.first + 1);
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.longestPalindrome("cbbd") << endl;
	system("pause");
	return 0;
}