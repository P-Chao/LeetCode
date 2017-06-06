#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	int minCut(string s){
		const int n = s.size();
		vector<int> cut(n+1, 0);
		for (int i = 0; i <= n; ++i){
			cut[i] = i - 1;
		}
		for (int i = 0; i < n; ++i){
			for (int r = 0; r < i && i + r < n && s[i - r] == s[i + r]; r++){
				cut[i + r + 1] = min(cut[i+r+1], 1 + cut[i-r]);
			}
			for (int r = 0; r <= i && i + r + 1 < n && s[i - r] == s[i + r + 1]; r++){
				cut[i + r + 2] = min(cut[i+r+2], 1 + cut[i-r]);
			}
		}
		return cut[n];
	}

	int minCutOld(string s){
		const int n = s.size();
		vector<int> min(n+1, -1);
		vector<vector<bool>> palin(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i){
			palin[i][i] = true;
		}

		for (int i = n - 1; i >= 0; --i){
			min[i] = min[i + 1] + 1;
			for (int j = i + 1; j < n; ++j){
				if ((s[i] == s[j]) && (j == i + 1 || palin[i + 1][j - 1])){
					palin[i][j] = true;
					if (min[i] > min[j + 1] + 1){
						min[i] = min[j + 1] + 1;
					}
				}
			}
		}

		return min[0];
	}

	int minCutMyBFS(string s) {
		const int n = s.size();
		if (n < 2){
			return 0;
		}
		vector<vector<bool>> valid(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i){
			valid[i][i] = true;
		}
		for (int i = 0; i < n - 1; ++i){
			int j = i + 1;
			valid[i][j] = (s[i] == s[j]);
		}
		for (int len = 2; len < n; ++len){
			for (int i = 0; i < n - len; ++i){
				int j = i + len;
				valid[i][j] = (s[i] == s[j]) && valid[i + 1][j - 1];
			}
		}

		queue<pair<int, int>> q;
		q.push({0, 0});
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			if (valid[t.first][n - 1]){
				return t.second;
			}
			for (int i = t.first; i < n; ++i){
				if (valid[t.first][i]){
					q.push({i+1, t.second +1});
				}
			}
		}
		return n-1;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	cout << s.minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp") << endl; //452
	system("pause");
	return 0;
}